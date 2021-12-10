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
 * @param position Position to put the Machine
 */
MachineDrawable::MachineDrawable(const std::wstring &name, const std::wstring &filename, wxPoint position) : Drawable(name)
{
    mPosition = position;
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
    mMachine->SetLocation(mPosition);
    mMachine->DrawMachine(graphics);
    graphics->PopState();
}

/**
 * Set the Machine Frame
 * @param frame Frame to set
 */
void MachineDrawable::SetFrame(int frame)
{
    mMachine->SetMachineFrame(frame - mMachineStartOffset);
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

/**
 * Set the Starting Offset for A Machine
 * @param offset Frame to offset by
 */
void MachineDrawable::SetStartOffset(int offset)
{
    mMachineStartOffset = offset;
}

/**
 * Get the Starting Offset for A Machine
 * @return Frames that this machine is offset by
 */
int MachineDrawable::GetStartOffset()
{
    return mMachineStartOffset;
}

/**
 * Starts the SetMachineNumber dialog
 * @param frame Parent window to start the dialog in
 */
void MachineDrawable::DoDialog(wxWindow* frame)
{
    MachineDialog dlg(frame, mMachine);
    if(dlg.ShowModal() == wxID_OK)
    {
        mMachine->SetFrameRate(30);
        mMachine->SetSpeed(1.0);
    }
}

/**
 * Get the Current Machine Number
 * @return Machine Number
 */
int MachineDrawable::GetMachineNumber()
{
    return mMachine->GetMachineNumber();
}

/**
 * Set the Machine Number
 * @param number Number to set
 */
void MachineDrawable::SetMachineNumber(int number)
{
    mMachine->SetMachineNumber(number);
    mMachine->SetFrameRate(30);
    mMachine->SetSpeed(1.0);
}
