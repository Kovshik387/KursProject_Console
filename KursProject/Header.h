#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <regex>
#include <algorithm>
#include <list>

#define FILE_NAME "Data.txt"
#define FILE_MAIN_NAME "DefualtData.txt"
#define SEARCH_EXP_NEW R"(\w{2,6}\s\w{2,10}\s\w{3,5}\s\w{3,15}\s\w{3,15}\s\d{1,2}\s\d{2,6}\s\w{3,7}\s\d{1})"
#define SEARCH_SHOES R"(Shoes)"
using namespace std;

class Builder
{
public:

	void virtual item() = 0;
	void virtual basket(int id_) = 0; // корзина ебанна€

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
	vector <string> Mybasket;
	int id = 0;
	static int id_all;
};

int Builder::id_all = 0;

class Object : public Builder	// ћагазин маленький, сделаем допущение того, что товаров больше 9 одного типа, он не может хранить.
{
public:

	void item() override {
		regex regular(SEARCH_EXP_NEW);
		smatch find_word;
		vector<string>::iterator it = data.begin();// ”даление мусора
		int i = 0;
		while (i < id) {
			if (!regex_match(data[i], find_word, regular)) {
				data.erase(data.begin() + i);
				id--; i--;
			}
			i++;
		}
	}

	void basket(int id_) override
	{
		fstream File(FILE_NAME);
		id_--; string temp;
		temp = (data[id_].c_str()[data[id_].size() - 1]);
		int count = stoi(temp);
		if (count == 1) {
			data.erase(data.begin() + id_);
			this->data.erase(data.begin() + id_);
		}
		else {
			count--; string temp2 = to_string(count);
			this->data[id_].replace(data[id_].size() - 1, data[id_].size(), temp2);
		}
		File.close();
		ofstream File_New(FILE_NAME, ios_base::trunc);
		if (!File_New.is_open()) throw exception("File read error");
		for (int i = 0; i < data.size(); i++) {
			if (i == data.size() - 1) File_New << data[i];
			else File_New << data[i] << endl;
		}
		File_New.close();
	}
	void PrintDataAll()
	{
		for (int i = 0; i < data.size(); i++)
			cout << "id: " << i + 1 << "\t" << data[i] << endl;
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

	void basket(int id_) override
	{
		fstream File(FILE_NAME);
		id_--; string temp;
		temp = (Shoes_Data[id_].c_str()[Shoes_Data[id_].size() - 1]);
		this->count = stoi(temp); 
		if (count == 1){
			data.erase(data.begin() + id_);
			this->Shoes_Data.erase(Shoes_Data.begin() + id_);
		}
		else{
			this->count--; string temp2 = to_string(count);
			this->Shoes_Data[id_].replace(Shoes_Data[id_].size() - 1, Shoes_Data[id_].size(), temp2);
		}
		File.close();
	}

	void item() override
	{

	}

	void PrintShoes()
	{
		for (int i = 0; i < Shoes_Data.size(); i++)
			cout << "id: "<< i + 1 <<"\t" << Shoes_Data[i] << endl;
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