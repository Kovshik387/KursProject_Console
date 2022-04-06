#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <regex>
#include <algorithm>
#include <list>

#define FILE_BASKET_NAME "Basket.txt"
#define FILE_NAME "Data.txt"
#define FILE_MAIN_NAME "DefualtData.txt"
#define SEARCH_EXP_NEW R"(\w{2,6}\s\w{2,10}\s\w{3,5}\s\w{3,15}\s\w{3,15}\s\d{1,2}\s\d{2,6}\s\w{3,7}\s\d{1})"
#define SEARCH_SHOES R"(Shoes)"
#define Password "OOP1337"
using namespace std;

class Builder
{
public:

	void virtual item() = 0;
	void virtual Print() = 0;

	Builder()
	{
		ifstream File(FILE_NAME); 
		if (!File.is_open()) throw exception("File read error");
		while (!File.eof()){
			id++; string temp;
			getline(File, temp);
			this->data.push_back(temp);
		}
		File.close();
	}

protected:
	vector <string> data;
	vector <string> basket_;
	int id = 0;
};

class Object : public Builder	// Магазин маленький, сделаем допущение того, что товаров больше 9 одного типа, он не может хранить.
{
public:

	void item() override {
		regex regular(SEARCH_EXP_NEW);
		smatch find_word;
		vector<string>::iterator it = data.begin();// Удаление мусора
		int i = 0;
		while (i < id) {
			if (!regex_match(data[i], find_word, regular)) {
				data.erase(data.begin() + i);
				id--; i--;
			}
			i++;
		}
	}

	void basket(int id_)
	{
		fstream File(FILE_NAME); fstream File_Basket(FILE_BASKET_NAME,ios_base::app);
		id_--; string temp; string buff;
		temp = (data[id_].c_str()[data[id_].size() - 1]);
		buff = data[id_];
		int count = stoi(temp);
		if (count == 1) {
			buff.replace(buff.size() - 1, buff.size(), "1");
			File_Basket << buff << endl;
			data.erase(data.begin() + id_);
		}
		else {
			buff.replace(buff.size() - 1, buff.size(), "1");
			File_Basket << buff << endl;
			count--; string temp2 = to_string(count);
			this->data[id_].replace(data[id_].size() - 1, data[id_].size(), temp2);
		}
		File.close(); File_Basket.close();
		ofstream File_New(FILE_NAME, ios_base::trunc);
		if (!File_New.is_open()) throw exception("File read error");
		for (int i = 0; i < data.size(); i++) {
			if (i == data.size() - 1) File_New << data[i];
			else File_New << data[i] << endl;
		}
		File_New.close();
	}
	void Print() override
	{
		for (int i = 0; i < data.size(); i++)
			cout << "id: " << i + 1 << "\t" << data[i] << endl;
	}
	void PrintBasket()
	{
		cout << "///////////////////////////Your Basket////////////////////////////" << endl;
		ifstream File_Basket(FILE_BASKET_NAME);
		if (!File_Basket.is_open()) throw exception("File read error");
		int i = 0; string temp;
		while (!File_Basket.eof()) {
			getline(File_Basket, temp);
			basket_.push_back(temp);
			cout << basket_[i]; i++;
		}
		cout << endl;
		cout << "//////////////////////////////////////////////////////////////////" << endl;
		
	}

protected:
};



class Shoes : public Object
{
public:
	
	Shoes()
	{
		smatch find_world;
		regex regular(SEARCH_SHOES);
		for (int i = 0; i < id; i++) 
		{
			if (regex_search(data[i], find_world, regular))
			{
				string temp;
				temp = data[i];
				this->Shoes_Data.push_back(temp);
			}
		}
	}

	void item() override
	{

	}

	void Print() override
	{
		int it = 0;
		for (int i = 0; i < data.size(); i++) {
			if (data[i].find("Shoes")) {
				cout << "id: " << i + 1 << "\t" << Shoes_Data[it] << endl; it++;
				if (it == Shoes_Data.size()) break;
			}
		}
	}

protected:
	vector<string> Shoes_Data;
	int count;
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
};