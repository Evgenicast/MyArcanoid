#include "DynamicObject.h"

DynamicObject::DynamicObject(QSizeF &_worldSize, KoafSize & Koafs_H_W, b2World & world_)
: AnyObject(_worldSize, Koafs_H_W, world_)
{
    bodyDef.type = b2_dynamicBody;
}

void DynamicObject::NextStep(double dt)
{
    (void)dt;
}
