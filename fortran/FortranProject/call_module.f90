program call
use f_function
    implicit none
real :: x
integer :: ii
do ii = 1,10
   x = ii
   print*, x,eval_f(x)
end do

end program call
