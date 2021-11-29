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

/**
 * Gets the Root Position of the Machine
 * @return Machine Position
 */
wxPoint Component::GetMachinePosition() const
{
    return mMachine->GetLocation();
}

/**
 * Gets the offset for this particular component
 * @return wxPoint with Offset
 */
wxPoint Component::GetPositionOffset() const
{
    return mPosition;
}

/**
 * Sets the offset for this component
 * @param position wxPoint with offset
 */
void Component::SetPositionOffset(wxPoint position)
{
    mPosition = position;
}

/**
 * Draws the polygon at the root position offseted by Component Position
 * @param graphics
 */
void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    DrawPolygon(graphics, GetMachinePosition().x + mPosition.x, GetMachinePosition().y - mPosition.y);
}

/**
 * Get the absolute position of a component on the screen
 * @return wxPoint with position
 */
wxPoint Component::GetAbsolutePosition() const
{
    return wxPoint(GetMachinePosition().x + mPosition.x, GetMachinePosition().y - mPosition.y);
}


