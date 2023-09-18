# Causality

Neste artigo, iremos passar pelo artigo (REF) cujo objetivo é prover uma revisão estruturada de métodos tanto tradicionais como os mais pontas de linha em causalidade em Aprendizado de Máquina e também discutir problemas em aberto. Nele é entendido como aprender causalidade de uma grande quantidade de dados (big data). 

Tarefas de Machine Learning podem ser preditivas ou descritivas por sua natureza. Preditivas quando tentamos adivinhar um comportamento do futuro utilizando dados do passado (aprendizado supervisionado); ou descritivas quando é utilizado de analises para sumarizar, classificar ou extrair regras afim de responder o que aconteceu no passado (principalmente utilizando aprendizado não supervisionado). Além disso, talvez queira-se entender relações de causalidade. Esse tipo de perguntas podem tomar duas formas: 
1) O quanto certas variáveis irão mudar ao manipularmos o valor de outra variável? (Inferência Causal)
2) Quais variáveis podemos modificar de modo a mudar o valor de outra variável? (Descoberta Causal).  

Aprenderemos:
1. Preliminares para aprender causalidade dos dados para Inferência Causal e Descoberta Causal
2. Dois frameworks formais: Modelos Causais Estruturais e Framework de Resultado Potencial.
3. Métodos para problemas de Inferência Causal:
   1. para dados com confundidores não-observados
   2. para dados sem confundidores não-observados
   3. para big data
4. Métodos para aprender relações causais tradicionais e avançados (que utilizam big data)
5. Pesquisas que conectam aprendizado causal e aprendizado de máquina.

## Dados para Aprendizado Causal

Existem dois tipos de dados intervecionistas e observacionais:
1. Intervecionistas: existe ao menos uma variável cujo valor é setado por intervenção;
2. Observacionais: o valor da variável é determinado por suas causas.

Apesar de existir estes dois tipos de dados, este artigo foca em dados observacionais para poder-se ser utilizar de big data.

Geralmente, para treinar e avaliar métodos de aprendizado causal, incluem-se efeitos causais ou relações causais. Efeitos causais médios podem ser obtidos por experimentos aleatórios.  