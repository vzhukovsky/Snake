#include "Field.h"
//#include <iostream>
//#include <windows.h>


Field::Field(int col, int row, int scale) : _col(col), _row(row), _scale(scale)
{

}

int Field::GetColCount()
{
	return this->_col;
}

int Field::GetRowCount()
{
	return this->_row;
}

int Field::GetScale()
{
	return _scale;
}

void Field::Draw()
{
	static int angle = 10;
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);

	// this->col + 1 because 25 cell = 26 vectical lines
	for(int i = 1; i <= this->_col + 1; i++)
	{
		glVertex2f(i * _scale, _scale);
		glVertex2f(i * _scale, _scale * (this->_row + 1));
	}

	for (int i = 1; i <= this->_row + 1; i++)
	{
		glVertex2f(_scale, _scale * i);
		glVertex2f((this->_col + 1) * _scale, _scale * i);
	}
	
	glEnd();
}

void Field::Resize(int weignt, int height)
{
	//_weight = weignt;
	//_height = height;
}


Field::~Field(void)
{
}
