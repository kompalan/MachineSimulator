/**
 * @file Piston.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "Piston.h"

Piston::Piston()
{
    Rectangle(-10, 0, 50, 100);
}

void Piston::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    SetImage(L"images/piston.png");
    DrawPolygon(graphics, GetMachinePosition().x - 100, GetMachinePosition().y - 100);
}

void Piston::Update()
{
    Component::Update();
}
