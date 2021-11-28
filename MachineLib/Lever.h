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
public:
    Lever();

    /// Copy constructor (disabled)
    Lever(const Lever &) = delete;

    /// Assignment operator
    void operator=(const Lever &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Update() override;

    std::shared_ptr<LeverEndSink> GetSink() const { return mSink; }

    std::shared_ptr<RotationSource> GetRotationSource() const { return mRotationSource; }

    std::shared_ptr<RodEndSource> GetRodSource() const { return mRodSource; }
};

#endif //CANADIANEXPERIENCE_LEVER_H
