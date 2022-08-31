# exceptions

### Best practices User defined Exceptions

- Exceptions should typically be derived from the Exception class, either directly or indirectly
- Should be usually kept simple, often only offering a number of attributes that allow information about the error to be extracted by handlers for the exception.
- When creating a module that can raise several distinct errors, a common practice is to create a base class for exceptions defined by that module, and subclass that to create specific exception classes for different error conditions.
- Most exceptions are defined with names that end in “Error”, similar to the naming of the standard exceptions

**Example:**

```
class Error(Exception):
    """Base class for exceptions in this module."""
    pass

class InputError(Error):
    """Exception raised for errors in the input.

    Attributes:
        expression -- input expression in which the error occurred
        message -- explanation of the error
    """

    def __init__(self, expression, message):
        self.expression = expression
        self.message = message

class TransitionError(Error):
    """Raised when an operation attempts a state transition that's not
    allowed.

    Attributes:
        previous -- state at beginning of transition
        next -- attempted new state
        message -- explanation of why the specific transition is not allowed
    """

    def __init__(self, previous, next, message):
        self.previous = previous
        self.next = next
        self.message = message
```

### Try and Except

- try
- except
- finally: Executa como última task antes do try completar. Roda mesmo o try produzingo ou não uma exceção.