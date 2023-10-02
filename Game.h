#ifndef GAME_H
#define GAME_H

#include <Box2D/box2d/box2d.h>
#include "AnyObject.h"
#include "Ball.h"
#include "Board.h"
#include "Brick.h"
#include "Room.h"
#include "MyWidgets.h"
#include <vector>
#include <list>
#include <QtWidgets>

class QPainter;
class QKeyEvent;

constexpr float WORLD_WIDTH = 10.0f; // meters (According to Box2dReqiurements the less = the better)
constexpr float WORLD_HEIGHT = 20.0f;

class MyContactListener : public b2ContactListener
{
    void BeginContact(b2Contact * contact)
    {
        auto bodyAUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        auto bodyBUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyAUserData.pointer && bodyBUserData.pointer )
        reinterpret_cast<AnyObject*>(bodyAUserData.pointer)->CheckCollisions(reinterpret_cast<AnyObject*>(bodyBUserData.pointer));
    }
};

class Game : public QWidget
{
        Q_OBJECT
private:

    QSizeF worldSize{WORLD_WIDTH, WORLD_HEIGHT};
    KoafSize m_Koafs_H_W;
    double kSize;

    bool m_isGameOver;
    bool m_isNewGame = false;

    MyContactListener MyListner;
    b2ContactListener listner;
    b2Vec2 gravity{0, 0};
    b2World world;

    Room m_Rooom;
    Board m_Board;
    Ball m_Ball;
    gameover::MyLabel m_GameOverLBL;

    std::list<AnyObject *> m_BrickList;

public:

    Game();

    void handleContact(Ball * BallPtr, Brick * BrickPtr);
    const QSizeF GetWorldSize() const { return worldSize; }// копия: нам нужно только для расчетов.
                                                            // конст - на всякий случай.
    void Set_kSize( double k ) { kSize = k; }
    void SetKSizeAdvance( double k, double kh, double kw) { m_Koafs_H_W.k = k; m_Koafs_H_W.kh = kh; m_Koafs_H_W.kw = kw; }

    void InitBricks();
    void SetNewGame( bool IsNewGame );
    void SetGameOver( bool IsGameOver) { m_isGameOver = IsGameOver; }

    const double & GetkSize() const { return kSize; }
    const KoafSize & GetKSizeAdvance() const { return m_Koafs_H_W; }
    const bool & GetIsGameOver() const { return m_isGameOver; }
    const bool & GetIsNewGame() const { return m_isNewGame; }

    Brick * CreateBrick(float x, float y, const float width, const float height);

    void NewGame();
    void GameOver();

    void ClearRoom();

    void DrawAll(QPainter *painter);
    void NextStep(double dt);
    void OnKeyPress(QKeyEvent *pe);
    void OnKeyRelease(QKeyEvent *pe);

    ~Game();
signals:
    void SignalGameOver();

//public slots:
//    void SlotNewGame();
};

#endif // GAME_H
