/**
 * @file Piston.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_PISTON_H
#define CANADIANEXPERIENCE_PISTON_H

#include "Component.h"

/**
 * Class representing a Piston
 */
class Piston : public Component {
private:

public:
    Piston();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
};

#endif //CANADIANEXPERIENCE_PISTON_H
