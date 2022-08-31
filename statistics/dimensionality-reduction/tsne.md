# tsne

## Overview

- Well suited for the visualization of -high-dimensional datasets-
- It is a -probablistic** technique, not a **mathematical** one
- Is computationally quite **heavy**, so, in case of very high dimensional data, 
you may need to apply another dimensionality reduction technique before using t-SNE 
(PCA for dense data or TruncatedSVD for sparse data)
- **It doesn’t always produce similar output on successive runs**

## Running it:

- Iterate until reaching a stable configuration
- The solution with the lowest KL divergence is ideal **however** sometimes it may not be the best one. But you can still use it to pick the optimal run for a given solution though

## Parameters Tunning Intuition:

- `perplexity`: a guess about the number of close neighbors each point has
    - Basically, the higher the perplexity is the higher value variance has.
    - Larger datasets usually require a larger perplexity
    - Consider selecting a value between 5 and 50
    - Getting the most from t-SNE may mean analyzing multiple plots with different perplexities
- `learning_rate`:
    - Usually in the range [10.0, 1000.0]
    - If the learning rate is too high, the data may look like a ‘ball’ with any point approximately equidistant from its nearest neighbours.
    - If the learning rate is too low, most points may look compressed in a dense cloud with few outliers.

---
# References

https://distill.pub/2016/misread-tsne/