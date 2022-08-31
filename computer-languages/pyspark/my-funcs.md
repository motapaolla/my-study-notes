# pyspark

# Pyspark

- **Widget variavel databricks notebook**

```python
dbutils.widgets.text(name="reference_date",
                     defaultValue=f"%Y-%m-%d:{yesterday}")
```

- **Pegar data de ontem**

```python
import datetime
yesterday = datetime.date.today() - datetime.timedelta(1) 
# or 
yesterday = F.date_sub(F.current_date(), 1)
```

- **Explodir coluna contendo lista de strings de structs**

`df = df.withColumn("values", F.explode('column')).select("*", F.col("values.*")).count()`

- **Nulos:** `F.col('col').isNotNull()` e `F.col('col').isNull()`
- **Transformação em colunas**: `df = df.withColumn('novo nome', condicao)`
- **Drop duplicates:** `df.dropDuplicates(['coluna'])`
- **Spark separa tudo em varios arquivos, esse comando junta tudo:** `df.coalesce(1)`
- **Binariza coluna:** `df.withColumn('column', F.col('column')>0.00698) # Threshold at mean value`
- **Median:** `df_no_zeros.approxQuantile("quality_score", [0.5], 0.25)`
- **Concat**:
    
    `df.union(df2)`
    
- **Statements condicionais**:
    
    ```
    # Em pandas
    df['cond'] = df.apply(lambda x: 1 if x.val1 > 1 else 2 if x.val2 == 6 else 3, axis=1)
    # Em pyspark
    df.withColumn('cond', F.when(df.val1>20, 1).when(df.val2 == 6, 2).otherwise(3))
    ```
    
- **UDF**:
    
    ```python
    from pyspark.sql.types import DoubleType
    fn = F.udf(lambda x: x+1, DoubleType())
    df.withColumn('col1', fn(df.col))
    ```
    
- **Salva no S3**:
    
    ```python
    df.write.option('maxRecordsPerFile', 50000) \  .json(output_path, mode='overwrite', compression='gzip')
    ```
    

---

# Functions

### Simple dataframe

```python
data = [("James","","Smith","36636","M",3000, False),
("Michael","Rose","","40288","M",4000, False),
("Robert","","Williams","42114","M",4000, False),
("Maria","Anne","Jones","39192","F",4000, True),
("Jen","Mary","Brown","52200","F",-1, True)  ]

schema = T.StructType([ \
    T.StructField("firstname", T.StringType(), True), \
    T.StructField("middlename", T.StringType(), True), \
    T.StructField("lastname", T.StringType(), True), \
    T.StructField("id", T.StringType(),  True), \
    T.StructField("gender", T.StringType(),  True), \
    T.StructField("salary", T.IntegerType(),  True), \
    T.StructField("bool", T.BooleanType(),  True)  ])

df = spark.createDataFrame(data=data, schema=schema)
```

- From a list of tuples

```python
columns = ["id","rank"]
data = [(1, 1), (2, 2), (4, 4), (5, 5), (6, 6), (7, 7), (8, 8), (9, 9), (10, 10)]
rank_precision = spark.createDataFrame(data).toDF(*columns)
```

### Describe for 2 columns

```python
def describe(df, cols):  
    """Get describe with median value (further to add other statistical functions)  
    :param df: [DataFrame], dataframe to make calculations  
    :param cols: [array], columns to select, could be string or list  
    :returns: [DataFrame], dataframe that can be passed to a display()  """
    
	describe_cols = ['summary']  
	vals = ['median']  
	if isinstance(cols, list) is False:    
		cols = [cols]  
		for col in cols:    
			describe_cols.append(col)    
			vals.append(df.approxQuantile(col, [0.5], 0.25)[0])  
    medianRow = spark.createDataFrame([tuple(vals)], describe_cols)  
    describe = df.select(cols).describe().union(medianRow)  
    return describe
```

### Get unique

```python
def distinct(df, col):  
    col = df.select(col).distinct().collect()  
    return [val[0] for val in col]
```

### Stratified split

```python
def get_stratified_sample(df, col, id_col, proportion_split=0.5):  
    """Gets a stratified sample of a dataset. Only works with boolean columns.  
    :param df: [pandas.DataFrame], dataframe to be stratified  
    :param col: [str], column to be used in the stratification  
    :param id_col: [str], name of the column to order by at the end  
    :param proportion_split: [float], proportion to split the datasets  
    :returns df: [pandas.DataFrame], stratified dataframe ordered by id_col  """  
    count_label_zeros = df.filter(df[col]==False).count()  
    count_label_ones = df.filter(df[col]==True).count()  
    if count_label_zeros > count_label_ones:    
        count = count_label_ones * 2 
    elif count_label_ones > count_label_zeros:    
        count = count_label_zeros * 2  
        count_splitted = count*proportion_split  
        fraction_zeros = count_splitted/count_label_zeros  
        fraction_ones = count_splitted/count_label_ones  
        df = ones.sample(fraction=fraction_ones, seed=5)\          
            .union(zeros.sample(fraction=fraction_zeros, seed=5))\          
            .orderBy(id_col)  
    return df
```

### Folders in path

```python
import boto3
def get_labeled_folders_in_s3_path(s3_labeled_folder, bucket):
	s3 = boto3.resource('s3')
	bucket = s3.Bucket(bucket)
	files_in_path = []
	for obj in bucket.objects.filter(Prefix=s3_labeled_folder):
		files_in_path.append(obj.key.replace(s3_labeled_folder, ''))
		folders_in_path = sorted(list(set(['/'.join(file.split('/')[:4]) 
			for file in files_in_path])))
		return folders_in_path
```

### Date widget

```python
import datetimeyesterday = datetime.date.today() - datetime.timedelta(1)
dbutils.widgets.text(name="reference_date", defaultValue=f"{yesterday:%Y-%m-%d}")
date = dbutils.widgets.get(name="reference_date")
```

### Rename S3 folder in Databricks

```python
def save_and_rename_s3_file(df, key, file_name, file_type='json', 
	root_bucket='dev-ifood-ml-sagemaker'):
	"""Save dataframe on an s3 bucket and format its name    
	:param df: [DataFrame], dataframe to be saved 
	:param key: [str], s3 key without brackets (\/) on start or end of string
	:param file_name: [str], name of the file without extention
	:param root_bucket: [str], bucket
	:param file_type: [str], file type, default 'json'
	"""
	folder = f's3://{root_bucket}/{key}/{file_name}'
	print(f'Saving file `{file_name}` on `{folder}`')
	df.coalesce(1).write.json(folder)
	print(f'Renaming file `{file_name}` from `{folder}`')
	for file in dbutils.fs.ls(folder):
	    path = file.path
	    if 'part-00000' in path:
	        dbutils.fs.mv(path, f'{folder}.{file_type}')
	    elif ('SUCCESS' in path) or ('committed' in path) or ('started' in path):
	            dbutils.fs.rm(path, True)
	            print(f'Removing temp folder `{folder}`')
	            dbutils.fs.rm(folder, True)
	            print('Done!')
```

```python
def save_and_rename_s3_file(df, output_path, file_type='json'):    
    df.coalesce(1).write.json(output_path, mode='overwrite', compression='gzip')    
    for file in dbutils.fs.ls(output_path):        
        path = file.path        # rename        
        if 'part-00000' in path:            
            dbutils.fs.mv(path, f'{output_path}.{file_type}')        
            # clean not needed files        
        elif ('SUCCESS' in path) or ('committed' in path) or ('started' in path):
            dbutils.fs.rm(path, True)    
            # remove old file    
        dbutils.fs.rm(output_path, True)    
        print('Done!')
```

### Get min max from a column

```python
def get_min_max(df, col):  
    aggs = df.groupBy().agg(F.min(col).alias('min'),                          
                            F.max(col).alias('max')).collect()  
    rowmin = aggs[0].min  
    rowmax = aggs[0].max  
    return rowmin, rowmax

def scale(row, rowmin, rowmax, vmin, vmax):  
    scaled = ((row - rowmin)/(rowmax - rowmin) * (vmax - vmin)) + vmin  
    return scaledscale_udf = F.udf(scale, T.DoubleType())
```

### Extração de "gramas"

```python
extract_qty_regex = '\d+(?:[.,]\d+)?\s*-?(?:g(?:r(?:a?mas?)?)?)'
qty_rgx_df = (porcao_rgx_df    
              .withColumn('extracted_qty_from_name', 
                          F.regexp_extract(F.col('item_name'), 
                                           extract_qty_regex, 0))    
              .withColumn('extracted_qty_from_description', 
                          F.regexp_extract(F.col('item_description'), 
                                           extract_qty_regex, 0))    
              .withColumn('extracted_qty', 
                          F.when((F.col('extracted_qty_from_name') != ''), 
                                 F.col('extracted_qty_from_name'))\        
                          .otherwise(F.col('extracted_qty_from_description'))    )\    
              .withColumn('extracted_qty', F.when((F.col('extracted_qty') != ''), 
                                                  F.col('extracted_qty'))\        
                          .otherwise(F.concat_ws(' ', F.col('item_quantity'),  
                                                 F.col('item_unit')))    )\
              .drop('extracted_qty_from_name', 'extracted_qty_from_description'))
```

### Get correlation matrix

```python
from pyspark.ml.stat import Correlation
from pyspark.ml.feature import VectorAssembler
import pandas as pd

def get_correlation_matrix(df, cols, coeff='pearson'):
	assembler = VectorAssembler(inputCols=cols, outputCol='features')
	vectors = assembler.transform(df).persist()
	pearsonCorr = Correlation.corr(vectors, 'features', coeff)
	corr_array = pearsonCorr.select(coeff+'(features)').collect()[0][0].toArray().tolist()
	corr_df = pd.DataFrame(corr_array, columns=cols, index=cols)
	vectors = vectors.unpersist()
	return corr_df
```

### Get histogram

```python
def get_histogram(df, col, nbins=20):
  hist = df.select(col).rdd.flatMap(lambda x: x).histogram(nbins)
  data = [(x, y) for x, y in zip(hist[0], hist[1])]
  columns = ['x', 'y']
  return spark.createDataFrame(data).toDF(*columns)
```

### Get value counts for all columns

```python
# Function for automatic value counts
def get_value_counts(df, col, max_vals=10):
  counts = df.groupBy(col).count().collect()
  if len(counts) > max_vals:
    counts = counts[:max_vals]
    
  title = f"> Counts: {col}"
  print("-"*len(title))
  print(title)
  print("-"*len(title))
  [print(f"{row[col]}: {row['count']}") for row in counts]
  print("")
```
