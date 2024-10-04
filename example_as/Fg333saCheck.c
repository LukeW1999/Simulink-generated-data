/* Fg333saCheck.c - Source file */
#include "Fg333saCheck.h"

// Function to calculate checksum (assumed to be implemented elsewhere)
extern uint8_t CheckSumAdd08(uint8_t *buffer, uint32_t length);

void Fg333saCheckFun(Fg333saCheck *is) {
    uint8_t chksum;
    is->bComSuc = 0; // FALSE
    
    if (is->rdLen == 19) {
        is->cntLenRd = 0;

        if (is->buffer[17] != (is->frm)) {
            is->cntUpdata = 0;
            is->frm = is->buffer[17];

            if ((is->buffer[0] == 0xAC) && (is->buffer[1] == 0x12)) {
                is->cntHead = 0;
                chksum = CheckSumAdd08(&is->buffer[0], 18);

                if (chksum == is->buffer[18]) {
                    is->cntCheck = 0;
                    is->bComSuc = 1; // TRUE
                } else {
                    is->cntCheck++;
                    is->totalCheck++;
                }
            } else {
                is->cntHead++;
                is->totalHead++;
            }
        } else {
            is->cntUpdata++;
            is->totalUpdata++;
        }
    } else {
        is->cntLenRd++;
        is->totalLenRd++;
    }

    return;
}
