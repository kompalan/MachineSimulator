/**
 * @file Piston.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_PISTON_H
#define CANADIANEXPERIENCE_PISTON_H

#include "Component.h"
#include "PistonSink.h"

/**
 * Class representing a Piston
 */
class Piston : public Component {
private:
    /// Piston Sink object
    std::shared_ptr<PistonSink> mSink;

    /// Image path
    std::wstring mImagePath;
public:
    Piston(const std::wstring &imagePath);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Update() override;

    /**
     * Getter for PistonSink Object
     * @return PistonSink object
     */
    std::shared_ptr<PistonSink> GetSink() const { return mSink; }
};

#endif //CANADIANEXPERIENCE_PISTON_H
