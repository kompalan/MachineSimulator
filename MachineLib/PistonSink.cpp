/**
 * @file PistonSink.cpp
 * @author Anurag Kompalli
 */

#include "PistonSink.h"

/**
 * Constructor
 * @param dependency Component this sink is tied to
 */
PistonSink::PistonSink(Component* dependency) : mDependentComponent(dependency)
{

}

/**
 * Updates the rod object and calls update
 * on the dependency
 * @param rod Rod object
 */
void PistonSink::UpdateRod(Rod* rod)
{
    mRod = rod;
    mDependentComponent->Update();
}