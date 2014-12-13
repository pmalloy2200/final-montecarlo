/*
 * Monte Carlo se calculation
 */

#include <gsl/gsl_rng.h>
#include <math.h>

double mc_se(long m, int n, gsl_rng *r)
{
   double x, y, a, b, c;       /* 5-dim coordinate, all between 0 and 1  */
   long count = 0L;
   long i;
   for (i = 0; i < m; i++) {
      /* generate random coordinates */
      x = gsl_rng_uniform(r);
      y = gsl_rng_uniform(r);
      a = gsl_rng_uniform(r);
      b = gsl_rng_uniform(r);
      c = gsl_rng_uniform(r);

      /* count when the point lands in the shape */
      if ((pow(x, (double) n) + pow(y, (double) n) + 
      pow(a, (double) n) + pow(b, (double) n) + pow(c, (double) n)) <= 1.0) {
         count += 1;
      }
   }

   return(32.0 * ((double)count)/((double)m));

} 
