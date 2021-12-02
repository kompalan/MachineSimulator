/**
 * @file Arm.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "Arm.h"

/// Position Correction for Arm because rectangle does not
/// end at arm holder
const double ArmCorrection = 10;

/**
 * Constructor
 * @param length Length of Arm
 * @param imagePath Path to arm image
 */
Arm::Arm(double length, const std::wstring &imagePath) : Component()
{
    mSink = std::make_shared<RotationSink>(this);
    mLength = length;
    mSource = std::make_shared<RodEndSource>();
    mImagesPath = imagePath;

    Rectangle(-5, 10, mLength, 20);
}

/**
 * Draws the Arm to the screen and rotates it based
 * on sink information
 * @param graphics wxGraphics Object
 */
void Arm::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    SetImage(mImagesPath);
    SetRotation(mSink->GetRotation());
    Component::Draw(graphics);
}

/**
 * Update function
 */
void Arm::Update()
{
    // Get end of the Arm by finding the Absolute position + the length
    // and using cos and sin to get x and y components
    double x = GetAbsolutePosition().x + (mLength-ArmCorrection) * cos(mSink->GetRotation() * M_PI * 2);
    double y = GetAbsolutePosition().y + (mLength-ArmCorrection) * sin(mSink->GetRotation() * M_PI * 2);
    mSource->UpdateSinks(wxPoint((int)x, (int)y));
}

