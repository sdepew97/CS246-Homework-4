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
also write a `Makefile`. The functions should be written in
`matrix.c`, and the unit tests go into `check_mat.c`. The repo
comes with a `main.c`; you can put code in the `main` function there
if you like in order to experiment with your work. This file will
not be graded.

This assignment concerns matrix multiplication. There is a gentle
reminder about matrix multiplication [here](https://www.mathsisfun.com/algebra/matrix-multiplying.html)
and an online matrix multiplication calculator [here](https://matrix.reshish.com/multiplication.php).

Throughout this assignment, you may assume that the input matrices are
the dimensions as given and that any result matrices are appropriately sized.

1. **Matrix equality**

    Write a function with this prototype:

    ```c
    bool eq_matrix(int n, int m, int mat1[n][m], int mat2[n][m]);
    ```

    The function should return `true` if `mat1` and `mat2` are equal,
    and `false` otherwise.

2. **Matrix printing**

    Write a function with this prototype:

    ```c
    void print_matrix(int n, int m, int mat[n][m]);
    ```

    This function prints the matrix to the screen. Assume the elements are at most 3 digits long.

3. **Scalar multiplication**

    Write a function with this prototype:

    ```c
    void scalar_mult(int scalar, int n, int m, int mat[n][m], int result[n][m]);
    ```

    This function should multiply the matrix `mat` (with `n` rows and `m` columns) by the scalar `scalar` and put
    the result in `result`.

    For example, here is a call to `scalar_mult`:

    ```c
    int numbers[3][2] = { { 3, 4 },
                          { 2, 8 },
                          { 9, 7 } };
    int res[3][2];
    scalar_mult(6, 3, 2, numbers, res);
    print_matrix(3, 2, res);
    ```

    This code should print

          18  24
          12  48
          54  42

4. **Matrix multiplication**

    Write a function with this prototype:

    ```c
    bool matrix_mult(int n1, int m1, int mat1[n1][m1],
                     int n2, int m2, int mat2[n2][m2],
                     int result[n1][m2]);
    ```

    If the dimensions of the two input matrices `mat1` and `mat2` allow for
    it (that is, if `m1` equals `n2`), this function multiplies these two
    matrices, putting the result in `result`. When this multiplication is
    successful (that is, the dimensions match up),
    this returns `true`; otherwise, it returns `false`.

5. **Exponentiation (slow)**

    Write a function with this prototype:

    ```c
    bool matrix_pow(int n, int m, int mat[n][m], int result[n][m]);
    ```
