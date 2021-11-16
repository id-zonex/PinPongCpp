#include "Ball.h"
#include "Library.h"
#include "Vector2.h"
#include "windows.h"


Ball::Ball(int mapSizeX, int mapSizeY, Platform* playerPlatform, char submol)
 : _mapSizeX(mapSizeX),
  _mapSizeY(mapSizeY),
  _playerPlatform(playerPlatform),
  Submol(submol)
{
    _position = Vector2( mapSizeX / 2, mapSizeY / 2 );
}

Ball::Ball(int mapSizeX, int mapSizeY, Platform* playerPlatform, Vector2 startPos, char submol)
  : _mapSizeX(mapSizeX),
  _mapSizeY(mapSizeY),
  _playerPlatform(playerPlatform),
  Submol(submol),
  _position(startPos)
{}

void Ball::MoveBall()
{
    MoveDirection = CheckCollision();

    SetPosition(Vector2(_position.X + MoveDirection.X, _position.Y + MoveDirection.Y));
}

void Ball::WriteBall()
{
    Clear();
    Renderer::WriteOfPosition(_position, Submol);
}

Vector2 Ball::CheckCollision()
{
    Vector2 newDirection = MoveDirection;

    if (_position.Y - 1 <= 0 || _position.Y >= _mapSizeY)
        newDirection.Y *= -1;

    if (_position.X - 1 <= 0 || _position.X >= _mapSizeX)
        newDirection.X *= -1;

    Vector2 playerLocation = _playerPlatform->GetLocation();

    if (_position.X + 3 >= playerLocation.X  && (_position.Y + 1 >= playerLocation.Y && _position.Y - 1 <= playerLocation.Y + _playerPlatform->GetSize()))
    {
        Score++;
        newDirection.X *= -1;

        SetPosition(Vector2(_position.X - 2, _position.Y));
        Clear();
    }

    return newDirection;
}

void Ball::SetPosition(const Vector2& newPosition)
{
    _oldPosition = _position;

    _position = newPosition;
}

void Ball::Clear()
{
   Renderer::WriteOfPosition(_oldPosition, ' ');
}

Vector2 Ball::GetPosition()
{
    return _position;
}
