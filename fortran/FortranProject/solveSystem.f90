! This module will create an array of the coefficients for the linear system and will solve it using the tridiagonal matrix method.
!Argel Ram'irez Reyes, sept 2016
module solveSystem
  use function
  implicit none
  

contains
  subroutine fill_Coef(N,Cs,Bs,As)
    Integer, intent(in):: N
    Real, dimension(N+1), intent(inout) :: Bs
    Real, dimension(N), intent(inout) :: Cs,As
    Cs(:)=1
    As(:) = 1
    Cs(1) = 0
    As(N) = 0
    Bs(:) = 2
    Bs(1) = 1
    Bs(N+1) = 1
  end subroutine fill_coef


  subroutine fill_Positions(N,h,Positions)
    Integer, intent(in) :: N
    Real, intent(in):: h
    Integer:: ii
    Real, dimension(N+1),intent(inout) :: Positions
    do ii=1,N+1
       Positions(ii) = h*ii-1
    end do
  end subroutine fill_Positions

  subroutine fill_Forces(N,h,T,Forces,Positions)
    Integer , intent(in) :: N
    Real, intent(in):: h,T
    Integer:: ii
    Real, dimension(N+1),intent(inout) :: Forces,Positions
    Forces(1) = 0
    Forces(N+1) = 0
    do ii=2,N       
       Forces(ii) =-(h**2)*eval_f(Positions(ii))/T
    end do
  end subroutine fill_Forces

  subroutine solve_System(N,h,T,Forces,Cs,Bs,As,U_sol)
    Integer , intent(in) :: N
    Real, intent(in):: h,T
    Integer:: ii
    Real, dimension(N+1), intent(inout) :: Forces,U_Sol
    Real, dimension(N+1), intent(inout) :: Bs
    Real, dimension(N), intent(inout) :: Cs,As
    Cs(1) = Cs(1)/Bs(1)
    do ii=2,N
           Cs(ii) = Cs(ii)/(Bs(ii)-(As(ii)*Cs(ii)))
           Forces(ii) = (Forces(ii)-(As(ii)*Forces(ii-1)))/(Bs(ii)-(As(ii)*Cs(ii)))
              
    end do
    U_sol(N+1) = Forces(N)
    do ii = N,1,-1
        U_sol(ii) = Forces(ii) - (Cs(ii)*U_sol(ii+1))
    end do

  end subroutine solve_System
  

end module solveSystem
