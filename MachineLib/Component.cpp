/**
 * @file Component.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "Component.h"
#include "ActualMachine.h"

/**
 * Constructor
 */
Component::Component() : Polygon()
{
}

wxPoint Component::GetMachinePosition() const
{
    return mMachine->GetLocation();
}

wxPoint Component::GetPositionOffset() const
{
    return mPosition;
}

void Component::SetPositionOffset(wxPoint position)
{
    mPosition = position;
}


