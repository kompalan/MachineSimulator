/**
 * @file Arm.cpp
 * @author Anurag Kompalli
 */

#include "Arm.h"

Arm::Arm() : Component()
{
    mSink = std::make_shared<RotationSink>(this);

    Rectangle(0, 10, 100, 20);
}

void Arm::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    SetImage(L"images/arm1.png");
    SetRotation(mSink->GetRotation());
    DrawPolygon(graphics, GetMachinePosition().x + 50, GetMachinePosition().y - 50);
}


void Arm::Update()
{

}

