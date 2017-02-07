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
write *functions* in the exercises, not *programs*. 
Instead, you will write *unit tests* for your programs; you will
also write a `Makefile`. The functions should be written in
`matrix.c`, and the unit tests go into `check_mat.c`. The last
problem will be written in `main.c`, but you may wish to use
`main.c` to do other tests as you work.

This assignment concerns matrix multiplication. There is a gentle
reminder about matrix multiplication [here](https://www.mathsisfun.com/algebra/matrix-multiplying.html)
and an online matrix multiplication calculator [here](https://matrix.reshish.com/multiplication.php).

Throughout this assignment, you may assume that the input matrices are
the dimensions as given and that any result matrices are appropriately sized.

0. **`Makefile`**

    Write a `Makefile` that will compile and link both the `check_mat` and `main` programs.
    Make sure to submit this along with your assignment.

1. **Matrix equality** (5 points)

    Write a function with this prototype:

    ```c
    bool eq_matrix(int n, int m, int mat1[n][m], int mat2[n][m]);
    ```

    The function should return `true` if `mat1` and `mat2` are equal,
    and `false` otherwise.

    Write tests (in `check_mat.c`) to test your function.

2. **Matrix printing** (5 points)

    Write a function with this prototype:

    ```c
    void print_matrix(int n, int m, int mat[n][m]);
    ```

    This function prints the matrix to the screen. Assume the elements are at most 3 digits long.

3. **Matrix identity** (5 points)

    Write a function with this prototype:

    ```c
    void identity_mat(int n, int mat[n][n]);
    ```

    This function stores an [identity matrix](http://www.web-formulas.com/Math_Formulas/Linear_Algebra_Definition_of_Identity_Matrix.aspx) in `mat`, which
    has size `n`-by-`n`. You may assume that `mat` is indeed square.

    Write tests (in `check_mat.c`) to test your function.

4. **Scalar multiplication** (10 points)

    Write a function with this prototype:

    ```c
    void scalar_mult(int scalar, int n, int m, int mat[n][m], int result[n][m]);
    ```

    This function multiplies the matrix `mat` (with `n` rows and `m` columns) by the scalar `scalar` and put
    the result in `result`.

    Write tests (in `check_mat.c`) to test your function.

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

5. **Matrix multiplication** (20 points)

    Write a function with this prototype:

    ```c
    void matrix_mult(int n1, int m1, int mat1[n1][m1],
                     int m2, int mat2[m1][m2],
                     int result[n1][m2]);
    ```

    This function multiplies the `n1`-by-`m1` matrix `mat1` by
    the `m1`-by-`m2` matrix `mat2`, putting the result in `result`.
    Note that the number of rows of `mat2` must equal the number of
    columns in `mat1`, as required by the laws of matrix multiplication.
    The output matrix has size `n1`-by-`m2`, also as required by the
    laws of matrix multiplication.

    Write tests (in `check_mat.c`) to test your function.

6. **Exponentiation (slow)** (20 points)

    Write a function with this prototype:

    ```c
    void matrix_pow(int n, int mat[n][n], int power,
                    int result[n][n]);
    ```

    This function raises the `n`-by-`n` matrix `mat` to the power
    `power`, placing the result in `result`.

    Your function should work by making `power` (or, perhaps, `power - 1`)
    calls to `matrix_mult`. You may assume `power` is non-negative.

    Here are two hints:

     * Do not try to use the same matrix as an input to `matrix_mult` as
       you use as its result.

     * You can use `scalar_mult` to copy a matrix from one array to another,
       if you multiply by 1.

7. **Exponentiation (fast)** (20 points)

    Write a function with this prototype:

    ```c
    void matrix_pow_rec(int n, int mat[n][n], int power,
                        int result[n][n]);
    ```

    This function behaves identically to `matrix_pow`, but it is
    implemented *recursively*, by using the [exponentiation-by-squaring
    algorithm](https://en.wikipedia.org/wiki/Exponentiation_by_squaring).
    The first code snippet on that Wikipedia page (in pseudocode) explains
    it well -- implement that version. (Do *not* worry about tail recursion!)

    Write tests (in `check_mat.c`) to test your function. To be very thorough,
    you could use `rand` (see King, p. 686) to randomly generate matrices
    and then check your two exponentiation functions against each other.

8. **Measure speedup** (5 points)

    In `main.c`, write a program that witnesses that the fast (recursive)
    version of exponentiation is indeed faster than the slow version.
    Your program, when run, should output the number of "clock ticks"
    required to run the slow exponentiation function and the number
    required to run the fast one. Use the `clock` function, as described
    on pp. 692-693 of King. (Don't forget to `#include <time.h>`.) When
    printing out numbers of clock ticks, you can use the format specifier
    `%lu`, for `unsigned long`.

    On my machine, raising a 50x50 matrix to the 50th power worked nicely
    to demonstrate this difference. Other machines may prefer other numbers.
    Note that this calculation surely overflows poor, small `int`s (that is,
    requires values above $2^31$), but do
    not worry about that.

9. **Reflections**

    Edit `refl.txt` (short for "reflections") to answer
    the questions therein.

There are also **10 points** for style.

When you're all done, submit on GitHub by creating a Pull
Request according to [these instructions](../submission.html).
