/**
 * @file MachineDrawableFactory.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINEDRAWABLEFACTORY_H
#define CANADIANEXPERIENCE_MACHINEDRAWABLEFACTORY_H

#include "MachineDrawable.h"

class Actor;

/**
 * Factory class to create MachineDrawable
 */
class MachineDrawableFactory {
private:
    std::shared_ptr<MachineDrawable> mMachine;

public:
    std::shared_ptr<Actor> Create(std::wstring imagesDir, wxPoint position);
    std::shared_ptr<MachineDrawable> GetMachineDrawable();
};

#endif //CANADIANEXPERIENCE_MACHINEDRAWABLEFACTORY_H
