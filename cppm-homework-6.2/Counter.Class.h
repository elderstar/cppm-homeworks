#pragma once

class Counter
{
public:

    Counter(int value);
    Counter();

    ~Counter();

    int subtract();

    int add();

    int getVal();

private:

    int start_value;
};