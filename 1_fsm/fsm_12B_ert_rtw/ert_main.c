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

static RT_MODEL rtM_;
static RT_MODEL *const rtMPtr = &rtM_; /* Real-time model */
static DW rtDW;                        /* Observable states */

_Bool nondet_bool();
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
double nondet_double();
int nondet_int();
void rt_OneStep(RT_MODEL *const rtM);
void rt_OneStep(RT_MODEL *const rtM)
{
	static boolean_T OverrunFlag = false;
	OverrunFlag = nondet_bool();  // Set OverrunFlag as a non-deterministic value

	/* Disable interrupts here */

	/* Set model inputs here */
	rtU_standby = nondet_bool();      // True when the pilot is in control of the vehicle
	rtU_apfail = nondet_bool();       // Failure indication from an external source
	rtU_supported = nondet_bool();    // Indication of the system's general health; must be True to enable operation
	rtU_limits = nondet_bool();       // External indication to sensor on faulty conditions
	rtY_pullup = nondet_bool();       // True when the autopilot is in the MANEUVER state
	rtDW.Merge = nondet_double();

	/* Check for overrun */
	if (OverrunFlag) {
		return;  // Exit early if an overrun is detected
	}

	/* Save FPU context here (if necessary) */
	/* Re-enable timer or interrupt here */
	int sit=1;
	sit = nondet_int();

	/* Check for overrun */
	if (OverrunFlag) {
		return;  // Exit early if an overrun is detected
	}

	/* Save FPU context here (if necessary) */
	/* Re-enable timer or interrupt here */

	sit = nondet_int();

	if (sit == 1) {
		// Requirement 1: Exceeding sensor limits shall latch an autopilot pullup
		__ESBMC_assume(rtU_limits && !rtU_standby && rtU_supported && !rtU_apfail);
		fsm_12B_step(rtM, rtU_standby, rtU_apfail, rtU_supported, rtU_limits, &rtY_pullup);
		__ESBMC_assert(rtY_pullup, "Requirement 1 violated: Pullup should be latched");

	} else if (sit == 2) {
		// Requirement 2: Change states from TRANSITION to STANDBY when in control
		__ESBMC_assume(rtDW.Merge == 0.0 && rtU_standby); // Transition state
		fsm_12B_step(rtM, rtU_standby, rtU_apfail, rtU_supported, rtU_limits, &rtY_pullup);
		__ESBMC_assert(rtDW.Merge == 3.0, "Requirement 2 violated: Should change to STANDBY");

	} else if (sit == 3) {
		// Requirement 3: Change states from TRANSITION to NOMINAL when supported and OverrunFlag is false (data is good)
		__ESBMC_assume(rtDW.Merge == 0.0 && rtU_supported && !OverrunFlag); // Transition state with good data
		fsm_12B_step(rtM, rtU_standby, rtU_apfail, rtU_supported, rtU_limits, &rtY_pullup);
		__ESBMC_assert(rtDW.Merge == 1.0, "Requirement 3 violated: Should change to NOMINAL");

	} else if (sit == 4) {
		// Requirement 4: Change states from NOMINAL to MANEUVER when OverrunFlag is true (data is not good)
		__ESBMC_assume(rtDW.Merge == 1.0 && OverrunFlag); // Nominal state with bad data
		fsm_12B_step(rtM, rtU_standby, rtU_apfail, rtU_supported, rtU_limits, &rtY_pullup);
		__ESBMC_assert(rtDW.Merge == 2.0, "Requirement 4 violated: Should change to MANEUVER");

	} else if (sit == 5) {
		// Requirement 5: Change states from NOMINAL to STANDBY when in control
		__ESBMC_assume(rtDW.Merge == 1.0 && rtU_standby); // Nominal state
		fsm_12B_step(rtM, rtU_standby, rtU_apfail, rtU_supported, rtU_limits, &rtY_pullup);
		__ESBMC_assert(rtDW.Merge == 3.0, "Requirement 5 violated: Should change to STANDBY");

	} else if (sit == 6) {
		// Requirement 6: Change states from MANEUVER to STANDBY when in control and OverrunFlag is false (data is good)
		__ESBMC_assume(rtDW.Merge == 2.0 && rtU_standby && !OverrunFlag); // Maneuver state with good data
		fsm_12B_step(rtM, rtU_standby, rtU_apfail, rtU_supported, rtU_limits, &rtY_pullup);
		__ESBMC_assert(rtDW.Merge == 3.0, "Requirement 6 violated: Should change to STANDBY");

	} else if (sit == 7) {
		// Requirement 7: Change states from PULLUP to TRANSITION when supported and OverrunFlag is false (data is good)
		__ESBMC_assume(rtDW.Merge == 3.0 && rtU_supported && !OverrunFlag); // Pullup state with good support and sensor data
		fsm_12B_step(rtM, rtU_standby, rtU_apfail, rtU_supported, rtU_limits, &rtY_pullup);
		__ESBMC_assert(rtDW.Merge == 0.0, "Requirement 7 violated: Should change to TRANSITION");

	} else if (sit == 8) {
		// Requirement 8: Change states from STANDBY to TRANSITION when not in control
		__ESBMC_assume(rtDW.Merge == 3.0 && !rtU_standby); // Standby state
		fsm_12B_step(rtM, rtU_standby, rtU_apfail, rtU_supported, rtU_limits, &rtY_pullup);
		__ESBMC_assert(rtDW.Merge == 0.0, "Requirement 8 violated: Should change to TRANSITION");

	} else if (sit == 9) {
		// Requirement 9: Change states from STANDBY to MANEUVER when apfail occurs
		__ESBMC_assume(rtDW.Merge == 3.0 && rtU_apfail); // Standby state with failure
		fsm_12B_step(rtM, rtU_standby, rtU_apfail, rtU_supported, rtU_limits, &rtY_pullup);
		__ESBMC_assert(rtDW.Merge == 2.0, "Requirement 9 violated: Should change to MANEUVER");

	} else if (sit == 10) {
		// Requirement 10: Change sensor states from NOMINAL to FAULT when limits are exceeded
		__ESBMC_assume(rtDW.Merge_g == 1.0 && rtU_limits); // Sensor nominal state
		fsm_12B_step(rtM, rtU_standby, rtU_apfail, rtU_supported, rtU_limits, &rtY_pullup);
		__ESBMC_assert(rtDW.Merge_g == 2.0, "Requirement 10 violated: Should change to FAULT");

	} else if (sit == 11) {
		// Requirement 11: Change sensor states from NOMINAL to TRANSITION when not requested
		__ESBMC_assume(rtDW.Merge_g == 1.0 && !rtU_supported); // Sensor nominal state with no request for support
		fsm_12B_step(rtM, rtU_standby, rtU_apfail, rtU_supported, rtU_limits, &rtY_pullup);
		__ESBMC_assert(rtDW.Merge_g == 0.0, "Requirement 11 violated: Should change to TRANSITION");

	} else if (sit == 12) {
		// Requirement 12: Change sensor states from FAULT to TRANSITION when not requested and limits not exceeded
		__ESBMC_assume(rtDW.Merge_g == 2.0 && !rtU_supported && !rtU_limits); // Sensor fault state with no request and no limits exceeded
		fsm_12B_step(rtM, rtU_standby, rtU_apfail, rtU_supported, rtU_limits, &rtY_pullup);
		__ESBMC_assert(rtDW.Merge_g == 0.0, "Requirement 12 violated: Should change to TRANSITION");

	} else if (sit == 13) {
		// Requirement 13: Change sensor states from TRANSITION to NOMINAL when requested and mode is correct
		__ESBMC_assume(rtDW.Merge_g == 0.0 && rtU_supported); // Sensor transition state with support
		fsm_12B_step(rtM, rtU_standby, rtU_apfail, rtU_supported, rtU_limits, &rtY_pullup);
		__ESBMC_assert(rtDW.Merge_g == 1.0, "Requirement 13 violated: Should change to NOMINAL");
	}


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



	rt_OneStep(rtM);









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
