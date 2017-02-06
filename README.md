---
title: CS 246 Assignment 4
---

<div id="header">

| **CS 246 Assignment 3**
| due 12:55pm on Tuesday, February 14, 2017

</div>

[Link back to syllabus](http://cs.brynmawr.edu/cs246/syllabus.html)

[Click here to start assignment](TODO)

Like all assignments, you will complete this assignment via
GitHub. See [the submission instructions](../submission.html)
for how to get the starter code and how to submit this
assignment.

Unlike in previous assignments, in this assignment, you will
write *functions* in the exercises, not *programs*. This homework
assignment does not have any programs you should write at all.
Instead, you will write *unit tests* for your programs; you will
also write a `Makefile`.

This assignment concerns matrix multiplication. There is a gentle
reminder about matrix multiplication [here](https://www.mathsisfun.com/algebra/matrix-multiplying.html)
and an online matrix multiplication calculator [here](https://matrix.reshish.com/multiplication.php).

1. **Matrix printing**

Write a function with this prototype:

```c
void print_matrix(int n, int m, int mat[n][m]);
```

This function prints the matrix to the screen. Assume the elements are at most 3 digits long.

1. **Scalar multiplication**

Write a function with this prototype:

```c
void scalar_mult(int scalar, int n, int m, int mat[n][m], int result[n][m]);
```

This function should multiply the matrix `mat` (with `n` rows and `m` columns) by the scalar `scalar` and put
the result in `result`. You can assume that `n` and `m` are both non-negative and that both the input
matrix `mat` and the output matrix `result` have `n` rows and `m` columns.

For example, here is a call to `scalar_mult`:

```c
int numbers[3][2] = { { 3, 4 },
                      { 2, 8 },
		      { 9, 7 } };
int res[3][2];
scalar_mult(6, 3, 2, numbers, res);
print_matrix(res);
```

This code should print

1. **Matrix multiplication**

Write a function with this prototype:

```c
bool matrix_mult(int n1, int m1
