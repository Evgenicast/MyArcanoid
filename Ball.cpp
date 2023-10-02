#include "Ball.h"
#include "Brick.h"
#include <QPainter>
#include <cmath>
#include <iostream>
#include <QDebug>

Ball::Ball(QSizeF &_worldSize, KoafSize & Koafs_H_W, b2World & world_)
: DynamicObject(_worldSize, Koafs_H_W, world_)
{
    m_IsHit = false;
}
void Ball::SetBall(float PosX, float PosY)
{
    bodyDef.position.Set(PosX-0.2, PosY-0.8); // wordl is 10/20.
    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this); //ОБЯЗАТЕЛЬНО ПЕРЕДАТЬ, ЧТОБЫ МОЖНО БЫЛО ОБРАБАТЫВАТЬ КОЛЛИЗИИ В КОНТАКТ ЛИСТНЕРЕР
    body = world.CreateBody(&bodyDef);
    const b2Vec2 velocity(-1.5f, -1.8f);
    body->SetLinearVelocity(velocity);
    shape.m_radius  = 0.4f; // in meters
    b2Fixture * fixture = body->CreateFixture(&shape, 1.0f);
    fixture->SetRestitution(1.0f);
    fixture->SetRestitutionThreshold(0.0f);
    fixture->SetDensity(0.5f);
    body->SetEnabled(false);
}

void Ball::SetIsHit(bool IsHit)
{
    m_IsHit = IsHit;
}

void Ball::Clear()
{
    body->GetWorld()->DestroyBody(body);
}

void Ball::DrawSelf(QPainter * painter) // 60 per second
{
    if(m_IsHit)
    {
        painter->setBrush(QColor(200,100,100));
    }
    else
    {
        painter->setBrush(QColor(35,200,100));
    }
    painter->setPen(QPen(Qt::darkBlue,  0.1 / m_Koafs_H_W.k));
    painter->drawEllipse(body->GetPosition().x / m_Koafs_H_W.kw , body->GetPosition().y / m_Koafs_H_W.kh,
                         shape.m_radius / m_Koafs_H_W.k , shape.m_radius / m_Koafs_H_W.k); // в пикселах !!!

}

Ball::~Ball()
{
    Clear();
}

void Ball::NextStep(double dt)
{      
    (void)dt;
}

void Ball::CheckCollisions(AnyObject * Object)
{
    if(this == Object)
        return;

    if(dynamic_cast<Brick*>(Object)) // тут только dynamic_cast , так как проверка !! if!!!
    {
        dynamic_cast<Brick*>(Object)->SetIsHit(true);
    }
}
