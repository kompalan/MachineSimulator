/**
 * @file PistonSink.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_PISTONSINK_H
#define CANADIANEXPERIENCE_PISTONSINK_H

#include "Component.h"

class Rod;

/**
 * Class Representing a Piston Sink
 */
class PistonSink {
private:
    /// Rod object
    Rod* mRod;

    /// Component Sink is Tied To
    Component* mDependentComponent;

public:
    /// Default Constructor (disabled);
    PistonSink() = delete;

    /// Copy constructor (disabled)
    PistonSink(const PistonSink &) = delete;

    /// Assignment operator
    void operator=(const PistonSink &) = delete;

    PistonSink(Component* dependency);

    void UpdateRod(Rod* rod);

    /**
     * Get the Position
     * @return Position as wxPoint
     */
    Rod* GetRod() const { return mRod; }
};

#endif //CANADIANEXPERIENCE_PISTONSINK_H
