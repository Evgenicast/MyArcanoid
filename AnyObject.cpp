#include "AnyObject.h"
#include <QPainter>

AnyObject::AnyObject(QSizeF &_worldSize, KoafSize & Koafs_H_W, b2World & world_)
: worldSize(_worldSize), m_Koafs_H_W(Koafs_H_W), world(world_){}





