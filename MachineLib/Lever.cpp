/**
 * @file Lever.cpp
 * @author Anurag Kompalli
 */

#include "Lever.h"
#include "Rod.h"

/**
 * Constructor
 */
Lever::Lever()
{
    mSink = std::make_shared<LeverEndSink>(this);
    mRotationSource = std::make_shared<RotationSource>();

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

void Lever::Update()
{
    Rod* rod = mSink->GetRod();
    wxPoint rodPos = rod->GetAbsolutePosition();
    wxPoint leverPos = GetAbsolutePosition();

    double a = 200;
    double b = rod->GetLength();

    double squaredY = pow((leverPos.y - rodPos.y), 2);
    double squaredX = pow((leverPos.x - rodPos.x), 2);

    double c = sqrt(squaredY + squaredX);

    double delta = atan2(-(leverPos.y - rodPos.y), (leverPos.x - rodPos.x));

    double numerator = (pow(b, 2)) + (pow(c, 2)) - (pow(a, 2));
    double alpha = acos(((numerator)/ (2*b*c)));

    double theta = delta - alpha;

    double rotations = theta / (2 * M_PI);
    rod->SetRotation(-rotations - 0.01);

    double x3 = rodPos.x + (b * cos(-theta));
    double y3 = rodPos.y + (b * sin(-theta));

    double phi = atan2((y3 - leverPos.y), (x3 - leverPos.x));
    double leverRotations = phi / (2*M_PI);
    SetRotation(leverRotations + 0.01);

    mRotationSource->UpdateSinks(leverRotations+0.01);
}

