/**
 * @file LeverEndSink.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_LEVERENDSINK_H
#define CANADIANEXPERIENCE_LEVERENDSINK_H

#include "Component.h"

class Rod;

class LeverEndSink {
private:
    /// Component Sink is Tied To
    Component* mDependentComponent;

    /// Rod object for negotiation
    Rod* mRod;

public:
    /// Default Constructor (disabled);
    LeverEndSink() = delete;

    /// Copy constructor (disabled)
    LeverEndSink(const LeverEndSink &) = delete;

    /// Assignment operator
    void operator=(const LeverEndSink &) = delete;

    LeverEndSink(Component* dependency);

    Rod* GetRod() const { return mRod; }

    void UpdateRod(Rod* rod);
};

#endif //CANADIANEXPERIENCE_LEVERENDSINK_H
