// ================================================
// snapshotInterface.h
// Created by Yaowei Lei on 2021/4/5.
// ================================================

#ifndef SFML_PROJECTS_SNAPSHOTINTERFACE_H
#define SFML_PROJECTS_SNAPSHOTINTERFACE_H

#include "snapshot.h"

template <class T>
class SnapshotInterface {
public:

// this function will return a snapshot of the object's current state
    virtual Snapshot<T>& getSnapshot() = 0;

// this function will apply a snapshot to the object.
//This will revert the object back to the state that has been recorded in the snapshot
    virtual void applySnapshot(const Snapshot<T>& snapshot) = 0;
};

#endif //SFML_PROJECTS_SNAPSHOTINTERFACE_H

