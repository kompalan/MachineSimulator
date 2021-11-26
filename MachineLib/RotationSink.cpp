/**
 * @file RotationSink.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "RotationSink.h"

void RotationSink::UpdateRotation(double rotation)
{
    mRotation = rotation;
    mDependentComponent->Update();
}

RotationSink::RotationSink(Component* dependency) : mDependentComponent(dependency)
{

}
