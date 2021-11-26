/**
 * @file CustomMachine.cpp
 * @author Anurag Kompalli
 */

#include "CustomMachine.h"
#include "MachineAFactory.h"

static const std::wstring imagesDir = L"/resources/images";

void CustomMachine::SetMachineNumber(int machine)
{
    mMachineNumber = machine;

    switch(machine) {
    case 1:
        MachineAFactory machineA(imagesDir);
        mMachine = machineA.Create();
        break;
    }
}

int CustomMachine::GetMachineNumber()
{
    return mMachineNumber;
}


void CustomMachine::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mMachine->DrawMachine(graphics);
}

void CustomMachine::SetLocation(wxPoint location)
{
    mMachine->SetLocation(location);
}

void CustomMachine::SetMachineFrame(int frame)
{
    mMachine->SetMachineFrame(frame);
}

void CustomMachine::SetFrameRate(double rate)
{
    mMachine->SetFrameRate(rate);
}

void CustomMachine::SetSpeed(double speed)
{
    mMachine->SetSpeed(speed);
}

double CustomMachine::GetMachineTime()
{
    return mMachine->GetMachineTime();
}

CustomMachine::CustomMachine() : Machine()
{
    MachineAFactory machineA(imagesDir);
    mMachine = machineA.Create();
}










