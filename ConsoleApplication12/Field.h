#pragma once
#include <stdlib.h>
#include <glut.h>
#include <Windows.h>

class Field
{
private:
	int _col;
	int _row;

	int _scale;

public:
	Field(int col, int row, int scale);

	int GetColCount();
	int GetRowCount();
	int GetScale();
	void Draw();
	void Resize(int weignt, int height);

	~Field(void);
};

