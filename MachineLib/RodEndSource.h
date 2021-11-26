/**
 * @file RodEndSource.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_RODENDSOURCE_H
#define CANADIANEXPERIENCE_RODENDSOURCE_H

#include "RodEndSink.h"

/**
 * Class Representing a Component Driving a Rod
 */
class RodEndSource {
private:
    /// Sinks associated with this source
    std::vector<RodEndSink *> mSinks;

public:
    RodEndSource();

    /// Copy constructor (disabled)
    RodEndSource(const RodEndSource &) = delete;

    /// Assignment operator
    void operator=(const RodEndSource &) = delete;

    void UpdateSinks(wxPoint point);
    void AddSink(RodEndSink* sink);
};

#endif //CANADIANEXPERIENCE_RODENDSOURCE_H
