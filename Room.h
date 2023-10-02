#ifndef ROOM_H
#define ROOM_H

#include "StaticObject.h"


class Room : public StaticObject
{
using RoomAttributesPtr = b2Body*;

private:

    b2PolygonShape m_GroundBoxShape;

public:

    Room() = delete;
    Room(QSizeF &_worldSize, KoafSize & Koafs_H_W, b2World & world_);

    void CreateRoom();

    void DrawSelf(QPainter *painter) override; // пока не нужен, далее решим.
    void CheckCollisions(AnyObject * Object) override;
    ~Room();

};

#endif // ROOM_H
