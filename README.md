# KNK Book

## Chapter 4 - Expresssions

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
