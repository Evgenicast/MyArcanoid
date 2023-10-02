#include "Room.h"
#include <QPainter>

Room::Room(QSizeF & _worldSize, KoafSize & Koafs_H_W, b2World & world_)
:StaticObject(_worldSize, Koafs_H_W, world_)
{
    CreateRoom();
}

void Room::CreateRoom()
{
    bodyDef.position.Set(5.0f, 0.0f); // потолок
    body = world.CreateBody(&bodyDef);
    m_GroundBoxShape.SetAsBox(5.0, 0.0);
    b2Fixture * fixture1 = body->CreateFixture(&m_GroundBoxShape, 1.0f);
    fixture1->SetFriction(0.0f);
    fixture1->SetRestitution(1.0f);
    fixture1->SetRestitutionThreshold(0.0f);
    fixture1->SetDensity(1.5);

    bodyDef.position.Set(10.0f, 10.0f); // правая стена
    body = world.CreateBody(&bodyDef);
    m_GroundBoxShape.SetAsBox(0.0, 10.0);
    b2Fixture * fixture2 = body->CreateFixture(&m_GroundBoxShape, 1.0f);
    fixture2->SetFriction(0.0f);
    fixture2->SetRestitution(1.0f);
    fixture2->SetRestitutionThreshold(0.0f);
    fixture2->SetDensity(1.5);

    bodyDef.position.Set(-0.3f, 10.0f); // левая стена
    body = world.CreateBody(&bodyDef);
    m_GroundBoxShape.SetAsBox(0.0, 10.0);
    b2Fixture * fixture3 = body->CreateFixture(&m_GroundBoxShape, 1.0f);
    fixture3->SetFriction(0.0f);
    fixture3->SetDensity(1.5);
    fixture3->SetRestitution(1.0f);
    fixture3->SetRestitutionThreshold(0.0f);
}

void Room::DrawSelf(QPainter * painter)
{
    (void)painter;
}

void Room::CheckCollisions(AnyObject *Object)
{
    if(this == Object)
        return;
}

Room::~Room()
{
    body->GetWorld()->DestroyBody(body);
}


