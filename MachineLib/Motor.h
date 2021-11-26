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

class Motor : public Component {
private:
    double mSpeed = 0.0;
    std::shared_ptr<Polygon> mBackground;
    double mRotation = 0;
    std::shared_ptr<RotationSource> mSource;

public:
    Motor();

    /// Copy constructor (disabled)
    Motor(const Motor &) = delete;

    /// Assignment operator
    void operator=(const Motor &) = delete;

    void SetSpeed(double speed) { mSpeed = speed; };
    void UpdateMachine(double time);
    void Update() override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    std::shared_ptr<RotationSource> GetSource() const { return mSource; }
};

#endif //CANADIANEXPERIENCE_MOTOR_H
