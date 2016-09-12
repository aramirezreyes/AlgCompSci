PROGRAM MULTIDIMENSIONAL_ARRAY
  IMPLICIT NONE
  REAL, DIMENSION(5000,5000) :: A,B,C
  REAL                       :: t1,t2
  INTEGER                    :: i,j
  DO i=1,5000
     DO j=1,5000
       A(i,j) = RAND(i)
       B(i,j) = RAND(j)
     END DO
  END DO

   call cpu_time(t1)
    DO i=1,5000
     DO j=1,5000
      C(i,j) =  A(i,j) * B(i,j)
     END DO
    END DO
    call cpu_time(t2)
 PRINT*, 'elapsed time with outer loop on lines : ', t2-t1


   call cpu_time(t1)
    DO i=1,5000
     DO j=1,5000
      C(j,i) =  A(j,i) * B(j,i)
     END DO
    END DO
    call cpu_time(t2)
 PRINT*, 'elapsed time with inner loop on lines: ', t2-t1



END PROGRAM MULTIDIMENSIONAL_ARRAY
