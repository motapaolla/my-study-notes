## Feature extraction

Feature extraction can be defined as a process of extracting a set of new features 
from the features set that is generated in feature selection stage. 

Feature extraction methods include principal component analysis (PCA), latent 
semantic indexing (LSI), clustering methods, etc.

### One-Hot Encoding (Count Vectorizing)

- Dado um conjunto de frases, listamos todas as palavras que existem em todas essas 
frases. Ou seja, pegamos o vocabulário de um corpus, e as colocamos em um vetor.
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

### Word Embeddings

Para mais informações checar [aqui](word-embeddings.md).
