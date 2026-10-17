//report meaningful errors instead of crashing.
#pragma once
#include <stdexcept>
#include <string>

namespace emu {

enum class ErrorKind {
    InvalidMemoryAddress,
    InvalidOpcode,
    UnsupportedInstruction,
    InvalidEncoding,
    IncompleteInstruction,
    NoHandler,          // dispatch table has no handler for the mnemonic
    StackOverflow,      // for W2
    StackUnderflow,     // for W2
    DivideByZero,       // for W2
    InvalidControlFlow  // for W2
};

class EmuError : public std::runtime_error {
public:
    EmuError(ErrorKind kind, const std::string& message)
        : std::runtime_error(message), kind_(kind) {}
    ErrorKind kind() const { return kind_; }

private:
    ErrorKind kind_;
};

}  // namespace emu
