# Var library
hello guys !!

I have tried to implement a single libary which 
can hold any of these three basic data types in cpp .\
I thought it  would give us an easy and handy tool to perform basic operations.\
I got this idea from `Var` keyword in `javascript`.
- int
- double 
- string


I still am a student. So, some of my implementation may not be up to all use cases.\
so do a little research before you use. \
there may be other similar libraries in the internet which might do the same job. 

 feel free to post your suggestions. 


## Header
To use the library.
1. Download the var.h file and place it in the same folder as the main program.

1. Include the following line.
```cpp
#include "var.h"
```
>**NOTE**: namespace is already used in the library. So no need to include it.



## Declaration
It is easy to declare var type.
Just like you declare any other type in C++.
```cpp
   Var a;
```
>**Note**: here 'V' for Var is capitalized and not small 'v'.



## Intialization
Initializing Var type is also similar to other data type in C++.
But it can be initialized with 
- int
- double
- string /char*
- Var
```cpp
    Var a = 10;
    Var b = 34.89;
    Var c = "hello";
    Var d = a ;
```
and your code might look like this
```cpp
#include "var.h"

int main()
{
    Var a = 12;
    Var b = 34.89;
    Var c = "hello";
    Var d = a;
    return 0;
}
```



## Input and Output
Getting input from the command line 
and printing output to the command line is just as simple
- use cin and cout like you usually do to get input and output.
```cpp
    Var a;
    cin>>a;
    cout<<a;
```
>**NOTE** : cin parse through the input and it implicity tries to figure out
 whether to treat it as a string or int or double \
 Eg 
 >1. If user input contains only decimal numbers, then it is treated as **int** implicitly.
 >1. If user input contains only decimal numbers and only one '.', then it wil be treated as **double** implicitly.
 >1. If user input contains any other characters, then it will be treated as **string** implicitly.
 
 
 >**NOTE** : If you want to treat a user input full of decimals to be treated as **string**, then try type convertion(next section).



## Type Convertion

If you want to take a __Var__ typed variable and want to get the content in basic data types like __int__ or __double__ or __string__.\
then use.
1. use `getint()` 
2. use `getdouble()`
3. use `getstring()`

```cpp
#include "var.h"
int main()
{
    //converting string to int
    Var a = "1098";
    int g = a.getint();
    cout<<"a "<< g <<endl;
    //converting string to double
    a = "10.89";
    double h;
    h = a.getdouble();
    cout<< "a "<< h <<endl;
    //converting int to string
    a = 45;
    string j = a.getstring();
    cout<< "a "<< j <<endl;
    return 0;
}
```
**NOTE**
1. direct assigning may throw error \
    eg:
    ```cpp
    Var g;
    g = 45; //works fine (int to var);
    int h;
    h = g; //error var(to int)
    ```
1. Trying to convert __invalid__ __string__ to __int__ / __double__ might throw error\
    eg:
    ```cpp
    Var g;
    g = "hello";
    int h;
    h = g.getint(); //error
    ```


## Type checking
Sometimes, you might want find the implicit type of the element stored in __Var__.
- use `gettype()`
```cpp
#include "var.h"
int main()
{
    //get type returns char
    Var a = 124;
    char g = a.gettype();
    cout<< g <<endl;
}
```
gettype() function return char
|  __datatypes__  |  function returns |
|-----------------|-------------------|
| 1.`int`         | 'i'               |
| 2. `double`     | 'd'               |
| 3. `string`     | 's'               |
| 4. no type (not intialized yet)| 'n' |



## Arithmetic Operations
`Var` can be used to perform basic arithmetic operations.
and you do it by using standard arithmetic operators.

|  __operators__ |  operations |
|-----------------|-------------------|
| `+`       |    addition      |
|  `-`      |    subtraction     |
|  `*`      |    multiplication     |
| `\`       |    division          |

sample code:
```cpp
Var a = 10;
Var b = 23.99;
Var c;
c = a+b;
```
here, result of operations would be of type with greater precedence.
and priority is give to 
string is given higher priority than double and int.
double is given higher priority than int.
>**Note** : here the `+` operator can be used to concatenate strings.\
 but using string with any other operators throws error in Runtime .\
 which can be handled using `try-catch`  statements. 

>**Note** : when using arithmetic operators, first variable should be always of type **Var**\
or else it will throw compile-time error.\

example:
```cpp

Var a = 34.56;
Var b;
b = a+23.45;// runs just fine.
b = 23.45 + a ; //throws error.
```


## String Operations
A lot of string library users like me
might prefer using inbuild functions,like `size()` to get the size of the string.\
 you can use these functions directly like you would do in a string.
sample code:
```cpp
Var s = "hello world ";
 int a = s.size();
```
other such functions are :

|  __operators__ |  operations |
|-----------------|-------------------|
| `push_back()`       |    append a character to the end of string     |
|  `pop_back()`      |    remove a character from the end of string    |
|  `append()`      |    append a string to the end of the string    |
| `size()`       |    returns the size of the string         |
| `length()`     |    returns the length of the string         |
| `begin()`       |   returns an iterator pointing to the start of the string       |
| `end()`           |   returns an iterator  pointing to the next of the end of the string         |



# future works
relational operator 



thank you all !!

