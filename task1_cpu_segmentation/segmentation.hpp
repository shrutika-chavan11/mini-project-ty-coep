
// 8086 real-mode address translation:
//
//        physical = (segment * 16 + offset)  &  0xFFFFF      (20-bit bus)

#pragma once
#include <cstdint>

namespace emu {

struct Segmentation {
    static constexpr uint32_t kAddressMask = 0xFFFFF;

    static constexpr uint32_t physical(uint16_t segment, uint16_t offset) {
        return ((static_cast<uint32_t>(segment) << 4) + offset) & kAddressMask;
    }
};

}  // namespace emu
