/**
 * @file LeverEndSource.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "LeverEndSource.h"

/**
 * Constructor
 */
LeverEndSource::LeverEndSource()
{

}

/**
 * Iterate the sinks and pass the Updated Rod obect to them
 * @param rod Rod object from source
 */
void LeverEndSource::UpdateSinks(Rod* rod)
{
    for(auto sink : mSinks)
    {
        sink->UpdateRod(rod);
    }
}

/**
 * Add a sink to this source
 * @param sink LeverEndSink object
 */
void LeverEndSource::AddSink(LeverEndSink* sink)
{
    mSinks.push_back(sink);
}
