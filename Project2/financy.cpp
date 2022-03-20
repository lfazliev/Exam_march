#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include <windows.h>
void showmenutrat(int iItem)
{
	if (iItem == 1) std::cout << "";
	else std::cout << "	";
	std::cout << "1 - Транспорт\n";
	if (iItem == 2) std::cout << "";
	else std::cout << "	";
	std::cout << "2 - Еда\n";
	if (iItem == 3) std::cout << "";
	else std::cout << "	";
	std::cout << "3 - Супермаркеты\n";
	if (iItem == 4) std::cout << "";
	else std::cout << "	";
	std::cout << "4 - Здоровье\n";
	if (iItem == 5) std::cout << "";
	else std::cout << "	";
	std::cout << "5 - Развлечения\n";
}
class expenses
{
	std::vector<int> transport, food, supermarkets, health, entertainments;
	int mouth, day;
public:
	void add(int sum)
	{
		int choose = 1, x = 1;
		std::cout << "Введите дату операции: месяц, день(в формате 10 26)";
		std::cin >> mouth;
		std::cin >> day;
		do
		{
			system("cls");
			showmenutrat(x);
			choose = _getch();
			switch (choose)
			{
			case 72:
			{
				if (x != 1)
					x--;
			}break;
			case 80:
			{
				if (x != 5)
					x++;
			}break;
			case 13:
			{
				if (x == 1)
					transport.push_back(sum);
				if (x == 2)
					food.push_back(sum);
				if (x == 3)
					supermarkets.push_back(sum);
				if (x == 4)
					health.push_back(sum);
				if (x == 5)
					entertainments.push_back(sum);
				choose = 0;
			}break;
			}
		} while (choose != 0);
	}
};
class walet
{
	int balance = 0;
	std::string name;
	
public:
	walet()
	{
		std::cout<<"Введите название карты.. ";
		std::cin >> name;
	}
	
	std::string& getName() { return name; }
	void setName(const std::string& num) { name = num; }
	int& getBalance() { return balance; } 
	void setBalance(const int& num) { balance = num; }
	
	void refill(int balanc)
	{
		balance = balanc;
	}
	void traty()
	{
		int sum;
		std::cout << "Каковы траты? - ";
		while (!(std::cin >> sum) || (std::cin.peek() != '\n'))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Input error! Repeat please...\n";
		}
		if (sum <= balance)
		{
			trata.add(sum);
			balance =- sum;
		}
		else
		{
			std::cout << "Недостаточно средств\n";
			system("pause");
		}
	}
};
void ShowMenu(int iItem)//Меню
{
	if (iItem == 1) std::cout << "";
	else std::cout << "	";
	std::cout << "1 - Добавить карту\n";
	if (iItem == 2) std::cout << "";
	else std::cout << "	";
	std::cout << "2 - Выбрать из существующих\n";
	if (iItem == 3) std::cout << "";
	else std::cout << "	";
	std::cout << "3 - Выход\n";
}
void ShowMenuTwo(int iItem)//Меню
{
	if (iItem == 1) std::cout << "-";
	else std::cout << " ";
	std::cout << "1 - Да\n";
	if (iItem == 2) std::cout << "-";
	else std::cout << " ";
	std::cout << "2 - Нет\n";
	
}
void ShowCard(int iItem, std::vector<walet>& walet)
{
	for (int i = 0; i < walet.size(); i++)
	{
		if (iItem == i) std::cout << "-";
		else std::cout << " ";
		std::cout << i << walet.at(i).getName() << " - Карта\n";
	}
}
void ShowMenuThree(int iItem)
{
	if (iItem == 1) std::cout << "-";
	else std::cout << " ";
	std::cout << "1 - Пополнить\n";
	if (iItem == 2) std::cout << "-";
	else std::cout << " ";
	std::cout << "2 - Расходы\n";
	if (iItem == 3) std::cout << "-";
	else std::cout << " ";
	std::cout << "3 - Баланс\n";
	if (iItem == 4) std::cout << "-";
	else std::cout << " ";
	std::cout << "4 - Назад\n";
}
void primenenie(int x, std::vector<walet>& walet)
{
	switch (x)
	{
	case 1:
	{
		walet.resize(walet.size() + 1);
		x = 1;
		int choose;
		do
		{
			system("cls");
			std::cout << "\nГотово, карта номер " << walet.size() << "." << walet.at(walet.size() - 1).getName() << " добавлена, желаете её пополнить?\n";
			ShowMenuTwo(x);
			choose = _getch();
			switch (choose)
			{
			case 72:
			{
				if (x != 1)
					x--;
			}break;
			case 80:
			{
				if (x != 2)
					x++;
			}break;
			case 13:
			{
				if (x == 1)
				{
					int a;
					std::cout << "Сколько вы хотите положить? - ";
					while (!(std::cin >> a) || (std::cin.peek() != '\n'))
					{
						std::cin.clear();
						while (std::cin.get() != '\n');
						std::cout << "Input error! Repeat please...\n";
					}
					walet.at(walet.size() - 1).refill(a);
					x = 0;
				}
				else
				{
					x = 0;
				}
			}break;
			}
		} while (x != 0);

	}break;
	case 2:
	{
		x = 0;
		int choose = 1;
		if (walet.size() != 0)
		{
			do
			{
				system("cls");
				ShowCard(x, walet);
				choose = _getch();
				switch (choose)
				{
				case 72:
				{
					if (x != 0)
						x--;
				}break;
				case 80:
				{
					if (x != walet.size()-1)
						x++;
				}break;
				case 13:
				{
					int o = 1;
					int buf;
					do
					{
						system("cls");
						ShowMenuThree(o);
						choose = _getch();
						switch (choose)
						{
						case 72:
						{
							if (o != 1)
								o--;
						}break;
						case 80:
						{
							if (o != 4)
								o++;
						}break;
						case 13:
						{
							if (o == 1)
							{
								std::cout << "На сколько пополнить? ";
								std::cin >> buf;
								walet.at(x).setBalance(walet.at(x).getBalance() + buf);
								choose = 0;
							}
							else
							{
								if (o!=4)
								{
									if (o == 3)
									{
										std::cout << walet.at(x).getBalance() << "\n";
										system("pause");
										choose = 0;
									}
									else {
										walet.at(x).traty();
										choose = 0;
									}
								}
								else
								{
									choose = 0;
								}
							}
						}break;
						}
					} while (choose != 0);
				}
				}
			} while (choose != 0);
		}
	}break;
	
	}
}
int main()
{
	system("chcp 1251");
	int choose, x = 1;
	std::vector<walet> walet;
	do
	{
		system("cls");
		ShowMenu(x);
		choose = _getch();
		switch (choose)
		{
		case 72:
		{
			if (x!=1)
			x--;
		}break;
		case 80:
		{
			if(x!=3)
			x++;
		}break;
		case 13:
		{
			if (x == 3)
			{
				return 0;
			}
			else
			primenenie(x, walet);
		}break;
		}
	} while (x != 0);
}
