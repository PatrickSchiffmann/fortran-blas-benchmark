REAL (C_DOUBLE) FUNCTION ddot_noblas(n, x, y) BIND(C)
    USE ISO_C_BINDING
    IMPLICIT NONE

    INTEGER (C_LONG), VALUE :: n
    REAL (C_DOUBLE), DIMENSION(n) :: x, y

    ddot_noblas = DOT_PRODUCT(x, y)

END FUNCTION

REAL (C_DOUBLE) FUNCTION ddot_blas(n, x, y) BIND(C)
    USE ISO_C_BINDING
    IMPLICIT NONE

    INTEGER (C_LONG), VALUE :: n
    REAL (C_DOUBLE), DIMENSION(n) :: x, y
    DOUBLE PRECISION ddot

    ddot_blas = ddot(n, x, 1, y, 1)

END FUNCTION
