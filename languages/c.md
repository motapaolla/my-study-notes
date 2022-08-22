# C

## General Sintax
- each statement ends with a semicolon (;),
- and all blocks of code are surrounded by curly braces ({}) (exception to this rule is that if a block has only a single statement, then the curly braces can be omitted)
- All variables in C must be declared, meaning there needs to be a single statement indicating the type of that variable
- unlike Python, the data type that a single variable can hold can’t change.


## if Statements:
- if works generally like it does in Python
- if statements don’t need an endif because blocks are delimited by {}.
Usage:
```
if (x == 0) 
	command;

if (x == 0) { 
	command;
}
else if (x != 1){
	command;
}
else {
	command;
}
```


## for Loops
- The syntax for functions in C is similar to that in Python, with the addition that the **return type** and **parameter types** must be **specified**. 

```
for ( <initialization>; <condition>; <increment>) {
    <code to be looped over>
}

for (i = 0; i < 8; ++i) {
    S[i] = sha_info->digest[i];
}

```


## Functions
```
<return_type> function_name(<parameters>) {
    <function_body>
}
```

- there are several modifiers that you can place on functions and variables
	- static: the static modifier here means something very different than if you placed it in front of a variable declaration.	
	- generally ignore these modifiers while trying to read and understand the CPython source code.

- the parameters that are passed to C functions are all passed by value, which is,
the function operates on a **copy of the value** and **not** on **the original value** in the calling function. To work around this, functions will frequently pass in the **address** of some data that the function can modify (pointers). 


## Pointers
- Are variables that hold the **address** of a value

```
int function_name(int *param1, float param2) {
    <function_body>
}
```
- Here the `param1` parameter will hold the **address** of, or a **pointer to**, an **int** value.
- There’s a special value in C called NULL that indicates a pointer doesn’t point to anything. This is important since there are very few limitations as to what values a pointer can have, and accessing a memory location that isn’t part of your program can cause very strange behavior.
-  if you try to access the memory at NULL, then your program will exit immediately. 


## Strings
- C doesn’t have a string type!
- strings in C are stored as **arrays of char** (for ASCII) or **wchar** (for Unicode) values, each of which holds a single character
- Strings are marked with a null terminator, which has a value 0 and is usually shown in code as \\0. (Basic string operations like strlen() rely on this null terminator)
- Because strings are just arrays of values, they cannot be directly copied or compared. The standard library has the strcpy() and strcmp() functions (and their wchar cousins) for doing these operations and more.

## Structs (custom data types)
- is how you can create new types in C
- The struct keyword allows you to group a set of different data types together into a new, custom data type:
```
struct <struct_name> {
    <type> <member_name>;
    <type> <member_name>;
    ...
};

struct arraydescr {
    char typecode;
    int itemsize;
    ...
};

```
- This creates a new data type called arraydescr which has many members, the first two of which are a char typecode and an int itemsize.
- Frequently structs will be used as part of a `typedef`, which provides a simple alias for the name. 
- In the example above, all variables of the new type must be declared with the full name struct arraydescr x;. Example:
```
typedef struct {
    PyObject_HEAD
    SEM_HANDLE handle;
    unsigned long last_tid;
    int count;
    int maxvalue;
    int kind;
    char *name;
} SemLockObject;
```
- This creates a new, custom struct type and gives it the name SemLockObject. To declare a variable of this type, you can simply use the alias `SemLockObject x`;.



## Arrays

```c
dataType arrayName[arraySize];

// Ways to initialize an array
float mark[5];
int mark[5] = {19, 10, 8, 17, 9};
int mark[] = {19, 10, 8, 17, 9};  // Here, we haven't specified the size. However, the compiler knows its size is 5 as we are initializing it with 5 elements.

// Change element
mark[4] = 0;

// take input and store it in the 3rd element
scanf("%d", &mark[2]);

// take input and store it in the ith element
scanf("%d", &mark[i-1]);

// print the first element of the array
printf("%d", mark[0]);
```
- the size and type of an array cannot be changed once it is declared.
- ACCESSING: You can **access elements** of an array by indices. The first element is mark[0], the second element is mark[1] and so on.
- ADDRESS OF AN ARRAY VALUE: Suppose the starting address of mark[0] is 2120d. Then, the address of the mark[1] will be 2124d. Similarly, the address of mark[2] will be 2128d and so on. This is because the size of a float is 4 bytes.

### Multidimensional
```c
float x[3][4];
float y[2][4][3];

// Different ways to initialize two-dimensional array

int c[2][3] = {{1, 3, 0}, {-1, 5, 9}};
         
int c[][3] = {{1, 3, 0}, {-1, 5, 9}};
                
int c[2][3] = {1, 3, 0, -1, 5, 9};

```


## Malloc
- abreviatura de memory allocation
- **aloca espaço** para um **bloco de bytes consecutivos na memória RAM** e **devolve** o **endereço** desse bloco
- O número de bytes é especificado no argumento da função.  No seguinte fragmento de código, malloc aloca 1 byte:
```c
char *ptr;
ptr = malloc (1);
scanf ("%c", ptr);
```
