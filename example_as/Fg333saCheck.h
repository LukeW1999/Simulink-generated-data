/* Fg333saCheck.h - Header file */
#ifndef FG333SA_CHECK_H
#define FG333SA_CHECK_H

#include <stdint.h> // For uint8_t, uint32_t, etc.

// Structure definition for Fg333saCheck
typedef struct {
    uint8_t *buffer;      // Input string buffer
    uint32_t rdLen;       // Length of the input string buffer
    uint32_t frm;         // Frame count
    uint32_t bComSuc;     // Flag indicates whether the validation succeeded
    int32_t cntLenRd;     // Continuous read length error count
    int32_t cntHead;      // Continuous frame header error count
    int32_t cntCheck;     // Continuous check error count
    int32_t cntUpdata;    // Continuous data update error count
    int32_t totalLenRd;   // Total read length error count
    int32_t totalHead;    // Total frame header error count
    int32_t totalCheck;   // Total check error count
    int32_t totalUpdata;  // Total data update error count
} Fg333saCheck;

// Function prototype
extern void Fg333saCheckFun(Fg333saCheck *is);

#endif // FG333SA_CHECK_H
