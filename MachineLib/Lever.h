/**
 * @file Lever.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_LEVER_H
#define CANADIANEXPERIENCE_LEVER_H

#include "Component.h"
#include "LeverEndSink.h"
#include "RotationSource.h"
#include "RodEndSource.h"

/**
 * Class representing a lever
 */
class Lever : public Component {
private:
    /// Lever End Sink
    std::shared_ptr<LeverEndSink> mSink;

    /// Rotation Source
    std::shared_ptr<RotationSource> mRotationSource;

    /// Rod Source
    std::shared_ptr<RodEndSource> mRodSource;

    /// Length of Lever
    double mLength;
public:
    Lever() = delete;

    /// Copy constructor (disabled)
    Lever(const Lever &) = delete;

    /// Assignment operator
    void operator=(const Lever &) = delete;

    Lever(double length);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Update() override;

    /**
     * Getter for LeverEnd Sink object
     * @return LeverEndSink object
     */
    std::shared_ptr<LeverEndSink> GetSink() const { return mSink; }

    /**
     * Getter for Rotation Source Object
     * @return RotationSource Object
     */
    std::shared_ptr<RotationSource> GetRotationSource() const { return mRotationSource; }

    /**
     * Getter for Rod Source Object
     * @return RodSource Object
     */
    std::shared_ptr<RodEndSource> GetRodSource() const { return mRodSource; }
};

#endif //CANADIANEXPERIENCE_LEVER_H
