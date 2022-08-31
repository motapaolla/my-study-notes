# LGBM

# LGBM

**Main points:**

- Light GBM is a **gradient boosting** framework that uses **tree based learning algorithm**.
- Grows tree vertically while other algorithm grows trees horizontally meaning that 
Light GBM grows tree leaf-wise while other algorithm grows level-wise.
- It will choose the leaf with max delta loss to grow.
- When growing the same leaf, Leaf-wise algorithms can reduce more loss than a 
level-wise algorithm
- Light GBM is prefixed as ‘Light’ because of its high speed.
- Light GBM can handle the large size of data and takes lower memory to run.
- Focuses on accuracy of results.
- Also supports GPU learning

**When not to use:**

- It is not advisable to use LGBM on small datasets.
- Is sensitive to overfitting and can easily overfit small data
- Suggestion is to use it only for data with 10,000+ rows.

### Parameters

- For dealing with categorical features:
    - `ignore_column`: same as categorical_feature just instead of considering specific columns as categorical, it will completely ignore them.
    - `categorical_feature`: It denotes the index of categorical features. If categorical_features=0,1,2 then column 0, column 1 and column 2 are categorical variables.
- For Faster Speed:
    - Use bagging by setting bagging_fraction and bagging_freq
    - Use feature sub-sampling by setting feature_fraction
    - Use small max_bin
    - Use save_binary to speed up data loading in future learning
    - Use parallel learning, refer to parallel learning guide.
- To deal with over-fitting:
    - Use small max_bin
    - Use small num_leaves
    - Use `min_data_in_leaf` and `min_sum_hessian_in_leaf`
    - Use bagging by set `bagging_fraction` and `bagging_freq`
    - Use feature sub-sampling by set f`eature_fraction`
    - Use bigger training data
    - Try lambda_l1, lambda_l2 and min_gain_to_split to regularization
    - Try max_depth to avoid growing deep tree
- For better accuracy:
    - Use large `max_bin` (may be slower)
    - Use small `learning_rate` with large `num_iterations`
    - Use large `num_leaves` (may cause over-fitting)
    - Use bigger training data
    - Try dart
    - Try to use categorical feature directly
- Other:
    - `num_leaves`: This is the main parameter to control the complexity of the tree model. Ideally, this value should be less than or equal to 2^(max_depth). Value more than this will result in overfitting.
    - `min_data_in_leaf`: Setting it to a large value can avoid growing too deep a tree, but may cause under-fitting. In practice, setting it to hundreds or thousands is enough for a large dataset.
    - `save_binary`: If you are really dealing with the memory size of your data file then specify this parameter as ‘True’. Specifying parameter true will save the dataset to binary file, this binary file will speed your data reading time for the next time.

---
# References

- https://medium.com/@pushkarmandot/https-medium-com-pushkarmandot-what-is-lightgbm-how-to-implement-it-how-to-fine-tune-the-parameters-60347819b7fc