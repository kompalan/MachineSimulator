/**
 * @file RotationSink.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSINK_H
#define CANADIANEXPERIENCE_ROTATIONSINK_H

#include "Component.h"

class RotationSink {
private:
    double mRotation = 0;
    Component* mDependentComponent;

public:
    /// Default Constructor (disabled);
    RotationSink() = delete;

    RotationSink(Component* dependency);
    void UpdateRotation(double rotation);

    double GetRotation() const { return mRotation; }
};

#endif //CANADIANEXPERIENCE_ROTATIONSINK_H
