#include "Game.h"
#include <QKeyEvent>
#include <QDebug>
#include <iostream>

Game::Game()
: world(gravity),
  m_Rooom(worldSize, m_Koafs_H_W, world),
  m_Board(worldSize, m_Koafs_H_W, world),
  m_Ball(worldSize, m_Koafs_H_W, world)
{
    world.SetContactListener(&MyListner);
}

void Game::InitBricks()
{
    int Row = static_cast<int>(worldSize.width()) - 1;
    int Col = 4;

    for ( int x = 1; x <= Row; x += 2 )
    {
        for( int y = 0; y < Col; ++y )
        {
            Brick * brick = new Brick(worldSize, m_Koafs_H_W, world);
            brick->SetPosition(static_cast<float>(x), static_cast<float>(y));
            brick->SetIsHit(false);
            m_BrickList.emplace_back(brick);
        }
    }
}

void Game::SetNewGame( bool IsNewGame )
{
    m_isNewGame = IsNewGame;
    SetGameOver(false );
    InitBricks();
    m_Board.SetBoard();
    m_Ball.SetBall(m_Board.GetBoardBody()->GetPosition().x, m_Board.GetBoardBody()->GetPosition().y);
    m_GameOverLBL.DestroyLabel(); //работает без проверки на состояние

}

void Game::DrawAll(QPainter * painter)
{
    if (m_isNewGame) // кирпичи есть, но не видны, можно сделать уровень с невидимыми кирпичами
    {
        m_Board.DrawSelf(painter);
        m_Ball.DrawSelf(painter);

        for (const auto & i : m_BrickList)
        {
            i->DrawSelf(painter);
        }
    }
}

void Game::GameOver()
{
    m_isGameOver = true;
    m_Ball.GetBodyPtr()->SetEnabled(false);
    m_Board.GetBoardBody()->SetEnabled(false);
    m_GameOverLBL.SetAnimation(WORLD_WIDTH, WORLD_HEIGHT, m_Koafs_H_W.kh, m_Koafs_H_W.kw);
    m_GameOverLBL.show();
    m_GameOverLBL.StartAnimation();
    //ClearRoom(); нет смысла. Алгоритм лямбды делает disable кирпичей и они не отображаются
}

void Game::ClearRoom()
{
    for (const auto & it : m_BrickList)
    {
        delete it;
    }
}

void Game::NextStep(double dt)
{
    world.Step(dt * 5.0, 6, 2); // вот тут можно с цветом поиграть. (как плохой вариант)
    m_BrickList.remove_if([](AnyObject * IsHit)
    {
        IsHit->SetStatus(Status::INVALID);
        return IsHit->GetIsHit();
    });

    float HeightInPixel = WORLD_HEIGHT / m_Koafs_H_W.kh;
    float BallPosInPix = m_Ball.GetBodyPtr()->GetPosition().y / m_Koafs_H_W.kh;;

    if(BallPosInPix > HeightInPixel && !GetIsGameOver())
    {
        GameOver();
    }
}

void Game::OnKeyPress(QKeyEvent * pe)
{    
    auto ball = m_Ball.GetBallBody();
    auto board = m_Board.GetBoardBody();
    switch (pe->key())
    {
    case Qt::Key_Up:
        ball->SetEnabled(true);
        break;
    case Qt::Key_Left:
        board->SetLinearVelocity({-2.5, 0.0});
        break;
    case Qt::Key_Right:
         board->SetLinearVelocity({2.5, 0.0});
        break;
    case Qt::Key_Down:
        ball->SetLinearVelocity({-0.5,  -1.5});
        break;
    case Qt::Key_P:
        ball->SetEnabled(false);
        break;
    }
    this->repaint();
}

void Game::OnKeyRelease(QKeyEvent * pe)
{
    auto board = m_Board.GetBoardBody();
    switch (pe->key())
    {
    case Qt::Key_Left:
        board->SetLinearVelocity({0.0, 0.0});
        break;
    case Qt::Key_Right:
        board->SetLinearVelocity({0.0, 0.0});
        break;
    }
}

Game::~Game()
{
    ClearRoom();
}

