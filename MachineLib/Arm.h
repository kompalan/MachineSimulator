/**
 * @file Arm.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ARM_H
#define CANADIANEXPERIENCE_ARM_H

#include "RotationSink.h"

/**
 * Class Representing an Arm Object
 */
class Arm : public Component {
private:
    /// Rotation sink
    std::shared_ptr<RotationSink> mSink;

public:
    Arm();

    /// Copy constructor (disabled)
    Arm(const Arm &) = delete;

    /// Assignment operator
    void operator=(const Arm &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Update() override;

    /**
     * Get the Sink Object Associated with it
     * @return RotationSink Object
     */
    std::shared_ptr<RotationSink> GetSink() const { return mSink; }
};

#endif //CANADIANEXPERIENCE_ARM_H
