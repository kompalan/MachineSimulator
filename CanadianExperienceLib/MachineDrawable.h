/**
 * @file MachineDrawable.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINEDRAWABLE_H
#define CANADIANEXPERIENCE_MACHINEDRAWABLE_H

#include "Drawable.h"
#include <machine-api.h>

/**
 * A Drawable that displays a Machine
 */
class MachineDrawable : public Drawable {
private:
    /// The machine we are drawing
    std::shared_ptr<Machine> mMachine;

    /// The start offset of the machine
    int mMachineStartOffset = 0;

    /// Position of the Machine
    wxPoint mPosition;
public:

    MachineDrawable(const std::wstring &name, const std::wstring &filename, const wxPoint position);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void SetFrame(int frame) override;

    bool HitTest(wxPoint pos) override;

    void SetStartOffset(int offset) override;

    int GetStartOffset() override;

    void DoDialog(wxWindow* parent);

    int GetMachineNumber();

    void SetMachineNumber(int number);
};

#endif //CANADIANEXPERIENCE_MACHINEDRAWABLE_H
