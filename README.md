# KNK Book

## Content

- [Chapter 4 Expressions](#chapter-4-expressions)
- [Chapter 5 Selection Statements](#chapter-5-selection-statements)
- [Chapter 7 Basic Types](#chapter-7-basic-types)
- [Chapter 8 Array](#chapter-8-array)
- [Chapter 9 Function](#chapter-9-function)
- [Chapter 11 Pointers](#chapter-11-pointers)
- [Chapter 12 Pointers and Arrays](#chapter-12-pointers-and-arrays)
- [Chapter 13 Strings](#chapter-13-strings)

## Chapter 4 Expressions

### Simple Assignment

- In C programming, single assignment is an `operator`, not a `statement`.

```c
// Sample 1
int i, j, k;

i = j = k = 0; // same as i = (j = (k = 0));
// Result - i = 0, j = 0, k = 0

// Sample 2
int x, y, z;

x = 3;
// it works, but not an good idea∏
z = x + (y = x);

// Result - x = 3, y = 3, z = 6
```

- assignment operator requires an `lvalue` as its left operand.
- `LValue` represents an object stored in computer memory, not a constant or the result of a computation.

> RValue is an expression that can appear on the right side.(i.e. variable, constant, or more complex expression) 

### Compound Assignment

- `v += e` is not exactly same as `v = v + e`
- In `v += e`, v will be evaluated only once; `v = v + e` causes v to be evaluated twice.

```c
// x *= (y + z);
// x = x * (y + z);
x *= y + z;

// x = (x * y) + z;
x = x * y + z;
```

### Expression Evaluation

```c
a = b += c++ - d + --e / -f
// Operator Priority: (a = (b += (((c++) - d) + ((--e) / (-f)))))
```

- C does not define the order in which subexpressions are evaluated. In the expression `(a + b) * (c - d)` we don't know whether `(a + b)` will be evaluated before `(c - d)`.

### Expression Statements

- In C, any Expression can be used as a Statement by appending a semicolon.

```c
// Example of Statement
++i;
i = 1;
```

## Chapter 5 Selection Statements

### Logical Expressions

- Relational Operators(`<`, `>`, `<=`, `>=`) has lower order of operations than Arithmetic operators.

```c
i + j < k - 1
// Same as: (i + j) < (k - 1)
```

- Relational Operators are left associative.

```c
i < j < k
// Same as: (i < j) < k
```

Logical Operators `&&`, `||` always evaluates its left operand first then the right operand. If left operand alone can evaluate whole expression, right operand will not be evaluated. This is called **short circuit**.

### The `if` Statement

- Form of `if` statement

```pseudo
if ( expression) statement
```

`if` statement can control two or more statements using **compound Statements**.

```pseudo
if ( expression) { statements }
```

### Boolean Values in C99

In C99, Boolean Value can be declared by writing `_Bool`. `_Bool` is unsigned integer type which can be assigned `0` or `1` only.

```c
_Bool flag;

flag = 5; // flag is 1
```

`<stdbool.h>` has `bool` macro which makes it easier to work with Boolean Value. `<stdbool.h>` also contains `true`, `false` macros which stand for 1, and 0.

```c
<stdbool.h>

bool flag; // Same as _Bool flag;

flag = true;
if (flag) {
    printf("It's true\n");
}
```

### Switch Statement

- Form of `switch` statement

```psuedo
switch ( expression) {
    case constant-expression : statements
    ...
    case constant-expression : statements
    default : statements
}
```

- Controlling expression: The word switch must be followed by an **integer expression** in parentheses.(integer, Charater)
- constant expression: it cannot contain variable or function calls.(i.e. `5 + 10` works, but `n + 10` not works.) constant expression must evaluate to an integer.

## Chapter 7 Basic Types

### Integer Types

- C's integer types come in different syizes. `int` is *usually* 32 bits.(varies from machine)
- The Range of each integer types is different from one machine to another.
- C standard does not force C's compiler to set its integer type's range of value.

#### Integer Constants

- Constants - numbers that appear in the text of a program, not numbers that are read, written, or computed.
- C supports integer constants to be written in decimal, octal, hexadecimal.
- Numbers are always saved in binary, regardless of integer constants.

```c
int num;

num = 010 ; // Octal Number, 8 in Decimal Number
num = 0xff; // Hexadecimal Number, 255 in Decimal Number

printf("%d\n", num);
```

- Number is treated as `long integer` or `unsigned integer` by C compiler, if it has letter `L` or `U` at the end of integer literal.
- C99 will use **smallest** type, if no letter exist.

```c
unsigned int num1;
long num2;
unsigned long num3;

num1 = 20U;
num2 = 46L;
num3 = 578UL;
```

#### Reading and Writing Integers

```c
// 64 bits machine
#include <limits.h>

int main(int argc, const char * argv[]) {
    printf("Range of int: %d ~ %d\n", INT_MIN, INT_MAX);
    printf("Range of long: %ld ~ %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of long long: %lld ~ %lld\n", LLONG_MIN, LLONG_MAX);
    printf("Range of unsigned long long: 0 ~ %llu\n", ULLONG_MAX);
}

// Range of int: -2147483648 ~ 2147483647
// Range of long: -9223372036854775808 ~ 9223372036854775807
// Range of long long: -9223372036854775808 ~ 9223372036854775807
// Range of unsigned long long: 0 ~ 18446744073709551615
```

### Floating Types

- Most morden computers follow the specifications in IEEE standard to save Floating-Point numbers.

### Character Types

#### Escape Sequences

- Some special characters can not be written, since they are invisible or since they can not be entered from keyboard. Escape sequence is special notation for these characters.
- C has two kinds of escape sequnces: `character escapes`, `numeric escapes`
- Character escapes represent some characters which used frequently.
- Numeric escapes can represent all ASCII characters. With single quotes and `\` notation, C can represent any ASCII letter using octal escape sequnece and hexadecimal escape sequence.

```c
// Character escape sequence
printf("abc \n def \n");

// Numeric Escape Sequence

// octal
char smallA = '\141';
// hexadecimal
char capitalA = '\x41';

printf("%c\n", smallA);
printf("%c\n", capitalA);

char c = '\x0a';
printf("abc \n def \n");
printf("abc %c def %c\n", c, c);
```

### Type Conversion

- C allows the basic types to be mixed in expressions. Single expression can contain mix of integers, floating-point numbers, and characters.

#### Implicit Conversion

- C compiler handles some conversions on it's own. These are known as `implicit conversions`.

#### The Usual Arithmetic Conversion

- Stratgy of Arithmetic Conversions - Convert operands to the **narrowest** type.

> Roughly speaking, one type is narrower than anther if it requires fewer bytes to store.(i.e. `int` is narrower than `long int`)

- Promotion is the act that convert the oprand of the narrower type to the type of the other operand to match the types of the operands.
- Integral Promotion - Convert character or short interger to type `int`(or `unsigned int` in some cases)

- **The type of either is a floating type** - promote the operand whose type is narrower.(i.e. One operand's type is `long double` and the other is `float`, convert `float` to `long double`)

```shell
float -> double -> long double
```

- **Neither operand type is a floating type** - Perform integral promotion first. Promote the operand whose type is narrower.

```shell
int -> unsigned int -> long int -> unsigned long int
```

#### Conversion During Assignment

- Right side of The assignment is converted to the type of the variable on the left side.
- If right side operand is `floating-point number` and left side operand type is `int`, fractional part of the number is missing.
- Assigning a value to a variable of a narrower type will give a meaningless result.

```c
int i;
// i is 842
i = 842.97;

char c;
// c is 16
c = 10000;
```

#### Type Casting

- Cast Expression

```expression
(type-name) expression
```

```c
float quotient;
int divisor

// (type-name) regard as unary operator.
quotient = (float) dividend / divisor
quotient = ((float) dividend) / divisor
```

### Type Definition

- Define Custom types make a program more understandable.

```c
typedef int Bool;
typedef float Dollars;

Bool flag;
Dollars cash_in, cash_out;
```

## Chapter 8 Array

### One Dimentional Array

- To access a particular element of an array, we write the array name followed by an integer value in square brackets(this is referred to as **subscripting** or **indexing** the array).

### Multidimentional Arrays

- To access the element of `m` in row `i`, we must write `m[i][j]`. The expression `m[i]` designates row `i` of `m`, and `m[i][j]` then selects element `j` in this row.
- Although we visualize two-dimentional arrays as tables, that's not the way they're actually stored in memory. C stores arrays in **row-major order** with row 0 first.
- Copy Array Using `memcpy`

```c
void copyArray() {
    const char suit_code[] = { 'c', 'h', 'd', 's'};
    char copied[4];

    memcpy(copied, suit_code, sizeof(suit_code));

    for(int i = 0; i < sizeof(suit_code); i++) {
        printf(" %c", copied[i]);
    }
    printf("\n");
}
```

## Chapter 9 Function

### Parameter & Argument

- Paramters appear in function **definitions**; they represents **values** to be supplied when the function is called.
- Arguments are **expressions** that appear in function **calls**

### Variable Length Array Parameters

```c
// Function Prototype
int sum_array(int n, int m, int a[n][m]);
```

### Program Termination

- The value returned by main is a status code; 0 means success

```c
#include <stdlib.h>

int main(void) {
    return 0;
    return EXIT_SUCCESS;
    exit(0);
    exit(EXIT_SUCCESS);
}
```

## Chapter 11 Pointers

### Pointer Variables

- Each variable in the program occupies one or more bytes in the memory.
- The address of the first byte is said to be the address of the variable.
- Addresses are represented by numbers, their range of values may differ from that of integers, so we can't necessarily store them in ordinary integer variables. We can store them in special `pointer varibles`.
- If we store the address of a variable `i` in the pointer variable `p`, we say that `p` points to `i`.
- A pointer is nothing more than an address, and a pointer variable is just a variable that can store an address.

### The Address and Indirection Operators

- To find the address of a variable, we use the `&` operator. To gain access to the object that a pointer points to, we use the `*` (indirection) operator.

```c
int value = 3;
int *pointer = &value; // *pointer is an alias of value.

printf("%d, %d\n", value, *pointer); // 3, 3
```

### Pointer as an Arguments

```c
void decompose(double x, long *int_part, double *frac_part) {
    *int_part = (long)x;
    *frac_part = x - *int_part;
}

long i;
double d;
long *p = &i;
double *q = &d;
decompose(3.141592, &i, &d);
decompose(3.141592, p, q);
```

## Chapter 12 Pointers and Arrays

### Pointer Arithmetic

- If `p` points to array element `a[i]`, then `p + j` points to `a[i + j]`.

```c
int a[5] = {0, 1, 2, 3, 4};
int *p;

p = &a[0]; // 0
int lastNum = *(p + 5); // 4
int undefined = *(p + 6); // Undefined Behavior
```

### Using an Array Name as a Pointer

- The name of an array can be used as a pointer to the first elemnt in the array.

```c
int a[5] = {0, 1, 2, 3, 4};
int *p, lastNum;

p = a; // *p becomes 0
lastNum = a + 5; // 4, a[4]
```

- C also allows us to subscript a pointer as though it were an array name.

```c
int a[5] = {0, 1, 2, 3, 4};
int *p;

p = a;
printf("%d\n", p[2]); // 2
```

### Pointers and Multidimentional Arrays

#### Processing the Rows of a Multidimentional Arrays

- Any 2D array `a`, the expression `a[i]` is a pointer to the first elemnt in row `i`.
- The Expression `a[i]` is equivalent to `*(a + i)`. Thus, `a[i][0]` is same as `*(a[i] + 0)`.

```c
// a is 2D Array
a[i] == *(a + i) // true
a[i][j] == *(a + i)[j] // true
*(a + i)[j] == *((a + i) + j) // true
```

```c
#define NUM_ROW 3
#define NUM_COL 4

int a[NUM_ROW][NUM_COL];
int *p, i = 0;
int callTime = 0;

for(p = a[i]; p < a[i] + NUM_COL; p++) {
    *p = 0;
    callTime++;
}
printf("CallTime - %d\n", callTime); // CallTime - 4
```

#### Processing the Columns of a Multidimentional Arrays

```c
#define NUM_ROW 3
#define NUM_COL 4

int a[NUM_ROW][NUM_COL] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
int (*ptr)[NUM_COL];

// Column Based Iteration
for(int i = 0; i < NUM_COL; i++) {
    for(ptr = &a[0]; ptr < &a[0] + NUM_ROW; ptr++) {
        printf("%d ", *((*ptr) + i));
    }
    printf("\n");
}

// 1 5 9 
// 2 6 10 
// 3 7 11 
// 4 8 12 
```

- `ptr` to be a **pointer to an array** of length `NUM_COL` whose elements are integers.
- `a` is not a pointer to `a[0][0]`. it's a pointer to `a[0]`. When used as pointer, `a` has type `int (*)[NUM_COLS]`.

```c
// Both Valid
for(p = &a[0]; p < &a[NUM_ROW]; p++) {
    (*p)[i] = 0;
}
for(p = a; p < a + NUM_ROW; p++) {
    (*p)[i] = 0;
}
```

## Chapter 13 Strings

- A *string literal* is a sequence of characters enclosed within double quotes.
- C treats string literals as character arrays. Character array for string literals contains one extra character(`null character`) to mark the end of the string.
- The string literal `"a"` is represented by `a pointer` to a memory location that contains the character `a`. The character constant `'a'` is represented by an `integer`.
- 

```c
// Initializeing a String Variable
char date1[8] = "June 14";

// Operations on String literals
char *p = "abc"; // p points to 'a'
char ch = "abc"[1]; // ch becomes 'b'
```

- Character Arrays and Character Pointers are not interchangable.
- If we want to modify element of string, we need to use array of characters instead of using pointer variable.

```c
char date1[] = "June 14";
char *date2 = "June 14";

date1[0] = 'P'; // fine
date2[0] = 'K'; // runtime crash
```

### Reading and Writing Strings

- Writing Strings Using `printf` and `puts`

```c
char date1[] = "June 14";
printf("%s\n", date1); // June 14
puts(date1); // June 14
printf("%.4s\n", date1); // June
```

- Reading Strings Using `scanf` and `gets`
- `scanf` stops reading characters when it encounters `new-line character`, `white space`, and `tab`.
- `gets` stops reading characters when it encounters `new-line character`.

```c
char str[80+1];
// Input: To C, or not to c
scanf("%s", str); // str = To
gets(str); // str = To C, or not to c

const int bufferSize = (sizeof(str) / sizeof(str[0]));
fgets(str, bufferSize, stdin); // str = To C, or not to c
```
