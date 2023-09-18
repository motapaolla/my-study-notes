# Bootstrapping

Bootstrapping is a cool method to estimate confidence intervals because it **does not rely on any assumption of data distribution**, since it calculates a proxy of this distribution from samples. And it is quite easy to implement by yourself!

## Bootstrap definition and principle

The bootstrap is a method 
- **for estimating standard errors** 
- **computing confidence intervals**.
  
There are many different types and methods of bootstrapping developed, but despite of many variations, all  bootstrap steps look as follows:

1. Obtain data sample x1,x2,…,xn drawn from a distribution F.
2. Define u – statistic computed from the sample (mean, median, etc).
3. Sample with replacement from the original data sample to get the empirical distribution
4. Repeat n times (n is the amount of bootstrap iterations).
5. Compute the statistic calculated from each resample.

Then the bootstrap principle says that:

1. The empirical distribution from bootstraps is approximately equal to distribution of sample data.
2. The variation of statistic computed from the sample is similar to the variation of statistic computed from each resample. So, the computed statistic from bootstrapping is a good proxy for statistic of the sample data.

Can be applied for different goals:

- Estimating Confidence intervals
- Hypothesis testing
- Bias elimination

## Methods for Bootstrapping Confidence Intervals

- `Empirical Bootstrapping`: Approximates the difference between bootstrapped means and sample mean
- `Percentile bootstrap`: Uses the distribu­tion of the bootstrap sample statistic as a direct approximation of the data sample statistic.
- `Normal bootstrap`: Calculates confidence intervals for the bootstrapped means.
- `Normal interval bootstrap`: Normal interval bootstrap repeats all steps of normal bootstrap, but use a new formula for CI.
- `Parametric Bootstrap`: It is very close to empirical approach, the only difference is in the source of the bootstrap sample. For the parametric bootstrap, we generate the bootstrap sample from a parametrized distribu­tion. It is often used for the efficient computation of Bayes posterior distributions, not for experimentation analysis.


# References
https://elizavetalebedeva.com/bootstrapping-confidence-intervals-the-basics/
