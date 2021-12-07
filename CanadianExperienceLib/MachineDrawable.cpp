/**
 * @file MachineDrawable.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "MachineDrawable.h"
#include <machine-api.h>
#include "Timeline.h"

/**
 * Constructor
 * @param name Name of the Machine
 * @param filename Path to images
 */
MachineDrawable::MachineDrawable(const std::wstring &name, const std::wstring &filename) : Drawable(name)
{
    MachineFactory factory(filename);
    mMachine = factory.CreateMachine();
    mMachine->SetSpeed(1.0);
    mMachine->SetFrameRate(30);
    mMachine->SetMachineFrame(0);
}

/**
 * Set the Location at 900, 500 and draw the machine
 * @param graphics Graphics object
 */
void MachineDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();
    mMachine->SetLocation(wxPoint(900, 500));
    mMachine->DrawMachine(graphics);
    graphics->PopState();
}

/**
 * Set the Machine Frame
 * @param frame Frame to set
 */
void MachineDrawable::SetFrame(int frame)
{
    mMachine->SetMachineFrame(frame - 100);
}

/**
 * Dummy HitTest to return false
 * @param pos Position where mouse is at
 * @return False
 */
bool MachineDrawable::HitTest(wxPoint pos)
{
    return false;
}
