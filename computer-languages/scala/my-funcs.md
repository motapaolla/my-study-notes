# scala 

```scala
import org.apache.spark.sql.DataFrame
def from_DF_to_test(result: DataFrame): String = {
  var seqToStr = result.collect().map(row => row.toSeq).toSeq.toString.split("WrappedArray")

  val n = seqToStr.size
  var content = "\n"
  for (i <- 2 to n-1) {
    val tuple = seqToStr(i).trim
    content = content.concat(tuple + "\n")
  }

  val colsArr = result.columns
  val cols = "\"" + colsArr.mkString("\", \"") + "\""

  val mockedStr = s"""Seq($content.toDF($cols)"""
  
  mockedStr
}
```