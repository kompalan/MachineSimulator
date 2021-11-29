/**
 * @file Rod.cpp
 * @author Anurag Kompalli
 */

#include "Rod.h"
#include "LeverEndSource.h"
#include "PistonSource.h"

/**
 * Constructor
 * @param length Length of the Rod
 */
Rod::Rod(double length)
{
    mLength = length;
    mSink = std::make_shared<RodEndSink>(this);
    mSource = std::make_shared<LeverEndSource>();
    mPistonSource = std::make_shared<PistonSource>();
    Rectangle(0, 5, mLength, 10);
}

/**
 * Draw the Rod, Get the Position from the Sink
 * @param graphics wxGraphics Object
 */
void Rod::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    SetColor(wxColor(128, 128, 128));
    auto position = mSink->GetPosition();
    SetPositionOffset(wxPoint(-(GetMachinePosition().x - position.x), GetMachinePosition().y - position.y));
    Component::Draw(graphics);
}

/**
 * Updates the sources with the Rod object
 */
void Rod::Update()
{
    mSource->UpdateSinks(this);
    mPistonSource->UpdateSinks(this);
}
