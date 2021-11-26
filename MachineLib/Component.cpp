/**
 * @file Component.cpp
 * @author Anurag Kompalli
 */

#include "Component.h"
#include "ActualMachine.h"

Component::Component()
{
    mDrawing = std::make_shared<Polygon>();
}

void Component::Update()
{

}

wxPoint Component::GetPosition() const
{
    return mMachine->GetLocation();
}


