/**
 * @file Motor.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "Motor.h"

/// Rotor Radius Constant
const static double BasicRotorRadius = 15;

/**
 * Constructor. Sets up the picture of the rotor
 * and the background of the motor.
 */
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

/**
 * Call the source with information about
 * this motor's rotation
 */
void Motor::Update()
{
    mSource->UpdateSinks(mRotation);
}

/**
 * Draw function. Draws the motor with two polygon
 * objects.
 * @param graphics wxGraphics object
 */
void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mBackground->SetColor(*wxBLACK);
    mBackground->DrawPolygon(graphics, GetMachinePosition().x, GetMachinePosition().y);

    SetColor(*wxRED);
    SetRotation(mRotation);

    Component::Draw(graphics);
}

/**
 * Set the current rotation based on the
 * time and speed and call update
 * @param time Time machine is at
 */
void Motor::UpdateMachine(double time)
{
    mRotation = time * mSpeed;
    Update();
}

