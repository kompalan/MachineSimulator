/**
 * @file RodEndSink.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_RODENDSINK_H
#define CANADIANEXPERIENCE_RODENDSINK_H

#include "Component.h"

/**
 * Class Representing a Component Driven
 * by a Rod
 */
class RodEndSink {
private:
    /// Position of the Source
    wxPoint mPosition;

    /// Component Sink is Tied To
    Component* mDependentComponent;
public:
    /// Default Constructor (disabled);
    RodEndSink() = delete;

    /// Copy constructor (disabled)
    RodEndSink(const RodEndSink &) = delete;

    /// Assignment operator
    void operator=(const RodEndSink &) = delete;

    RodEndSink(Component* dependency);
    void UpdatePosition(wxPoint position);

    /**
     * Get the Position
     * @return Position as wxPoint
     */
    wxPoint GetPosition() const { return mPosition; }
};

#endif //CANADIANEXPERIENCE_RODENDSINK_H
