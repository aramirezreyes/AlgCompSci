module function
  implicit none
contains
  function eval_f(x) result (f)
    real, intent(in) :: x
    real :: f
    f = -1 
  end function eval_f
end module function
