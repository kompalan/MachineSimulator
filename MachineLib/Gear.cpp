/**
 * @file Gear.cpp
 * @author Anurag Kompalli
 */

#include "Gear.h"

const double ToothDepth = 5;     ///< Depth of a tooth in pixels
const double ToothWidth = 0.33;  ///< Width of a tooth at the top as fraction of tooth pitch
const double ToothSlope = 0.1;   ///< Fraction of pitch where the tooth slopes up or down
const double PI2 = M_PI * 2;

Gear::Gear(int teeth, int outerRadius, int innerRadius, wxColor color)
{
    mTeeth = teeth;
    mOuterRadius = outerRadius;
    mInnerRadius = innerRadius;
    mColor = color;
    mSink = std::make_shared<RotationSink>(this);
    mSource = std::make_shared<RotationSource>();
}

void Gear::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    // Where the tooth starts in the arc
    double toothStart = 1.0 - ToothWidth - ToothSlope * 2;

    for (int t = 0; t < mTeeth; t++)
    {
        double angle1 = double(t) / double(mTeeth) * PI2;
        double angle2 = double(t + toothStart) / double(mTeeth) * PI2;
        double angle3 = double(t + toothStart + ToothSlope) / double(mTeeth) * PI2;
        double angle4 = double(t + toothStart + ToothSlope + ToothWidth) / double(mTeeth) * PI2;
        double angle5 = double(t + toothStart + ToothSlope * 2 + ToothWidth) / double(mTeeth) * PI2;

        GetBaseDrawing()->AddPoint(mInnerRadius * cos(angle1), mInnerRadius * sin(angle1));
        GetBaseDrawing()->AddPoint(mInnerRadius * cos(angle2), mInnerRadius * sin(angle2));
        GetBaseDrawing()->AddPoint(mOuterRadius * cos(angle3), mOuterRadius * sin(angle3));
        GetBaseDrawing()->AddPoint(mOuterRadius * cos(angle4), mOuterRadius * sin(angle4));
        GetBaseDrawing()->AddPoint(mInnerRadius * cos(angle5), mInnerRadius * sin(angle5));
    }

    GetBaseDrawing()->SetColor(mColor);
    GetBaseDrawing()->SetRotation(mGearRotation + mPhase);
    GetBaseDrawing()->DrawPolygon(graphics, GetPosition().x + mTempPos.x, GetPosition().y - mTempPos.y);
}

void Gear::Update()
{
    mSource->UpdateSinks(mSink->GetRotation());

    if(mSink != nullptr)
    {
        mGearRotation = (mSink->GetRotation());
    }

    Drive();
}

void Gear::AddGear(Gear* gear)
{
    mGears.push_back(gear);
}

void Gear::Drive()
{
    for(auto gear : mGears)
    {
        auto num = -((GetRotation() * (GetNumTeeth() / gear->GetNumTeeth()))) + GetPhase();
        gear->SetRotation(num);
    }
}

