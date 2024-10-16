// ================================================
// snapshot.cpp.c
// Created by Yaowei Lei on 2021/4/5.
// ================================================

#ifndef SFML_PROJECTS_SNAPSHOT_CPP
#define SFML_PROJECTS_SNAPSHOT_CPP

#include "snapshot.h"

template <class T>
Snapshot<T>::Snapshot() { }

template <class T>
const T &Snapshot<T>::getData() const {
    return data;
}

template <class T>
void Snapshot<T>::setData(const T &data) {
    Snapshot<T>::data = data;
}

template <class T>
const States &Snapshot<T>::getState() const {
    return state;
}

template <class T>
void Snapshot<T>::setState(const States &state) {
    Snapshot<T>::state = state;
}

template <class T>
const std::string &Snapshot<T>::getComponentId() const {
    return componentID;
}

template <class T>
void Snapshot<T>::setComponentId(const std::string &componentId) {
    componentID = componentId;
}

#endif //SFML_PROJECTS_SNAPSHOT_CPP
