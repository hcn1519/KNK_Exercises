# KNK Book

## Content

- [Chapter 4 Expressions](#chapter-4-expressions)
- [Chapter 5 Selection Statements](#chapter-5-selection-statements)

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
