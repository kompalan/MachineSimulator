/**
 * @file LeverEndSource.cpp
 * @author Anurag Kompalli
 */

#include "LeverEndSource.h"

LeverEndSource::LeverEndSource()
{

}

void LeverEndSource::UpdateSinks(Rod* rod)
{
    for(auto sink : mSinks)
    {
        sink->UpdateRod(rod);
    }
}

void LeverEndSource::AddSink(LeverEndSink* sink)
{
    mSinks.push_back(sink);
}
