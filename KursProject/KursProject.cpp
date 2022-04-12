#include "Header.h"	// подключение заголовочного файла
using namespace std;

//	точки throw,
//	меню
//	оставляй айди

void SetData();

int main()
{
	srand(time(0)); //псевдо-рандомные числа
	bool flag = false; int kostil = 0; /* :))))) */ Admin admin; User user;
    setlocale(LC_ALL, "ru");	//подключение

	//cout << "Вход:\t" << endl;
	//cout << "Как пользователь - 1\nКак администратор - 2" << endl;
	//int swi; cin >> swi;

	//switch (swi)
	//{
	//case 1:
	//	break;
	//case 2:
	//	break;
	//default:
	//	break;
	//}

	while (true)
	{
		cout << "#0 - Выход			" << "\t\t\t\t\t18 - Войти" << endl;
		cout << "#1 - Товары		" << endl;
		cout << "#2 - Обувь			" << endl;
		cout << "#3 - Штаны			" << endl;
		cout << "#4 - Верхняя Одежда" << endl;
		cout << "#5 - Корзина       " << endl;
		int mode; Object object; cin >> mode;
		if (cin.fail()) throw exception("Введён неизвестный символ");
		switch (mode)
		{
		case 1:
			system("cls");
			while (true) {
			object.item(); object.Print();
			cout << "////////////////////////////////////////////////////////////////////////////////" << endl;
			char mode_i; 
			cout << "Для покупки введите букву b" << endl;
			cout << "Для выхода из списка введите любую другую букву" << endl;
			cin >> mode_i;
			if (mode_i == 'b') {
				while (true) {
					cout << "Введите артикул желаемого товара" << endl;
					int ask;
					cin >> ask;
					if (ask > object.GetCount() && ask != '0') throw exception("Не существующий артикул товара");
					else {
						object.basket(ask);
						cout << "1 - Назад" << endl;
						cout << "Любая клавиша - Продолжить" << endl;
						char ask_b; cin >> ask_b;
						system("cls");
						object.Print();
						if (ask_b == '1') break;
						else continue;
					}
				}
			}
			else break;
			}
			system("cls");
			break;
		case 2:
			system("cls");
			while (true) {
				Cloth cloth; cloth.Print();
				cout << "////////////////////////////////////////////////////////////////////////////////" << endl;
				char mode_i;
				cout << "Для покупки введите букву b" << endl;
				cout << "Для выхода из списка введите любую другую букву" << endl;
				cin >> mode_i;
				if (mode_i == 'b') {
					while (true) {
						cout << "Введите артикул желаемого товара" << endl;
						int ask;
						cin >> ask;
						if (ask > cloth.GetCount() && ask <= 0) throw exception("Не существующий артикул товара");
						else {
							cloth.basket(ask);
							cout << "1 - Назад" << endl;
							cout << "Любая клавиша - Продолжить" << endl;
							char ask_b; cin >> ask_b;
							system("cls");
							object.Print();
							if (ask_b == '1') break;
							else continue;
						}
					}
				}
				else break;
			}
			system("cls");
			break;
		case 3:
			system("cls");
			while (true) {
				Pants pants; pants.Print();
				cout << "////////////////////////////////////////////////////////////////////////////////" << endl;
				char mode_i;
				cout << "Для покупки введите букву b" << endl;
				cout << "Для выхода из списка введите любую другую букву" << endl;
				cin >> mode_i;
				if (mode_i == 'b') {
					while (true) {
						cout << "Введите артикул желаемого товара" << endl;
						int ask;
						cin >> ask;
						if (ask > pants.GetCount() && ask <= 0) throw exception("Не существующий артикул товара");
						else {
							pants.basket(ask);
							cout << "1 - Назад" << endl;
							cout << "Любая клавиша - Продолжить" << endl;
							char ask_b; cin >> ask_b;
							system("cls");
							object.Print();
							if (ask_b == '1') break;
							else continue;
						}
					}
				}
				else break;
			}
			system("cls");
			break;
		case 4:
			system("cls");
			while (true) {
				Cloth cloth; cloth.Print();
				cout << "////////////////////////////////////////////////////////////////////////////////" << endl;
				char mode_i;
				cout << "Для покупки введите букву b" << endl;
				cout << "Для выхода из списка введите любую другую букву" << endl;
				cin >> mode_i;
				if (mode_i == 'b') {
					while (true) {
						cout << "Введите артикул желаемого товара" << endl;
						int ask;
						cin >> ask;
						if (ask > cloth.GetCount() && ask <= 0) throw exception("Не существующий артикул товара");
						else {
							cloth.basket(ask);
							cout << "1 - Назад" << endl;
							cout << "Любая клавиша - Продолжить" << endl;
							char ask_b; cin >> ask_b;
							system("cls");
							object.Print();
							if (ask_b == '1') break;
							else continue;
						}
					}
				}
				else break;
			}
			system("cls");
			break;
		case 5:
			if (!flag) {
				object.PrintBasket();
				system("pause");
				system("cls");
				break;
			}
		case 6:
			system("cls");
			int temp_day;
			temp_day = 1 + rand() % 15;
			user.SetDay(temp_day);
			cout << "//////////////////////////////////////////////" << endl;
			cout << "///////////Assembly///////////////////////////" << endl;
			cout << "//////////////////////////////////////////////" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "//////////////////////////////////////////////" << endl;
			cout << "///////////Estimated delivery time " << temp_day << "//////////" << endl;
			cout << "//////////////////////////////////////////////" << endl;
			user.Purchase();
			this_thread::sleep_for(chrono::seconds(1));
		case 7:
			cout << "////////////" << endl;
			cout << "Days off: " <<user.GetDay()<<"/" << endl;
			cout << "////////////" << endl;
			break;
		case 99:
			SetData();
			break;
		case 0:
			exit(0);
		default:
			cout << "Введена неизвестная команда" << endl;
			system("pause");
			system("cls");
		}
	}




	//while (true) {
	//	cout << "#0 - exit          " << endl; 
	//	cout << "#1 - product       " << endl;
	//	cout << "#2 - shoes         " << endl;
	//	cout << "#3 - reset         " << endl;
	//	cout << "#4 - basket        " << endl;
	//	if (!flag) {
	//		cout << "#6 - Login as admin" << endl;// Admin привелегии
	//		cout << "38 - Purchase      " << endl;// Покупка товара
	//	}
	//	if (flag) { 
	//		cout << "11 - PRINT_ALL" << endl;
	//		cout << "12 - ADD_NEW" << endl;
	//	}
	//	int mode; cin >> mode; Object object;
	//	if (mode == 0) break;
	//	if (mode == 1) {
	//	    object.item(); object.Print();
	//		cout << "b - buy\nr - return\n";
 //			char mode_i; cin >> mode_i;
	//		if (mode_i == 'b') {
	//			int ask; cin >> ask;
	//			object.basket(ask);
	//		}
	//		//else throw exception("Error Data");
	//	}
	//	if (mode == 2) { Cloth shoes; shoes.Print(); 
	//		cout << "b - buy\nr - return\n";
	//		char mode_i; cin >> mode_i;
	//		if (mode_i == 'b') {
	//			int ask; cin >> ask;
	//			shoes.basket(ask);
	//		}
	//	}
	//	if (mode == 3) SetData();
	//	if (mode == 4) { object.PrintBasket(); }
	//	if (!flag) {
	//		if (mode == 6) {
	//			string pass; cin >> pass;
	//			if (pass == admin.GetPassword()) flag = true;
	//		}
	//	}
	//	if (mode == 11 && flag) {
	//		admin.Print_Admin_Data();
	//	}
	//	if (mode == 38)
	//	{
	//		int temp_day = 1 + rand() % 15;
	//		user.SetDay(temp_day);
	//		cout << "//////////////////////////////////////////////" << endl;
	//		cout << "///////////Assembly///////////////////////////" << endl;
	//		cout << "//////////////////////////////////////////////" << endl;
	//		this_thread::sleep_for(chrono::seconds(2));
	//		cout << "//////////////////////////////////////////////" << endl;
	//		cout << "///////////Estimated delivery time " << temp_day << "//////////" << endl;
	//		user.Purchase();
	//		this_thread::sleep_for(chrono::seconds(1));
	//	}
	//	if (mode == 39)
	//	{
	//		cout << "////////////" << endl;
	//		cout << "Days off: " <<user.GetDay()<<"/" << endl;
	//		cout << "////////////" << endl;
	//	}
	//	if (mode == 12 && flag) {
	//		fstream File(FILE_NAME, ios_base::app);
	//		 if (kostil == 0) { File << endl; kostil= 1;}
	//		string temp, new_str;
	//		cout << "Добавление:";										//
	//		cout << "\nCategory\t"; cin >> temp; new_str += temp + " ";	//
	//		cout << "\nType    \t"; cin >> temp; new_str += temp + " ";	//
	//		cout << "\nSex     \t"; cin >> temp; new_str += temp + " ";	//
	//		cout << "\nBrand   \t"; cin >> temp; new_str += temp + " ";	//
	//		cout << "\nModel   \t"; cin >> temp; new_str += temp + " ";	// Формирование строки пользователя
	//		cout << "\nSize    \t"; cin >> temp; new_str += temp + " ";	//
	//		cout << "\nPrice   \t"; cin >> temp; new_str += temp + " ";	//
	//		cout << "\nColor   \t"; cin >> temp; new_str += temp + " ";	//
	//		cout << "\nCount   \t"; cin >> temp; new_str += temp;		//
	//		File << new_str << endl;	// Запись собранной строки пользователя в "корзину"
	//		File.close();			    // Закрытие отработавшего файла
	//	}
	//	cout << "//////////////////////////////////////////////" << endl;
	//}

    return 0;
}

void SetData()	// Функция возвращение данных в исходный вид
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
