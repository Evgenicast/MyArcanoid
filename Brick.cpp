#include "Brick.h"
#include "Ball.h"

#include <QPainter>

Brick::Brick(QSizeF &_worldSize, KoafSize & Koafs_H_W, b2World & world_)
: StaticObject(_worldSize, Koafs_H_W, world_)
{    //НУЖНО УБРАТЬ, ТАК КАК НЕ В КОНТЕЙНЕРЕ ИЛИ РЕШИТЬ, КАК УДАЛЯТЬ
    bodyDef.position.Set(1.0f, 0.0f);
    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
    body = world.CreateBody(&bodyDef);
    m_BrickShape.SetAsBox(HALFWIDTH, HALFHEIGHT);
    b2Fixture * fixture = body->CreateFixture(&m_BrickShape, 1.0f);
    fixture->SetRestitution(1.0f);
    fixture->SetRestitutionThreshold(0.0f);
    fixture->SetDensity(1.5f);
    fixture->SetFriction(0.0f);

}

void Brick::SetPosition(float x, float y)
{
    this->body->SetTransform({x,y}, 0.0f);
}

void Brick::SetIsHit(bool IsHit)
{
    m_IsHit = IsHit;
}

void Brick::SetStatus(Status status)
{
    m_Status = status;
}

b2Body * Brick::GetBodyPtr()
{
    return body;
}

void Brick::DrawSelf(QPainter *painter)
{

//    std::uniform_real_distribution dist(0.0, 6.0);
    if(m_IsHit)
    {
//        painter->setBrush(QColor(200,100, 200));
        //std::uniform_int_distribution dist(0, 255);
        painter->setBrush(QColor(0,  100, 200));
    }
    else
    {
//        painter->setBrush(QColor(180,150,200));
        std::uniform_int_distribution dist(0, 255);
        painter->setBrush(QColor(dist(gen), 100, 200));

    }
    painter->setPen(QPen(Qt::blue, 5 ));
    painter->drawRect((body->GetPosition().x - HALFWIDTH) / m_Koafs_H_W.kw , body->GetPosition().y / m_Koafs_H_W.kh,
                      ((HALFWIDTH * 2) / m_Koafs_H_W.kw) , (HALFHEIGHT/ m_Koafs_H_W.kh) );
}

void Brick::CheckCollisions(AnyObject * Object)
{
    SetIsHit(true);
    auto fix = body->GetFixtureList();
    fix->SetSensor(true); // Отменяет коллизии.
    static_cast<Ball *>(Object)->SetIsHit(true); // можно влиять и на объект
}

void Brick::Clear()
{
    body->GetWorld()->DestroyBody(body);
}

Brick::~Brick()
{
    Clear();
}
