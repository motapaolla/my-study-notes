# Dataset and Model Drift/Shift
_[drift and shift are the same in this context]_

Data drift is one of the top reasons model accuracy degrades over time. For machine learning models, data drift is the **change in model input data** that leads to model performance degradation. 

Causes of data drift include:
- Upstream process changes, such as a sensor being replaced that changes the units of measurement from inches to centimeters.
- Data quality issues, such as a broken sensor always reading 0.
- Natural drift in the data, such as mean temperature changing with the seasons.
- Change in relation between features, or covariate shift.

The effort it takes to handle the drift may vary depending on the nature, extent, and type of the drift, in few cases, data drift is manageable by retraining the model on the new data but sometimes we may have to go back to the drawing board and start from scratch.


## Types of data drifts

There are 3 types of drift:
1. Feature drift
2. Prediction drift
3. Concept drift

But they all originate from the point the drift is detected either from the data or if the predictions are incorrect.

### Covariate or Feature drift 

Covariate drift or feature drift happens when p(X) changes but p(y|x) remains the same. In other words, covariate shift is the **change of distributions in one or more of the independent variables (input features).** 

An example could be if a model you put into production starts to see a new age demographic as its user base grows. You might have trained on younger users, but over time you might have a lot of older users as well. And so you will see an increase in mean and variance, and therefore a data drift.

Performance degradation will be more apparent when this sort of shift happens in one or more of the top contributing variables of a model. 

You should verify that the input features are stable (i.e check for this sort of shift within and between the train and test sets) during model development as well, and then continue to do so with model monitoring after deployment.

Methods for identifying this type of shift are: model-based

### Prediction drift or Prior Probability Drift

Label drift happens when p(y) changes but p(x|y) remains the same. With prior probability shift, the **distribution of the input variables remains the same but the distribution of the target variable changes**. 

An example could be some companies that were not really affected by the lockdown and have not suffered any revenue losses but they deliberately chose not to repay their loan installments to take advantage of government subsidies and maybe save that money in case the situation does worsen for them in the future (same X distribution but different Y).

Methods for identifying this type of shift are: ...

### Concept drift

Concept drift happens when p(y|X) changes but p(X) remains the same. With concept drift **the relationships between the input and output variables change**. This means that the distributions of input variables (such as user demographics, frequency of words, etc.) might even remain the same and we must instead focus on the changes in the relationship between X and Y.

Concept drift is more likely to appear in domains that are dependent on time, such as time series forecasting and data with seasonality. Learning a model over a given month won’t generalize to another month. There are few different ways in which concept drift might show up.

**Types of concept drift:**
- Gradual Concept Drift: Gradual or incremental drift is the concept drift that we can observe happening over time and therefore can expect.
- Sudden Concept Drift: As the name suggests, these concept shifts happen by surprise and suddenly.
- Recurring Concept Drift: Recurrent concept drift is pretty much “seasonality”. But seasonality is a common in machine learning with time series data and is something we are aware of. So if we expect this sort of drift, for example a different pattern on weekends or on certain holidays of the year, we just need to make sure that we train the model with data representing this seasonality. This sort of data drift usually becomes a problem in production only if a new pattern develops that the model is unfamiliar with.

Methods for identifying this type of shift are: ...

## Detection methods

Data drifts can be identified using: 
- Sequential analysis methods: Like DDM (drift detection method)/EDDM (early DDM) rely on the error rate to identify the drift detection.
- Model-based methods: Uses a custom model to identify the drift.
- Statistical methods: Use statistical distance calculation methods to calculate drift between probability distributions. Some of the popular statistical methods to calculate the difference between any 2 populations are Population Stability Index, Kullback-Leiber or KL Divergence, Jenson-Shannon or JS Divergence, Kolmogorov-Smirnov Test or KS Test, Wasserstein Metric or Earth Mover Distance.


## Automate

https://towardsdatascience.com/automating-data-drift-thresholding-in-machine-learning-systems-524e6259f59f

# References

https://www.arangodb.com/2020/11/arangoml-part-4-detecting-covariate-shift-in-datasets/

https://towardsdatascience.com/why-data-drift-detection-is-important-and-how-do-you-automate-it-in-5-simple-steps-96d611095d93

https://towardsdatascience.com/data-drift-part-1-types-of-data-drift-16b3eb175006

https://towardsdatascience.com/machine-learning-model-drift-9cc43ad530d6#:~:text=given%20house%20features.-,Types%20of%20model%20drift,concept%20drift%20and%20data%20drift.