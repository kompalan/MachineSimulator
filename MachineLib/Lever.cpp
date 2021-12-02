/**
 * @file Lever.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "Lever.h"
#include "Rod.h"

/// Rotation correction because the edge of the rectangle is
/// not the edge of the lever
const double RotationCorrection = 0.015;

/// Position offset between edge of rectangle and edge of lever
const double PositionOffset = 10;

/**
 * Constructor
 * @param length Length of Lever
 * @param imagePath Path to Lever Image
 */
Lever::Lever(double length, const std::wstring &imagePath)
{
    mLength = length;
    mSink = std::make_shared<LeverEndSink>(this);
    mRotationSource = std::make_shared<RotationSource>();
    mRodSource = std::make_shared<RodEndSource>();
    mImagePath = imagePath;

    Rectangle(-mLength/2, 25, mLength, 50);
}

/**
 * Draw Function. Draws the lever with the proper rotation
 * and positioning
 * @param graphics wxGraphics object
 */
void Lever::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    SetImage(mImagePath);
    Component::Draw(graphics);
}

/**
 * Update function. Takes the Sinks rod object
 * and does negotiation calculations to figure out the rotation
 * of the rod and the lever.
 */
void Lever::Update()
{
    // For figure pertaining to this calculation: refer to
    // https://facweb.cse.msu.edu/cbowen/cse335/project2-fs21/lever.php

    Rod* rod = mSink->GetRod();
    wxPoint rodPos = rod->GetAbsolutePosition();
    wxPoint leverPos = GetAbsolutePosition();

    double a = mLength/2;
    double b = rod->GetLength();

    double squaredY = pow((leverPos.y - rodPos.y), 2);
    double squaredX = pow((leverPos.x - rodPos.x), 2);

    double c = sqrt(squaredY + squaredX);

    // calculate delta, which is the arm horizontal to vector
    // pointing to middle of lever angle
    double delta = atan2(-(leverPos.y - rodPos.y), (leverPos.x - rodPos.x));

    double numerator = (pow(b, 2)) + (pow(c, 2)) - (pow(a, 2));

    // calculate alpha, which is the angle between the rod and the
    // vector pointing to the middle of lever
    double alpha = acos(((numerator)/ (2*b*c)));

    // Therefore, the amount we need to rotate is the difference
    double theta = delta - alpha;

    // Convert to rotations
    double rotations = (-theta / (2 * M_PI)) - RotationCorrection;
    rod->SetRotation(rotations);

    // Get the end of the lever based on theta
    double x3 = (rodPos.x) + (b * cos(-theta));
    double y3 = (rodPos.y) + (b * sin(-theta));

    // Use x3 and y3 to calculate how much the lever should rotate
    double phi = atan2((y3 - (leverPos.y)), (x3 - (leverPos.x)));
    double leverRotations = phi / (2 * M_PI);
    SetRotation(leverRotations);

    mRotationSource->UpdateSinks(leverRotations);

    // Use this new information about phi to calculate the other
    // end of the lever
    double rodConnectionX = ((leverPos.x) - (a * cos(-phi))) + PositionOffset;
    double rodConnectionY = ((leverPos.y) - (a * sin(phi)));

    mRodSource->UpdateSinks(wxPoint(rodConnectionX, rodConnectionY));
}

