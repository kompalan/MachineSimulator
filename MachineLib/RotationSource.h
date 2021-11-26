/**
 * @file RotationSource.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSOURCE_H
#define CANADIANEXPERIENCE_ROTATIONSOURCE_H

#include "RotationSink.h"

class RotationSource {
private:
    std::vector<RotationSink *> mSinks;

public:
    RotationSource();

    /// Copy constructor (disabled)
    RotationSource(const RotationSource &) = delete;

    /// Assignment operator
    void operator=(const RotationSource &) = delete;

    void UpdateSinks(double rotation);
    void AddSink(RotationSink* sink);
};

#endif //CANADIANEXPERIENCE_ROTATIONSOURCE_H
