# cross-val

# Description

- It is a resampling procedure used to **evaluate (and only evaluate) machine learning models**
and access how the model will perform for an independent test dataset.
- Once the model is evaluated, in order to get the best model, train with full data.
- With the change in the random state of the split, the accuracy of the model also changes, so we are not able to achieve a fixed accuracy for the model.
- Data needs to split into:
    - **Training data**: Used for model development
    - **Validation data**: Used for validating the performance of the same model
    - **Test data**: Used to test the final model performance

# CV Types

Exhaustive cross-validation methods are cross-validation methods that learn and test 
in all possible ways. 
- **Pros**: 
  - Simple, easy to understand, and implement. 
- **Cons**: 
  - The model may lead to a low bias. 
  - The computation time required is high.

# CV Techniques

## Leave p-out cross-validation (Exhaustive)

P is the size of the test sets and it must be strictly less than the number of samples. This technique involves using p-observation as validation data, and remaining data is used to train the model.

A variant of LpOCV with p=2 known as leave-pair-out cross-validation has been recommended as a nearly unbiased method for estimating the area under ROC curve of a binary classifier.

## Leave-one-out cross-validation (Exhaustive)

Leave-one-out cross-validation (LOOCV) is an exhaustive cross-validation technique. It is a category of LpOCV with the case of p=1. For a dataset having n rows, 1st row is selected for validation, and the rest (n-1) rows are used to train the model. For the next iteration, the 2nd row is selected for validation and rest to train the model. Similarly, the process is repeated until n steps or the desired number of operations.

## Holdout cross-validation (Exhaustive)

This technique *randomly* splits the dataset into train and test data depending on data analysis. Generally, the split of training data is more than test data. The more data is used to train the model, the better the model is. For the holdout cross-validation method, a good amount of data is isolated from training. However, it is not suitable for an imbalanced dataset and a lot of data is isolated from training the model.

## k-fold cross-validation

In k-fold cross-validation, the original dataset is equally partitioned into k subparts or folds. Out of the k-folds or groups, for each iteration, one group is selected as validation data, and the remaining (k-1) groups are selected as training data.

## Stratified k-fold cross-validation


# References

https://towardsdatascience.com/understanding-8-types-of-cross-validation-80c935a4976d