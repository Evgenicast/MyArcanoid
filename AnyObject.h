#ifndef ANYOBJECT_H
#define ANYOBJECT_H

#include <QVector2D>
#include "Box2D/box2d/box2d.h"

class QPainter;

enum class Status
{
    VALID,
    INVALID
};

struct KoafSize
{
    float k = 0.0f;
    float kw = 0.0f;
    float kh = 0.0f;
};

class AnyObject
{
protected:

    QSizeF & worldSize;
    KoafSize & m_Koafs_H_W;
    b2World & world;
    b2Body * body;
    b2BodyDef bodyDef;
    bool m_IsHit;
    Status m_Status;

public:

    AnyObject();
    AnyObject(QSizeF &_worldSize, KoafSize & Koafs_H_W, b2World & world_);

    AnyObject(const AnyObject &) = delete;
    AnyObject(AnyObject &&) noexcept = delete;

    AnyObject & operator=(const AnyObject &) = delete;
    AnyObject & operator=(AnyObject &&) noexcept = delete;

    virtual void CheckCollisions(AnyObject * Object) = 0;
    virtual bool GetIsHit() const { return m_IsHit; }
    virtual void SetIsHit(bool IsHit) { m_IsHit = IsHit; }
    virtual void SetStatus(Status status) { m_Status = status; }
    virtual b2Body * GetBodyPtr() { return body; }

    virtual void DrawSelf(QPainter * painter) = 0;


    virtual ~AnyObject() = default;
};

#endif // ANYOBJECT_H
