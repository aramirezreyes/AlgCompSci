program call
  use solveSystem
  implicit none
  real                 ::L,h,T,x
  integer              ::N,ii
  real, allocatable, dimension(:,:) :: Coef
  real,allocatable, dimension(:)   :: Forces, Displacements,Positions,U_sol
  print*, "Escriba el número de puntos"
  read*, N
  L=1
  h = L/N
  T = 1
  allocate(Coef(N+1,N+1))
  allocate(Forces(N+1))
  allocate(Displacements(N+1))
  allocate(Positions(N+1))
  allocate(U_sol(N+1))
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
