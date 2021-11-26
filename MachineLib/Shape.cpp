/**
 * @file Shape.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "Component.h"
#include "Shape.h"

/**
 * Constructor
 */
Shape::Shape()
{
    mSink = std::make_shared<RotationSink>(this);
}

/**
 * Adds the Point to the Polygon path
 * @param x x coordinate
 * @param y y coordinate
 */
void Shape::AddPoint(double x, double y)
{
    Component::AddPoint(x, y);
}

/**
 * Draws the Shape to the screen rotated according to
 * sink information
 * @param graphics wxGraphics Object
 */
void Shape::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    SetRotation(mSink->GetRotation());
    Component::Draw(graphics);
}


/**
 * Sets the image of the object. Either call
 * this or SetColor before drawing
 * @param imagePath Path to image
 */
void Shape::DrawImage(std::wstring imagePath)
{
    SetImage(imagePath);
}

/**
 * Sets the color of the polygon
 * @param color wxColor Object
 */
void Shape::SetColor(wxColour color)
{
    Component::SetColor(color);
}

/**
 * Wrapper for Polygon Rectangle
 * @param x x position
 * @param y y position
 * @param w width
 * @param h height
 */
void Shape::DrawRectangle(int x, int y, int w, int h)
{
    Rectangle(x, y, w, h);
}


