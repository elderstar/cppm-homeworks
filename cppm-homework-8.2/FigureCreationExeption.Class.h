#include <iostream>
#pragma once

class WrongShape : public std::domain_error
{
public:
    WrongShape(const char* reason);

    const char* reason;
    //const char* what() const override;
};