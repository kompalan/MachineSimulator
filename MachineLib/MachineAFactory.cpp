/**
 * @file MachineAFactory.cpp
 * @author Anurag Kompalli
 */

#include "MachineAFactory.h"
#include "Shape.h"
#include "Gear.h"

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
    machine->SetRootMotor(motor);
    machine->AddComponent(motor);

    // Add A Shape
    auto shape = std::make_shared<Shape>();
    shape->DrawRectangle(-300, 115, 500, 70);
    shape->DrawImage(L"images/base.png");
    machine->AddComponent(shape);

    // Add A Blue Gear of Outer Radius 90 and 20 teeth
    auto gear = std::make_shared<Gear>(45, 85, 80, *wxBLUE);
    machine->AddComponent(gear);

    // Constrain the Gear to the Motor via a Rotation sink
    motor->GetSource()->AddSink(gear->GetSink().get());

    // Add A Second, Smaller Black Gear with 10 teeth and outer radius 40
    auto gear2 = std::make_shared<Gear>(20, 35, 30, *wxBLACK);
    machine->AddComponent(gear2);

    // Constrain the Gear to the Bigger Gear via a Rotation Sink
    gear->GetSource()->AddSink(gear2->GetSink().get());

    auto gear3 = std::make_shared<Gear>(10, 25, 20, *wxRED);
    machine->AddComponent(gear3);
    gear2->AddGear(gear3.get());
    gear3->SetTempPos(wxPoint(250+17.5+38, 250));
    gear3->SetPhase(-0.1);

    auto gear4 = std::make_shared<Gear>(15, 25, 20, *wxGREEN);
    machine->AddComponent(gear4);
    gear->AddGear(gear4.get());
    gear4->SetTempPos(wxPoint(250+105, 250));
    gear4->SetPhase(-1.5);
    gear->SetPhase(-0.5);

    return machine;
}
