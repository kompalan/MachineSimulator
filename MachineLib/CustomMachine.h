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

class CustomMachine : public Machine {
private:
    int mMachineNumber = 0;
    std::shared_ptr<ActualMachine> mMachine;
public:
    CustomMachine();
    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;
    void SetLocation(wxPoint location) override;
    void SetMachineFrame(int frame) override;
    void SetFrameRate(double rate) override;
    void SetSpeed(double speed) override;
    void SetMachineNumber(int machine) override;
    int GetMachineNumber() override;
    double GetMachineTime() override;
};

#endif //CANADIANEXPERIENCE_CUSTOMMACHINE_H
