# probability

# Probability

In the classic interpretation, a probability is measured by the number of times event x occurs divided by the total number of trials. In other words, **the frequency of the event occurring**.

- It can be written as: `P(A)`
- It can be calculated by:

$$
P(A) = \frac{N_{A}}{N}
$$

## Types of Probabilities

There are three types of probabilities:

- **Joint probability**: The probability of two events occurring simultaneously.
- **Marginal probability**: The probability of an event irrespective of the outcome of another variable.
- **Conditional probability**: The probability of one event occurring in the presence of a second event. É a interseção de duas probabilidades.

## Joint Probability

- Joint probability is the probability of two events happening together. Example: Probability of a positive review having the word “Happy” in it.
- The two events are usually designated event A and event B.
- In probability terminology, it can be written as: `P(A and B) or P(A ∩ B) or P(A, B)`
- The formula is:

$$
P(A\cap B)=P(A,B)=\frac{N_A\cap N_B}{N}
$$


### Joint Probability Distribution

A joint probability distribution shows a probability distribution for **two (or more)** random variables. Instead of events being labeled A and B, the norm is to use X and Y. The formal definition is: `f(x, y) = P(X = x, Y = y)`

- The whole point of the joint distribution is to look for a **relationship** between two variables.
- For example, the following table shows some probabilities for X and Y happening at the same time:

You can use the table to find probabilities. For example: Question: What is the probability for Y = 2 and X = 3? Answer: Look at the table for the intersection of Y = 2 and X = 3. The answer (1/6) is circled:

### Joint Probability Mass Function

If your variables are **discrete** (like in the above table example), their distribution can be described by a **Joint Probability Mass Function** or **Joint PMF**. Basically, if you have found all probabilities for all possible combinations of X and Y, then you have created a joint PMF.

### Joint Probability Density Function

If you have **continuous** variables, they can be described with a **Probability Density Function** or **PDF**.

Unlike the discrete variable example above, you can’t write out every combination of every variable because you would have infinite possibilities to write out (which is, of course, impossible). What you can do is **create a formula**. The formula that describes all possible combinations of X and Y is called a Joint PDF.

## Marginal Probability

Specifically, it quantifies how likely a specific outcome is for a random variable, such as the flip of a coin, the roll of a dice, or drawing a playing card from a deck.

## Conditional Probability

- A conditional probability is the probability of an event X occurring when a secondary event Y is true.
- Mathematically, it is represented as `P(A | B)`.

$$
P(A|B)=\frac{N_A}{N_B}
$$

or $ P(A|B)= $ also, from Bayes Rule: $ P(B|A) = P(A|B)  $

- This is read as “probability of X given Y has happened” or “looking at the elements of set A, the chance that one also belongs to set B”

# References

https://www.statisticshowto.com/joint-probability-distribution/ https://tinyheero.github.io/2016/03/20/basic-prob.html#joint-probabilities https://machinelearningmastery.com/joint-marginal-and-conditional-probability-for-machine-learning/