// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

bool gameOver;

const int width = 80;
const int height = 40;

int x, y, fruitX, fruitY, score;

enum eDirection{STOP = 0, LEFT,RIGHT,UP,DOWN};
eDirection direction;

void Setup()
{
	srand(time(NULL));
	gameOver = false;

	direction = STOP;
	x = width / 2;
	y = height / 2;

	fruitX = rand() % width;
	fruitY = rand() % height;

	score = 0;
}

void Draw()
{
	system("cls");

	for (int i = 0; i < width +1; i++) cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width -1) cout << "#";
			if (i == y && j == x) cout << "@";
			else if (i == fruitY && j == fruitX) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < width +1; i++) cout << "#";
	cout << endl;

	cout << "SCORE: " << score << endl;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			direction = LEFT;
			break;
		case 'd':
			direction = RIGHT;
			break;
		case 'w':
			direction = UP;
			break;
		case 's':
			direction = DOWN;
			break;
		}
	}

}

void Logic()
{
	switch (direction)
	{
	case LEFT:
		x -= 1;
		break;
	case RIGHT:
		x += 1;
		break;
	case UP:
		y -= 1;
		break;
	case DOWN:
		y += 1;
		break;
	}

	if (x > width - 1 || y > height - 1 || x < 1 || y < 1) gameOver = true;

	if (x == fruitX && y == fruitY)
	{
		score++;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
}

int main()
{
	Setup();

	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
