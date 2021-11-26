/**
 * @file Component.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_COMPONENT_H
#define CANADIANEXPERIENCE_COMPONENT_H

#include "Polygon.h"

class ActualMachine;

/**
 * General Component Class.
 */
class Component : public Polygon {
private:
    /// Position of the Component (offset from root location)
    wxPoint mPosition;

    /// Machine Pointer
    ActualMachine* mMachine;

public:
    Component();

    /// Copy constructor (disabled)
    Component(const Component &) = delete;

    /// Assignment operator
    void operator=(const Component &) = delete;

    virtual void Update() {};
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) = 0;
    wxPoint GetMachinePosition() const;
    wxPoint GetPositionOffset() const;
    void SetPositionOffset(wxPoint position);

    void SetMachine(ActualMachine* machine) { mMachine = machine; }
    ActualMachine* GetMachine() const { return mMachine; }
};

#endif //CANADIANEXPERIENCE_COMPONENT_H
