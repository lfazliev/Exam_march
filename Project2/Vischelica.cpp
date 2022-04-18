#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include <windows.h>
class slova//класс слов, есть переменные для простых, средних, сложно
{
	int pol;//Переменная для цикла
	std::string text_sum, buf, word;//текст, буфер, слово
	std::ifstream text;//Файл
public:
	std::vector<std::string> low, mid, har; //Векторы со словами разной сложности
	slova()								// элемент вектора для каждого слова
	{
		text.open("C:/Users/Ленар/Desktop/Текстовый документ.txt");
		if (text)
		{
			while (!text.eof())
			{
				std::getline(text, buf);//Через буфер записываем из файла в стринг
				text_sum = text_sum + '\n' + buf;
			}
			text.close();
			for (int i = 0; i < text_sum.size(); i++)
			{
				if (text_sum.at(i) != '\n')//Декодировка с исключение переходов на новую строку
				text_sum.at(i) = (int)text_sum.at(i) - 3;
			}
			for (int i = 0; i < text_sum.size() - 1; i++)
			{
				if (text_sum.at(i) == '\n')//Пропускаем переход в начала файла
				{
					i = i++;
				}
				else
				{
					pol = 1;
					if (text_sum.at(i) == '/')//Начало слова запуск цикла
					{
						while (pol != 0)
						{
							i = i++;
							if (text_sum.at(i) != '/')//Записываем пока не найдём окончаение слова 
							{
								word.push_back(text_sum.at(i));
							}
							else
							{
								pol = 0;
								if (word.size() <= 5)//Присваеваем сложность по кол-ву букв
								{
									low.push_back(word);
								}
								if (6<=word.size() <=9)
								{
									mid.push_back(word);
								}
								if (word.size() >= 9)
								{
									har.push_back(word);
								}
								word.clear();
								i = i--;
							}
						}
					}
				}
			}
		}
		else
			std::cout << "Не открыт";
	}
};
void ShowMenu(int iItem)//Меню
{
	if (iItem == 1) std::cout << "";
	else std::cout << "	";
	std::cout << "1 - Начать игру\n";
	if (iItem == 2) std::cout << "";
	else std::cout << "	";
	std::cout << "2 - Информация\n";
	if (iItem == 3) std::cout << "";
	else std::cout << "	";
	std::cout << "3 - Выход\n";
}
void ShowMenuTwo(int iItem)//Меню выбора информации
{
	if (iItem == 1) std::cout << "";
	else std::cout << "	";
	std::cout << "1 - Автор\n";
	if (iItem == 2) std::cout << "";
	else std::cout << "	";
	std::cout << "2 - Правила игры\n";
	if (iItem == 3) std::cout << "";
	else std::cout << "	";
	std::cout << "3 - Назад\n";
}
void ShowMenuThree(int iItem)//Меню выбора сложности
{
	if (iItem == 1) std::cout << "";
	else std::cout << "	";
	std::cout << "1 - Легко\n";
	if (iItem == 2) std::cout << "";
	else std::cout << "	";
	std::cout << "2 - Средне\n";
	if (iItem == 3) std::cout << "";
	else std::cout << "	";
	std::cout << "3 - Сложно\n";
	if (iItem == 4) std::cout << "";
	else std::cout << "	";
	std::cout << "4 - Назад\n";
}
void ShowChooseWord(int xItem, int yItem)//отображение меню выбора букв
{
	if (xItem == 1 and yItem == 1) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "А\t";
	if (xItem == 2 and yItem == 1) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Б\t";
	if (xItem == 3 and yItem == 1) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "В\t";
	if (xItem == 4 and yItem == 1) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Г\t";
	if (xItem == 5 and yItem == 1) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Д\t";
	if (xItem == 6 and yItem == 1) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Е\t";
	if (xItem == 7 and yItem == 1) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Ё\n";
	if (xItem == 1 and yItem == 2) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Ж\t";
	if (xItem == 2 and yItem == 2) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "З\t";
	if (xItem == 3 and yItem == 2) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "И\t";
	if (xItem == 4 and yItem == 2) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Й\t";
	if (xItem == 5 and yItem == 2) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "К\t";
	if (xItem == 6 and yItem == 2) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Л\t";
	if (xItem == 7 and yItem == 2) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "М\n";
	if (xItem == 1 and yItem == 3) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Н\t";
	if (xItem == 2 and yItem == 3) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "О\t";
	if (xItem == 3 and yItem == 3) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "П\t";
	if (xItem == 4 and yItem == 3) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Р\t";
	if (xItem == 5 and yItem == 3) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "С\t";
	if (xItem == 6 and yItem == 3) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Т\t";
	if (xItem == 7 and yItem == 3) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "У\n";
	if (xItem == 1 and yItem == 4) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Ф\t";
	if (xItem == 2 and yItem == 4) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Х\t";
	if (xItem == 3 and yItem == 4) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Ц\t";
	if (xItem == 4 and yItem == 4) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Ч\t";
	if (xItem == 5 and yItem == 4) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Ш\t";
	if (xItem == 6 and yItem == 4) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Щ\n";
	if (xItem == 1 and yItem == 5) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Ъ\t";
	if (xItem == 2 and yItem == 5) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Ы\t";
	if (xItem == 3 and yItem == 5) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Ь\t";
	if (xItem == 4 and yItem == 5) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Э\t";
	if (xItem == 5 and yItem == 5) std::cout << "\t&";
	else std::cout << "	";
	std::cout << "Ю\t";
	if (xItem == 6 and yItem == 5) std::cout << "\t & ";
	else std::cout << "	";
	std::cout << "Я\n";
}
void game(int& y, int& x, int z)
{
	int popitcy=0, choosa = 1, err = 0, error = 0;
	slova gg;
	std::string word, black, ops;
	char choose;
	if (z == 1)//Сложность 1-3, выбирается в меню функции primenenie
	{
		int a = 1 + rand() % gg.low.size()-1;
		word = gg.low.at(a);
	}
	if (z == 2)
		word = gg.mid.at(1 + rand() % gg.mid.size()-1);
	if (z == 3)
	{
		word = gg.har.at(1 + rand() % gg.har.size()-1);
	}
	for (int i = 0; i < word.size(); i++)
	{
		black.push_back('@');
	}
	SYSTEMTIME st1, st2;
	GetLocalTime(&st1);
	std::vector <char> bucschet;
	do
	{
		std::cout << black << "\nПопыток " << popitcy << "\n";
		std::cout << "Выберите буву\n";
		ShowChooseWord(x, y);
		choosa = _getch();
		system("cls");
		switch (choosa)
		{
		case 72:
		{
			if (y != 1)
				y--;
		}break;
		case 80:
		{
			if (y != 5)
			{
				if (x == 7)
				{
					if (y != 3)
					{
						y++;
					}
				}
				else
					y++;
			}
		}break;
		case 75:
		{
			if (x != 1)
				x--;
		}break;
		case 77:
		{
			if (x != 7)
			{
				if (y == 4 or y == 5)
				{
					if (x != 6)
					{
						x++;
					}
				}
				else
				{
					x++;
				}
			}
		}break;
		case 13:
		{
			
			if (x == 1 and y == 1)
			{
				choose = 'а';
			}
			if (x == 2 and y == 1)
			{
				choose = 'б';
			}
			if (x == 3 and y == 1)
			{
				choose = 'в';
			}
			if (x == 4 and y == 1)
			{
				choose = 'г';
			}
			if (x == 5 and y == 1)
			{
				choose = 'д';
			}
			if (x == 6 and y == 1)
			{
				choose = 'е';
			}
			if (x == 7 and y == 1)
			{
				choose = 'ё';
			}
			if (x == 1 and y == 2)
			{
				choose = 'ж';
			}
			if (x == 2 and y == 2)
			{
				choose = 'з';
			}
			if (x == 3 and y == 2)
			{
				choose = 'и';
			}
			if (x == 4 and y == 2)
			{
				choose = 'й';
			}
			if (x == 5 and y == 2)
			{
				choose = 'к';
			}
			if (x == 6 and y == 2)
			{
				choose = 'л';
			}
			if (x == 7 and y == 2)
			{
				choose = 'м';
			}
			if (x == 1 and y == 3)
			{
				choose = 'н';
			}
			if (x == 2 and y == 3)
			{
				choose = 'о';
			}
			if (x == 3 and y == 3)
			{
				choose = 'п';
			}
			if (x == 4 and y == 3)
			{
				choose = 'р';
			}
			if (x == 5 and y == 3)
			{
				choose = 'с';
			}
			if (x == 6 and y == 3)
			{
				choose = 'т';
			}
			if (x == 7 and y == 3)
			{
				choose = 'у';
			}
			if (x == 1 and y == 4)
			{
				choose = 'ф';
			}
			if (x == 2 and y == 4)
			{
				choose = 'х';
			}
			if (x == 3 and y == 4)
			{
				choose = 'ц';
			}
			if (x == 4 and y == 4)
			{
				choose = 'ч';
			}
			if (x == 5 and y == 4)
			{
				choose = 'ш';
			}
			if (x == 6 and y == 4)
			{
				choose = 'щ';
			}
			if (x == 1 and y == 5)
			{
				choose = 'ъ';
			}
			if (x == 2 and y == 5)
			{
				choose = 'ы';
			}
			if (x == 3 and y == 5)
			{
				choose = 'ь';
			}
			if (x == 4 and y == 5)
			{
				choose = 'э';
			}
			if (x == 5 and y == 5)
			{
				choose = 'ю';
			}
			if (x == 6 and y == 5)
			{
				choose = 'я';
			}
			int pol=0;
			for (int i = 0; i < bucschet.size(); i++)
			{
				if (bucschet.at(i)==choose)
				{
					pol++;
				}
			}
			if (pol != 1)
			{
				popitcy++;
				bucschet.push_back(choose);
				for (int i = 0; i < word.size(); i++)
				{
					if (word.at(i) == choose)
					{
						black.at(i) = word.at(i);
						err++;
					}
				}
				if (err == 0)
				{
					ops = ops + ' ' + choose;
					error++;
				}
				err = 0;
				int schet = 0;
				for (int i = 0; i < black.size(); i++)
				{
					if (black.at(i) != '@')
					{
						schet++;
					}
				}
				if (schet == black.size())
				{
					choosa = 0;
					GetLocalTime(&st2);
					long double T1 = (long double)(st1.wHour * 60 * 60 * 1000 + st1.wMinute * 70 * 1000 + st1.wSecond * 1000 + st1.wMilliseconds);
					long double T2 = (long double)(st2.wHour * 60 * 60 * 1000 + st2.wMinute * 70 * 1000 + st2.wSecond * 1000 + st2.wMilliseconds);
					std::cout << "Вы выйграли сделав " << popitcy << " попыток, " << error << " ошибки, Слово " << word << "\nОшибки " << ops << "\n";
					std::cout << "Время " << (int)((T2 - T1) / 1000) << " секунд\n\n";
					system("pause");
				}
				else
				{
					if (error == 7)
					{
						std::cout << "Вы проиграли!\n";
						choosa = 0;
						system("pause");
					}
				}
			}
			else
			{
				std::cout << "Уже было\n";
			}
		}break;
		}
	} while (choosa != 0);
}
int main()
{
	srand(time(0));
	system("chcp 1251");
	int choose, x, y, o = 1, z = 1, f = 1; /*choose - сюда записываем клавиши через getch,	x, y - позиции при выборе букв в игре, o - позиция для второго меню,z - позиция в главном меню, f позиция в меню инфо*/
	do
	{
		ShowMenu(z);//Выводим главное меню с положением z
		choose = _getch();
		system("cls");
		switch (choose)
		{
		case 72:
		{
			if (z != 1)
				z--;
		}break;
		case 80:
		{
			if (z != 3)
				z++;
		}break;
		case 13:
		{
			switch (z)
			{
			case 1:
			{
				do
				{
					ShowMenuThree(o);
					choose = _getch();
					system("cls");
					switch (choose)
					{
					case 72:
					{
						if (o != 1)
						{
							o--;
						}
					}break;
					case 80:
					{
						if (o != 4)
						{
							o++;
						}
					}break;
					case 13:
					{
						z = 1;
						switch (o)
						{
						case 1:
						{
							game(x = 1, y = 1, o);
							choose = 0;
						}break;
						case 2:
						{
							game(x = 1, y = 1, o);
							choose = 0;
						}break;
						case 3:
						{
							game(x = 1, y = 1, o);
							choose = 0;
						}break;
						case 4:
						{
							choose = 0;
							z, o = 1;
						}break;
						}
					}break;
					}
				} while (choose != 0);
				break;
			case 2:
			{
				do
				{
					ShowMenuTwo(f);
					choose = _getch();
					system("cls");
					switch (choose)
					{
					case 72:
					{
						if (f != 1)
						{
							f--;
						}
					}break;
					case 80:
					{
						if (f != 3)
						{
							f++;
						}
					}break;
					case 13:
					{
						z = 1;
						switch (f)
						{
						case 1:
						{
							std::cout << "\nФазлиев Ленар Рамилевич, г.Сочи\n";
						}break;
						case 2:
						{
							std::cout << "\nКомпьютер загадывает слово, изначально все буквы слова неизвестны, игрок предлагает букву, которая может входить в это слово.\nЕсли такая буква есть в слове, то соответствующими этой букве место в слове раскрывается.\n Если такой буквы нет, то буква засчитывается в ошибку. \nИгрок продолжает отгадывать буквы до тех пор, пока не отгадает всё слово.Или не достигнт 7-ми неверных попыток\n Если игроку удаётся угадать слово, он выигрывает.\n";
						}break;
						case 3:
						{
							choose = 0;
							z, o = 1;
						}break;
						}
					}break;
					}
				} while (choose != 0);
				break;
			}break;
			case 3:
			{
				z = 0;
			}break;
			}
			}
		}
		}
	} while (z != 0);
}