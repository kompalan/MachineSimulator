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

/**
 * Class Holding a Machine, holds all components
 * and handles drawing and updating for everything
 */
class ActualMachine {
private:
    /// Machine Time
    double mTime;

    /// Absolute Machine Location
    wxPoint mLocation = wxPoint(0, 0);

    /// Framerate of the Machine
    double mFrameRate;

    /// Current Frame that we are on
    int mCurrentFrame;

    /// All Components in the machine (used for drawing)
    std::vector<std::shared_ptr<Component>> mComponents;

    /// Motor Object to Kick off Updates
    std::shared_ptr<Motor> mMotor;

public:
    ActualMachine();

    /// Copy constructor (disabled)
    ActualMachine(const ActualMachine &) = delete;

    /// Assignment operator
    void operator=(const ActualMachine &) = delete;

    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics);
    void SetLocation(wxPoint location);
    void SetMachineFrame(int frame);
    void SetFrameRate(double rate);
    void SetSpeed(double speed);
    double GetMachineTime();
    void AddComponent(std::shared_ptr<Component> component);

    /**
     * Sets the root of the machine. Initial Update Goes
     * to this Motor
     * TODO: Should this bee a list?
     * @param motor Motor to set as root
     */
    void SetRootMotor(std::shared_ptr<Motor> motor) { mMotor = motor; }

    /**
     * Getter for the Location of the Machine
     * @return wxPoint for the location
     */
    wxPoint GetLocation() const { return mLocation; }
};

#endif //CANADIANEXPERIENCE_ACTUALMACHINE_H
