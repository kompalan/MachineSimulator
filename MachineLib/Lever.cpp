/**
 * @file Lever.cpp
 * @author Anurag Kompalli
 */

#include "Lever.h"


Lever::Lever()
{
    Rectangle(-200, 0, 400, 50);
}

void Lever::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    SetImage(L"images/lever.png");
    Component::Draw(graphics);
}

