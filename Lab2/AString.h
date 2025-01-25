#pragma once
#include <string>

class AString {
public:
    virtual ~AString() {}
    virtual const std::string& GetName() const = 0;
    virtual const std::string& GetVal() const = 0;
    virtual AString* operator-(const AString& other) const = 0;
    virtual void Show() const = 0;
};

