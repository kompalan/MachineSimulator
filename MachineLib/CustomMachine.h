/**
 * @file CustomMachine.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CUSTOMMACHINE_H
#define CANADIANEXPERIENCE_CUSTOMMACHINE_H

#include "Machine.h"
#include "ActualMachine.h"

/**
 * CustomMachine class, direct all calls to ActualMachine
 */
class CustomMachine : public Machine {
private:
    /// The Machine Number
    int mMachineNumber = 0;

    /// Pointer to the Current Machine
    std::shared_ptr<ActualMachine> mMachine;

public:
    CustomMachine();

    /// Copy constructor (disabled)
    CustomMachine(const CustomMachine &) = delete;

    /// Assignment operator
    void operator=(const CustomMachine &) = delete;

    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;
    void SetLocation(wxPoint location) override;
    wxPoint GetLocation() override;
    void SetMachineFrame(int frame) override;
    void SetFrameRate(double rate) override;
    void SetSpeed(double speed) override;
    void SetMachineNumber(int machine) override;
    int GetMachineNumber() override;
    double GetMachineTime() override;
};

#endif //CANADIANEXPERIENCE_CUSTOMMACHINE_H
