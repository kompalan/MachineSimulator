/**
 * @file PistonSource.cpp
 * @author Anurag Kompalli
 */

#include "PistonSource.h"
#include "PistonSink.h"

/**
 * Constructor
 */
PistonSource::PistonSource()
{

}

/**
 * Iterate through sinks and update with the
 * new rod object
 * @param rod Rod object from source
 */
void PistonSource::UpdateSinks(Rod* rod)
{
    for(auto sink : mSinks)
    {
        sink->UpdateRod(rod);
    }
}

/**
 * Add a sink to this source
 * @param sink PistonSink object
 */
void PistonSource::AddSink(PistonSink* sink)
{
    mSinks.push_back(sink);
}

