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

/**
 * Class representing a gear
 */
class Gear : public Component {
private:
    /// Teeth of the Gear
    int mTeeth = 0;

    /// Outer Radius of the Gear
    int mOuterRadius = 0;

    /// Inner Radius of the Gear
    int mInnerRadius = 0;

    /// Color of the Gear
    wxColor mColor = *wxBLACK;

    /// Gear sink object
    std::shared_ptr<RotationSink> mSink;

    /// Gear source object
    std::shared_ptr<RotationSource> mSource;

    /// Gears that this gear drives
    std::vector<Gear *> mGears;

    /// Gear rotation
    double mGearRotation = 0.0;

    /// Phase offset of the gear (used for meshing)
    double mPhase = 0.0;

    /// Hub of the Gear
    std::shared_ptr<Polygon> mHub;

public:
    /// Default constructor (disabled)
    Gear() = delete;

    /// Copy constructor (disabled)
    Gear(const Gear &) = delete;

    /// Assignment operator
    void operator=(const Gear &) = delete;

    Gear(int teeth, int outerRadius, int innerRadius, wxColor color);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Update() override;

    void AddGear(Gear* gear);

    void Drive();

    /**
     * Makes a Sink Object and returns it
     * @return Rotation Sink Pointer
     */
    RotationSink* MakeSink();

    /**
     * Getter for the Sink
     * @return RotationSink object
     */
    std::shared_ptr<RotationSink> GetSink() const { return mSink; }

    /**
     * Getter for the source
     * @return RotationSource object
     */
    std::shared_ptr<RotationSource> GetSource() const { return mSource; }

    /**
     * Setter for the gear rotation
     * @param rotation Rotation to set in rotations
     */
    void SetGearRotation(double rotation) { mGearRotation = rotation; }

    /**
     * Gets the gear rotation
     * @return rotations
     */
    double GetGearRotation() const { return mGearRotation; }

    /**
     * Gets the number of teeth on the gear
     * @return Number of teeth
     */
    int GetNumTeeth() const { return mTeeth; }

    /**
     * Sets the phase of the gear
     * @param phase Phase to set
     */
    void SetPhase(double phase) { mPhase = phase; }

    /**
     * Gets the phase of the gear
     * @return Phase of the gear
     */
    double GetPhase() const { return mPhase; }
};

#endif //CANADIANEXPERIENCE_GEAR_H
