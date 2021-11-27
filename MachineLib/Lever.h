/**
 * @file Lever.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_LEVER_H
#define CANADIANEXPERIENCE_LEVER_H

#include "Component.h"

/**
 * Class representing a lever
 */
class Lever : public Component {
private:

public:
    Lever();

    /// Copy constructor (disabled)
    Lever(const Lever &) = delete;

    /// Assignment operator
    void operator=(const Lever &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
};

#endif //CANADIANEXPERIENCE_LEVER_H
