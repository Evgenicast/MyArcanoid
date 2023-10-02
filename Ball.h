#ifndef BALL_H
#define BALL_H

#include "DynamicObject.h"

class QPainter;

class Ball : public DynamicObject
{
private:

    b2CircleShape shape;

public:
    Ball() = delete;
    Ball(QSizeF &_worldSize, KoafSize & Koafs_H_W, b2World & world_);
    void SetBall(float PosX, float PosY);

    void NextStep(double dt) override;
    void CheckCollisions(AnyObject * Object) override;



    void SetIsHit(bool IsHit) override;
    b2Body * GetBallBody() const { return body ;}

    void Clear();
    void DrawSelf(QPainter *painter) override;

    ~Ball();
};

#endif // BALL_H
