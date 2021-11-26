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

    /// Stub Update Function
    virtual void Update() {};
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    wxPoint GetMachinePosition() const;
    wxPoint GetPositionOffset() const;
    void SetPositionOffset(wxPoint position);

    /**
     * Sets the Machine object
     * @param machine Machine to set
     */
    void SetMachine(ActualMachine* machine) { mMachine = machine; }

    /**
     * Gets the current Machine
     * @return Machine to get
     */
    ActualMachine* GetMachine() const { return mMachine; }
};

#endif //CANADIANEXPERIENCE_COMPONENT_H
