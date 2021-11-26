/**
 * @file RotationSink.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "RotationSink.h"



/**
 * Constructor
 * @param dependency Component that is connected to this sink
 */
RotationSink::RotationSink(Component* dependency) : mDependentComponent(dependency)
{

}


/**
 * Set the current Rotation and update the component
 * @param rotation Rotation to set
 */
void RotationSink::UpdateRotation(double rotation)
{
    mRotation = rotation;
    mDependentComponent->Update();
}
