SUBROUTINE daxpy_noblas(n, a, x, y) BIND(C)
    USE ISO_C_BINDING
    IMPLICIT NONE

    INTEGER (C_LONG), VALUE :: n
    REAL (C_DOUBLE), VALUE :: a
    REAL (C_DOUBLE), DIMENSION(n) :: x, y

    y = a * x + y

END SUBROUTINE

SUBROUTINE daxpy_blas(n, a, x, y) BIND(C)
    USE ISO_C_BINDING
    IMPLICIT NONE

    INTEGER (C_LONG), VALUE :: n
    REAL (C_DOUBLE), VALUE :: a
    REAL (C_DOUBLE), DIMENSION(n) :: x, y

    CALL daxpy(n, a, x, 1, y, 1)

END SUBROUTINE
