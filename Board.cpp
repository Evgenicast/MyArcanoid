#include "Board.h"
#include <QPainter>
#include <QDebug>

Board::Board(QSizeF &_worldSize, KoafSize &Koafs_H_W, b2World & world_)
:  DynamicObject(_worldSize, Koafs_H_W, world_)
{
//    SetBoard();
}

void Board::SetBoard()
{
    bodyDef.position.Set(5.0f, 19.0f);
    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
    body = world.CreateBody(&bodyDef);
    m_BoardShape.SetAsBox(1.5, 0.5);
    b2Fixture * fixture = body->CreateFixture(&m_BoardShape, 0.0f);
    fixture->SetRestitution(1.0f);
    fixture->SetRestitutionThreshold(0.0f);
    fixture->SetFriction(0.0f);
    fixture->SetDensity(0.5f);
    body->SetEnabled(true);
}

void Board::NextStep( double dt )
{
    (void)dt;
}

void Board::DrawSelf( QPainter * painter )
{
    painter->setBrush(QColor(0,0,0));
    painter->setPen(QPen(Qt::red, 3 ));
    painter->drawRect((body->GetPosition().x - 1.5) / m_Koafs_H_W.kw , body->GetPosition().y / m_Koafs_H_W.kh,
                      ((1.5 * 2) / m_Koafs_H_W.kw) , (0.5 / m_Koafs_H_W.kh) );
}

void Board::CheckCollisions(AnyObject * Object)
{
    if(this == Object)
        return;
}

void Board::Clear()
{
    body->GetWorld()->DestroyBody(body);
    //body = nullptr;
}

Board::~Board()
{
    Clear();
}
