# Word Embeddings

Vetores de palavras densos, distribuidos e com tamanho fixo, construidos utilizando 
estatistica de co-ocorrencia de palavras dada pela hipótese distribucional.

Com o tempo, percebeu-se que esses chamados Word Embeddings poderiam ser 
utilizados como features em tarefas de NLP. 
Word2Vec. Percebeu-se também o fato de que eles codificam a sintática e a 
semantica dos relacionamentos de palavras de maneira extremamente acurada. 
Mais recentemente, outras maneiras de geração desses embeddings tem emergido, 
as quais não utilizam redes neurais e camadas de embeddings mas sim matrizes de 
palavra-contexto que geral representações vetoriais de palavras. Dentre os modelos 
mais influenciais, temos o GloVe.

Utilizam-se da seguinte presunção, que vem da Hipótese Distribucional sugerida em 
1954: **Palavras com contextos similares possuem significados similares.**

Tipos de modelos de embeddings:

- Prediction-based: derivados de redes neurais. Utilizados em modelos de 
linguagem (que prevem a proxima palavra dado o seu contexto)
- Count-based: derivados de contagem global de contexto de palavras de 
co-ocorrencia.

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


