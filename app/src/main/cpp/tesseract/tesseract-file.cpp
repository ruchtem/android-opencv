// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
double mysqrt (int value)
{
  fprintf(stdout,"mysqrt called!!");
  double outputValue = sqrt(value);
  fprintf(stdout,"The square root of");
  return outputValue;
}
