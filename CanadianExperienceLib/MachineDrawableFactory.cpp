/**
 * @file MachineDrawableFactory.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "MachineDrawableFactory.h"
#include "Actor.h"
#include "MachineDrawable.h"

/**
 * This is a factory method that creates the MachineDrawable
 * @param imagesDir Directory that contains images for this application
 * @return Pointer to MachineDrawable object
 */
std::shared_ptr<Actor> MachineDrawableFactory::Create(std::wstring imagesDir)
{
    std::shared_ptr<Actor> actor = std::make_shared<Actor>(L"Machine");

    auto machine = std::make_shared<MachineDrawable>(L"Machine", imagesDir);

    actor->AddDrawable(machine);

    return actor;
}
