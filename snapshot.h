// ================================================
// snapshot.h
// Created by Yaowei Lei on 2021/4/5.
// ================================================

#ifndef SFML_PROJECTS_SNAPSHOT_H
#define SFML_PROJECTS_SNAPSHOT_H

#include <SFML/Graphics.hpp>
#include "states.h"

template <class T>
class Snapshot {
private:
    T data;
    States state;
    std::string componentID;

public:
    const T &getData() const;

    void setData(const T &data);

    const States &getState() const;

    void setState(const States &state);

    const std::string &getComponentId() const;

    void setComponentId(const std::string &componentId);

    Snapshot();
};

#include "snapshot.cpp"

#endif //SFML_PROJECTS_SNAPSHOT_H
