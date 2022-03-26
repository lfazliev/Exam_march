#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include <algorithm>
void ShowMenuTwo(int iItem)//Меню
{
	if (iItem == 1) std::cout << "-";
	else std::cout << " ";
	std::cout << "1 - Да\n";
	if (iItem == 2) std::cout << "-";
	else std::cout << " ";
	std::cout << "2 - Нет\n";
}
void save(std::ofstream &cold, std::string &record)
{
	int choose = 1, o = 1;
	do
	{
		system("cls");
		std::cout << "Хотите сохранить?\n";
		ShowMenuTwo(o);
		choose = _getch();
		switch (choose)
		{
		case 72:
		{
			if (o == 2)
				o--;
		}break;
		case 80:
		{
			if (o == 1)
				o++;
		}break;
		case 13:
		{
			if (o == 1)
			{
				if (cold.is_open())
				{
					cold << record;
					record.clear();
					cold.close();
				}
			}
			record.clear();
			cold.close();
			choose = 0, o = 1;
		}break;
		}

	} while (choose != 0);
}
void showmenutrat(int iItem, std::vector<std::string> cat)
{
	int i = 0;
	for (i; i < cat.size(); i++)
	{
		if (iItem == i) std::cout << "-";
		else std::cout << " ";
		std::cout << i + 1 << "." << cat.at(i) << "\n";
	}
	if (iItem == i) std::cout << "-";
	else std::cout << " ";
	std::cout << "Добавить категорию\n";
	if (iItem == i+1) std::cout << "-";
	else std::cout << " ";
	std::cout << "Отмена\n";
}
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
	std::cout << "3 - Сформировать отсчёт\n";
	if (iItem == 4) std::cout << "";
	else std::cout << "	";
	std::cout << "4 - Сформировать рейтинг\n";
	if (iItem == 5) std::cout << "";
	else std::cout << "	";
	std::cout << "5 - Выход\n";
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
	std::cout << "4 - Удалить\n";
	if (iItem == 5) std::cout << "-";
	else std::cout << " ";
	std::cout << "5 - Назад\n";
}
void ShowMenufour(int iItem)
{
	if (iItem == 0) std::cout << "-";
	else std::cout << " ";
	std::cout << "За день\n";
	if (iItem == 1) std::cout << "-";
	else std::cout << " ";
	std::cout << "За неделю\n";
	if (iItem == 2) std::cout << "-";
	else std::cout << " ";
	std::cout << "За месяц\n";
	if (iItem == 3) std::cout << "-";
	else std::cout << " ";
	std::cout << "Назад\n";
}
void ShowMenuSix(int iItem)
{
	if (iItem == 1) std::cout << "-";
	else std::cout << " ";
	std::cout << "За неделю\n";
	if (iItem == 2) std::cout << "-";
	else std::cout << " ";
	std::cout << "За месяц\n";
	if (iItem == 3) std::cout << "-";
	else std::cout << " ";
	std::cout << "Назад\n";
}
void ShowMenufive(int iItem)
{
	if (iItem == 1) std::cout << "-";
	else std::cout << " ";
	std::cout << "Топ 3 затрат\n";
	if (iItem == 2) std::cout << "-";
	else std::cout << " ";
	std::cout << "Топ 3 категорий\n";
	if (iItem == 3) std::cout << "-";
	else std::cout << " ";
	std::cout << "Назад\n";
}
class calendar
{
	int month, year, day = 0;
	std::string monthsList[12] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
	int mDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days;
	int current;
	int t[12] = { 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
private:
	void scet()
	{
		int y = year % 100;
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
	}
public:
	int& getDay() { return day; }
	void setDay(const int& num) { day = num; }
	int& getMonth() { return month; }
	void setMonth(const int& num) { month = num; }
	int& getYear() { return year; }
	void setYear(const int& num) { year = num; }
	int& getDays() { return days; }
	calendar(){}
	calendar(const calendar& other)
	{
		 this->days = other.days;
		 this->current = other.current;
		 this->month = other.month;
		 this->year = other.year;
		 this->day = other.day;
	}
	void add(int pol)
	{
		std::cout << "Введите номер года от 1900 до 2035: ";
		std::cin >> year;
		while (year < 1900 || year > 2035)
		{
			std::cout << "Неверно введён год. Введите число от 1900 до 2035:\n";
			std::cin >> year;
		}
		std::cout << "Введите номер месяца: ";
		std::cin >> month;
		while (month < 1 || month > 12)
		{
			std::cout << "Неверно введён месяц. Введите номер месяца от 1 до 12, где \n 1 - январь \n 12 - декабрь ";
			std::cin >> month;
		}
		scet();
		switch (pol)
		{
		case 0:
		{
			std::cout << "Введи день ";
			std::cin >> day;
			while (day > days || day <= 0)
			{
				std::cout << "\nНеверно Введи день ";
				std::cin >> day;
			}
		}break;
		case 1:
		{
			std::cout << "Введи день с которого начнётся неделя\n";
			std::cin >> day;
			while (day > days || day <= 0)
			{
				std::cout << "\nНеверно Введи день ";
				std::cin >> day;
			}
		}break;
		case 2:
		{
			day = 1;
		}break;
		}
		
	}
	void perasch()
	{
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
		}
		scet();
	}
};
class card
{
	int balance = 0;
	std::string name;
public:
	card()
	{
		std::cout << "Введите название карты.. ";
		std::cin >> name;
	}
	std::string& getName() { return name; }
	void setName(const std::string& num) { name = num; }
	int& getBalance() { return balance; }
	void setBalance(const int& num) { balance = num; }
	void add(int a)
	{
		balance += a;
	}
	void addmoney(int buf)
	{
		if (buf > 0)
		{
			balance = balance + buf;
		}
		else
			std::cout << "\nПрикол\n";
	}
	void tratim(int A, int&B)
	{
		if (A <= balance)
		{
			balance = balance - A;
			B = 1;
		}
		else
			std::cout << "Денег нет" << std::endl;
		system("pause");
	}
};
void ShowCard(int iItem, std::vector<card> card)
{
	int i = 0;
	for (i; i < card.size(); i++)
	{
		if (iItem == i) std::cout << "-";
		else std::cout << " ";
		std::cout << i+1 << "." << card.at(i).getName() << " - Карта\n";
	}
	if (iItem == i) std::cout << "-";
	else std::cout << " ";
	std::cout << "Назад\n";
}
class operaci
{
	calendar date;
	int cost, type;
public:
	calendar getDate() { return date; }
	void setDate(calendar param) { date = param; }
	int& getCost() { return cost; }
	void setCost(const int& num) { cost = num; }
	int& getType() { return type; }
	void setType(const int& num) { type = num; }
	operaci(int b)
	{
		date.add(0);
		cost = b;
	
	}
	operaci(){}
	operaci(const operaci& other)
	{
		this->cost = other.cost;
		this->date = other.date;
		this->type = other.type;
	}
};
class walet
{
	std::vector<card> carda;
	std::vector<operaci> oper;
	std::vector<std::string> category;
private:
	void recrep(calendar dat, int B,int &A, std::string &record)
	{
		for (int i = 0; i < oper.size(); i++)
		{
			if (oper.at(i).getDate().getYear() == dat.getYear())
			{
				if (oper.at(i).getDate().getMonth() == dat.getMonth())
				{
					if (B != 1)
					{
						if (oper.at(i).getDate().getDay() == dat.getDay())
						{
							A++;
							record = record + std::to_string(A) + '.' + std::to_string(oper.at(i).getCost());
							printcat(oper.at(i).getType(), record);
						}
					}
					else
					{
						A++;
						record = record + std::to_string(A) + '.' + std::to_string(oper.at(i).getCost());
						printcat(oper.at(i).getType(), record);
					}
				}
			}
		}
	}
	void rectop(calendar dat, int B, std::vector<operaci>& list)
	{
		for (int i = 0; i < oper.size(); i++)
		{
			if (oper.at(i).getDate().getYear() == dat.getYear())
			{
				if (oper.at(i).getDate().getMonth() == dat.getMonth())
				{
					if (B == 0)
					{
						if (oper.at(i).getDate().getDay() == dat.getDay())
						{
							list.push_back(oper.at(i));
						}
					}
					else
					{
						list.push_back(oper.at(i));
					}
					
				}
			}
		}
	}
public:
	void setCarda(const std::vector<card>& num) { carda = num; }
	std::vector<card>& getCarda() { return carda; }
	void setOper(const std::vector<operaci>& num) { oper = num; }
	std::vector<operaci>& getOper() { return oper; }
	std::vector<std::string>& getCateg() { return category; }
	walet()
	{
		category.push_back("Дом");
		category.push_back("Еда");
		category.push_back("Долги");
		category.push_back("Транспорт");
		category.push_back("Счета и услуги");
		category.push_back("Личные расходы");
		category.push_back("Сбережения");
	}
	void addcat()
	{
		std::cout << "Введите названик категории... ";
		category.resize(category.size() + 1);
		std::cin >> category.at(category.size() - 1);
	}
	void printcat(int type, std::string& record)
	{
		for (int i = 0; i < category.size(); i++)
		{
			if (type == i)
				record = record + ' ' + category.at(i) + '\n';
		}
	}
	void addcard()
	{
		carda.resize(carda.size() + 1);
		int choose, o = 1;
		do
		{
			system("cls");
			std::cout << "\nГотово, карта номер " << carda.size() << "." << carda.at(carda.size() - 1).getName() << " добавлена, желаете её пополнить?\n";
			ShowMenuTwo(o);
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
				if (o != 2)
					o++;
			}break;
			case 13:
			{
				if (o == 1)
				{
					int a;
					std::cout << "Сколько вы хотите положить? - ";
					while (!(std::cin >> a) || (std::cin.peek() != '\n'))
					{
						std::cin.clear();
						while (std::cin.get() != '\n');
						std::cout << "Input error! Repeat please...\n";
					}
					carda.at(carda.size() - 1).add(a);
				}
				o = 0;
			}break;
			}
		} while (o != 0);
	}
	void report(int F, std::string record, std::ofstream&cold)
	{
		calendar dat;
		int A = 0;
		switch (F)
		{
		case 0:
		{
			dat.add(F);
			recrep(dat, 0,A, record);
			std::cout << record;
			
		}break;
		case 1:
		{
			dat.add(F);
			for (int i = 0; i < 7; i++)
			{
				recrep(dat, 0,A, record);
				dat.setDay(dat.getDay() + 1);
				dat.perasch();
			}
			std::cout << record;
		}break;
		case 2:
		{
			dat.add(F);
			recrep(dat, 1,A,record);
			std::cout << record;
		}break;
		}
		system("pause");
		save(cold, record);
	}
	void topik(std::vector<operaci>& list, int pol)
	{
		calendar dat;
		switch (pol)
		{
		case 0:
		{
			dat.add(pol+1);
			for (int i = 0; i < 7; i++)
			{
				rectop(dat,pol, list);
				dat.setDay(dat.getDay() + 1);
				dat.perasch();
			}
		}break;
		case 1:
		{
			dat.add(pol+1);
			rectop(dat, pol, list);
		}break;

		}
	}
};
void primenenie(int x, walet& waleta)
{
	std::string naxo = "C:/Users/Ленар/Desktop/File.financi.txt", record;
	std::ofstream cold;
	switch (x)
	{
	case 1:
	{
		waleta.addcard();
	}break;
	case 2:
	{

		if (waleta.getCarda().size() != 0)
		{
			int choose, o = 0, a = 1;
			do
			{
				system("cls");
				ShowCard(o, waleta.getCarda());
				choose = _getch();
				switch (choose)
				{
				case 72:
				{
					if (o != 0)
						o--;
				}break;
				case 80:
				{
					if (o != waleta.getCarda().size())
						o++;
				}break;
				case 13:
				{
					if (o != waleta.getCarda().size())
					{
						int choosa;
						do
						{
							system("cls");
							ShowMenuThree(a);
							choosa = _getch();
							switch (choosa)
							{
							case 72:
							{
								if (a != 1)
									a--;
							}break;
							case 80:
							{
								if (a != 5)
									a++;
							}break;
							case 13:
							{
								
								switch (a)
								{
								case 1:
								{
									int buf;
									std::cout << "На сколько пополнить? - ";
									std::cin >> buf;
									waleta.getCarda().at(o).addmoney(buf);
									choosa = 0;
								}break;
								case 2:
								{
									int A, B = 0, C = 1;
									std::cout << "Сколько тратим? - ";
									std::cin >> A;
									waleta.getCarda().at(o).tratim(A, B);
									if (B == 1)
									{
										waleta.getOper().push_back(operaci(A));
										int iltem = 0;
										do
										{
											
											system("cls");
											std::cout << "Выберите категорию\n";
											showmenutrat(iltem, waleta.getCateg());
											choose = _getch();
											switch (choose)
											{
											case 72:
											{
												if (iltem != 0)
													iltem--;
											}break;
											case 80:
											{
												if (iltem != waleta.getCateg().size() + 1)
													iltem++;
											}break;
											case 13:
											{
												if (iltem <= waleta.getCateg().size() - 1)
												{
													waleta.getOper().at(waleta.getOper().size()-1).setType(iltem);
													std::cout << "Операция добавлена\n";
													choose = 0;
													system("pause");
												}
												if (iltem == waleta.getCateg().size())
												{
													waleta.addcat();
												}
												if (iltem == waleta.getCateg().size() + 1)
												{
													choose = 0;
													C = 0;
												}
												iltem = 0;
											}break;
											}
										} while (choose != 0);
										if (C == 0)
										{
											waleta.getCarda().at(o).addmoney(A);
										}
									}
									choosa = 0;
								}break;
								case 3:
								{
									std::cout << waleta.getCarda().at(o).getBalance() << "\n";
									system("pause");
									choosa = 0;
								}break;
								case 4:
								{
									auto iter = waleta.getCarda().begin();
									waleta.getCarda().erase(iter + o);
									choosa = 0;
								}break;
								case 5:
								{
									o = 0;
									choosa = 0;
								}break;
								}
								a = 1;
								choosa = 0;
							}
							}
						} while (choosa != 0);
					}
					else
					{
						choose = 0;
					}
					o = 0;
				}break;
				}
			} while (choose != 0);
		}
		else
		{
			int choose = 1, o = 1;
			do
			{
				system("cls");
				std::cout << "Нет карт, хотите добавить?\n";
				ShowMenuTwo(o);
				choose = _getch();
				switch (choose)
				{
				case 72:
				{
					if (o == 2)
						o--;
				}break;
				case 80:
				{
					if (o == 1)
						o++;
				}break;
				case 13:
				{
					if (o == 1)
					{
						waleta.addcard();
					}
					choose = 0;
					o = 1;
				}break;
				}
			} while (choose != 0);
		}
	}break;
	case 3:
	{
		int o = 0, choose;
		if (waleta.getOper().size() != 0)
		{
			do
			{
				system("cls");
				ShowMenufour(o);
				choose = _getch();
				switch (choose)
				{
				case 72:
				{
					if (o != 0)
						o--;
				}break;
				case 80:
				{
					if (o != 3)
						o++;
				}break;
				case 13:
				{
					switch (o)
					{
					case 0:
					{
						cold.open(naxo);
						waleta.report(0, record, cold);
					}break;
					case 1:
					{
						cold.open(naxo);
						waleta.report(1, record, cold);
					}break;
					case 2:
					{
						cold.open(naxo);
						waleta.report(2, record, cold);
					}break;
					case 3:
					{
						choose = 0;
					}break;
					}
					system("pause");
					choose = 0;
					o = 0;
				}break;
				}
			} while (choose != 0);
		}
		else
		{
			std::cout << "Нет операций\n";
			system("pause");
		}
	}break;
	case 4:
	 {
		int o = 1, choosa;
		if (waleta.getOper().size() != 0)
		{
			do
			{
				system("cls");
				ShowMenufive(o);
				choosa = _getch();
				switch (choosa)
				{
				case 72:
				{
					if (o != 1)
						o--;
				}break;
				case 80:
				{
					if (o != 3)
						o++;
				}break;
				case 13:
				{
					switch (o)
					{
					default:
					case 1:
					{
						int a = 1, choose;
						do
						{
							system("cls");
							ShowMenuSix(a);
							choose = _getch();
							switch (choose)
							{
							case 72:
							{
								if (a != 1)
									a--;
							}break;
							case 80:
							{
								if (a != 3)
									a++;
							}break;
							case 13:
							{
								std::vector<operaci> lists;
								std::vector<operaci> top(3);
								top.resize(3);
								for (int i = 0; i < top.size(); i++)
								{
									top.at(i).setCost(1);
								}
								switch (a)
								{
								case 1:
								{
									waleta.topik(lists, 0);
								}break;
								case 2:
								{
									waleta.topik(lists, 1);
								}break;
								case 3:
								{
									choose = 0;
								}break;
								}
								if (choose != 0)
								{
									if (lists.size() == 1)
									{
										record = std::to_string(1) + '.' + std::to_string(lists.at(0).getCost()); waleta.printcat(lists.at(0).getType(), record);
										std::cout << record;
										system("pause");
										cold.open(naxo);
										save(cold, record);

									}
									if (lists.size() == 2)
									{
										for (int i = 0; i < lists.size(); i++)
										{
											if (lists.at(i).getCost() >= top.at(0).getCost())
											{
												top.at(1) = top.at(0);
												top.at(0) = lists.at(i);
											}
											else
											{
												if (lists.at(i).getCost() >= top.at(1).getCost())
												{
													top.at(1) = lists.at(i);
												}
											}
										}
										for (int i = 0; i < 2; i++)
										{
											record = record + std::to_string(i + 1) + '.' + std::to_string(top.at(i).getCost()); waleta.printcat(top.at(i).getType(), record);
										}
										std::cout << record;
										system("pause");
										cold.open(naxo);
										save(cold, record);

									}
									if (lists.size() >= 3)
									{
										for (int i = 0; i < lists.size(); i++)
										{
											if (lists.at(i).getCost() >= top.at(0).getCost())
											{
												top.at(2) = top.at(1);
												top.at(1) = top.at(0);
												top.at(0) = lists.at(i);
											}
											else
											{
												if (lists.at(i).getCost() >= top.at(1).getCost())
												{
													top.at(2) = top.at(1);
													top.at(1) = lists.at(i);
												}
												else
												{
													top.at(2) = lists.at(i);
												}
											}
										}
										for (int i = 0; i < top.size(); i++)
										{
											record = record + std::to_string(i + 1) + '.' + std::to_string(top.at(i).getCost()); waleta.printcat(top.at(i).getType(), record);

										}
										std::cout << record;
										system("pause");
										cold.open(naxo);
										save(cold, record);

									}
								}
								a = 1;
								choose = 0;
							}break;
							}
						} while (choose != 0);
					}break;
					case 2:
					{
						int a = 1, choose;
						do
						{
							system("cls");
							ShowMenuSix(a);
							choose = _getch();
							switch (choose)
							{
							case 72:
							{
								if (a != 1)
									a--;
							}break;
							case 80:
							{
								if (a != 3)
									a++;
							}break;
							case 13:
							{
								std::vector<operaci> lists;
								std::vector<int> top(3);
								std::vector<int> topcat(waleta.getCateg().size());
								top.resize(3);
								switch (a)
								{
								case 1:
								{
									waleta.topik(lists, 0);
								}break;
								case 2:
								{
									waleta.topik(lists, 1);
								}break;
								case 3:
								{
									choose = 0;
								}break;
								}
								if (choose != 0)
								{
									for (int i = 0; i < top.size(); i++)
									{
										top.at(i) = 0;
									}
									for (int i = 0; i < waleta.getCateg().size(); i++)
									{
										for (int j = 0; j < lists.size(); j++)
										{
											if (lists.at(j).getType() == i)
											{
												topcat.at(i) = topcat.at(i) + lists.at(j).getCost();
											}
										}
									}
									if (lists.size() == 1)
									{
										record = std::to_string(1) + '.' + std::to_string(lists.at(0).getCost());
										waleta.printcat(lists.at(0).getType(), record);
										std::cout << record;
										system("pause");
										cold.open(naxo);
										save(cold, record);
									}
									else
									{
										for (int i = 0; i < topcat.size(); i++)
										{
											if (topcat.at(i) >= topcat.at(top.at(0)))
											{
												top.at(2) = top.at(1);
												top.at(1) = top.at(0);
												top.at(0) = i;
											}
											else
											{
												if (topcat.at(i) >= topcat.at(top.at(1)))
												{
													top.at(2) = top.at(1);
													top.at(1) = i;
												}
												else
												{
													top.at(2) = i;
												}
											}
										}
										for (int i = 0; i < top.size(); i++)
										{
											record = record + std::to_string(i + 1) + '.' + std::to_string(topcat.at(top.at(i)));
											waleta.printcat(top.at(i), record);
										}
										std::cout << record;
										system("pause");
										cold.open(naxo);
										save(cold, record);

									}
								}
								a = 1;
								choose = 0;
							}break;
							}
						} while (choose != 0);
					}break;
					case 3:
					{
						choosa = 0;
					}break;
					}
					o = 1;
					choosa = 0;
				}
				}
			}while (choosa != 0);
		}
		else
		{
			std::cout << "Нет операций\n";
			system("pause");
		}
	}break;
	}
}
int main()
{
	system("chcp 1251");
	int choose, x = 1;
	walet waleta;
	do
	{
		system("cls");
		ShowMenu(x);
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
			if (x == 5)
			{
				return 0;
			}
			else
				primenenie(x, waleta);
			x = 1;
		}break;
		}
	}while (choose != 0);
}
