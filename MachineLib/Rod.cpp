/**
 * @file Rod.cpp
 * @author Anurag Kompalli
 */

#include "Rod.h"

/**
 * Constructor
 * @param length Length of the Rod
 */
Rod::Rod(double length)
{
    mLength = length;
    mSink = std::make_shared<RodEndSink>(this);

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

    DrawPolygon(graphics, position.x, position.y);
}
