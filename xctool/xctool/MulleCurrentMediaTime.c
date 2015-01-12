//
//  MulleCurrentMediaTime.c
//  xctool
//
//  Created by Nat! on 12/01/15.
//  Copyright (c) 2015 Facebook, Inc. All rights reserved.
//

#include "MulleCurrentMediaTime.h"

#include <stdint.h>
#include <mach/mach_time.h>

//
// adapted from: https://developer.apple.com/library/mac/qa/qa1398/_index.html
//
static mach_timebase_info_data_t    sTimebaseInfo;


double  MulleCurrentMediaTime(void)
{
    uint64_t   ticks;
    double      ns;

    if( ! sTimebaseInfo.denom)
      mach_timebase_info( &sTimebaseInfo);

    ticks = mach_absolute_time();
    ns    = (double) ticks * sTimebaseInfo.numer / sTimebaseInfo.denom;

    return( ns / 1000000000.0);
}
