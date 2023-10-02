#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include "AnyObject.h"

class DynamicObject : public AnyObject
{
private:
    QPointF CenterPos;
public:
    DynamicObject() = delete;
    DynamicObject(QSizeF &_worldSize, KoafSize & Koafs_H_W, b2World & world_);

    virtual void NextStep(double dt) = 0;
};

#endif // DYNAMICOBJECT_H
