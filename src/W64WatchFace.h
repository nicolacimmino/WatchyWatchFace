#ifndef __WATCHY_WATCHFACE_H__
#define __WATCHY_WATCHFACE_H__

#include <Watchy.h>
#include "C64_Pro_Mono_STYLE18pt7b.h"
#include "C64_Pro_Mono_STYLE6pt7b.h"
#include "icons.h"

class W64WatchFace : public Watchy
{
public:
    void drawWatchFace();
    void drawTime();
    void drawDate();    
};

#endif
