
#pragma once
#include <string>

#include "flags.hpp"
#include "memory.hpp"
#include "registers.hpp"
#include "segmentation.hpp"

namespace emu {

class CPUState {
public:
    CPUState() { reset(); }


    void reset();

    Registers regs;
    Flags     flags;
    Memory    memory;

 
    uint32_t physicalAddress(SegReg seg, uint16_t offset) const {
        return Segmentation::physical(regs.seg(seg), offset);
    }


    uint8_t  readByte(SegReg seg, uint16_t offset) const;
    uint16_t readWord(SegReg seg, uint16_t offset) const;
    void     writeByte(SegReg seg, uint16_t offset, uint8_t value);
    void     writeWord(SegReg seg, uint16_t offset, uint16_t value);


    void     push16(uint16_t value);  
    uint16_t pop16();                 

   
    std::string dump() const;
};

}  // namespace emu
