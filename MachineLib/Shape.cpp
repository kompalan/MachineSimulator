/**
 * @file Shape.cpp
 * @author Anurag Kompalli
 */

#include "Component.h"
#include "Shape.h"

Shape::Shape()
{
    mSink = std::make_shared<RotationSink>(this);
}

void Shape::AddPoint(double x, double y)
{
    GetBaseDrawing()->AddPoint(x, y);
}

void Shape::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    GetBaseDrawing()->SetRotation(mSink->GetRotation());
    GetBaseDrawing()->DrawPolygon(graphics, GetPosition().x + 50, GetPosition().y - 50);
}

void Shape::Update()
{
}

void Shape::DrawImage(std::wstring imagePath)
{
    GetBaseDrawing()->SetImage(imagePath);
}

void Shape::SetColor(wxColour color)
{
    GetBaseDrawing()->SetColor(color);
}

void Shape::DrawRectangle(int x, int y, int w, int h)
{
    GetBaseDrawing()->Rectangle(x, y, w, h);
}


