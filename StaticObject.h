#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "AnyObject.h"

class StaticObject : public AnyObject
{
private:
//???

public:
    StaticObject() = delete;
    StaticObject(QSizeF &_worldSize, KoafSize &Koafs_H_W, b2World & world_);
};

#endif // STATICOBJECT_H
