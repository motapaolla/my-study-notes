# Cheat Sheet


### Display columns and rows

```
pd.options.display.max_columns = 200
pd.options.display.max_rows = 200
```

### Notation

```
pd.set_option('display.float_format', lambda x: '%.2f' % x)
```

### Simple dataframe

```
import pandas as pd
df = pd.DataFrame({'y': [0, 1, 0, 1, 0], 'cat': ['a', 'b', 'c', 'd', 'e'], 'dog': ['a', 'b', 'c', 'd', 'e'], 'float': [123.2, 2.0, 3.23, 4.555555, 6.3]})
```

### Remove warnings

```
import warnings
warnings.filterwarnings('ignore')
```

### Display markdown on cell

```
from IPython.display import display, Markdown, Latex
display(Markdown('#### Applicated for many job titles'))
```

### Format 2 decimal points

```
# format()
formatted = "{:.2f}".format(a_float)

# f string
formatted = f'My number is {a_float:.2f}'

# formatting operator
formatted = '%.2f' % a_float

# round function
formatted = round(a, 2)
```

### Align markdown

```
<h1 align="center">Title</h1>
```

### Save local dataset

```
%store <name>
%store -r <name>
```

### Dates

```
pd.Timestamp(2017, 1, 1, 12)
pd.to_datetime(df[col])
```

### Today date

```
from datetime import date
today = date.today()
```

### Remove cache from pip

```
$ pip cache purge
```

### Strings

- `r'your text\n'` -> raw string, sem interpretar os caracteres especiais

### HASH CPF

```python
import hashlib

def hash_str(s):
    encoded_str = s.encode()
    hash_obj_sha384 = hashlib.sha384(encoded_str)
    return hash_obj_sha384.hexdigest()
```