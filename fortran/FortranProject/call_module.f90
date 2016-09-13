program call
  use f_function
  implicit none
  real :: x
  integer :: ii


  real                 ::L,h,T
  integer              ::N 
  real, allocatable, dimension(:,:) :: Coef
  real,allocatable, dimension(:)   :: Forces, Displacements,Positions
  integer              :: ii,jj
  print*, "Escriba el número de puntos"
  read*, N
  h = L/N
  allocate(Coef(N+1,N+1))
  allocate(Forces(N+1))
  allocate(Displacements(N+1))
  allocate(Positions(N+1))

  !aquí se deben llelmar las subrutinas después de alocarse  

  deallocate(Coef)
  deallocate(Forces)
  deallocate(Displacements)
  deallocate(Positions)


  do ii = 1,10
     x = ii
     print*, x,eval_f(x)
  end do

end program call
