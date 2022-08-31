# rasa

## Anotações

fluxos: data nlu

```
stories:
    é os fluxos
    generate stories graph
    são treinadas -> proposito de generalizar
rules:
    sobrescreve os fluxos
    resposta curta e automatica
    não são treinadas
    usadas para iterações curtas
    pra não quebrar o fluxo
```

config.yml - configura a pipeline, o que vai ser feito - não precisa ser em ordem - configura o modelo de NLP - policies - configura o modelo de stories - determina o proximo passo - treina o modelo de grafo

domain.yml define todo o dominio do bot quais intenceoes treinaveis e entidades treinaveis tem que tá ai todas se for chamada em outro lugar não vai entender bot pode disparar mensagem simples (responses) e uma ação tambem se cinfugura a sessão sessai é o momento do usuario configura o tempo de expiracao da sessao

connectors - conectar com os aplicativos de conversa - segue o ututorial do docs

# Rasa

## Forms

- Slots: It’s like a variable to store information. Each piece of information a form collects is stored in a slot. A slot saves information to the assistant’s memory in a key-value format, like “name”:”Susan” or “birthday”:”June 18”. We can think of slots as the basic unit of a form.
- Entities: are important keywords that are extracted from a user’s message. For example, a name, a city, a vendor name, a product, or a date. They are one way you can fill slots in a form.
- Buttons: In cases where you want to enforce a **limited set of entity values**, you can offer the user buttons to choose
- Intents: An intent is the goal or intention behind a user’s message. It’s another way a slot can be filled is with a value mapped to an intent. We train a model with a list of intents and every time a user sends a message to the assistant, the NLU model decides which intent the message matches out of the list of intents it’s been trained to recognize. When might you want to fill a form slot using an intent? One common example is a yes/no question, for example, “Do you want to receive special offers and promotions?”. If the model predicts intent:affirm, we know the user said yes and we can save the slot value to True; if the model predicts intent:deny, we know they’ve said no and save the slot to False. Then, we can use these boolean values to create conditional logic in custom actions, like saving the user’s information to a mailing list if their answer is yes.

### Slots

Slots are like a variable to store information. Each piece of information a form collects is stored in a slot.

A slot saves information to the bot’s memory in a key-value format, like “name”:“Susan” or “birthday”:“June 18”.

Slots are defined in the `domain.yml` file.

At a minimum, you need to provide:

- The name of the `slot key` (e.g. name, email, etc.)
- The `type of slot`. (For this, read https://rasa.com/docs/rasa/domain/#slots)

Example:

```
slots:
  user_name:
    type: unfeaturized
```

### Types of slot

When choosing your slot types, you’ll need to decide whether your slots should be `featurized` or `unfeaturized`.

- `Featurized` slots can affect the predictions made by the Rasa dialogue management model, meaning the model considers whether or not the slot has been filled when deciding which action to take next. OBS: For some slot types, like text slots, the actual value of the slot doesn’t matter, only whether it’s been filled. For other slot types, like categorical slots, the value does matter. You can see the full list of featurized slot types in the documentation.
- `Unfeaturized` slots don’t affect the flow of the conversation. The best practice is to use unfeaturized slots in your forms, unless you have a reason why the slot should be considered by the dialogue management model.

### Response templates

It’s a way to ask the user for information. The response template defines the *message the assistant sends to the user, when trying to fill a slot*. The information the user will type will be attributed to a slot.

Response templates are defined in the `domain.yml` file, and there’s a special naming convention used when the response template is prompting the user for a slot value:

```

For example, if we want to collect the user’s name and save it to the user_name slot, we’d create a response template like this to ask “What is your name?”:

```

utter_ask_user_name: - text: What is your name? ```

By default, Rasa Open Source fills a slot with an entity that has the same name

### Filling

By default, Rasa Open Source fills a slot with an entity that has the same name. So if you’ve defined a name slot in your domain file, and you also have a name entity defined in your domain and training data, when the NLU model extracts the name entity, it’ll be saved to the name slot automatically.

But what if you want to save a slot value that isn’t an entity? Remember, you can also save slot values based on intent—either a mapped value like True or the full text of the user message. If a slot should be filled by anything other than an entity of the same name, you’ll need to map the slot. Slot mapping creates rules around how a slot should be filled.

Slot mapping is configured by the slot_mappings function, within the FormAction method. In the next section, we’ll discuss how FormAction lets you configure a form’s behavior.

# References

https://blog.rasa.com/how-to-build-your-first-rasa-form/