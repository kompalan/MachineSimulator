/**
 * @file Piston.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "Piston.h"

/**
 * Constructor
 */
Piston::Piston()
{
    Rectangle(-10, 0, 50, 100);
}

/**
 * Draw function. Draws an image of a piston
 * to the screen
 * @param graphics wxGraphics object
 */
void Piston::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    SetImage(L"images/piston.png");
    Component::Draw(graphics);
}