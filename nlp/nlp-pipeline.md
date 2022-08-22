# NLP - Text Classification

The process of text classification includes four steps: 
1. document preprocessing,
2. feature selection, 
3. feature extraction and 
4. text classification.

---
## Document preprocessing

Document preprocessing is the process of preprocessing the corpus in order to remove any noise that does not add any key or important information regarding the corpora.

Many natural language processing tasks involve syntactic and semantic analysis, used to break down human language into machine-readable chunks.
1. **Syntactic analysis**, also known as parsing or syntax analysis, identifies the syntactic structure of a text and the dependency relationships between words, represented on a diagram called a parse tree.
2. **Semantic analysis** focuses on identifying the meaning of language. However, since language is polysemic and ambiguous, semantics is considered one of the most challenging areas in NLP. 
Semantic tasks analyze the structure of sentences, word interactions, and related concepts, in an attempt to discover the meaning of words, as well as understand the topic of a text.


### Stop Words Removal

It is used for **syntax** understanding. Includes getting rid of common language articles, pronouns and prepositions such as “and”, “the” or “to” in English.

The thing is stop words removal can wipe out relevant information and modify the context in a given sentence. For example, if we are performing a sentiment analysis we might throw our algorithm off track if we remove a stop word like “not”. Under these conditions, you might select a minimal stop word list and add additional terms depending on your specific objective.

### Tokenization

Is the process of segmenting a text into sentences and words. It is used for **syntax** understanding.

In essence, it’s the task of **cutting a text into pieces** called *tokens*, and at the same time throwing away certain characters, such as punctuation. 

The tokenization process can be particularly problematic when dealing with text domains which contain lots of hyphens, parentheses, and other punctuation marks. Since some languages are different from each other, spitting on blank spaces may separate two words that would mean one thing, e.g. New York. Also, for the same reason, removing punctuation would remove the period from “e.g.”, a sentence that has one meaning.

### Stemming

It is used for **syntax** understanding. Refers to the process of slicing the end or the beginning of words with the intention of removing affixes (lexical additions to the root of the word, e.g. prefix or suffix).

The problem is that affixes can create or expand new forms of the same word (called **inflectional** affixes), or even create new words themselves (called **derivational** affixes).

In English, prefixes are always derivational (the affix creates a new word as in the example of the prefix “eco” in the word “ecosystem”), but suffixes can be derivational (the affix creates a new word as in the example of the suffix “ist” in the word “guitarist”) or inflectional (the affix creates a new form of word as in the example of the suffix “er” in the word “faster”).

It has serious limitations and different use cases. It can be used to correct spelling errors from the tokens. **Stemmers are simple to use and run very fast** (they perform simple operations on a string), and if speed and performance are important in the NLP model, then stemming is certainly the way to go. Remember, we use it with the objective of improving our performance, not as a grammar exercise.

### Lemmatization

It is used for **syntax** understanding. Has the objective of reducing a word to its base form and grouping together different forms of the same word. For example, verbs in past tense are changed into present (e.g. “went” is changed to “go”) and synonyms are unified (e.g. “best” is changed to “good”).

Although it seems closely related to the Stemming process, Lemmatization uses a different approach to reach the root forms of words.

Lemmatization resolves words to their dictionary form (known as *lemma*) for which it requires detailed dictionaries in which the algorithm can look into and link words to their corresponding lemmas.

Lemmatization also takes into consideration the context of the word in order to **solve other problems like disambiguation**, which means it can discriminate between identical words that have different meanings depending on the specific context.

By providing a part-of-speech parameter to a word (whether it is a noun, a verb, and so on) it’s possible to define a role for that word in the sentence and remove disambiguation.

Since it requires more knowledge about the language structure than a stemming approach, it **demands more computational power** than setting up or adapting a stemming algorithm.

### Morphological segmentation.

It is used for **syntax** understanding. This divides words into smaller parts called morphemes. Example: The word untestably would be broken into [[un[[test]able]]ly], where the algorithm recognizes "un," "test," "able" and "ly" as morphemes. This is especially useful in machine translation and speech recognition. 

### Parsing

It is used for **syntax** understanding. This is the grammatical analysis of a sentence. Example: A natural language processing algorithm is fed the sentence, "The dog barked." Parsing involves breaking this sentence into parts of speech -- i.e., dog = noun, barked = verb. This is useful for more complex downstream processing tasks.

### Normalization


### Part of speech tagging


### Named entity recognition

Used for when wanting to get **semantics** of a text.

This determines words that can be categorized into groups. Example: An algorithm using this method could analyze a news article and identify all mentions of a certain company or product. Using the semantics of the text, it would be able to differentiate between entities that are visually the same. For instance, in the sentence, "Daniel McDonald's son went to McDonald's and ordered a Happy Meal," the algorithm could recognize the two instances of "McDonald's" as two separate entities -- one a restaurant and one a person.

### Word sense disambiguation

Used for when wanting to get **semantics** of a text.

This derives the meaning of a word based on context. Example: Consider the sentence, "The pig is in the pen." The word pen has different meanings. An algorithm using this method can understand that the use of the word pen here refers to a fenced-in area, not a writing implement.

Depending on their context, words can have different meanings. Take the word “book”, for example:

    You should read this book; it’s a great novel!
    You should book the flights as soon as possible.
    You should close the books by the end of the year.
    You should do everything by the book to avoid potential complications.

There are two main techniques that can be used for word sense disambiguation (WSD): knowledge-based (or dictionary approach) or supervised approach. The first one tries to infer meaning by observing the dictionary definitions of ambiguous terms within a text, while the latter is based on natural language processing algorithms that learn from training data.

---

## Feature selection

Feature selection can be defined as a process of selecting the subset from the original feature set on the basis of importance of features.

There are three categories of feature selection methods: filters, wrappers and embedded methods, ordered by order of speed. In which:

1. **Filters** technique uses various scoring functionalities
and select top-N features having the highest scores. They are
computationally faster than wrapper method. The limitation is
that the feature dependencies are not taken into consideration.

2. **Wrappers** technique uses a learning model to evaluate the
features, consider feature dependencies, it provide interaction
between feature subset search and choice of the learning
model. The limitation is that they are computationally slower
than the filters.  

3. **Embedded** methods are same like the wrappers. However, they are 
computationally slower than the wrappers. 



---

## Feature extraction

Feature extraction can be defined as a process of extracting a set of new features from the features set that is generated in feature selection stage. 

Feature extraction methods include principal component analysis (PCA) [5], latent semantic indexing (LSI) [11], clustering methods, etc.

### One-Hot Encoding (Count Vectorizing)

- Dado um conjunto de frases, listamos todas as palavras que existem em todas essas frases. Ou seja, pegamos o vocabulário de um corpus, e as colocamos em um vetor.
- Cada palavra desse vetor vai ser uma coluna no dataset e cada linha vai ser uma frase. Com a última coluna sendo a coluna de label.
- Para cada aparição de uma palavra em uma frase (linha), é atribuido 1 a sua respectiva coluna.
- **Limitações**: O problema com essa representação é que tem muitos zeros. Isso impossibilita o uso dela para um conjunto de frases com um vocabulário muito extenso, por conta de **tanto o tempo de treinamento como o de predição ficarem muito longos**. Também não conseguimos inferir relacionamento semântico entre duas palavras, como por exemplo, dizer que duas palavras tem significados parecidos.

### Vetores de frequencia

- Essa técnica utiliza a representação esparsa (descrita acima) para formar uma representação mais densa do vocabulário.
- O jeito como esses vetores de frequencia são montados, agora, é agrupando esse dataset pela label e somando os valores das colunas.
- Desse modo, teremos um dicionário contendo a quantidade de vezes que cada palavra apareceu no corpus inteiro e para cada sentimento, “Positivo” ou “Negativo”.
- Utilizando esse dicionário, transformamos uma nova frase somando os valores dados às palavras mapeadas no dicionário. O formato final do vetor: $ V=[1, Pos, Neg] $ Onde:
    - *1* é referente a um valor `bias`
    - *Pos* é a contagem dos `valores positivos`
    - *Neg*, a contagem dos `valores negativos`
- Dessa forma construimos um dataset mais denso contendo informações das frases.
- **Limitações**: o problema com essa representação é que não conseguimos inferir relacionamento semântico entre duas palavras, como por exemplo, dizer que duas palavras tem significados parecidos.
- Usado frequentemente para medição de similaridade entre documentos em análises textuais.

### TF-IDF

- Parecidos com os vetores one-hot encode, em que cada coluna é uma palavra e cada linha é uma frase. Só que, aqui, em vez de a coluna receber um valor relacionado a presença da palavra na frase (linha), ela receberá um valor relacionado a esse cálculo: Frequencia do termo na frase dividido pela frequencia do termo no documento inteiro.
- Sua fórmula é dada por *R* = *Term* − *Frequency*(*TF*)/*InverseDocumentFrequency*(*IDF*)
- Desse modo, palavras que ocorrem muito no corpus são dados pesos muito baixos (denominador aumenta muito). Por exemplo, stopword como “the” ou “and”, que não dão muito valor ao significado da frase.
- **Limitações**: Sofre ainda a mesma limitação de que ter representações com muitas dimensões que não capturam relacionamentos.
- Usado frequentemente para medição de similaridade entre documentos em análises textuais e em information retrieval.

### Matriz de co-ocorrencia

- É uma matriz gigante que possui o tamanho do vocabulário do corpus: No. Linhas = No. colunas = N. palavras do corpus
- A quantidade de vezes em que uma palavra ocorre junto com outra é marcada na matriz. Caso contrário, possuem 0.
- Desse modo podemos pegar relações entre palavras.
- **Limitações**: Representação gigante. Muito maior que a One Hot Encoding.

![/Users/paolla.magalhaes/Workspace/mynotes/img/2022-01-29-18-58-06-image.png](/Users/paolla.magalhaes/Workspace/mynotes/img/2022-01-29-18-58-06-image.png)


### Word Embeddings

- Com o tempo, percebeu-se que esses chamados Word Embeddings poderiam ser utilizados como features em tarefas de NLP. Word2Vec. Percebeu-se também o fato de que eles codificam a sintática e a semantica dos relacionamentos de palavras de maneira extremamente acurada.
- Mais recentemente, outras maneiras de geração desses embeddings tem emergido, as quais não utilizam redes neurais e camadas de embeddings mas sim matrizes de palavra-contexto que geral representações vetoriais de palavras. Dentre os modelos mais influenciais, temos o GloVe.

Utilizam-se da seguinte presunção, que vem da Hipótese Distribucional sugerida em 1954:

- Palavras com contextos similares possuem significados similares.

O significado, então, de Word Embeddings, pode ser:

- Vetores de palavras densos, distribuidos e com tamanho fixo, construidos utilizando estatistica de co-ocorrencia de palavras dada pela hipótese distribucional.

Tipos de modelos de embeddings:

- Prediction-based: derivados de redes neurais. Utilizados em modelos de linguagem (que prevem a proxima palavra dado o seu contexto)
- Count-based: derivados de contagem global de contexto de palavras de co-ocorrencia.

#### Word2vec

- Não foi utilizado o vetor one-hot-encoded, mas sim um mapa de vetores multidimensional (uma forma algébrica de representar o texto através de coordenadas), onde cada vetor irá representar uma palavra/sentença
- Agora, a grande sacada foi a seguinte: ao invés de passar apenas informações ao modelo da frequência de cada palavra no texto, foi fornecido muito mais informações que o modelo poderá explorar para aumentar seu “aprendizado” sobre o conjunto de texto.
- Assim, de posse destes vetores multidimensionais, podemos verificar a distância entre cada vetor, desse modo, verificando sua similaridade de acordo com a Hipótese Distribucional.

##### Arquitetura do Word2Vec

- Utiliza dois modelos de rede neurais em sua arquitetura, os quais possuem uma camada de entrada, uma camada oculta e uma camada de saída:
    - **CBOW (Continuous Bag of Words):** utilizado para descobrir a palavra central de uma sentença, baseado nas palavras que a cercam.
    - **Skip-Gram**: aqui, ao invés de tentarmos descobrir a palavra central, faremos o processo inverso; da palavra central, tentaremos descobrir as palavras de contexto.
        
        **Exemplo CBOW**
        
- Para esse exemplo, utilizaremos a frase “O cachorro correu atrás do gato”
- Para representação, utilizaremos a seguinte notação: `([palavras de contexto], palavra alvo)`
- Para este exemplo, utilizaremos uma janela de contexto de tamanho 2, o que significa que “olharemos” apenas para uma palavra anterior e outra após a palavra alvo.
- Então vejamos como a frase pode ser representada:
    
    ```
      1. ([O, correu], cachorro)
      2. ([cachorro, atrás], correu)
      3. ([correu, do], atrás)
      4. ([atrás, gato], do)
    ```
    
- Com estes dados, pretendemos “ensinar” ao modelo a predizer uma palavra alvo, baseada em palavras de contexto.
- Portanto, a arquitetura do modelo de rede neural do CBOW, terá:
    - Uma camada de entrada recebendo os dados pré-processados (vide exemplo acima)
    - E na camada de saída, terá uma palavra que representa a maior probabilidade para a palavra alvo.
        
        **Exemplo Skip-gram**
        
- Utilizaremos a mesma frase “O cachorro correu atrás do gato”
- Para representação, utilizaremos a seguinte notação: `(palavra central, [palavras de contexto])`
- Utilizaremos uma janela de contexto de tamanho 2
- Então vejamos como a frase pode ser representada:
    
    ```
      1. (cachorro, [O, correu])
      2. (correu, [cachorro, atrás])
      3. (atrás, [correu, do])
      4. (do, [atrás, gato])
    ```
    
- A arquitetura do modelo Skip-Gram, terá:
    - Na camada de entrada, apenas a palavra alvo
    - Na camada de saída, diferentes probabilidades, cada uma contendo palavras de contexto possíveis.
    - Uma camada escondida, cuja dimensão é igual ao tamanho do embedding, o qual é menor que o tamanho dos vetores de entrada e de saida.
    - Tanto os dados de entrada como os de saida possuem a mesma dimensão, one-hot encoded.
    - No final da camada de saída, uma função de ativação softmax é aplicada de modo que cada elemento do vetor de saída descreve o quão provável uma palavra irá aparecer no contexto.
- O embedding das palavras target, então, pode ser obtido ao extrairmos as camadas escondidas após alimentarmos a rede com a representação vetorial.

##### Limitações

- Although Word2Vec successfully handles the issue posed by one-hot vector, it has several limitation. The biggest challenge is that it is not able to represent words that do not appear in the training dataset. Even though using a larger training set that contains more vocabulary, some rare words used very seldom can never be mapped to vectors.

#### FastText

- É uma extensão do Wor2Vec
- Proposto pelo Facebook em 2016
- Soluciona o problema existente no Word2Vec de que o mesmo não funciona bem para palavras que não existem no dataset de treinamento.
- Aqui, em vez de alimentarmos apenas palavras na Rede Neural, essas palavras são quebradas em várias sub-palavras, chamadas de n-grams (tipicamente de tamanho 3-6). Por exemplo, os tri-grams da palavra *apple* são *app*, *ppl* e *ple* (ignorando as fronteiras de inicio e fim das palavras). O embedding para *apple* será então a SOMA desses n-grams. Ao fim do treinamento da Rede Neural, teremos todos os word embeddings de todos os n-grams do dataset de treino.
- Isso garante que palavras raras podem agora ser representadas dado que é altamente provável que alguns de seus n-grams também apareçam em outras palavras.

##### Limitações

- Toma mais tempo para treinar o FastText por conta de o número de n-grams ser maior que o número de palavras.

#### GloVe

- Uma extensão do word2vec (e melhor do que ele)
- A pegada do GloVe é que ele adicionou estatísticas globais à tarefa de modelagem para geração do embedding
- Aqui não temos uma janela de contexto (quantas palavras antes e depois iremos olhar em relação à palavra), mas temos uma matriz de contexto-de-palavras/co-ocorrencia-de-palavras que aprende estatísticas ao longo do corpus

![/Users/paolla.magalhaes/Workspace/mynotes/img/2022-01-29-19-19-45-image.png](/Users/paolla.magalhaes/Workspace/mynotes/img/2022-01-29-19-19-45-image.png)



<!-- 
### Neural Network Language Models

Esses dois campos independentes foram unidos em **Neural Network Language Models** (NNLMs), dendo desenvolvidos primeiro modelos de linguagem em larga escala, baseado em redes neurais.

**Feature chave**: O modo como vetores de palavras crus são primeiros projetados em uma camada embedding antes de serem utilizadas para alimentar outras camadas da rede.

*Isso foi feito para amenizar o efeito da alta de dimensionalidade em modelos de linguagem e ajudar sua generalização.*
 -->
---

## Text classification
For text classification various classifiers sucb as decision
Tree (DT), K Nearest Neigbbor (KNN), Support Vector
Machine (SVM), Naive Bayes (NB), etc. can be used.


---

# References

https://medium.com/@everton.tomalok/word2vec-e-sua-import%C3%A2ncia-na-etapa-de-pr%C3%A9-processamento-d0813acfc8ab

https://towardsdatascience.com/introduction-to-word-embeddings-4cf857b12edc

https://ieeexplore.ieee.org/abstract/document/7566545

https://www.techtarget.com/searchenterpriseai/definition/natural-language-processing-NLP

https://monkeylearn.com/natural-language-processing/


