// ================================================
// states.cpp.c
// Created by Yaowei Lei on 2021/4/5.
// ================================================

#include "states.h"

States::States() {
    for(int i = 0; i != LASTSTATE; i++) {
        states[static_cast<ObjectState>(i)] = false;
    }
}

bool States::checkState(ObjectState state) const {
    for (auto iter : states) {
        if (iter.first == state) {
            return iter.second;
        }
    }
    return false;
}

void States::enableState(ObjectState state) {
    states[state] = true;
}

void States::disableState(ObjectState state) {
    states[state] = false;
}