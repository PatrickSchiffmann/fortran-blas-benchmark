SUBROUTINE dscal_noblas(n, a, x) BIND(C)
    USE ISO_C_BINDING
    IMPLICIT NONE

    INTEGER (C_LONG), VALUE :: n
    REAL (C_DOUBLE), VALUE :: a
    REAL (C_DOUBLE), DIMENSION(n) :: x

    x = a * x

END SUBROUTINE

SUBROUTINE dscal_blas(n, a, x) BIND(C)
    USE ISO_C_BINDING
    IMPLICIT NONE

    INTEGER (C_LONG), VALUE :: n
    REAL (C_DOUBLE), VALUE :: a
    REAL (C_DOUBLE), DIMENSION(n) :: x

    CALL dscal(n, a, x, 1)

END SUBROUTINE
