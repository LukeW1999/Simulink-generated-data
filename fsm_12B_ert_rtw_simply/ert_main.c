/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'fsm_12B'.
 *
 * Model version                  : 25.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Oct  3 18:16:23 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 11
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>            /* This example main program uses printf/fflush */
#include "fsm_12B.h"                   /* Model header file */
#include "assert.h"

static RT_MODEL rtM_;
static RT_MODEL *const rtMPtr = &rtM_; /* Real-time model */
static DW rtDW;                        /* Observable states */

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

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(RT_MODEL *const rtM);
void rt_OneStep(RT_MODEL *const rtM)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */


  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example main function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific. This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  RT_MODEL *const rtM = rtMPtr;
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */
  rtM->dwork = &rtDW;

  /* Initialize model */
  fsm_12B_initialize(rtM);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.2 seconds (base rate of the model) here.
   * The call syntax for rt_OneStep is
   *
   *  rt_OneStep(rtM);
   */
  /*
   *
   * write about the assertion here:*/

  __ESBMC_assume(rtU_limits==1 && rtU_standby==0 && rtU_supported ==1 && rtU_apfail==0);
  //__ESBMC_assume(rtU_limits==1 );
  //__ESBMC_assume(rtU_standby==0 );
  //__ESBMC_assume(rtU_supported==1 );
  __ESBMC_assert(rtU_limits==0,"1");


  /* Step the model */
  //fsm_12B_step(rtM, rtU_standby, rtU_apfail, rtU_supported, rtU_limits, rtY_pullup);

  //assert(rtU_limits == 1 );



  /* The option 'Remove error status field in real-time model data structure'
   * is selected, therefore the following code does not need to execute.
   */
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
