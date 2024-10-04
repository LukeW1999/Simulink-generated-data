
#include "Fg333saCheck.h"
int main() {
    // Initialize variables
    Fg333saCheck pIp;

    uint8_t buffer[19];
    pIp.buffer = &buffer[0];

    int32_t cntLenRd_old = pIp.cntLenRd;
    int32_t totalLenRd_old = pIp.totalLenRd;

    // Preconditions
    __CPROVER_assume(pIp.rdLen != 19);

    // Call the IP interface to be verified
    Fg333saCheckFun(&pIp);

    // Postconditions
    __CPROVER_assert(pIp.bComSuc == 0,"");
    __CPROVER_assert(pIp.cntLenRd == cntLenRd_old + 1,"");
    __CPROVER_assert(pIp.totalLenRd == totalLenRd_old + 1,"");

    return 0;
}
