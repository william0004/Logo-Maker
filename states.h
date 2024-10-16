// ================================================
// states.h
// Created by Yaowei Lei on 2021/4/5.
// ================================================

#ifndef SFML_PROJECTS_STATES_H
#define SFML_PROJECTS_STATES_H

#include <map>

enum ObjectState{
    HIDDEN,
    HIGHLIGHTED,
    ENABLED,
    HIDEBARBOX,
    TOGGLE,
    MOVABLE,
    UNLOCK,
    ///This should always be the last state
    LASTSTATE
};

class States {
private:
    std::map<ObjectState, bool> states;

public:
    States();
    bool checkState(ObjectState) const;
    void enableState(ObjectState);
    void disableState(ObjectState);

};

#endif //SFML_PROJECTS_STATES_H
