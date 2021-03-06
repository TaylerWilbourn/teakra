#pragma once

#include <functional>
#include "common_types.h"

namespace Teakra {

class Timer {
public:
    enum CountMode : u32 {
        Single = 0,
        AutoRestart = 1,
        FreeRunning = 2,
        EventCount = 3,
    };

    void Restart();
    void Tick();
    void TickEvent();

    std::function<void()> handler;

    u16 update_mmio = 0;
    u16 pause = 0;
    u16 count_mode = 0;
    u16 scale = 0;

    u16 start_high = 0;
    u16 start_low = 0;
    u32 counter = 0;
    u16 counter_high = 0;
    u16 counter_low = 0;

private:
    void UpdateMMIO();
};

} // namespace Teakra
