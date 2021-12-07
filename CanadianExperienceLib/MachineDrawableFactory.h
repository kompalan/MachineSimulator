/**
 * @file MachineDrawableFactory.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINEDRAWABLEFACTORY_H
#define CANADIANEXPERIENCE_MACHINEDRAWABLEFACTORY_H

class Actor;

/**
 * Factory class to create MachineDrawable
 */
class MachineDrawableFactory {
private:

public:
    std::shared_ptr<Actor> Create(std::wstring imagesDir);
};

#endif //CANADIANEXPERIENCE_MACHINEDRAWABLEFACTORY_H
