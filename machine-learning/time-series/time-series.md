# Components of Time Series

Time series analysis provides a body of techniques to better understand a dataset. 
Perhaps the most useful of these is the decomposition of a time series into 4 
constituent parts:
- Level: The baseline value for the series if it were a straight line. 
- Trend: The optional and often linear increasing or decreasing behavior of the series overtime. 
- Seasonality: The optional repeating patterns or cycles of behavior over time. 
- Noise: The optional variability in the observations that cannot be explained by the model.

## Feature Engineering

There are three classes of features that we can create from our time series dataset: 
- Date Time Features: these are components of the time step itself for each observation. 
- Lag Features: these are values at prior time steps. 
- Window Features: these are a summary of values over a fixed window of prior time steps

### Date Time Features

- Minutes elapsed for the day.
- Hour of day.
- Business hours or not.5.5.
- Weekend or not.
- Season of the year.
- Business quarter of the year.
- Daylight savings or not.
- Public holiday or not.
- Leap year or not.

### Lag Features

Lag features are the classical way that time series forecasting problems are transformed into supervised learning problems. The simplest approach is to predict the value at the next time (t+1) given the value at the current time (t). The supervised learning problem with shifted values looks as follows:

```
Value(t), Value(t+1)
Value(t), Value(t+1)
Value(t), Value(t+1)
```

For building these features we use the `shift()` function from Pandas library. Shifting the dataset by 1 creates the t column, adding a NaN (unknown) value for the first row. The time series dataset without a shift represents the t+1.

### Window Features

The addition of lag features is called the sliding window method, in this case with a window width of 1. We can expand the window width and include more lagged features. However, we must discard the first few rows that do not have enough data to train a supervised model.

Sometimes, depending on the domain of your problem, perhaps you need a lag value from last week, last month, and last year. In the case of the temperature dataset, a lag value from the same day in the previous year or previous few years may be useful.

A difficulty with the sliding window approach is how large to make the window for your problem. Perhaps a good starting point is to perform a sensitivity analysis and try a suite of different window widths to in turn create a suite of different views of your dataset and see which results in better performing models. There will be a point of diminishing returns.

#### Rolling Window

Sometimes, depending on the domain of your problem, perhaps you need a lag value from last week, last month, and last year. In the case of the temperature dataset, a lag value from the same day in the previous year or previous few years may be useful. We can use this with rolling() function.

```python
def get_rolling_window(df, width):    
    shifted = temps.shift(width - 1)    
    window = shifted.rolling(window=width)    
    rw = pd.concat([window.min(), window.mean(), window.max()], axis=1)    
    rw.columns = ['min', 'mean', 'max']    
    df = pd.concat([rw, temps], axis=1)    
    return df
```

#### Expanding Window

Can help with keeping track of the bounds of observable data. Like the `rolling()` 
function on DataFrame, Pandas provides an `expanding()` function4 that collects sets 
of all prior values for each time step.

```python
def get_expanding_window(df):
	window = df.expanding()
	df = pd.concat([window.min(), window.mean(), window.max(), temps.shift(-1)], axis=1)
	df.columns = ['min', 'mean', 'max', df.columns[3]]
	return df
```

## Visualization

Usually we can use these plots to visualize a time series: 
- Line Plots. 
- Histograms and Density Plots. 
- Box and Whisker Plots. 
- Heat Maps. 
- Lag Plots or Scatter Plots. 
- Autocorrelation Plots.

### Line plot

df[time_col].plot(style=‘k.’)

It can be helpful to compare line plots for the same interval, such as from day-to-day, month-to-month, and year-to-year.

Group the observations by year (or month or day)

---
# References

https://www.dataquest.io/blog/tutorial-time-series-analysis-with-pandas/ https://towardsdatascience.com/almost-everything-you-need-to-know-about-time-series-860241bdc578