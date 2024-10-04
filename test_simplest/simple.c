#include "assert.h"

#include <stddef.h>

#include <stdio.h>

typedef unsigned char boolean_T;
typedef int int_T;

/* '<Root>/standby' */
static boolean_T rtU_standby;

/* '<Root>/apfail' */
static boolean_T rtU_apfail;

/* '<Root>/supported' */
static boolean_T rtU_supported;

/* '<Root>/limits' */
static boolean_T rtU_limits;

/* '<Root>/pullup' */
static boolean_T rtY_pullup;

int_T main(int_T argc, const char *argv[])
{

  __ESBMC_assume(rtU_limits==1 && rtU_standby==0 && rtU_supported ==1 && rtU_apfail==0);
  //__ESBMC_assume(rtU_limits==1 );
  //__ESBMC_assume(rtU_standby==0 );
  //__ESBMC_assume(rtU_supported==1 );
  __ESBMC_assert(rtU_limits==0,"1");
return 0;

}
