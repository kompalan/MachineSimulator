/**
 * @file MachineBFactory.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "MachineBFactory.h"
#include "Shape.h"
#include "Lever.h"
#include "Rod.h"
#include "Piston.h"
#include "Arm.h"
#include "Gear.h"
#include "LeverEndSource.h"

/**
 * Constructor
 * @param imagesDir Images Directory
 */
MachineBFactory::MachineBFactory(std::wstring imagesDir)
{
    mImagesDir = imagesDir;
}

/**
 * Creates a Machine Object
 * @return ActualMachine Object
 */
std::shared_ptr<ActualMachine> MachineBFactory::Create()
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

    // Add A Blue Gear of Outer Radius 90 and 20 teeth
    auto gear = std::make_shared<Gear>(45, 85, 80, *wxBLUE);
    machine->AddComponent(gear);
    gear->SetPositionOffset(wxPoint(250, 250));

    // Constrain the Gear to the Motor via a Rotation sink
    motor->GetSource()->AddSink(gear->MakeSink());

    // Add A Second, Smaller Black Gear with 10 teeth and outer radius 40
    auto gear2 = std::make_shared<Gear>(20, 35, 30, *wxBLACK);
    machine->AddComponent(gear2);
    gear2->SetPositionOffset(wxPoint(250, 250));

    // Constrain the Gear to the Bigger Gear via a Rotation Sink
    gear->GetSource()->AddSink(gear2->MakeSink());

    // Add a third, red gear and constrain it to gear 2
    auto gear3 = std::make_shared<Gear>(10, 25, 20, *wxRED);
    machine->AddComponent(gear3);
    gear2->AddGear(gear3.get());
    gear3->SetPositionOffset(wxPoint(250+17.5+38, 250));
    gear3->SetPhase(-0.1);

    // Add A fourth, green gear and constrain it to gear 1
    auto gear4 = std::make_shared<Gear>(15, 25, 20, *wxGREEN);
    machine->AddComponent(gear4);
    gear->AddGear(gear4.get());
    gear4->SetPositionOffset(wxPoint(250+105, 250));
    gear4->SetPhase(-0.1);

    // Add an Arm of length 100
    auto arm1 = std::make_shared<Arm>(100);
    machine->AddComponent(arm1);
    arm1->SetPositionOffset(wxPoint(50, 50));
    motor->GetSource()->AddSink(arm1->GetSink().get());

    auto piston1 = std::make_shared<Piston>();
    piston1->SetPositionOffset(wxPoint(-100, 100));
    machine->AddComponent(piston1);

    auto rod = std::make_shared<Rod>(200);
    arm1->GetSource()->AddSink(rod->GetSink().get());
    machine->AddComponent(rod);

    auto lever = std::make_shared<Lever>();
    lever->SetPositionOffset(wxPoint(-200, 200));
    rod->GetSource()->AddSink(lever->GetSink().get());

    machine->AddComponent(lever);

    return machine;
}
