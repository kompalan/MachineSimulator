/**
 * @file RotationSink.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSINK_H
#define CANADIANEXPERIENCE_ROTATIONSINK_H

#include "Component.h"

/**
 * Class Representing a RotationSink Object
 */
class RotationSink {
private:
    /// Rotation of the Source
    double mRotation = 0;

    /// Component tht this sink is tied to
    Component* mDependentComponent;

public:
    /// Default Constructor (disabled);
    RotationSink() = delete;

    /// Copy constructor (disabled)
    RotationSink(const RotationSink &) = delete;

    /// Assignment operator
    void operator=(const RotationSink &) = delete;

    RotationSink(Component* dependency);
    void UpdateRotation(double rotation);

    /**
     * Gets the rotation
     * @return Rotation
     */
    double GetRotation() const { return mRotation; }
};

#endif //CANADIANEXPERIENCE_ROTATIONSINK_H
