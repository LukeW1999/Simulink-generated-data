# Simulink-Generated-Data

### **Project Overview**
This project is aimed at testing Linear Temporal Logic (LTL) properties in embedded C code, which is generated from Simulink models from the NASA FRET project. The models used are part of the ten Lockheed Martin cyber-physical challenge problems.

**Note**: The requirements are limited by **Copyright 2016, Lockheed Martin Corporation. All rights reserved**, and therefore cannot be provided in this repository. However, you can access the related challenge problems via the following link: [Lockheed Martin Cyber-Physical Challenge Problems](https://github.com/hbourbouh/lm_challenges).

### **Current Progress**
- **Generation of Assumptions and Assertions**: The task of generating assume and assert statements has been completed.
- **Testing ESBMC Assumptions and Assertions**: The testing has been performed based on a similar project, which is detailed in this [arxiv paper](https://arxiv.org/abs/2404.00795). The project used Software IP Components to generate C code. ESBMC successfully detected value errors and functioned correctly even with multi-assume statements.

### **LTL Capture Without FRET Example**

#### **Requirement Example**:
When exceeding sensor limits, the autopilot should latch the pullup if the pilot is not in control (not in standby) and the system is supported (not failed).

#### **LTL Expression**:
\`\`\`LTL
G ((limits && !standby && supported && !apfail) -> F pullup)
\`\`\`

#### **FRET Tool Result**:
Response = ((limits & !standby & !apfail & supported) => pullup).

Corresponding C code:
\`\`\`c
/* Requirement 1: When sensor limits are exceeded, the autopilot pullup should be latched */

__ESBMC_assume(rtU_limits && !rtU_standby && rtU_supported && !rtU_apfail);
__ESBMC_assert(rtY_pullup, \"Requirement 1 violated: Pullup should be latched\");

\`\`\`

### **ESBMC Usage Example**
To verify the generated C code with ESBMC, use the following command:
\`\`\`bash
esbmc ert_main.c fsm_12B.c -I ./ -I /usr/local/MATLAB/R2024b/simulink/include --symex-trace
\`\`\`

### **Avoiding LLM Memory Issues**
Use two agents to prevent LLM memory loss and illusion problems.
