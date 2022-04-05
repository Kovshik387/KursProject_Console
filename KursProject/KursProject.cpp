#include "Header.h"
using namespace std;

void SetData();

int main()
{
    setlocale(LC_ALL, "ru");
	while (true) {
		cout << "0 - exit   " << endl;
		cout << "1 - product" << endl;
		cout << "2 - shoes  " << endl;
		cout << "3 - reset  " << endl;
		int mode; cin >> mode;
		if (mode == 0) break;
		if (mode == 1) {
			Object object; object.item(); object.PrintDataAll();
			cout << "b - buy\nr - return\n";
			char mode_i; cin >> mode_i;
			if (mode_i == 'b') {
				int ask; cin >> ask;
				object.basket(ask);
			}
			if (mode_i == 'r') continue;
			//else throw exception("Error Data");
		}
		if (mode == 2) { Shoes shoes; shoes.PrintShoes(); int ask; cin >> ask; shoes.basket(ask); }
		if (mode == 3) SetData();
		if (mode == 4) { Object object; object.PrintDataAll();}
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

