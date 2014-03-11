#include <stdlib.h>
#include <glut.h>

#include "Field.h"
#include "Snake.h"

using namespace std;


int column = 25;
int row = 15;
int scale = 25;

int weight = scale * (column + 2);
int height = scale * (row + 2);
int delay = 250;

Field myField(column, row, scale);
Snake mySnake(5, myField);

void Display() 
{
	//static int angle = 10;
	glClear(GL_COLOR_BUFFER_BIT);

	if (!mySnake.Move())
		exit(0);
	//glRotated(angle++, 1, 1, 0);
	//if (angle == 180)
		//angle = 0;
	myField.Draw();
	mySnake.Draw();

	glFlush();
}

void timer(int)
{
	Display();
	glutTimerFunc(delay, timer, 0);
}

void keyboard(int ch, int x, int y)
{
	switch (ch)
	{
	case 100:
		{
			mySnake.Left();
		}
		break;

	case 103:
		{
			mySnake.Up();
		}
		break;

	case 102:
		{
			mySnake.Right();
		}
		break;

	case 101:
		{
			mySnake.Down();
		}
		break;


	default:
		mySnake.Move();
	}
}

void Initialize() 
{
	glClearColor(0, 0, 0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, weight, height, 0);
	//glRotated(90, 0, 0, 1);
	//glScaled(-1, 0, -1);
}

int CALLBACK WinMain(HINSTANCE hThis, HINSTANCE hPrev, LPSTR cmdLine, int hShowMode)
{	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(weight, height);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("Snake :D");
	glutDisplayFunc(Display);
	glutSpecialFunc(keyboard);
	glutTimerFunc(delay, timer, 0);
	Initialize();

	glutMainLoop();
	return 0;
}