/**
 * @file MachineDrawable.cpp
 * @author Anurag Kompalli
 */

#include "MachineDrawable.h"
#include <machine-api.h>
#include "Timeline.h"

MachineDrawable::MachineDrawable(const std::wstring &name, const std::wstring &filename) : Drawable(name)
{
    MachineFactory factory(filename);
    mMachine = factory.CreateMachine();
    mMachine->SetSpeed(1.0);
    mMachine->SetMachineFrame(0);
    mMachine->SetFrameRate(30);
}

void MachineDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();
    mMachine->SetLocation(wxPoint(900, 500));
    mMachine->DrawMachine(graphics);
    graphics->PopState();
}

void MachineDrawable::SetFrame(int frame)
{
    mMachine->SetMachineFrame(frame);
}

bool MachineDrawable::HitTest(wxPoint pos)
{
    return false;
}
