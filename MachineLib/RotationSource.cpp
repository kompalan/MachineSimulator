/**
 * @file RotationSource.cpp
 * @author Anurag Kompalli
 */

#include "RotationSource.h"

void RotationSource::UpdateSinks(double rotation)
{
    for(auto sink : mSinks)
    {
        sink->UpdateRotation(rotation);
    }
}

void RotationSource::AddSink(RotationSink* sink)
{
    mSinks.push_back(sink);

}
