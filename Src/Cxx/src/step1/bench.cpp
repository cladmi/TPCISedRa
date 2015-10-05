#include "Sphere.hpp"
#include <time.h>
#include <cstddef>
#include <iostream>

double delta(timespec start, timespec end)
{
	timespec temp;
	if ((end.tv_nsec-start.tv_nsec)<0) {
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1e9+end.tv_nsec-start.tv_nsec;
	}
  else
  {
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
  return (double) (temp.tv_sec + 1e-9*temp.tv_nsec);
}

int main()
{

  double result=0.;
  double etime=0.;

  timespec t0;
  timespec t1;

  // useless
  unsigned nbtrials=10;

  std::cout.precision(5);
  std::cout << std::scientific;

  for (unsigned trial=0; trial<nbtrials; ++trial)
  {

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t0);

    for(std::size_t i=0; i<1000000; ++i)
    {
      result+=Sphere((double)(i)).volume();
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t1);

    double itime = delta(t0, t1);

    etime += itime;
  }

  etime /= nbtrials;

  std::cout << "time:" << etime <<std::endl;
  std::cout << "result:" << result << std::endl;

  return result==0.;
}
