#include <iostream> 
#include <string> 
#include <ctime> 
#include <sstream> 

const int SIZE = 9;

class TicTacToe
{

private:
	std::string field[SIZE] = { "0","1","2","3","X","5","6","7","8" };
	int num;

public:

	int counter = 0;

	TicTacToe()
	{
	}

	void readNum()
	{
		std::cout << "Введите номер, куда будете ставить нолик:" << std::endl;
		std::cin >> num;
		if ((field[num] != "O") && (field[num] != "X"))
		{
			setO(num);
		}
		else
		{
			std::cout << "Эта ячейка недоступна, выберите другую:" << std::endl;
			readNum();
		}
	}

	void setX()
	{

		switch (counter)
		{
		case 0:
		{
			if (field[0] != "O")
				field[0] = "X";
			else
				field[2] = "X";
			break;
		}
		case 1:
		{
			if (field[1] == "O")
				field[6] = "X";
			else
				if (field[3] == "O")
					field[2] = "X";
				else
					field[testPreWin()] = "X";
			break;
		}
		default:
		{
			if (testPreWin() == -1)
				field[randNum()] = "X";
			else
				field[testPreWin()] = "X";
			break;
		}
		}
		counter++;
	}

	int randNum()
	{
		int num;
		while (true)
		{
			num = rand() % 9;
			if ((field[num] != "X") && (field[num] != "O"))
				break;
		}
		return num;
	}

	void setO(int num)
	{
		field[num] = 'O';
	}

	void getField()
	{
		for (int i = 0; i < SIZE; i++)
		{
			std::cout << field[i] << " ";
			if ((i == 2) || (i == 5) || (i == 8))
				std::cout << std::endl;
		}
	}

	std::string to_string(int n)
	{
		std::ostringstream ss;
		ss << n;
		return ss.str();
	}

	int testPreWin()
	{
		for (int i = 0; i <= 6; i += 3)
		{
			if ((field[i] == field[i + 1]) && (field[i + 2] == to_string(i + 2))) return i + 2;
			if ((field[i] == field[i + 2]) && (field[i + 1] == to_string(i + 1))) return i + 1;
			if ((field[i + 1] == field[i + 2]) && (field[i] == to_string(i))) return i;
		}

		for (int i = 0; i <= 2; i++)
		{
			if ((field[i] == field[i + 3]) && (field[i + 6] == to_string(i + 6))) return i + 6;
			if ((field[i] == field[i + 6]) && (field[i + 3] == to_string(i + 3))) return i + 3;
			if ((field[i + 3] == field[i + 6]) && (field[i] == to_string(i))) return i;
		}

		if ((field[0] == field[4]) && (field[8] == "8")) return 8;
		if ((field[0] == field[8]) && (field[4] == "4")) return 4;
		if ((field[8] == field[4]) && (field[0] == "0")) return 0;

		if ((field[2] == field[4]) && (field[6] == "6")) return 6;
		if ((field[2] == field[6]) && (field[4] == "4")) return 4;
		if ((field[6] == field[4]) && (field[2] == "2")) return 2;

		return -1;
	}

	std::string testWin()
	{
		if (((field[0] == field[4]) && (field[0] == field[8]))
			|| ((field[2] == field[4]) && (field[2] == field[6])))
			return field[4];

		for (int i = 0; i < 3; i++)
		{
			if ((field[i] == field[i + 3]) && (field[i] == field[i + 6]))
				return field[i];
			if ((field[i * 3] == field[(i * 3) + 1]) && (field[i * 3] == field[(i * 3) + 2]))
				return field[i * 3];
		}

		return "E";
	}
};

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(0));

	TicTacToe game;
	std::string test;

	while (true)
	{
		system("cls");
		game.getField();
		game.readNum();
		game.setX();
		test = game.testWin();

		if (game.counter == 4)
		{
			system("cls");
			game.getField();
			std::cout << "\nНичья\n" << std::endl;
			break;
		}

		if (test != "E")
		{
			system("cls");
			game.getField();
			std::cout << "\nВыиграл " << game.testWin() << std::endl << std::endl;
			break;
		}
	}

	system("pause");
	return 0;
}