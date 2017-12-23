SUBROUTINE dswap_noblas(n, x, y) BIND(C)
    USE ISO_C_BINDING
    IMPLICIT NONE

    INTEGER (C_LONG), VALUE :: n
    REAL (C_DOUBLE), DIMENSION(n) :: x, y

    REAL (C_DOUBLE), DIMENSION(n) :: tmp
    tmp = x
    x = y
    y = tmp

END SUBROUTINE

SUBROUTINE dswap_blas(n, x, y) BIND(C)
    USE ISO_C_BINDING
    IMPLICIT NONE

    INTEGER (C_LONG), VALUE :: n
    REAL (C_DOUBLE), DIMENSION(n) :: x, y

    CALL dswap(N, x, 1, y, 1)

END SUBROUTINE
