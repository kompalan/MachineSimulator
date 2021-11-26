/**
 * @file MachineAFactory.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINEAFACTORY_H
#define CANADIANEXPERIENCE_MACHINEAFACTORY_H

#include "ActualMachine.h"

/**
 * Factory to Create an A-Type Machine
 */
class MachineAFactory {
private:
    /// Directory from which to pull pictures
    std::wstring mImagesDir;

public:
    MachineAFactory(std::wstring imagesDir);
    std::shared_ptr<ActualMachine> Create();
};

#endif //CANADIANEXPERIENCE_MACHINEAFACTORY_H
