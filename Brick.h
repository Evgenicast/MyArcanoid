#ifndef BRICK_H
#define BRICK_H

#include "StaticObject.h"

#include <QVector2D>
#include <random>

class QPainter;

class Brick : public StaticObject
{    
private:

    b2PolygonShape m_BrickShape;

    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<int> dist{0, 200};

public:

    static constexpr float HALFHEIGHT = 1.0f;// same
    static constexpr float HALFWIDTH = 1.0f;

    Brick() = delete;
    Brick(QSizeF &_worldSize, KoafSize & Koafs_H_W, b2World & world_);
    void SetPosition(float x, float y);
    void SetIsHit(bool IsHit) override;
    void SetStatus(Status status) override;

    b2Body * GetBodyPtr() override;

    void DrawSelf(QPainter * painter) override;
    void CheckCollisions(AnyObject * Object) override;

    void Clear();
    ~Brick();
};

#endif // BRICK_H
