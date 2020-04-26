#include "game_of_life.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

bool game_of_life::slucajna_vrijednost()
{

	if ((rand() % 4) > 0)
		return false;
	else
		return true;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (i < 0 || j < 0 || i>20 || j>40)
	{
		return false;
	}
	else
	{
		if (_generacija[i][j])
			return true;
		else
			return false;
	}
}

game_of_life::game_of_life()
{
	srand(time(0));
	for (i = 0; i < 20; i++)
		for (j = 0; j < 40; j++)
		{
			if (slucajna_vrijednost())
			{
				_generacija[i][j] = true;
			}
			else
			{
				_generacija[i][j] = false;
			}
		}
}

void game_of_life::sljedeca_generacija()
{

	for(i=0;i<20;i++)
		for (j = 0; j < 40; j++)
		{
			int b = 0;
			if (celija_zauzeta(i-1,j-1))
			{
				++b;
			}
			if (celija_zauzeta(i-1, j))
			{
				++b;
			}
			if (celija_zauzeta(i, j-1))
			{
				++b;
			}
			if (celija_zauzeta(i+1, j-1))
			{
				++b;
			}
			if (celija_zauzeta(i-1, j+1))
			{
				++b;
			}
			if (celija_zauzeta(i+1, j))
			{
				++b;
			}
			if (celija_zauzeta(i, j+1))
			{
				++b;
			}
			if (celija_zauzeta(i+1, j+1))
			{
				++b;
			}
			if (b == 3 && _generacija[i][j] == false)
			{
				_sljedeca_generacija[i][j] = true;
			}
			else
				if (b < 2 || b >3)
				{
					_sljedeca_generacija[i][j] = false;
				}
				else

					_sljedeca_generacija[i][j] = _generacija[i][j];

		}

	for (i = 0; i < 20; i++)
		for (j = 0; j < 40; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}

}

void game_of_life::iscrtaj()
{

	for (i = 0; i < 20; i++)
	{
		cout << endl;
		for (j = 0; j < 40; j++)
		{
			if (_generacija[i][j])
				cout << '*';
			else
				cout << '_';
		}
	}

}
