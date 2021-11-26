/**
 * @file Arm.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ARM_H
#define CANADIANEXPERIENCE_ARM_H

#include "RotationSink.h"
#include "RodEndSource.h"

/**
 * Class Representing an Arm Object
 */
class Arm : public Component {
private:
    /// Rotation sink
    std::shared_ptr<RotationSink> mSink;

    /// Position source
    std::shared_ptr<RodEndSource> mSource;

    /// Length of the Arm
    double mLength;

public:
    Arm(double length);

    /// Default Constructor (disabled)
    Arm() = delete;

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

    /**
     * Get the Source Object
     * @return RodEndSource Object
     */
    std::shared_ptr<RodEndSource> GetSource() const { return mSource; }
};

#endif //CANADIANEXPERIENCE_ARM_H
