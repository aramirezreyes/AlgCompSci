PROGRAM NEWTON ! Argel Ramirez Reyes
  REAL :: f,df,epsilon,x_zero,x_1,x_2
  INTEGER :: n
  
  PRINT*, 'Introduce the desired precision for the root'
  READ*, epsilon
  PRINT*, 'The selected precision is: '
  PRINT*, epsilon

  PRINT*, 'Introduce the initial point'
  READ*, x_zero
  PRINT*, 'The initial vqlue of x is: '
  PRINT*, x_zero
  
  x_1 = x_zero - (x_zero - exp(-1*x_zero))/(1 + exp(-x_zero))
  x_2 = x_1 - (x_1 - exp(-1*x_1))/(1 + exp(-x_1))
  N = 1;
  DO WHILE (abs((x_2-x_1) / x_1 ) >= epsilon)
  ! PRINT*, (abs((x_2-x_1) / x_1 ) >= epsilon)
   x_1 = x_2
   x_2 = x_1 - (x_1 - exp(-1*x_1))/(1 + exp(-x_1))
   N = N+1
  END DO

  PRINT*, 'The root of the equation is: '
  PRINT*, x_2
  PRINT*, 'And it was found after: '
  PRINT*, N
  PRINT*, 'Iterations'

END PROGRAM NEWTON
