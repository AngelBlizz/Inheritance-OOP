#include "BinString.h"
#include <iostream>
#include <bitset>

BinString::BinString(const std::string& name, const std::string& val)
    : name(name), val(val) {
}

const std::string& BinString::GetName() const {
    return name;
}

const std::string& BinString::GetVal() const {
    return val;
}

void BinString::Show() const {
    std::cout << "BinString: " << name << " = " << val << std::endl;
}

AString* BinString::operator-(const AString& other) const {
    const BinString* otherBin = dynamic_cast<const BinString*>(&other);
    if (otherBin) {
        int val1 = std::stoi(val, nullptr, 2);
        int val2 = std::stoi(otherBin->GetVal(), nullptr, 2);
        int result = val1 - val2;
        return new BinString(name, std::bitset<32>(result).to_string());
    }
    return nullptr;
}