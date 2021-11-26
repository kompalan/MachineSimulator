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

/**
 * Class Representing a Rod Object
 */
class Rod : public Component {
private:
    /// Length of the Rod
    double mLength;

    /// RodEndSink Object
    std::shared_ptr<RodEndSink> mSink;
public:
    Rod(double length);

    /// Default Constructor (disabled)
    Rod() = delete;

    /// Copy constructor (disabled)
    Rod(const Rod &) = delete;

    /// Assignment operator
    void operator=(const Rod &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Get the Rod Sink
     * @return RodEndSink object
     */
    std::shared_ptr<RodEndSink> GetSink() const { return mSink; }
};

#endif //CANADIANEXPERIENCE_ROD_H
