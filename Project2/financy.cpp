#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include <windows.h>
class calendar
{
	int month, year, day = 0;
	std::string monthsList[12] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
	int mDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days;
	int current;
	int t[12] = { 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	int y = year % 100;
public:
	calendar()
	{
		std::cout << "Введите номер месяца: ";
		std::cin >> month;
		while (month < 1 || month > 12)
		{
			std::cout << "Неверно введён месяц. Введите номер месяца от 1 до 12, где \n 1 - январь \n 12 - декабрь";
			std::cin >> month;
		}
		std::cout << "Введите номер года от 1900 до 2035: ";
		std::cin >> year;
		while (year < 1900 || year > 2035)
		{
			std::cout << "Неверно введён год. Введите число от 1900 до 2035:\n";
			std::cin >> year;
		}
		current = y / 12 + y % 12 + y % 12 / 4 + t[month - 1] +
			(20 - year / 100);
		if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month <= 2)
			current--;
		current = current % 7;
		if (month == 2)
		{   // 1 - это февраль месяц, так как счёт начинается с 0.
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
			{
				days = 29; // Если високосный
			}
			else
			{
				days = mDays[month - 1];
			}
		}
		else
		{
			days = mDays[month - 1];
		}
		std::cout << "\nВведи день ";
		std::cin >> day;
		while (day > days || day <= 0)
		{
			std::cout << "\nНеверно Введи день ";
			std::cin >> day;
		}
		/*day += 20;
		if (day > days)
		{
			day = day - days;
			if (month != 12)
			{
				month++;
			}
			else
			{
				year++;
				month = 1;
			}
		}*/
	}
};
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
class category;
class operaci
{
	calendar date;
	int sum;
public:
	operaci(int gg)
	{
		sum = gg;
	}
	void add(category* cat, operaci& op)
	{
		cat.add(op);
	}

};
class category{};
operaci::operaci() { cat = new category; }
class category
{
	std::vector<operaci> transport, food, supermarkets, health, entertainments;
public:
	void add(operaci op)
	{

		int choose = 1, x = 1;
		
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
					transport.push_back(op);
				if (x == 2)
					food.push_back(op);
				if (x == 3)
					supermarkets.push_back(op);
				if (x == 4)
					health.push_back(op);
				if (x == 5)
					entertainments.push_back(op);
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
	void traty(std::vector<operaci>& op)
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
			op.push_back(sum);
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
void primenenie(int x, std::vector<walet>& walet, std::vector<operaci>&op, category &cat)
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
										walet.at(x).traty(op);
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
	std::vector<operaci>op;
	category cat;
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
			primenenie(x, walet,op,cat);
		}break;
		}
	} while (x != 0);
}
