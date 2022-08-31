# Regression Metrics

- `errors`: A diferença dos valores preditos menos os valores reais:`ŷ - y`
- `variance`: a measure of how far observed values differ from the average of 
predicted values. The goal is to have a value that is low.
- `r2 score`: Best possible score is 1.0 and it can be negative (because the 
model can be arbitrarily worse). Varies between 0 and 100%. It is the total variance 
explained by model / total variance. A low value would show a low level of 
correlation. So if it is 100%, the two variables are perfectly correlated, with 
no variance at all.
- `mean square error (MSE)`: It is the average of the square of the errors. The 
larger the number the larger the error.
- `mean absolute error (MAE)`: É a soma dos valores absolutos dos erros dividido 
pela quantidade de pontos (ou seja, a quantidade de linhas do dataset). É uma 
métrica que mede sem considerar a direção. Código abaixo para o cálculo do MAE.

```python
def mae(predictions, targets):
    # Retrieving number of samples in dataset
    samples_num = len(predictions)

    # Summing absolute differences between predicted and expected values
    accumulated_error = 0.0
    for prediction, target in zip(predictions, targets):
        accumulated_error += np.abs(prediction - target)

    # Calculating mean
    mae_error = (1.0 / samples_num) * accumulated_error

    return mae_error
```

### References

https://towardsdatascience.com/coding-deep-learning-for-beginners-linear-regression-part-2-cost-function-49545303d29f

hθ(x) = θo x + θ1x