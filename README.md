# fortran-blas-benchmark

Collection of Google Benchmark based benchmarks to compare a BLAS library (e.g. Intel MKL) versus simply using Fortran's array operations.

```Fortran
    INTEGER (C_LONG), VALUE :: n
    REAL (C_DOUBLE), VALUE :: a
    REAL (C_DOUBLE), DIMENSION(n) :: x, y

    ! Everyone can read this.
    y = a * x + y
     
    ! Is this faster? Enough, to put up with making code hard to read?
    CALL daxpy(n, a, x, 1, y, 1)
```

## Status
BLAS level 1 functions are mostly implemented, except for functions for rotation operations. Results for a single system (Intel Skylake, Intel Compilers + MKL 2018) already show clear speed-ups for level 1, so the purpose is fulfilled.

Adding level 2 and 3 is low priority, because there is an obvious advantage for BLAS, and implementing these operations with array operations is less straight forward. The expected advantage for BLAS is the availability of (hand tuned) cache re-use optimisations such as loop blocking, which were not possible for level 1's streaming operations.

## Results
Results for the system mentioned above are in [this Jupyter notebook](analysis/analysis.ipynb). To re-run on your system, adapt the Makefile for your compilers and BLAS. Run `make results` and re-run the notebook on your results file.

