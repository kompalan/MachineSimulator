/**
 * @file Motor.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "Motor.h"

const static double BasicRotorRadius = 15;
const static double RotorOffset = 50;

Motor::Motor() : Component()
{
    mSource = std::make_shared<RotationSource>();

    mBackground = std::make_shared<Polygon>();
    mBackground->Rectangle(0, 0, 100, 100);

    double angle;
    for (int i = 1; i < 30; i++)
    {
        angle = double(i) / 30 * M_PI * 2;
        AddPoint(BasicRotorRadius * cos(angle),
                BasicRotorRadius * sin(angle));
    }

    AddPoint(0.0, BasicRotorRadius * sin(angle));
    AddPoint(0.0, -BasicRotorRadius * sin(angle));

}

void Motor::Update()
{
    mSource->UpdateSinks(mRotation);
}

void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mBackground->SetColor(*wxBLACK);
    mBackground->DrawPolygon(graphics, GetMachinePosition().x, GetMachinePosition().y);

    SetColor(*wxRED);
    SetRotation(mRotation);
    DrawPolygon(graphics, GetMachinePosition().x + RotorOffset, GetMachinePosition().y - RotorOffset);
}

void Motor::UpdateMachine(double time)
{
    mRotation = time * mSpeed;
    Update();
}

