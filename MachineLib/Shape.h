/**
 * @file Shape.h
 * @author Anurag Kompalli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_SHAPE_H
#define CANADIANEXPERIENCE_SHAPE_H

#include "Component.h"
#include "RotationSink.h"

class Shape : public Component {
private:
    std::shared_ptr<RotationSink> mSink;

public:
    Shape();

    std::shared_ptr<RotationSink> GetSink() const { return mSink; }

    void AddPoint(double x, double y);

    void DrawImage(std::wstring imagePath);

    void DrawRectangle(int x, int y, int w, int h);

    void SetColor(wxColor color);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Update() override;
};

#endif //CANADIANEXPERIENCE_SHAPE_H
