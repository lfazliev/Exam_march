/*#include <iostream> //В 29 строке вводится место для сохранения
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
void checkaut(int& buf)
{
	while (!(std::cin >> buf) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! Repeat please...\n";
	}
}
void save(std::string& record)
{
	int choose = 1, o = 1;
	std::ofstream cold;*/
	/*std::string naxo = "C:/Users/Ленар/Desktop/File.financi.txt";
	std::cout << "\nВведите место сохранения";*//*
	std::cin >> naxo;
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
				cold.open(naxo);
				if (cold.is_open())
				{
					cold << record;
					record.clear();
					cold.close();
				}
				else
				{
					std::cout << "\nФайл не открыт\n";
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
	if (iItem == i + 1) std::cout << "-";
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
	std::cout << "2 - Новая трата\n";
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
	calendar() {}
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
		checkaut(year);
		while (year < 1900 || year > 2035)
		{
			std::cout << "Неверно введён год. Введите число от 1900 до 2035:\n";
			std::cin >> year;
		}
		std::cout << "Введите номер месяца: ";
		checkaut(month);
		while (month < 1 || month > 12)
		{
			std::cout << "Неверно введён месяц. Введите номер месяца от 1 до 12, где \n 1 - январь \n 12 - декабрь ";
			checkaut(month);
		}
		scet();
		if (pol == 0 or pol == 1)
		{
			if (pol == 1)
				std::cout << "Введи день с которого начнётся неделя\n";
			else
				std::cout << "Введи день\n";
			checkaut(day);
			while (day > days || day <= 0)
			{
				if (pol == 1)
					std::cout << "Неверно! Повторите попытку.\nВведи день с которого начнётся неделя\n";
				else
					std::cout << "Неверно! Повторите попытку.\nВведи день\n";
				checkaut(day);
				system("cls");
			}
		}
		if (pol == 2)
		{
			day = 1;
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
	card(std::vector<card> carda)
	{
		int choose, o = 1;
		std::cout << "Введите название карты.. ";
		std::cin >> name;
		
		do
		{
			system("cls");
			std::cout << "\nГотово, карта номер " << carda.size()+1 << "." << name << " добавлена, желаете её пополнить?\n";
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
					int A;
					addmoney(A);
				}
				o = 0;
			}break;
			}
		} while (o != 0);
	}
	std::string& getName() { return name; }
	void setName(const std::string& num) { name = num; }
	int& getBalance() { return balance; }
	void setBalance(const int& num) { balance = num; }
	void addmoney(int &buf)
	{
		std::cout << "На сколько пополнить ? - ";
		checkaut(buf);
		while (buf <= 0)
		{
			std::cout << "Неверно введена сумма. Введите не меньше 0 \nНа сколько пополнить ? -";
			checkaut(buf);
		}
		balance = balance + buf;
	}
	
};
void ShowCard(int iItem, std::vector<card> card)
{
	int i = 0;
	for (i; i < card.size(); i++)
	{
		if (iItem == i) std::cout << "-";
		else std::cout << " ";
		std::cout << i + 1 << "." << card.at(i).getName() << " - Карта\n";
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
	operaci() {}
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
	std::vector<std::string> category = { "Дом", "Еда" , "Долги" ,"Транспорт", "Счета и услуги" , "Личные расходы", "Сбережения" };
private:
public:
	std::vector<card>& getCarda() { return carda; }
	std::vector<operaci>& getOper() { return oper; }
	std::vector<std::string>& getCateg() { return category; }
	void rectop(calendar dat, int B, std::vector<operaci>& list)
	{
		for (int i = 0; i < oper.size(); i++)
		{
			if (oper.at(i).getDate().getYear() == dat.getYear() and oper.at(i).getDate().getMonth() == dat.getMonth())
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
	void recrep(calendar dat, int B, int& A, std::string& record)
	{
		for (int i = 0; i < oper.size(); i++)
		{
			if (oper.at(i).getDate().getYear() == dat.getYear() and oper.at(i).getDate().getMonth() == dat.getMonth())
			{
				if (B != 1)
				{
					if (oper.at(i).getDate().getDay() == dat.getDay())
					{
						A++;
						record = record + std::to_string(A) + '.' + std::to_string(oper.at(i).getCost()) + ' ' + std::to_string(oper.at(i).getDate().getYear()) + '.' + std::to_string(oper.at(i).getDate().getMonth()) + '.' + std::to_string(oper.at(i).getDate().getDay());
						printcat(oper.at(i).getType(), record);
					}
				}
				else
				{
					A++;
					record = record + std::to_string(A) + '.' + std::to_string(oper.at(i).getCost())+ ' ' + std::to_string(oper.at(i).getDate().getYear()) + '.' + std::to_string(oper.at(i).getDate().getMonth()) + '.' + std::to_string(oper.at(i).getDate().getDay());
					printcat(oper.at(i).getType(), record);
				}
			}
		}
	}
	void trata(int o, walet& waleta)
	{
		int A, B=0, choose = 0, C = 1;
		if (carda.at(o).getBalance() > 0)
		{
			std::cout << "Сколько тратим? - ";
			checkaut(A);
			while (A <= 0)
			{
				std::cout << "Неверно введена сумма. Введите не меньше 0 ";
				checkaut(A);
			}
			if (A <= carda.at(o).getBalance())
			{
				carda.at(o).getBalance() = carda.at(o).getBalance() - A;
				B = 1;
			}
			else
				std::cout << "Недостаточно средств" << std::endl;
			system("pause");
			if (B == 1)
			{
				oper.push_back(operaci(A));
				int iltem = 0;
				do
				{
					system("cls");
					std::cout << "Выберите категорию\n";
					showmenutrat(iltem, category);
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
						if (iltem != category.size() + 1)
							iltem++;
					}break;
					case 13:
					{
						if (iltem <= category.size() - 1)
						{
							oper.at(oper.size() - 1).setType(iltem);
							std::cout << "Операция добавлена\n";
							choose = 0;
							system("pause");
						}
						if (iltem == category.size())
						{
							std::cout << "Введите название категории... ";
							category.resize(category.size() + 1);
							std::cin >> category.at(category.size() - 1);
						}
						if (iltem == category.size() + 1)
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
					waleta.getCarda().at(o).getBalance() + A;
					waleta.getOper().pop_back();
				}
			}
		}
		else
			std::cout << "Нет денег\n";
		system("pause");
	}
	void printcat(int type, std::string& record)
	{
		for (int i = 0; i < category.size(); i++)
		{
			if (type == i)
				record = record + ' ' + category.at(i) + '\n';
		}
	}
};
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
			std::string record;
			switch (x)
			{
			case 1:
			{
				waleta.getCarda().push_back(waleta.getCarda());
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
											int A;
											waleta.getCarda().at(o).addmoney(A);
											choosa = 0;
										}break;
										case 2:
										{
											waleta.trata(o,waleta);
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
								waleta.getCarda().push_back(waleta.getCarda());
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
							calendar dat;
							int A = 0;
							switch (o)
							{
							case 0:
							{
								dat.add(0);
								waleta.recrep(dat, 0, A, record);
								std::cout << record;
							}break;
							case 1:
							{
								dat.add(1);
								for (int i = 0; i < 7; i++)
								{
									waleta.recrep(dat, 0, A, record);
									dat.setDay(dat.getDay() + 1);
									dat.perasch();
								}
								std::cout << record;
							}break;
							case 2:
							{
								dat.add(2);
								waleta.recrep(dat, 1, A, record);
								std::cout << record;

							}break;
							case 3:
							{
								choose = 0;
							}break;
							}
							system("pause");
							if (o != 3)
							{
								save(record);
							}
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
											top.at(i).setCost(0);
										}
										calendar dat;
										switch (a)
										{
										case 1:
										{
											dat.add(1);
											for (int i = 0; i < 7; i++)
											{
												waleta.rectop(dat, 0, lists);
												dat.setDay(dat.getDay() + 1);
												dat.perasch();
											}
										}break;
										case 2:
										{
											dat.add(2);
											waleta.rectop(dat, 1, lists);
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
												record = std::to_string(1) + '.' + std::to_string(lists.at(0).getCost()) + ' ' + std::to_string(lists.at(0).getDate().getYear()) + '.' + std::to_string(lists.at(0).getDate().getMonth()) + '.' + std::to_string(lists.at(0).getDate().getDay()); waleta.printcat(lists.at(0).getType(), record);
												std::cout << record << "\n";
												system("pause");
												save(record);
											}
											if (lists.size() > 1)
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
															if (lists.at(i).getCost() >= top.at(2).getCost())
															{
																top.at(2) = lists.at(i);
															}
														}
													}
												}
												int a;
												if (lists.size()==2)
												{
													a = top.size() - 1;
												}
												for (int i = 0; i < a; i++)
												{
													record = record + std::to_string(i + 1) + '.' + std::to_string(top.at(i).getCost()) +' '+ std::to_string(top.at(i).getDate().getYear()) + '.' + std::to_string(top.at(i).getDate().getMonth()) + '.' + std::to_string(top.at(i).getDate().getDay()); waleta.printcat(top.at(i).getType(), record);
												}
												std::cout << record << "\n";
												system("pause");
												save(record);
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
										calendar dat;
										switch (a)
										{
										case 1:
										{
											dat.add(1);
											for (int i = 0; i < 7; i++)
											{
												waleta.rectop(dat, 0, lists);
												dat.setDay(dat.getDay() + 1);
												dat.perasch();
											}
										}break;
										case 2:
										{
											dat.add(2);
											waleta.rectop(dat, 1, lists);
										}break;
										case 3:
										{
											choose = 0;
										}break;
										}
										if (choose != 0)
										{
											choose = 0;
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
											for (int i = 0; i < topcat.size(); i++)
											{
												if (topcat.at(i) < topcat.at(top.at(0)))
												{
													top.at(0) = i;
												}
											}
											top.at(1) = top.at(0);
											top.at(2) = top.at(0);
											if (lists.size() == 1)
											{
												record = std::to_string(1) + '.' + std::to_string(lists.at(0).getCost());
												waleta.printcat(lists.at(0).getType(), record);
												std::cout << record << "\n";
												system("pause");
												save(record);
											}
											if (lists.size() > 1)
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
															if (topcat.at(i) >= topcat.at(top.at(2)))
															{
																top.at(2) = i;
															}
														}
													}
												}
												for (int i = 0; i < top.size(); i++)
												{
													record = record + std::to_string(i + 1) + '.' + std::to_string(topcat.at(top.at(i)));
													waleta.printcat(top.at(i), record);
												}
												std::cout << record << "\n";
												system("pause");
												save(record);
											}
										}
										a = 1;
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
					} while (choosa != 0);
				}
				else
				{
					std::cout << "Нет операций\n";
					system("pause");
				}
			}break;
			case 5:
			{
				return 0;
			}
			}
			x = 1;
		}break;
		}
	} while (choose != 0);
}
*/