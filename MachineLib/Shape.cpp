/**
 * @file Shape.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "Component.h"
#include "Shape.h"

Shape::Shape()
{
    mSink = std::make_shared<RotationSink>(this);
}

void Shape::AddPoint(double x, double y)
{
    Component::AddPoint(x, y);
}

void Shape::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    SetRotation(mSink->GetRotation());
    DrawPolygon(graphics, GetMachinePosition().x + GetPositionOffset().x, GetMachinePosition().y - GetPositionOffset().y);
}

void Shape::Update()
{
}

void Shape::DrawImage(std::wstring imagePath)
{
    SetImage(imagePath);
}

void Shape::SetColor(wxColour color)
{
    Component::SetColor(color);
}

void Shape::DrawRectangle(int x, int y, int w, int h)
{
    Rectangle(x, y, w, h);
}


