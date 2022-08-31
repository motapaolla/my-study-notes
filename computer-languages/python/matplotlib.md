# matplotlib

# Common params

- `alpha`: transparency
- `linestyle`: estilo da linha, ‘solid’, ‘dashed’, ‘dashdot’, ‘dotted’
- `bgcolor`: cor do background
- `color`: cor de algo

# Create axes

```
ax = plt.axes(axisbg='#E6E6E6')
ax.set_axisbelow(True): coloca os plots a frente do grid
```

# Hide border line

```
for spine in ax.spines.values():
    spine.set_visible(False)
```

# Change axes params

```
ax.tick_params(colors='g', direction='out')
```

# Styles default

- `plt.style.available`: vê lista de styles predefinidos
- `plt.style.use('stylename')`: usar o style

# Rotate x ticks

plt.xticks(rotation=45) style=‘k.’ - black dots