# Logging


---
# Material teórico

## Entidades

- [Logger](#logger): Interface
- [Handler](#handler): manda os registros de log criados pelos loggers para a 
destinação apropriada
- **Filters**: Filtra os registros de log a serem mostrados
- [Formatters](#formatters): Formata os registros de log no output final

Uma informação de um evento de log é passado por todos esses em ordem em 
uma instância de LogRecord.

O logging é feito utilizando métodos e instâncias da classe *Logger*. 
Cada instância tem um nome e utiliza uma convenção de nomenclatura. 
Por exemplo um logger chamado ‘scan’ tem filhos chamados `scan.html`, `scan.pdf`, etc.

Uma boa convenção é utilizar um logger a nivel de módulo, com cada módulo 
sendo instanciado a partir de:

    `logger = logging.getLogger(__name__)`

Isso faz com que os nomes de logger rastreie a hierarquia pacote/módulo e é 
intuitivamente óbvio onde os eventos são guardados só usando o nome do *logger*.

*root logger* é a raiz da hierarquia dos *loggers*. Esse é o *logger* usado pelas 
funções `debug()`, `info()`, `warning()`, `error()` e `critical()`, as quais só 
chamam os métodos de mesmo nome do *root logger*. O nome do *root logger* é 
printado como `root` na saída logada.

É possível mostrar logs em diferentes destinatários: arquivos, HTTP GET/POST locations, 
email via SMTP, generic sockets, queues ou qualquer mecanismo de log como o Windows 
NT event log. Quem faz isso é as classes de *handler*. Como padrão o destinatário 
não é setado (vai pro console), mas ele pode ser setado usando a função `basicConfig()`.

# Log levels

- **DEBUG**: Detailed information, typically of interest only when diagnosing problems.
- **INFO**: Confirmation that things are working as expected.
- **WARNING**: An indication that something unexpected happened, or indicative of some problem in the near future (e.g. ‘disk space low’). The software is still working as expected.
- **ERROR**: Due to a more serious problem, the software has not been able to perform some function.
- **CRITICAL**: A serious error, indicating that the program itself may be unable to continue running.

# Logger

Tem 3 funções: 1. Expor métodos que permitem logar mensagens de log em tempo de execução 2. Determinar que mensagens vão ser acionadas baseada em severidade ou objetos de filtro 3. Passam mensagens relevantes a todos os handlers interessados

Os métodos mais utilizados são: de configuração e de mensagem. https://docs.python.org/3/library/logging.html#logging.Logger

### Métodos de Configuração

- `Logger.setLevel()`: especifíca o level mínimo que o logger será ativado
- `Logger.addHandler()` e `Logger.removeHandler()`: adiciona ou remove os objetos de *handler* do logger
- `Logger.addFilter()` e `Logger.removeFilter()`: adiciona ou remove objetos de *filter* do logger

OBS: Você não precisa chamar esses métodos sempre.

### Métodos de Mensagem

- `Logger.debug()`, `Logger.info()`, `Logger.warning()`, `Logger.error()`, e `Logger.critical()`: Todos criam mensagens nos leveis correspondentes. A mensagem é uma string.
- `Logger.exception()`: Cria mensagens parecidas com o método `Logger.error()`. A diferença é que `Logger.exception()` joga um stack trace com ele. Chama esse apenas para tratamentos de exceção.
- `Logger.log():` takes a log level as an explicit argument. This is a little more verbose for logging messages than using the log level convenience methods listed above, but this is how to log at custom log levels.

### Outros métodos

- `getLogger()`: retorna uma referência a uma instancia de logger com o nome especificado se for provido (retorna `root` se não for provido nada).

# Handler

Ver https://docs.python.org/3/howto/logging.html#useful-handlers. Mas se quiser mostrar as mensagens no console mesmo, tem apenas três que é pra se preocupar: - `setLevel()`: especifíca o level mínimo que o logger será ativado igual como nos objetos loggers. The level set in the logger determines which severity of messages it will pass to its handlers. The level set in each handler determines which messages that handler will send on. - `setFormatter()`: selects a Formatter object for this handler to use - `addFilter()` e `removeFilter()`: respectively configure and deconfigure filter objects on handlers

O código não deve diretamente instanciar e usar instancias de *Handler*. Em vez disso, a classe * Handler* é uma classe base que define a interface que todos os handlers devem ter e estabelece um behavior padrão que as classes filhas podem usar ou sobrescrever. É meio que utilizada como configuração.

# Formatters

Configura a ordem final, a estrutura e os conteúdos da mensagem de log. Ao contrário da `logging.Handler`, o código pode instanciar classes *Formatter*, apesar de você poder fazer uma sublasse do formatter se sua aplicação precisar desse comportamento.

O construtor aceita 3 argumentos opcionais: - format string: se nada for passado, utilizamos a mensagem crua de erro. - format data (em string): se nada for passado, utiliza-se o formato %Y-%m-%d %H:%M:%S. - um indicador de estilo: Pode ser: %, ‘{‘ ou ‘$’. Se nada for passado, então `%` é usado.

Exemplo: `logging.Formatter.__init__(fmt=None, datefmt=None, style='%')`

If the style is ‘%’, the message format string uses %(<dictionary key>)s styled string substitution; the possible keys are documented in LogRecord attributes. If the style is ‘{’, the message format string is assumed to be compatible with str.format() (using keyword arguments), while if the style is ‘$’ then the message format string should conform to what is expected by `string.Template.substitute()`.

# Configurando um Log

Programadores podem configurar um logging de 3 maneiras: 1. Criando loggers, handlers, e formatters explicitamente no código 2. Criando um logging config file e o lendo utilizando a função `fileConfig()` 3. Criando um dicionário de informções de configuração e o passando para a função `dictConfig()`

Para referência das duas ultimas opções, verificar https://docs.python.org/3/library/logging.config.html#logging-config-api.

Abaixo está um fluxo normal de logging a nivel de código:

```python
import logging
# create logger
logger = logging.getLogger('simple_example')
logger.setLevel(logging.DEBUG)
# create console handler and set level to debug
ch = logging.StreamHandler()
ch.setLevel(logging.DEBUG)
# create formatter
formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
# add formatter to ch
ch.setFormatter(formatter)
# add ch to logger
logger.addHandler(ch)
# 'application' code
logger.debug('debug message')
logger.info('info message')
logger.warning('warn message')
logger.error('error message')
logger.critical('critical message')
```

Rodando isso, produz:

```
$ python simple_logging_module.py
2005-03-19 15:10:26,618 - simple_example - DEBUG - debug message
2005-03-19 15:10:26,620 - simple_example - INFO - info message
2005-03-19 15:10:26,695 - simple_example - WARNING - warn message
2005-03-19 15:10:26,697 - simple_example - ERROR - error message
2005-03-19 15:10:26,773 - simple_example - CRITICAL - critical message
```

Agora, exemplo do mesmo programa mas pegando de um arquivo:

```python
import logging
import logging.config
logging.config.fileConfig('logging.conf')
# create logger
logger = logging.getLogger('simpleExample')
# 'application' code
logger.debug('debug message')
logger.info('info message')
logger.warning('warn message')
logger.error('error message')
logger.critical('critical message')
```

Arquivo de configuração:

```
[loggers]
keys=root,simpleExample

[handlers]
keys=consoleHandler

[formatters]
keys=simpleFormatter

[logger_root]
level=DEBUG
handlers=consoleHandler

[logger_simpleExample]
level=DEBUG
handlers=consoleHandler
qualname=simpleExample
propagate=0

[handler_consoleHandler]
class=StreamHandler
level=DEBUG
formatter=simpleFormatter
args=(sys.stdout,)

[formatter_simpleFormatter]
format=%(asctime)s - %(name)s - %(levelname)s - %(message)s
datefmt=
```

You can see that the config file approach has a few advantages over the Python 
code approach, mainly separation of configuration and code and the ability of 
noncoders to easily modify the logging properties.

Here’s an example of the same configuration as above, in YAML format for the new 
dictionary-based approach:

```
version: 1
formatters:
  simple:
    format: '%(asctime)s - %(name)s - %(levelname)s - %(message)s'
handlers:
  console:
    class: logging.StreamHandler
    level: DEBUG
    formatter: simple
    stream: ext://sys.stdout
loggers:
  simpleExample:
    level: DEBUG
    handlers: [console]
    propagate: no
root:
  level: DEBUG
  handlers: [console]
```

For more information about logging using a dictionary, see https://docs.python.org/3/library/logging.config.html#logging-config-api.

## Configuring logging dictionary file

`logging.config.dictConfig(config_file)` é como a gente chama o config file. 
O arquivo de dicionário passado nessa função, deve ter as seguintes chaves.

- **version**: 1 (sempre é esse e é o único obrigatório)
- **formatters**: recebe um dicionário no qual cada chave é uma formatter id e cada valor é um dict descrevendo como configurar aquela instancia de formatter
- **filters**: recebe um dicionário no qual cada chave é uma filter id e cada valor é um dict descrevendo a configuração daquela instancia de filter
- **handlers**: recebe um dicionário no qual cada chave é uma handler id e cada valor é um dict descrevendo a configuração daquela instancia de filter
    - **class** (mandatory): O nome da class de handler (exemplo: `logging.StreamHandler` ou `logging.handlers.RotatingFileHandler`)
    - **level** (optional): The level of the handler.
    - **formatter** (optional): The id of the formatter for this handler.
    - **filters** (optional): A list of ids of the filters for this handler.
- **loggers**: recebe um dicionário no qual cada chave é uma logger id e cada valor é um dict descrevendo a configuração daquela instancia de logger
    - **level** (optional). The level of the logger.
    - **propagate** (optional). The propagation setting of the logger.
    - **filters** (optional). A list of ids of the filters for this logger.
    - **handlers** (optional). A list of ids of the handlers for this logger.
- **root**: this will be the configuration for the root logger. Processing of the configuration will be as for any logger, except that the propagate setting will not be applicable.
- **incremental**: whether the configuration is to be interpreted as incremental to the existing configuration. This value defaults to False, which means that the specified configuration replaces the existing configuration with the same semantics as used by the existing fileConfig() API. If the specified value is True, the configuration is processed as described in the section on Incremental Configuration.
- **disable_existing_loggers**: whether any existing non-root loggers are to be disabled. This setting mirrors the parameter of the same name in fileConfig(). If absent, this parameter defaults to True. This value is ignored if incremental is True.

# Referencias

https://docs.python.org/3/howto/logging.html


---
# Cheat sheet
## Instanciar uma configuração

- `logging.basicConfig()` -> Seta o valor default level no arquivo
- `logging.getLogger()` -> pega um logger já feito em um script
- `logging.config.fileConfig()` -> Pega de um arquivo ini
- `logging.config.dictConfig()` -> Pega de um arquivo yaml ou json

## Level

- **DEBUG**: Detailed information, typically of interest only when diagnosing problems.
- **INFO**: Confirmation that things are working as expected.
- **WARNING**: An indication that something unexpected happened, or indicative of some problem in the near future (e.g. ‘disk space low’). The software is still working as expected.
- **ERROR**: Due to a more serious problem, the software has not been able to perform some function.
- **CRITICAL**: A serious error, indicating that the program itself may be unable to continue running.

## Messages

- logger.debug()
- logger.info()
- logger.warning()
- logger.error()
- logger.critical()

## ini file

```
[loggers]
keys=root,log02,log03,log04,log05,log06,log07

[handlers]
keys=hand01,hand02,hand03,hand04,hand05,hand06,hand07,hand08,hand09

[formatters]
keys=form01,form02,form03,form04,form05,form06,form07,form08,form09
```

## Modular components

- loggers: tipos de
- handlers: pra onde vai
- formatters: formatacao

### Loggers

```
[logger_parser]
level=DEBUG
handlers=hand01
propagate=1
qualname=compiler.parser
```

- **level** and **handlers**: entries are interpreted as for the root logger, except that if a non-root logger’s level is specified as NOTSET, the system consults loggers higher up the hierarchy to determine the effective level of the logger.
- **propagate**: when 1 indicates that messages must propagate to handlers higher up the logger hierarchy. If 0, indicates that messages are not propagated to handlers up the hierarchy.
- **qualname**: the name used by the application to get the logger.

### Handlers

```
[handler_hand01]
class=StreamHandler
level=NOTSET
formatter=form01
args=(sys.stdout,)
```

- **class**: the handler’s class (as determined by eval() in the logging package’s namespace). The level is interpreted as for loggers, and NOTSET is taken to mean ‘log everything’.
- **formatter**: the key name of the formatter for this handler. If blank, a default formatter (logging._defaultFormatter) is used. If a name is specified, it must appear in the [formatters](about:blank#formatters) section and have a corresponding section in the configuration file.
- **args**: when `eval()`uated in the context of the logging package’s namespace, is the list of arguments to the constructor for the handler class. Refer to the constructors for the relevant handlers, or to the examples below, to see how typical entries are constructed. If not provided, it defaults to ().
- **kwargs** (optional): when eval()uated in the context of the logging package’s namespace, is the keyword argument dict to the constructor for the handler class. If not provided, it defaults to {}.

### Formatters

```
[formatter_form01]
format=F1 %(asctime)s %(levelname)s %(message)s
datefmt=
class=logging.Formatter
```

- **format**: the overall format string, and the
- **datefmt**: the strftime()-compatible date/time format string. If empty, the package substitutes something which is almost equivalent to specifying the date format string ‘%Y-%m-%d %H:%M:%S’. This format also specifies milliseconds, which are appended to the result of using the above format string, with a comma separator. An example time in this format is 2003-01-23 00:29:50,411.
- **class** (optional): the name of the formatter’s class (as a dotted module and class name.) This option is useful for instantiating a Formatter subclass. Subclasses of Formatter can present exception tracebacks in an expanded or condensed format.