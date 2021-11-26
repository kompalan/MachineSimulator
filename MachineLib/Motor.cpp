/**
 * @file Motor.cpp
 * @author Anurag Kompalli
 */

#include "Motor.h"

const static double BasicRotorRadius = 15;
const static double RotorOffset = 50;

Motor::Motor() : Component()
{
    mSource = std::make_shared<RotationSource>();

    mBackground = std::make_shared<Polygon>();
    mBackground->Rectangle(0, 0, 100, 100);

    double angle;
    auto shaft = GetBaseDrawing();
    for (int i = 1; i < 30; i++)
    {
        angle = double(i) / 30 * M_PI * 2;
        shaft->AddPoint(BasicRotorRadius * cos(angle),
                BasicRotorRadius * sin(angle));
    }

    shaft->AddPoint(0.0, BasicRotorRadius * sin(angle));
    shaft->AddPoint(0.0, -BasicRotorRadius * sin(angle));

}

void Motor::Update()
{
    mSource->UpdateSinks(mRotation);
}

void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mBackground->SetColor(*wxBLACK);
    mBackground->DrawPolygon(graphics, GetPosition().x, GetPosition().y);

    GetBaseDrawing()->SetColor(*wxRED);
    GetBaseDrawing()->SetRotation(mRotation);
    GetBaseDrawing()->DrawPolygon(graphics, GetPosition().x + RotorOffset, GetPosition().y - RotorOffset);
}

void Motor::UpdateMachine(double time)
{
    mRotation = time * mSpeed;
    Update();
}

