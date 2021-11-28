/**
 * @file LeverEndSink.cpp
 * @author Anurag Kompalli
 */

#include "LeverEndSink.h"

LeverEndSink::LeverEndSink(Component* dependency) : mDependentComponent(dependency)
{

}

void LeverEndSink::UpdateRod(Rod* rod)
{
    mRod = rod;
    mDependentComponent->Update();
}


