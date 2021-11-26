/**
 * @file Arm.cpp
 * @author Anurag Kompalli
 */

#include "Arm.h"

/**
 * Constructor
 * @param length Length of Arm
 */
Arm::Arm(double length) : Component()
{
    mSink = std::make_shared<RotationSink>(this);
    mLength = length;
    mSource = std::make_shared<RodEndSource>();

    Rectangle(0, 10, mLength, 20);
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
}

/**
 * Update function
 */
void Arm::Update()
{
    double x = (GetMachinePosition().x + GetPositionOffset().x) + (mLength-10) * cos(mSink->GetRotation() * M_PI * 2);
    double y = (GetMachinePosition().y - GetPositionOffset().y) + (mLength-10) * sin(mSink->GetRotation() * M_PI * 2);
    mSource->UpdateSinks(wxPoint((int)x, (int)y));
}

