# seaborn

# Regression Plots

- sns.regplot(x=“total_bill”, y=“tip”, data=tips);
- sns.lmplot(x=“total_bill”, y=“tip”, data=tips);
- Params:
    - x_jitter -> Add some random noise (“jitter”) to the discrete values to make easier to see the distribution of the values (does not influence the regression line fit itself)
    - robust=True -> Makes robust to outliers

## References:
https://seaborn.pydata.org/tutorial/regression.html https://seaborn.pydata.org/generated/seaborn.stripplot.html

# Plot one variable

```
sns.stripplot(x=tips["total_bill"])
plt.plot(data['day'], 'o')
sns.distplot(df['time_to_promotion'])
```

# Plot more than one variable

```
fig, axs = plt.subplots(ncols=3)
sns.regplot(x='value', y='wage', data=df_melt, ax=axs[0])
sns.regplot(x='value', y='wage', data=df_melt, ax=axs[1])
sns.boxplot(x='education',y='wage', data=df_melt, ax=axs[2])
```

# Categorical variables

## Categorical scatterplots:

- stripplot() (with kind=“strip”; the default)
- swarmplot() (with kind=“swarm”)

## Categorical distribution plots:

- boxplot() (with kind=“box”)
- violinplot() (with kind=“violin”)
- boxenplot() (with kind=“boxen”)

## Categorical estimate plots:

- pointplot() (with kind=“point”)
- barplot() (with kind=“bar”)
- countplot() (with kind=“count”) # distribution of categorical

## > Draw a scatterplot where one variable is categorical

```
sns.stripplot(x="day", y="total_bill", data=tips)
```

## > Nest the strips within a second categorical variable

```
sns.stripplot(x="sex", y="total_bill", hue="day", data=tips)
```

## > Boxplot by one categorical variable

```
sns.boxplot(x="categorical_var", y="cont_var", data=df)
```

## > Boxplot by two categorical variables

```
ax = sns.boxplot(x="categorical_var_1", y="cont_var", hue="categorical_var_2", data=df, palette="Set3")
```

## > Show the datapoints on top of the boxes

```
sns.swarmplot(x="day", y="total_bill", data=tips, color=".25")
```

# Distribution plots
```
sns.displot(penguins, x=“flipper_length_mm”)
```
## References
https://seaborn.pydata.org/tutorial/distributions.html
