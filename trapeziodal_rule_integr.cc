// @brief:  Trapeziodal rule integration of function f(x)
//          with OpenMp; mipt cource: parallel algorithms
// @author: Khodakov Dmitry, mipt group 811, dmitryhd@gmail.com
// @date:   23 sept 2011
// @compile: g++ -g -Wall -fopenmp -lm -o integr trapeziodal_rule_integr.cc
// @run:    ./integr 0.1 0.3 200

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

// @brief:  integrate fuction func with constant step,
//          trapezional rule, Cortez formula I = step*([f0-fn]/2 + sum(fi))
// @arguments:  func - callback for function;
//              xbegin - begin integration from xbegin
//              xend - end integration on xend
//              num - number of integration steps (!strongly > 0!)
// @return: result of integration
double trapeziodal_rule_integrate (double (*func)(double x),
                                    double xbegin,
                                    double xend,
                                    int num)
{
  double step = (xend - xbegin)/num;
  double res = step*(func(xbegin)+func(xend))/2;
  int add_index;
  double current_arg = xbegin;
  // OpenMp parallelization
#pragma omp parallel shared(res) private (add_index)
  {
#pragma omp for
    for (add_index = 0; add_index < num - 1; ++add_index)
    {
      current_arg += step;
      res += func(current_arg)*step;
      // debug
      // printf("iter: %d, arg = %g\n", add_index, current_arg);
    }
  }
  return res;
}

// fuction to integrate
double sin_func (double x)
{
  return sin(x);
}

void print_usage(char **argv)
{
  printf("usage: %s <begin> <end> <num of iterations>\n", argv[0]);
}

int main (int argc, char **argv)
{
  // getting argument: begin end, num of iterations
  if (argc != 4)
  {
    print_usage(argv);
    return 0;
  }
  double begin  = atof(argv[1]);
  double end    = atof(argv[2]);
  int num_iter  = atoi(argv[3]);
  // make sure that begin < end
  if (begin > end)
  {
    double tmp = end;
    end = begin;
    begin = tmp;
  }
  if (begin == end)
  {
    print_usage(argv);
    printf("wrong (zero) integration interval\n");
    return 1;
  }
  if (num_iter <= 0)
  {
    print_usage(argv);
    printf("wrong number of iterations. should be > 0\n");
    return 1;
  }

  // call integrate fuction
  double res = trapeziodal_rule_integrate(sin_func, begin, end, num_iter);

  // OpenMp initialization
  omp_set_dynamic(0); // disable dynamic thread detection;
  omp_set_num_threads(omp_get_num_procs());
  // debug
  // printf("current number of processors is: %d\n", omp_get_num_procs());

  // print result
  printf("%g\n", res);
  return 0;
}

