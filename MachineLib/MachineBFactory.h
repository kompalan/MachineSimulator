/**
 * @file MachineBFactory.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINEBFACTORY_H
#define CANADIANEXPERIENCE_MACHINEBFACTORY_H

#include "ActualMachine.h"

/**
 * Factory to Create a B-Type Machine
 */
class MachineBFactory {
private:
    /// Directory from which to pull pictures
    std::wstring mImagesDir;

public:
    MachineBFactory(std::wstring imagesDir);
    std::shared_ptr<ActualMachine> Create();
};

#endif //CANADIANEXPERIENCE_MACHINEBFACTORY_H
