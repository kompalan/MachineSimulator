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

/**
 * Class Representing a Shape Object
 */
class Shape : public Component {
private:
    /// RotationSink Object
    std::shared_ptr<RotationSink> mSink;

public:
    Shape();

    /// Copy constructor (disabled)
    Shape(const Shape &) = delete;

    /// Assignment operator
    void operator=(const Shape &) = delete;

    void AddPoint(double x, double y);

    void DrawImage(std::wstring imagePath);

    void DrawRectangle(int x, int y, int w, int h);

    void SetColor(wxColor color);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Get the sink object
     * @return RotationSink object
     */
    std::shared_ptr<RotationSink> GetSink() const { return mSink; }
};

#endif //CANADIANEXPERIENCE_SHAPE_H
