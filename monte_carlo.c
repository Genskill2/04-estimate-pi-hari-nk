#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


float frandom()
{
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}

float mc_pi(int n)
{
  float count=0;
  for(int i=0;i<n;i++)
  {
    float x_axis=frandom();
    float y_axis=frandom();
    float dist=sqrt(x_axis*x_axis+y_axis*y_axis);

    if(dist<=1)
    {
      count=count+1;

    }
  }
  float mc=count/n;
  return mc*4;
}



int main(void)
{
  float pi0;
  float pi1;

  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);

  if (pi0 == pi1)
    {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }

  if (fabs(pi0 - pi1) > 0.05)
    {
        printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
        abort();
    }


  for (int i=2000; i<5000; i++)
    {
      pi0 = mc_pi(i);
      if (!(fabs(pi0 - M_PI) < 0.4))
      {
        printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
        abort();
      }
    }
}



