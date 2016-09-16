program call
  use solveSystem
  implicit none
  real                 ::L,h,T,t1,t2
  integer              ::N,ii

  real,allocatable, dimension(:)   :: Forces, Displacements,Positions,U_sol,Cs,Bs,As
  print*, "#Escriba el número de puntos"
  read*, N
  L=1
  h = L/N
  T = 1
  allocate(Cs(N))
  allocate(Bs(N+1))
  allocate(As(N))
  allocate(Forces(N+1))
  allocate(Displacements(N+1))
  allocate(Positions(N+1))
  allocate(U_sol(N+1))
  call cpu_time(t1)
  call fill_Coef(N,Cs,Bs,As)
  call fill_Positions(N,h,Positions)
  call fill_Forces(N,h,T,Forces,Positions)
  call solve_System(N,h,T,Forces,Cs,Bs,As,U_sol)
  call cpu_time(t2)
  print*, N, t2-t1
  deallocate(Cs)
  deallocate(Bs)
  deallocate(As)
  deallocate(Forces)
  deallocate(Displacements)
  deallocate(Positions)
  deallocate(U_sol)


end program call
