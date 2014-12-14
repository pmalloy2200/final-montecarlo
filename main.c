/* 
 * Monte Carlo calculation of volume of
 * 5-dimensional superellipsoid
 */
#include <stdio.h>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_statistics.h>

double mc_se (long m, int n, gsl_rng * r);

#define POINTS 500000           /* number of random points to generate */
#define NEXP 50                 /* number of experiments */

int
main (void)
{
    double vol[NEXP];           /* calculated values of volume */
    gsl_rng *r;
    double mean, sd;
    int n, j;
    unsigned long seed = 1UL;
    long p = POINTS;

    /* allocate random number generator */
    r = gsl_rng_alloc (gsl_rng_taus2);

    /* seed the random number generator */
    gsl_rng_set (r, seed);

    for (n = 1; n < 10; n++)
    {
        for (j = 0; j < NEXP; j++)
        {
            /* calculate pi using Monte Carlo algorithm */
            vol[j] = mc_se (p, n, r);
        }
        mean = gsl_stats_mean (vol, 1, NEXP);
        sd = gsl_stats_sd_m (vol, 1, NEXP, mean);
        printf ("%15d   %10.8f   %10.8f\n", n, mean, sd);
    }

    gsl_rng_free (r);

    return (0);
}
