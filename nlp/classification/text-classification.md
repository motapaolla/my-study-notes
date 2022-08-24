# Text classification 

It is a machine learning technique that assigns a set of predefined categories to 
open-ended text. Text classifiers can be used to organize, structure, and categorize 
pretty much any kind of text – from documents, medical studies and files, and all 
over the web. 

Examples: 
- new articles can be organized by topics; 
- support tickets can be organized by urgency; 
- chat conversations can be organized by language; 
- brand mentions can be organized by sentiment

Uses:
- **sentiment analysis**; 
- **topic labeling**; 
- **spam detection**; 
- **intent detection**;
- **Grammatical Correctness**;
- 

There are many approaches to automatic text classification, but they all fall under 
three types of systems:
- Rule-based systems
- Machine learning-based systems
- Hybrid systems

## Rule-based systems

This approach classify text into organized groups by using a set of **handcrafted** 
**linguistic rules**. These rules instruct the system to use semantically relevant 
elements of a text to identify relevant categories based on its content. 

Each rule consists of **an antecedent** or **pattern** and **a predicted category**.
It is similar to using a regex.

Rule-based systems are human comprehensible and can be improved over time. But this 
approach has some disadvantages. For starters, these systems require deep knowledge 
of the domain. They are also time-consuming, since generating rules for a complex 
system can be quite challenging and usually requires a lot of analysis and testing. 
Rule-based systems are also difficult to maintain and don’t scale well given that 
adding new rules can affect the results of the pre-existing rules.

## Machine learning-based systems

It uses a machine learning model. Instead of relying on manually crafted rules, 
machine learning text classification learns to make classifications based on past 
observations. 

By using pre-labeled examples as training data, the algorithms can learn 
the different associations between pieces of text, and that a particular output 
(i.e., tags) is expected for a particular input (i.e., text). A “tag” is the 
pre-determined classification or category that any given text could fall into.

The pipeline of text classification follows the pipelin: 
1. document preprocessing,
2. feature selection, 
3. feature extraction and 
4. text classification.

Text classification with machine learning is usually much more accurate than 
human-crafted rule systems, especially on complex NLP classification tasks. Also, 
classifiers with machine learning are easier to maintain and you can always tag 
new examples to learn new tasks.

Popular algorithms:
- the Naive Bayes family of algorithms; 
- support vector machines (SVM);
- deep learning.


# References

https://monkeylearn.com/text-classification/
