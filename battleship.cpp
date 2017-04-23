#include <iostream>
#include <ctime>

using namespace std;

const int DIM = 10;
int maxship = 10;
int matrix[DIM][DIM];

void clear()
{
	for (int i = 0; i < DIM; i++)
	{

		for (int j = 0; j < DIM; j++)
		{
			matrix[i][j] = 0;
		}
	}



}


void Show()
{
	for (int i = 0; i < DIM; i++)
	{

		for (int j = 0; j < DIM; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}



}
int NumberOfShips()
{

	int c = 0;
	for (int i = 0; i < DIM; i++)
	{

		for (int j = 0; j < DIM; j++)
		{
			if (matrix[i][j] == 1)
				c++;
			
		}
	}
	return c;
}
void SetShips()
{
	int s = 0;
	while (s < maxship)
	{
		int x = rand() % rows;
		int y = rand() % elements;
		if (matrix[x][y] != 1)
		{
			s++;
			matrix[x][y] = 1;
		}
	}

}

bool Attack(int x, int y)
{
	bool false;
	if (matrix[x][y] == 1)
	{
		matrix[x][y] = 2;
		false = true;
	}
	return false;
}
int main()
{


	srand(time(NULL));
	clear();
	SetShips();
	int pos1, pos2;
	char prompt;
	while (1)
	{
		cout << "Please input location "; cin >> pos1 >> pos2;
		if (Attack(pos1, pos2))
			cout << "HIT!" << endl;
		else
			cout << "MISS!" << endl;
		cout << "Number of Ships lef: " << NumberOfShips() << endl;
		cout << "Do you want to give up? (y/n)";
		cin >> prompt;
		if (prompt == 'y')
			break;
	}
	cout << "Game over! " << endl;
	Show();

	system("pause");
	return 0;


}
