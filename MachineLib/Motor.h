/**
 * @file Motor.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MOTOR_H
#define CANADIANEXPERIENCE_MOTOR_H

#include "Component.h"
#include "RotationSource.h"

class Component;

/**
 * Class Representing a Motor
 */
class Motor : public Component {
private:
    /// Speed of the Motor
    double mSpeed = 0.0;

    /// Background of the Motor
    std::shared_ptr<Polygon> mBackground;

    /// Rotation of the Rotor
    double mRotation = 0;

    /// Source Object
    std::shared_ptr<RotationSource> mSource;

public:
    Motor();

    /// Copy constructor (disabled)
    Motor(const Motor &) = delete;

    /// Assignment operator
    void operator=(const Motor &) = delete;

    void UpdateMachine(double time);
    void Update() override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Get the source object
     * @return Source object
     */
    std::shared_ptr<RotationSource> GetSource() const { return mSource; }

    /**
     * Sets the speed of the motor
     * @param speed Speed of the motor
     */
    void SetSpeed(double speed) { mSpeed = speed; };

    /**
     * Gets the speed of the motor
     * @return Speed of the motor
     */
    double GetSpeed() const { return mSpeed; }
};

#endif //CANADIANEXPERIENCE_MOTOR_H
