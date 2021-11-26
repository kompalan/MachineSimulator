/**
 * @file MachineBFactory.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "MachineBFactory.h"
#include "Shape.h"

MachineBFactory::MachineBFactory(std::wstring imagesDir)
{
    mImagesDir = imagesDir;
}

std::shared_ptr<ActualMachine> MachineBFactory::Create()
{
    auto machine = std::make_shared<ActualMachine>();

    auto shape = std::make_shared<Shape>();
    shape->DrawRectangle(-100, -100, 200, 200);
    shape->DrawImage(L"images/luke.jpg");

    machine->AddComponent(shape);

    return machine;
}
