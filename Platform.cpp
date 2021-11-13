#include "Library.h"
#include "Platform.h"

Platform::Platform(Vector2 position, int border, int size) : _position(position), _border(border), _size(size)
{}

void Platform::ControlePlatform()
{
    _yDirection = 0;

    if (GetAsyncKeyState('W') && _position.Y - 1 > 0)
        _yDirection = -1;

    if (GetAsyncKeyState('S') && _position.Y + _size < _border)
        _yDirection = 1;

    _position.Y += _yDirection;

    if (_yDirection != 0)
        WritePlatform();
}

void Platform::WritePlatform()
{
    for (SHORT y = 0; y <= _size; y++)
        Renderer::WriteOfPosition(Vector2{ _position.X, _position.Y + y }, '#');

    if (_yDirection > 0)
        Renderer::WriteOfPosition(Vector2{ _position.X, _position.Y - _yDirection }, ' ');
    else if (_yDirection < 0)
        Renderer::WriteOfPosition(Vector2{ _position.X, (_position.Y + _size + _yDirection) + 2 }, ' ');
}

Vector2 Platform::GetLocation()
{
    return _position;
}

int Platform::GetSize() 
{
    return _size;
}
