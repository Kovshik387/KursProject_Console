#include "Header.h"
using namespace std;

void SetData();

int main()
{
	bool flag = false;
    setlocale(LC_ALL, "ru");
	while (true) {
		
		cout << "0 - exit          " << endl; 
		cout << "1 - product       " << endl;
		cout << "2 - shoes         " << endl;
		cout << "3 - reset         " << endl;
		cout << "4 - print	       " << endl;
		cout << "5 - basket        " << endl;
		cout << "6 - Login as admin" << endl;
		if (flag) {
			cout << "7 - PRINT_ALL" << endl;
			cout << "8 - ADD_NEW" << endl;
		}
		int mode; cin >> mode; Object object;
		if (mode == 0) break;
		if (mode == 1) {
		    object.item(); object.Print();
			cout << "b - buy\nr - return\n";
			char mode_i; cin >> mode_i;
			if (mode_i == 'b') {
				int ask; cin >> ask;
				object.basket(ask);
			}
			if (mode_i == 'r') continue;
			//else throw exception("Error Data");
		}
		if (mode == 2) { Shoes shoes; shoes.Print(); int ask; cin >> ask; shoes.basket(ask); }
		if (mode == 3) SetData();
		if (mode == 4) { object.Print();}
		if (mode == 5) { object.PrintBasket(); }
		if (mode == 6) {
			string pass; cin >> pass;
			if (pass == Password) flag = true;
		}
		system("pause");
		cout << "////////////////////////////////////////////////////////////////////////////////" << endl;
	}

    return 0;
}

void SetData()
{
	ifstream File_Default(FILE_MAIN_NAME);
	vector<string> temp_data; string temp;
	if (!File_Default.is_open()) throw exception("File read error");
	while (!File_Default.eof()) {
		getline(File_Default, temp);
		temp_data.push_back(temp);
	}
	File_Default.close();
	ofstream File_Data(FILE_NAME,ios_base::trunc);
	if (!File_Data.is_open()) throw exception("File read error");
	for (int i = 0; i < temp_data.size(); i++) {
        if (i == temp_data.size() - 1) File_Data << temp_data[i];
        else File_Data << temp_data[i] << endl;
	}

	File_Data.close();
}

