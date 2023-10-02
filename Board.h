#ifndef BOARD_H
#define BOARD_H
#include "DynamicObject.h"
#include <QVector2D>

class QPainter;

class Board : public DynamicObject
{
private:

    b2PolygonShape m_BoardShape;

public:
    Board() = delete;
    Board(QSizeF &_worldSize, KoafSize & Koafs_H_W, b2World & world_);
    void SetBoard();

    void SetImIt(const bool & IsHit) { m_IsHit = IsHit; }
    b2Body * GetBoardBody() const { return body ;}

    void NextStep(double dt) override;
    void DrawSelf(QPainter * painter) override;
    void CheckCollisions(AnyObject * Object) override;

    void Clear();
    ~Board();
};

#endif // BOARD_H
