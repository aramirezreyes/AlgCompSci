PROGRAM CIRCLE_AND_SPHERE

  REAL ::r,a,v
  CHARACTER(3) :: usrAns
  REAL, PARAMETER :: pi = 3.14159234
  PRINT*, 'Welcome, this program will tell you the volume and area of your sphere'
  usrAns = 'yes'
  DO WHILE (usrAns == 'yes' .or. usrAns == 'YES')
    PRINT*, 'What is the radius?: '
    READ*, r
    PRINT*, 'The area is: '
    PRINT*, 4.0*pi*r**2
    PRINT*, 'The volume is: '
    PRINT*, (4.0/3.0)*pi*r**3
    PRINT*, 'Want to do it again?'
    READ*, usrAns
  END DO

END PROGRAM CIRCLE_AND_SPHERE
