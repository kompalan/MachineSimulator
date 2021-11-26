/**
 * @file Gear.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_GEAR_H
#define CANADIANEXPERIENCE_GEAR_H

#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"

class Gear : public Component {
private:
    int mTeeth;
    int mOuterRadius;
    int mInnerRadius;
    wxColor mColor;

    std::shared_ptr<RotationSink> mSink;

    std::shared_ptr<RotationSource> mSource;

    std::vector<Gear *> mGears;

    double mGearRotation = 0.0;

    double mPhase = 0.0;

    wxPoint mTempPos = wxPoint(250, 250);

public:
    /// Default constructor (disabled)
    Gear() = delete;

    Gear(int teeth, int outerRadius, int innerRadius, wxColor color);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Update() override;

    std::shared_ptr<RotationSink> GetSink() const { return mSink; }

    std::shared_ptr<RotationSource> GetSource() const { return mSource; }

    void SetRotation(double rotation) { mGearRotation = rotation; }
    double GetRotation() const { return mGearRotation; }

    int GetNumTeeth() const { return mTeeth; }

    void AddGear(Gear* gear);

    void Drive();

    void SetPhase(double phase) { mPhase = phase; }
    double GetPhase() const { return mPhase; }

    void SetTempPos(wxPoint pos) { mTempPos = pos; }
};

#endif //CANADIANEXPERIENCE_GEAR_H
