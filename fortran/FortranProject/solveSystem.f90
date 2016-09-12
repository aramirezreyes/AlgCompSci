! This module will create an array of the coefficients for the linear system and will solve it using the tridiagonal matrix method.
!Argel Ram'irez Reyes, sept 2016
module system_solver
  implicit none
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
contains
  subroutine fill_matrix
    Coef(1,1) = 1
    Coef(N+1,N+1) = 1
    do ii=2,N
       Coef(ii,ii-1) = 1
       Coef(ii,ii) = -2
       Coef(ii,ii+1) = 1
    end do
  end subroutine fill_matrix


  subroutine fill_Positions
    do ii=1,N+1
       Positions(ii) = h*ii-1
    end do
  end subroutine fill_Positions

  subroutine fill_Forces
    Forces(1) = 0
    Forces(N+1) = 0
    do ii=2,N       
       Forces(ii) =-(h**2)*eval_f(Positions(ii))/T
    end do
  end subroutine fill_Forces

  

end module system_solver.f90
