# Dialogue generation 

Is the task of "understanding" natural language inputs - within natural language 
processing in order to produce output. 

The systems are usually intended for conversing with humans, for instance back and 
forth dialogue with a conversation agent like a chatbot. 

Some example benchmarks for this task (see others such as Natural Language Understanding) include FusedChat, 
[Ubuntu DIalogue Corpus (UDC)](https://www.aclweb.org/anthology/W15-4640/) and [Seq2seq](https://aclanthology.org/P15-1152.pdf)
(actually, almost all of the existing generative approach use the Seq2Seq model). 

Models can be evaluated via metrics such as BLEU, ROUGE, and METEOR albeit with challenges in terms of weak correlation 
with human judgement, that may be addressed by new ones like UnSupervised and Reference-free (USR) and 
Metric for automatic Unreferenced dialog evaluation (MaUde).

# References

https://github.com/csnlp/Dialogue-Generation