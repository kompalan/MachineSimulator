/**
 * @file Lever.cpp
 * @author Anurag Kompalli
 */

#include "Lever.h"

/**
 * Constructor
 */
Lever::Lever()
{
    Rectangle(-200, 0, 400, 50);
}

/**
 * Draw Function. Draws the lever with the proper rotation
 * and positioning
 * @param graphics wxGraphics object
 */
void Lever::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    SetImage(L"images/lever.png");
    Component::Draw(graphics);
}

