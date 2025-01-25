#pragma once

#include "AString.h"

class SymbString : public AString {
public:
    SymbString(const std::string& name, const std::string& val);
    const std::string& GetName() const override;
    const std::string& GetVal() const override;
    void Show() const override;
    AString* operator-(const AString& other) const override;

private:
    std::string name;
    std::string val;
};

