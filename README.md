# Homework 5
### due until 2.12., 8:30

Write a program that solves the linear oscillator equation
<p align="center">

<img src="stuffy_stuff/formel.png" width="250">
</p>

 subject to the given initial conditions. Implement the Euler forward and the Euler backward method. Integrate from *t=0* to *t=20pi* and create a plot which compares both numerical solutions *x(t)* to the analytic solution. Next to your code submit two plots, one for *dt = pi/10* and one for *dt = pi/100*.

Note:
* You will need arrays of length two (since this results in a two-dimensional ODE system)
* For the implicit method:
  * write down the formal implicit Euler method
  * insert your right-hand side f
  * now analytically solve for y_{n+1} to obtain the formula you have to implement
