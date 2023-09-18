# conda

### Check if it’s up to date

```
$ conda update conda
```

### Create a virtual environment

```
$ conda create -n yourenvname python=x.x 
```

### List environments

```
$ conda env list
```

### Activate your environment

```
$ conda activate yourenvname
```

### Remove environment

```
$ conda remove --name myenv --all
    - If doesn’t work, try: $ conda env remove --name myenv
```

### Check size of env

```
$ du -sh <path-to-env>
```

Example: `$ du -sh /anaconda3/envs/matthew`