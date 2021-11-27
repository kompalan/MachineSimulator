/**
 * @file MachineAFactory.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "MachineAFactory.h"
#include "Shape.h"
#include "Gear.h"
#include "Arm.h"
#include "Piston.h"
#include "Rod.h"
#include "Lever.h"

/**
 * Constructor
 * @param imagesDir Directory to Pull Images from
 */
MachineAFactory::MachineAFactory(std::wstring imagesDir)
{
    mImagesDir = imagesDir;
}

/**
 * Creates a A-Type Machine
 * @return Machine Object
 */
std::shared_ptr<ActualMachine> MachineAFactory::Create()
{
    // Create our machine
    auto machine = std::make_shared<ActualMachine>();

    // Add a Motor
    auto motor = std::make_shared<Motor>();
    motor->SetPositionOffset(wxPoint(50, 50));
    machine->SetRootMotor(motor);
    machine->AddComponent(motor);

    // Add A Shape
    auto shape = std::make_shared<Shape>();
    shape->DrawRectangle(-300, 115, 500, 70);
    shape->DrawImage(L"images/base.png");
    shape->SetPositionOffset(wxPoint(50, 50));
    machine->AddComponent(shape);

    auto gear1 = std::make_shared<Gear>(10, 25, 20, wxColor(128, 128, 128));
    gear1->SetPositionOffset(wxPoint(50, 50));
    motor->GetSource()->AddSink(gear1->MakeSink());
    machine->AddComponent(gear1);

    auto gear2 = std::make_shared<Gear>(20, 45, 40, *wxBLUE);
    gear2->SetPositionOffset(wxPoint(50+10+12.5+46, 50));
    gear1->AddGear(gear2.get());
    machine->AddComponent(gear2);

    // Add an Arm of length 100
    auto arm1 = std::make_shared<Arm>(100);
    machine->AddComponent(arm1);
    arm1->SetPositionOffset(wxPoint(50+25+45, 50));
    gear2->GetSource()->AddSink(arm1->GetSink().get());

    auto rod = std::make_shared<Rod>(200);
    arm1->GetSource()->AddSink(rod->GetSink().get());
    machine->AddComponent(rod);

    auto lever = std::make_shared<Lever>();
    lever->SetPositionOffset(wxPoint(50, 200));
    machine->AddComponent(lever);

    return machine;
}
