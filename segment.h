#ifndef SEGMENT_H
#define SEGMENT_H

#include <QPainter>
#include <QtMath>
#include <QVector2D>
class Segment
{
public:
    Segment();
    Segment(float x, float y, float angle_, float len_);
    Segment(Segment *parent_, float angle_, float len_);
    void show(QPainter *painter);
    void update(){calculate_end();}
    void follow(float tx, float ty);
    void set_angle(float _angle){angle = _angle;}
    float get_angle(){return angle;}

    Segment *parent;
    QVector2D start;
    QVector2D end;
    float angle;
    float len;

    void calculate_end();

};

#endif // SEGMENT_H
