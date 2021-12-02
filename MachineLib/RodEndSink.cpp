/**
 * @file RodEndSink.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "RodEndSink.h"

/**
 * Constructor
 * @param dependency Component that is tied to this sink
 */
RodEndSink::RodEndSink(Component* dependency) : mDependentComponent(dependency)
{
}

/**
 * Set the current position
 * @param position Position to set
 */
void RodEndSink::UpdatePosition(wxPoint position)
{
    mPosition = position;
    mDependentComponent->Update();
}


