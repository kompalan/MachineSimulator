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
    void UpdateSinks(double rotation);
    void AddSink(RotationSink* sink);
};

#endif //CANADIANEXPERIENCE_ROTATIONSOURCE_H
