/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: fsm_12B.h
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

#ifndef fsm_12B_h_
#define fsm_12B_h_
#ifndef fsm_12B_COMMON_INCLUDES_
#define fsm_12B_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* fsm_12B_COMMON_INCLUDES_ */

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Merge;                        /* '<S4>/Merge' */
  real_T Merge_g;                      /* '<S14>/Merge' */
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S1>/Unit Delay1' */
  boolean_T Merge_p[3];                /* '<S5>/Merge' */
  boolean_T UnitDelay2_DSTATE;         /* '<S1>/Unit Delay2' */
} DW;

/* Real-time Model Data Structure */
struct tag_RTM {
  DW *dwork;
};

/* Model entry point functions */
extern void fsm_12B_initialize(RT_MODEL *const rtM);
extern void fsm_12B_step(RT_MODEL *const rtM, boolean_T rtU_standby, boolean_T
  rtU_apfail, boolean_T rtU_supported, boolean_T rtU_limits, boolean_T
  rtY_pullup);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'fsm_12B'
 * '<S1>'   : 'fsm_12B/FiniteStateMachine'
 * '<S2>'   : 'fsm_12B/FiniteStateMachine/Manager'
 * '<S3>'   : 'fsm_12B/FiniteStateMachine/Sen'
 * '<S4>'   : 'fsm_12B/FiniteStateMachine/Manager/Actions'
 * '<S5>'   : 'fsm_12B/FiniteStateMachine/Manager/Output'
 * '<S6>'   : 'fsm_12B/FiniteStateMachine/Manager/Actions/Maneuver'
 * '<S7>'   : 'fsm_12B/FiniteStateMachine/Manager/Actions/Nominal'
 * '<S8>'   : 'fsm_12B/FiniteStateMachine/Manager/Actions/Standby'
 * '<S9>'   : 'fsm_12B/FiniteStateMachine/Manager/Actions/Transition'
 * '<S10>'  : 'fsm_12B/FiniteStateMachine/Manager/Output/Maneuver'
 * '<S11>'  : 'fsm_12B/FiniteStateMachine/Manager/Output/Nominal'
 * '<S12>'  : 'fsm_12B/FiniteStateMachine/Manager/Output/Standby'
 * '<S13>'  : 'fsm_12B/FiniteStateMachine/Manager/Output/Transition'
 * '<S14>'  : 'fsm_12B/FiniteStateMachine/Sen/Actions'
 * '<S15>'  : 'fsm_12B/FiniteStateMachine/Sen/Output'
 * '<S16>'  : 'fsm_12B/FiniteStateMachine/Sen/Actions/Fault'
 * '<S17>'  : 'fsm_12B/FiniteStateMachine/Sen/Actions/Nominal'
 * '<S18>'  : 'fsm_12B/FiniteStateMachine/Sen/Actions/Transition'
 */
#endif                                 /* fsm_12B_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
