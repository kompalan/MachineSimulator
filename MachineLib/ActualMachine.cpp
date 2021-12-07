/**
 * @file ActualMachine.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "ActualMachine.h"
#include "Motor.h"
#include "Component.h"

/**
 * Constructor
 */
ActualMachine::ActualMachine()
{
    mMotor = std::make_shared<Motor>();
    mTime = 0;
}

/**
 * Loops over the components in order.
 * Calls each draw function
 * @param graphics wxGraphicsContext Object
 */
void ActualMachine::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    for(auto component : mComponents)
    {
        component->Draw(graphics);
    }
}

/**
 * Sets the Absolute Location of the Machine
 * @param location wxPoint with the location
 */
void ActualMachine::SetLocation(wxPoint location)
{
    mLocation = location;
}

/**
 * Sets the current frame of the Machine
 * @param frame Frame that we are on
 */
void ActualMachine::SetMachineFrame(int frame)
{
    mCurrentFrame = fmax(0, frame);
    mTime = mCurrentFrame / mFrameRate;
    mMotor->UpdateMachine(mTime);
}

/**
 * Sets the Framerate of the Machine
 * @param rate Rate to set
 */
void ActualMachine::SetFrameRate(double rate)
{
    mFrameRate = rate;
}

/**
 * Sets the Motor Speed
 * @param speed Speed of the Motor
 */
void ActualMachine::SetSpeed(double speed)
{
    /// TODO: This might need to be changed to machine speed
    mMotor->SetSpeed(speed);
}

/**
 * Getter for the Machine Time
 * @return Machine Time
 */
double ActualMachine::GetMachineTime()
{
    return mTime;
}

/**
 * Adds a component to the components list to be drawn
 * @param component Component object to add
 */
void ActualMachine::AddComponent(std::shared_ptr<Component> component)
{
    mComponents.push_back(component);
    component->SetMachine(this);
}










