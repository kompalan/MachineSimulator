/**
 * @file CustomMachine.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "CustomMachine.h"
#include "MachineAFactory.h"
#include "MachineBFactory.h"

/// Base Directory for all Images
static const std::wstring imagesDir = L"/resources/images";

/**
 * Constructor. Creates a Machine A and
 * Sets it to the current machine
 */
CustomMachine::CustomMachine() : Machine()
{
    MachineAFactory machineA(imagesDir);
    mMachine = machineA.Create();
}

/**
 * Sets the Machine Number and Creates the
 * corresponding machine
 * @param machine Machine number
 */
void CustomMachine::SetMachineNumber(int machine)
{
    mMachineNumber = machine;

    switch(mMachineNumber)
    {
        case 0:
        {
            MachineAFactory machineA(imagesDir);
            mMachine = machineA.Create();
            break;
        }
        case 1:
        {
            MachineBFactory machineB(imagesDir);
            mMachine = machineB.Create();
            break;
        }
        default:
        {
            MachineAFactory machineDefault(imagesDir);
            mMachine = machineDefault.Create();
            break;
        }
    }
}

/**
 * Gets the current machine number
 * @return Machine Number
 */
int CustomMachine::GetMachineNumber()
{
    return mMachineNumber;
}

/**
 * Draws the current Machine
 * @param graphics wxGraphicsContext Object
 */
void CustomMachine::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mMachine->DrawMachine(graphics);
}

/**
 * Sets the location
 * @param location wxPoint object with the location
 */
void CustomMachine::SetLocation(wxPoint location)
{
    mMachine->SetLocation(location);
}

/**
 * Sets the Current Frame
 * @param frame Frame number
 */
void CustomMachine::SetMachineFrame(int frame)
{
    mMachine->SetMachineFrame(frame);
}

/**
 * Sets the frame rate
 * @param rate frame rate
 */
void CustomMachine::SetFrameRate(double rate)
{
    mMachine->SetFrameRate(rate);
}

/**
 * Set the speed of the machine
 * @param speed Machine Speed
 */
void CustomMachine::SetSpeed(double speed)
{
    mMachine->SetSpeed(speed);
}

/**
 * Gets the Current Time of the Machine
 * @return Machine Time
 */
double CustomMachine::GetMachineTime()
{
    return mMachine->GetMachineTime();
}

/**
 * Gets the Current Location of the Machine
 * @return wxPoint with the current location
 */
wxPoint CustomMachine::GetLocation()
{
    return mMachine->GetLocation();
}










