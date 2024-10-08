/* Copyright 2015-2024 The MathWorks, Inc. */

#ifndef SLTESTTYPES_H
#define SLTESTTYPES_H

#ifdef SUPPORTS_PRAGMA_ONCE
#pragma once
#endif

#include <stdbool.h>
typedef struct slTestBlkInfo {
    const char* blkPath;
    int blkId;
    void* targetSpecificInfo;
    const char* mdlRefFullPath;
    bool isRequirementsTable;
    bool logOnlyTestedVerifyResults;
} slTestBlkInfo_t;

#endif
