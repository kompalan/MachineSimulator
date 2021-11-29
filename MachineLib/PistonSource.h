/**
 * @file PistonSource.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_PISTONSOURCE_H
#define CANADIANEXPERIENCE_PISTONSOURCE_H

#include "RodEndSink.h"
#include "Rod.h"
#include "PistonSink.h"

/**
 * Class Representing a Piston Source
 */
class PistonSource {
private:
    /// Sinks associated with this source
    std::vector<PistonSink *> mSinks;

public:
    PistonSource();

    /// Copy constructor (disabled)
    PistonSource(const PistonSource &) = delete;

    /// Assignment operator
    void operator=(const PistonSource &) = delete;

    void UpdateSinks(Rod* rod);
    void AddSink(PistonSink* sink);
};

#endif //CANADIANEXPERIENCE_PISTONSOURCE_H
