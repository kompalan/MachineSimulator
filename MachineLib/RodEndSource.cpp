/**
 * @file RodEndSource.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "RodEndSource.h"

/**
 * Constructor
 */
RodEndSource::RodEndSource()
{

}

/**
 * Add A Sink to this Source
 * @param sink Sink to add
 */
void RodEndSource::AddSink(RodEndSink* sink)
{
    mSinks.push_back(sink);
}

/**
 * Iterate through sinks and pass the position to them
 * @param point Position from Source
 */
void RodEndSource::UpdateSinks(wxPoint point)
{
    for(auto sink : mSinks)
    {
        sink->UpdatePosition(point);
    }
}

