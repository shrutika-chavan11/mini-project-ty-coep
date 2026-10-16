
#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

namespace emu {

class Memory {
public:
    static constexpr std::size_t kSize = 1u << 20;

    Memory() : data_(kSize, 0) {}

    void clear();

    uint8_t  read8(uint32_t physAddr) const;
    uint16_t read16(uint32_t physAddr) const;
    void     write8(uint32_t physAddr, uint8_t value);
    void     write16(uint32_t physAddr, uint16_t value);
    void loadBlock(uint32_t physAddr, const uint8_t* bytes, std::size_t length);

private:
    void check(uint32_t physAddr, std::size_t length) const;
    std::vector<uint8_t> data_;
};

}  // namespace emu
