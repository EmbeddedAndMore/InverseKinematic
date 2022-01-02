#include "segment.h"
#include <iostream>

Segment::Segment(){}
Segment::Segment(float x, float y, float angle_, float len_)
{
    start = QVector2D(x, y);
    angle = angle_;
    len = len_;
    calculate_end();
}

Segment::Segment(Segment *parent_, float angle_, float len_)
{
    parent = parent_;
    start = parent->end;
    angle = angle_;
    len = len_;
    calculate_end();
}

void Segment::show(QPainter *painter)
{
    painter->setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::RoundCap));
    painter->drawLine(start.x(), start.y(), end.x(), end.y());
}

void Segment::follow(float tx, float ty)
{
    float dx = tx - start.x();
    float dy = ty - start.y();
    angle = qRadiansToDegrees(qAtan2(dy, dx));

    float new_start_x = tx - (len * cos(qDegreesToRadians(angle)));
    float new_start_y = ty - (len * sin(qDegreesToRadians(angle)));
    start = QVector2D(new_start_x, new_start_y);
}

void Segment::calculate_end()
{
    float dx = len * cos(qDegreesToRadians(angle));
    float dy = len * sin(qDegreesToRadians(angle));
    end = QVector2D(start.x() + dx, start.y() + dy);
}
