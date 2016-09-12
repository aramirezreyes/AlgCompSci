PROGRAM DYNAMIC_ALLOCATION

INTEGER, DIMENSION(:,:), ALLOCATABLE :: A
INTEGER                              :: n,m,j,i,k

PRINT*, 'Introduce the number of lines: '
READ*, n
PRINT*, 'Introduce the number of columns: '
READ*, m

ALLOCATE(A(n,m))
k = 1
DO j=1,n
 DO i=1,m
    IF (MOD(j,2) == 0) THEN
      A(j,i) = 1
    ELSE 
       A(j,i) = k
       k = k+1
    END IF
 END DO
END DO



DO j=1,n
   PRINT*, (A(j,i), i=1,m)
END DO
DEALLOCATE(A)

END PROGRAM DYNAMIC_ALLOCATION
