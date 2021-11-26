/**
 * @file ActualMachine.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ACTUALMACHINE_H
#define CANADIANEXPERIENCE_ACTUALMACHINE_H

#include "Motor.h"

class Component;

class ActualMachine {
private:
    double mTime;
    wxPoint mLocation = wxPoint(0, 0);
    double mFrameRate;
    int mCurrentFrame;

    std::vector<std::shared_ptr<Component>> mComponents;

    std::shared_ptr<Motor> mMotor;
public:
    ActualMachine();

    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics);
    void SetLocation(wxPoint location);
    void SetMachineFrame(int frame);
    void SetFrameRate(double rate);
    void SetSpeed(double speed);
    double GetMachineTime();

    void SetRootMotor(std::shared_ptr<Motor> motor) { mMotor = motor; }

    void AddComponent(std::shared_ptr<Component> component);

    /**
     * Getter for the Location of the Machine
     * @return wxPoint for the location
     */
    wxPoint GetLocation() const { return mLocation; }
};

#endif //CANADIANEXPERIENCE_ACTUALMACHINE_H
