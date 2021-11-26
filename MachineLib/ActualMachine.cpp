/**
 * @file ActualMachine.cpp
 * @author Anurag Kompalli
 */

#include <sstream>
#include "ActualMachine.h"
#include "Motor.h"
#include "Component.h"

ActualMachine::ActualMachine()
{
    mMotor = std::make_shared<Motor>();
}

void ActualMachine::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    for(auto component : mComponents)
    {
        component->Draw(graphics);
    }
}

void ActualMachine::SetLocation(wxPoint location)
{
    mLocation = location;
}

void ActualMachine::SetMachineFrame(int frame)
{
    mCurrentFrame = frame;
    mTime = mCurrentFrame / mFrameRate;
    mMotor->UpdateMachine(mTime);
}

void ActualMachine::SetFrameRate(double rate)
{
    mFrameRate = rate;
}

void ActualMachine::SetSpeed(double speed)
{
    mMotor->SetSpeed(speed);
}

/**
 * Getter for the Machine Time
 * @return
 */
double ActualMachine::GetMachineTime()
{
    return mTime;
}

void ActualMachine::AddComponent(std::shared_ptr<Component> component)
{
    mComponents.push_back(component);
    component->SetMachine(this);
}










