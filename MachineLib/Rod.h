/**
 * @file Rod.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ROD_H
#define CANADIANEXPERIENCE_ROD_H

#include "Component.h"
#include "RodEndSink.h"

class LeverEndSource;

/**
 * Class Representing a Rod Object
 */
class Rod : public Component {
private:
    /// Length of the Rod
    double mLength;

    /// RodEndSink Object
    std::shared_ptr<RodEndSink> mSink;

    /// LeverEndSource Object
    std::shared_ptr<LeverEndSource> mSource;

public:
    Rod(double length);

    /// Default Constructor (disabled)
    Rod() = delete;

    /// Copy constructor (disabled)
    Rod(const Rod &) = delete;

    /// Assignment operator
    void operator=(const Rod &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Update() override;

    /**
     * Get the Rod Sink
     * @return RodEndSink object
     */
    std::shared_ptr<RodEndSink> GetSink() const { return mSink; }

    /**
     * Get the Lever Source
     * @return LeverEndSource object
     */
    std::shared_ptr<LeverEndSource> GetSource() const { return mSource; }

    /**
     * Get the Rod Length
     * @return Length
     */
    double GetLength() const { return mLength; }
};

#endif //CANADIANEXPERIENCE_ROD_H
