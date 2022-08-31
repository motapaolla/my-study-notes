# Ensemble Methods

An ensemble is just a collection of predictors which come together to give a final 
prediction. Many different predictors trying to predict same target variable will 
perform a better job than any single predictor alone. Ensembling techniques are 
further classified into Bagging and Boosting.

## Ensembling techniques

### Bagging

- A simple ensemble technique in which we build many independent predictors/models/learners and combine them using some model averaging techniques. (e.g. weighted average, majority vote or normal average).
- We typically take random sub-sample/bootstrap of data for each model, so that all the models are little different from each other. So, each model will have different observations based on the bootstrap process.
- Because this technique takes many uncorrelated learners to make a final model, it reduces error by reducing variance.
- An example of bagging ensemble is Random Forest models.

### Boosting

- An ensemble technique in which the predictors are not made independently, but sequentially.
- This technique employs the logic in which the subsequent predictors learn from the mistakes of the previous predictors. Therefore, the observations have an unequal probability of appearing in subsequent models and ones with the highest error appear most.
- This way, the observations are not chosen based on the bootstrap process, but based on the error
- The predictors can be chosen from a range of models like decision trees, regressors, classifiers etc.
- Because new predictors are learning from mistakes committed by previous predictors, it takes less time/iterations to reach close to actual predictions.
- But we have to choose the stopping criteria carefully or it could lead to overfitting on training data.
- Gradient Boosting is an example of boosting algorithm.

## Other concepts

### Bootstrap

A technique of loading a program into a computer by means of a few initial instructions which enable the introduction of the rest of the program from an input device.

## References

- https://medium.com/mlreview/gradient-boosting-from-scratch-1e317ae4587d