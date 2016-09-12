! This module will create an array of the coefficients for the linear system and will solve it using the tridiagonal matrix method.
!Argel Ram'irez Reyes, sept 2016
module system_solver
  implicit none
  real, dimension(100,100) :: Coef
  real, dimension(100)     :: Forces, Displacments
  integer                  :: ii,jj
contains
  function eval_f(x) result (f)
    real, intent(i) :: x
    real :: f
    print*, x
    f  = -1
  end function eval_f
end module system_solver.f90
