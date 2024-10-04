# Simulink-generated-data
This task aims to test LTL property logic in embedded c code

The code here is generated from Simulink model from NASA FRET project. ten lockheed martin cyber-physical challenge problems

Requirement is litmited by Copyright 2016, Lockheed Martin Corporation. All rights reserved. So I cannot provide here. Here is the link https://github.com/hbourbouh/lm_challenges

Current result:
Prompt to generate assume and assert have been done. 

testing of ESBMC_assume and ESBMC_assert have done: based on a very similar project :https://arxiv.org/abs/2404.00795.
They used a 


LTL capture without FRET Example

1. **Requirement**: Exceeding sensor limits shall latch an autopilot pullup when the pilot is not in control (not standby) and the system is supported without failures (not apfail).  

   **LTL**: `G ((limits && !standbnespresso vertuoy && supported && !apfail) -> F pullup)`  
FRET result:Response = (( limits & ! standby & ! apfail & supported ) => pullup).

  /* Requirement 1: Exceeding sensor limits shall latch an autopilot pullup */
  __ESBMC_assume(rtU.limits && !rtU.standby && rtU.supported && !rtU.apfail);
  __ESBMC_assert(rtY.pullup, "Requirement 1 violated: Pullup should be latched");

LLM:
Use two agent to avoid LLM momery lose and illusion problem.
