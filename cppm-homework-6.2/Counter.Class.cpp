#include "Counter.Class.h"

Counter::Counter(int value) {

    start_value = value;
};

Counter::Counter() {

    start_value = 0;
};

Counter::~Counter() {};

int Counter::subtract() {

    return --start_value;
}

int Counter::add() {

    return ++start_value;
}

int Counter::getVal() {

    return start_value;
}

int start_value = 0;