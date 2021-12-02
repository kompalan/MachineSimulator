/**
 * @file Piston.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "Piston.h"
#include "Rod.h"
#include <cmath>

/**
 * Constructor
 * @param imagePath Path to Piston Image
 */
Piston::Piston(const std::wstring &imagePath)
{
    mSink = std::make_shared<PistonSink>(this);
    mImagePath = imagePath;
    Rectangle(-25, -10, 50, 100);
}

/**
 * Draw function. Draws an image of a piston
 * to the screen
 * @param graphics wxGraphics object
 */
void Piston::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    SetImage(mImagePath);
    Component::Draw(graphics);
}

/**
 * Updates the Piston Y position and Rod Angle based
 * on Lever Position and Angle
 */
void Piston::Update()
{
    Rod* rod = mSink->GetRod();
    auto position = rod->GetAbsolutePosition();

    double diffX = abs(GetAbsolutePosition().x - position.x);

    double alpha = asin((diffX)/(rod->GetLength()));

    double beta = (M_PI/2) - alpha;

    double rotations = (beta / (2 * M_PI));
    rod->SetRotation(rotations);

    double yPos = rod->GetLength() * sin(beta);
    SetPositionOffset(wxPoint(GetPositionOffset().x, rod->GetPositionOffset().y - yPos - 100));
}
