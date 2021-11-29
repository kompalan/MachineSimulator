/**
 * @file LeverEndSink.cpp
 * @author Anurag Kompalli
 */

#include "LeverEndSink.h"

/**
 * Constructor
 * @param dependency Component that this sink is tied to
 */
LeverEndSink::LeverEndSink(Component* dependency) : mDependentComponent(dependency)
{

}

/**
 * Store the rod pointer and call update on the next object
 * @param rod Rod object
 */
void LeverEndSink::UpdateRod(Rod* rod)
{
    mRod = rod;
    mDependentComponent->Update();
}


