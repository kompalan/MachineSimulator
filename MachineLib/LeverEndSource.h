/**
 * @file LeverEndSource.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_LEVERENDSOURCE_H
#define CANADIANEXPERIENCE_LEVERENDSOURCE_H

#include "LeverEndSink.h"
#include "Rod.h"

/**
 * Class representing a Lever Source
 */
class LeverEndSource {
private:
    /// Sinks associated with this source
    std::vector<LeverEndSink *> mSinks;

public:
    LeverEndSource();

    /// Copy constructor (disabled)
    LeverEndSource(const LeverEndSource &) = delete;

    /// Assignment operator
    void operator=(const LeverEndSource &) = delete;

    void UpdateSinks(Rod* rod);
    void AddSink(LeverEndSink* sink);
};

#endif //CANADIANEXPERIENCE_LEVERENDSOURCE_H
