#include "SymbString.h"
#include <iostream>
#include <algorithm>

SymbString::SymbString(const std::string& name, const std::string& val)
    : name(name), val(val) {
}

const std::string& SymbString::GetName() const {
    return name;
}

const std::string& SymbString::GetVal() const {
    return val;
}

void SymbString::Show() const {
    std::cout << "SymbString: " << name << " = " << val << std::endl;
}

AString* SymbString::operator-(const AString& other) const {
    const SymbString* otherSymb = dynamic_cast<const SymbString*>(&other);
    if (otherSymb) {
        std::string result = val;
        size_t pos = result.find(otherSymb->GetVal());
        if (pos != std::string::npos) {
            result.erase(pos, otherSymb->GetVal().length());
        }
        return new SymbString(name, result);
    }
    return nullptr;
}