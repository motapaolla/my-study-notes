# Fairness Metrics

### Average Odds Difference

$$
\frac{(Fallout_{unpriv} - Fallout_{priv})+(Recall_{unpriv} - Recall_{priv})}{2}
$$

### Equal Opportunity Difference

*Precisionunpriv* − *Precisionpriv*

### Disparate Impact

$$
\frac{P_{unpriv}(1)}{P_{priv}(1)}
$$

### Statistical Parity Difference

*Punpriv*(1) − *Ppriv*(1)

## Fairness definition

### PARIDADE ESTATÍSTICA

*Punpriv*(1) = *Ppriv*(1)

### IGUALDADE DE OPORTUNIDADE

*Falloutunpriv* = *Falloutpriv*

*Recallunpriv* = *Recallpriv*

### PARIDADE PREDITIVA

*Precisionunpriv* = *Precisionpriv*

### 

*score* = *mean*(*std*(*hue*) + *mean*(*saturation*) + *std*(*saturation*) + *mean*(*value*) + *std*(*value*))