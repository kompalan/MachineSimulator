/**
 * @file RotationSource.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "RotationSource.h"

/**
 * Constructor
 */
RotationSource::RotationSource()
{

}

/**
 * Update all sinks with the current rotation
 * @param rotation Rotation to update sinks with
 */
void RotationSource::UpdateSinks(double rotation)
{
    for(auto sink : mSinks)
    {
        sink->UpdateRotation(rotation);
    }
}

/**
 * Add a Rotation sink to the source
 * @param sink RotationSink object to add
 */
void RotationSource::AddSink(RotationSink* sink)
{
    mSinks.push_back(sink);

}
