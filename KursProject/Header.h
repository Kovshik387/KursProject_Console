#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <regex>
#include <algorithm>
#include <ctime>

#define FILE_BASKET_NAME "Basket.txt"		//
#define FILE_NAME "Data.txt"				// Имена Файлов
#define FILE_MAIN_NAME "DefualtData.txt"	//
#define SEARCH_EXP_NEW R"(\w{2,6}\s\w{2,10}\s\w{3,5}\s\w{3,15}\s\w{3,15}\s\d{1,2}\s\d{2,6}\s\w{3,7}\s\d{1})" //Общее регулярное выражение
#define SEARCH_SHOES R"((Shoes)\s\w{2,10}\s\w{3,5}\s\w{3,15}\s\w{3,15}\s\d{1,2}\s\d{2,6}\s\w{3,7}\s\d{1})" // Регулярное выражение для группы Shoes
#define SEARCH_PANTS R"((Pants)\s\w{2,10}\s\w{3,5}\s\w{3,15}\s\w{3,15}\s\d{1,2}\s\d{2,6}\s\w{3,7}\s\d{1})" // Регулярное выражение для группы Pants
#define SEARCH_CLOTH R"((Cloth)\s\w{2,10}\s\w{3,5}\s\w{3,15}\s\w{3,15}\s\d{1,2}\s\d{2,6}\s\w{3,7}\s\d{1})" // Регулярное выражение для группы Cloth


void Travel(int day);

using namespace std;
//
//	Требуемые классы
//
class Admin //продвинутый уровень бытия
{
public:

	Admin()
	{
		ifstream File(FILE_MAIN_NAME);	// конструктор ворует начальные данные
		if (!File.is_open()) throw exception("File read error");
		while (!File.eof()) {
			string temp;	// временная переменная строчного типа
			getline(File, temp);
			this->admin_data.push_back(temp);
		}
		File.close();
	}

	void Print_Admin_Data()
	{
		cout << "View only Administator///////////////////////////////////////////" << endl;
		for (int i = 0; i < admin_data.size(); i++)
			cout << admin_data[i] << endl;
		cout << "/////////////////////////////////////////////////////////////////" << endl;
	}

	string GetPassword()
	{
		return Password;
	}
private:
	string Password = "OOP1337";	//пароль администратора
	vector <string> admin_data;		//вектор строчного типа
};

class User	//обычный уровень бытия
{
public:

	void Purchase()
	{
		int it = day;
		fstream File(FILE_BASKET_NAME,ios::out);
		thread thr(Travel,it);
		thr.detach();
	}

	void SetDay(int day)
	{
		this->day = day;
	}

	int GetDay()
	{
		return this->day;
	}

private:
	static int day;
};

int User::day = 0;

class Builder	// Основной класс, трудяга-работяга на нём все держится...
{
public:

	void virtual item() = 0;	//виртуальн метод ????
	void virtual Print() = 0;	//виртуальный метод вывода данных на консоль

	Builder()	// конструктор класса Builder, переносит данные из файла в вектор строчного типа
	{
		ifstream File(FILE_NAME); 
		if (!File.is_open()) throw exception("File read error");
		while (!File.eof()){
			id++; string temp;	// 
			getline(File, temp);
			this->data.push_back(temp);
		}
		File.close();
	}

protected:
	vector <string> data;
	int id = 0; // общее количество 
};

class Object : public Builder	// Магазин маленький, сделаем допущение того, 
{							    // что товаров больше 9 одного типа, он не может хранить.
public:

	void item() override {	// функция отсеивания "неправильных" товаров
		regex regular(SEARCH_EXP_NEW);	// регулярное выражение
		smatch find_word;
		vector<string>::iterator it = data.begin();// Удаление мусора
		int i = 0; // временная переменная, но ОНА НЕОБХОДИМА
		count = id;
		while (i < id) {
			if (!regex_match(data[i], find_word, regular)) {// проверка
				data.erase(data.begin() + i);
				id--; i--;									// сдвиг итератора 
			}
			i++;
		}
	}

	void basket(int id_) // нужно привести в порядок
	{					 // 
		fstream File(FILE_NAME); fstream File_Basket(FILE_BASKET_NAME,ios_base::app); // открытие файлов
		id_--; // аргумент передаваем в метод класса Object
		string temp; string buff; // временные переменные
		temp = (data[id_].c_str()[data[id_].size() - 1]);
		buff = data[id_];
		int count = stoi(temp); // преобразование из строчного типа в целочисленный
		if (count == 1) {									// проверка, если товар в одном экземпляре,
			buff.replace(buff.size() - 1, buff.size(), "1");// то удаляем его из общего списка товаров
			File_Basket << buff << endl;
			data.erase(data.begin() + id_);
		}
		else {
			buff.replace(buff.size() - 1, buff.size(), "1");
			File_Basket << buff << endl; // запись данных в файл "корзина"
			count--; string temp2 = to_string(count); // преоброзование уменьшенного значения в строчный тип
			this->data[id_].replace(data[id_].size() - 1, data[id_].size(), temp2); // замена в векторе количества товара
		}
		File.close(); File_Basket.close(); // закрытие отработанных файлов
		ofstream File_New(FILE_NAME, ios_base::trunc); // открытие файла в режиме "запись в конец"
		if (!File_New.is_open()) throw exception("File read error"); // ошибка открытия файла
		for (int i = 0; i < data.size(); i++) {  // запись добавленного предмета в конец "корзины"
			if (i == data.size() - 1) File_New << data[i]; // костыль
			else File_New << data[i] << endl;			   //
		}
		File_New.close();
	}
	void Print() override // Вывод всех удовлетворяющих товаров
	{
		for (int i = 0; i < data.size(); i++)
			cout << "id: " << i + 1 << "\t" << data[i] << endl;
	}
	void PrintBasket() // вывод предметов в "корзине"
	{
		cout << "///////////////////////////Your Basket////////////////////////////" << endl; //
		ifstream File_Basket(FILE_BASKET_NAME); // чтение из файла Basket.txt
		if (!File_Basket.is_open()) throw exception("File read error");
		int i = 0; string temp;
		while (!File_Basket.eof()) {
			getline(File_Basket, temp);
			basket_.push_back(temp);
			cout << basket_[i] << endl; i++;
		}
		cout << "//////////////////////////////////////////////////////////////////" << endl;
	}

	int GetCount()
	{
		return count;
	}

protected:
	vector <string> basket_;
	int count;
};

class Shoes : public Object	//класс абстрактного понятия ботинок
{
public:
	
	Shoes() // Нахождение товаров, принадлежащие группе Shoes
	{
		smatch find_world;
		regex regular(SEARCH_SHOES);	// регулярное выражение
		count = 0;
		for (int i = 0; i < id; i++) 
		{
			if (regex_search(data[i], find_world, regular)){
				count++;
			}
		}
	}

	void item() override	// ???
	{

	}

	void Print() override // Вывод товаров, принадлежащие группе Shoes
	{	
		
		smatch find_world;
		regex regular(SEARCH_SHOES);	// регулярное выражение
		int it = 0;
		for (int i = 0; i < data.size(); i++) {
			if (regex_search(data[i], find_world, regular)) {
				cout << "id: " << i + 1 << "\t" << data[i] << endl; it++;
				if (it == count) break;
			}
		}
	}

protected:
	vector<string> Shoes_Data;	//вектор строчно типа
	int count = 0;			    //зачем он нужен?
};

class Pants : public Object	//класс абстрактного понятия верхней одежды
{
public:

	Pants() // Нахождение товаров, принадлежащие группе вернхней одежды
	{
		smatch find_world;
		regex regular(SEARCH_PANTS);	// регулярное выражение
		for (int i = 0; i < id; i++)
		{
			if (regex_search(data[i], find_world, regular)) {
				count++;
			}
		}
	}

	void item() override	// ???
	{

	}

	void Print() override // Вывод товаров, принадлежащие группе Pants
	{
		smatch find_world;
		regex regular(SEARCH_PANTS);	// регулярное выражение
		int it = 0;
		for (int i = 0; i < data.size(); i++) {
			if (regex_search(data[i], find_world, regular)) {
				cout << "id: " << i + 1 << "\t" << data[i] << endl; it++;
				if (it == count) break;
			}
		}
	}

protected:
	vector<string> Cloth_Data;	//вектор строчно типа
	int count = 0;			    //зачем он нужен?
};

class Cloth : public Object	//класс абстрактного понятия ботинок
{
public:

	Cloth() // Нахождение товаров, принадлежащие группе Shoes
	{
		smatch find_world;
		regex regular(SEARCH_CLOTH);	// регулярное выражение
		for (int i = 0; i < id; i++)
		{
			if (regex_search(data[i], find_world, regular)) {
				count++;
			}
		}
	}

	void item() override	// ???
	{

	}

	void Print() override // Вывод товаров, принадлежащие группе Shoes
	{

		smatch find_world;
		regex regular(SEARCH_CLOTH);	// регулярное выражение
		int it = 0;
		for (int i = 0; i < data.size(); i++) {
			if (regex_search(data[i], find_world, regular)) {
				cout << "id: " << i + 1 << "\t" << data[i] << endl; it++;
				if (it == count) break;
			}
		}
	}

protected:
	vector<string> CLOTH_Data;	//вектор строчно типа
	int count = 0;			    //зачем он нужен?
};

enum class MyEnumClass
{
	Category = 0,
	Type = 1,
	Sex = 2,
	Brand = 3,
	Mark = 4,
	Size = 5,
	Price = 6,
	Color = 7,
	Count = 8
};	 // нужно впихнуть

void Travel(int day)
{
	User u;
	while (day > 0) {
		this_thread::sleep_for(chrono::seconds(2));
		day--; u.SetDay(day);
	}
	cout << "Your item has been delivered successfully" << endl;
}