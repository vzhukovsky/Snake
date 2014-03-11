#include "Field.h"

class  Snake
{
private:
	int _size;
	Field &_field; 
	COORD *arr;

	int _dx, _dy; // new coordinates

	enum MyEnum
	{
		LEFT,
		RIGHT, 
		UP,
		DOWN
	};

	int _direction;

public:
	 Snake(int size, Field &f);
	~Snake();

	void Draw();
	bool Move();

	void Left();
	void Right();
	void Up();
	void Down();

};
