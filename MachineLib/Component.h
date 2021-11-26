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

class Component : public Polygon {
private:
    wxPoint mPosition;

    ActualMachine* mMachine;
    std::shared_ptr<Polygon> mDrawing;
public:
    Component();

    virtual void Update();
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) = 0;
    wxPoint GetPosition() const;

    void SetMachine(ActualMachine* machine) { mMachine = machine; }
    ActualMachine* GetMachine() const { return mMachine; }

    Polygon* GetBaseDrawing() const { return mDrawing.get(); }
};

#endif //CANADIANEXPERIENCE_COMPONENT_H
