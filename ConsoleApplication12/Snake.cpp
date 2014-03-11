#include "Snake.h"

Snake::Snake(int size, Field &field): _size(size), _field(field)
{
	arr = new COORD [_size];

	for (int i = 0; i < size; i++)
	{
		arr[i].X = 5 + i;
		arr[i].Y = 5; 
	}

	// Right
	_dx = 1;
	_dy = 0;
	_direction = RIGHT;
}

Snake::~Snake()
{
	delete [] arr;
}

void Snake::Draw()
{
	glColor3f(1, 0, 0);
	//glBegin(GL_POLYGON);

	float x1, y1, x2, y2;

	for(int i = 0; i < _size; i++)
	{
		x1 = arr[i].X * _field.GetScale() + _field.GetScale() * 0.15;
		y1 = arr[i].Y * _field.GetScale() + _field.GetScale() * 0.15;

		x2 = (arr[i].X + 0.9) * _field.GetScale();
		y2 = (arr[i].Y + 0.9) * _field.GetScale();

		glRectf(x1, 
				y1,
				x2,
				y2
				);
	}

	//glEnd();
}

bool Snake::Move()
{
	COORD next;

	next.X = arr[_size - 1].X + _dx;
	next.Y = arr[_size - 1].Y + _dy;

	if (next.X == 0 || next.X == _field.GetColCount() + 1 || next.Y == 0 || next.Y == _field.GetRowCount() + 1)
	{
		return false;
	}
	for (int i = 0; i < _size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}

	arr[_size - 1] = next;
}

void Snake::Left()
{
	if (_direction != RIGHT)
	{
		_dx = -1;
		_dy = 0;
		_direction = LEFT;
	}
}

void Snake::Right()
{
	if (_direction != LEFT)
	{
		_dx = 1;
		_dy = 0;
		_direction = RIGHT;
	}
}

void Snake::Up()
{
	if (_direction != DOWN)
	{
		_dx = 0;
		_dy = 1;
		_direction = UP;
	}
}

void Snake::Down()
{
	if (_direction != UP)
	{
		_dx = 0;
		_dy = -1;
		_direction = DOWN;
	}
}