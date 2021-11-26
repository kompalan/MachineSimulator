/**
 * @file Arm.cpp
 * @author Anurag Kompalli
 */

#include "Arm.h"

/**
 * Constructor
 */
Arm::Arm() : Component()
{
    mSink = std::make_shared<RotationSink>(this);

    Rectangle(0, 10, 100, 20);
}

/**
 * Draws the Arm to the screen and rotates it based
 * on sink information
 * @param graphics wxGraphics Object
 */
void Arm::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    SetImage(L"images/arm1.png");
    SetRotation(mSink->GetRotation());
    Component::Draw(graphics);
    //DrawPolygon(graphics, GetMachinePosition().x + 50, GetMachinePosition().y - 50);
}

/**
 * Update function
 */
void Arm::Update()
{

}

