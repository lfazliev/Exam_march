/*#include <iostream>//������ ��������� �����, ������ ����� �������� /
#include <string>
#include <fstream>
int main()
{
	system("chcp 1251");
	std::ifstream text;
	std::string text_sum, buf;
	text.open("C:/Users/�����/Desktop/��������� ��������.txt");
		if (!text)
		{
			std::cout << "�� ������ ����";
		}
		else
		{
			while (!text.eof())
			{
				std::getline(text, buf);
				text_sum = text_sum + '\n' + buf;
			}
			text.close();
			std::cout <<"�� �����������\n" << text_sum;
			for (int i = 0; i < text_sum.size(); i++)
			{
				if (text_sum.at(i) != '\n')
					text_sum.at(i) = (int)text_sum.at(i) + 3;
			}
			std::cout << "\n����� �����������\n";
			std::cout << text_sum;
			std::ofstream out("C:/Users/�����/Desktop/��������� ��������.txt");
			if (out.is_open())
			{
				out << text_sum;
				std::cout << "\n���������";
			}
			out.close();
		}
}*/