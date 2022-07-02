#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct PhoneBook
{
	string name;
	string address;
	string number;
};

// ukuran array
const int SIZE = 100;
// counter, menghitung jumlah data yang tersimpan
int counter = 0;
// array untuk menyimpan data
PhoneBook pb[SIZE];
void add_contact(); void show_contact();
void sc_contact();  void ed_contact();
char get_menu();

int main()
{
	while (true)
	{
		char select = get_menu();
		if (select == '1')
			add_contact();
		else if (select == '2')
			show_contact();
		else if (select == '3')
			sc_contact();
		else if (select == '4')
			ed_contact();
		else if (select == '5')
			break;
	}
	return 0;
}

void add_contact()
{
	system("cls");
	cout << "Add New Contact\n\n";
	cout << "- Name		: ";
	getline(cin, pb[counter].name);
	cout << "- Address	: ";
	getline(cin, pb[counter].address);
	cout << "- Phone		: ";
	getline(cin, pb[counter].number);
	++counter;
}

void show_contact()
{
	system("cls");
	cout << "Show Contact\n\n";
	cout << "--------------------------------------------------------------\n";
	cout << setw(4) << "#";
	cout << setw(15) << "Name";
	cout << setw(30) << "Address";
	cout << setw(13) << "Number";
	cout << endl;
	cout << "--------------------------------------------------------------\n";
	for (int i = 0; i < counter; ++i)
	{
		cout << setw(4) << i + 1;
		cout << setw(15) << pb[i].name;
		cout << setw(30) << pb[i].address;
		cout << setw(13) << pb[i].number;
		cout << endl;
	}
	cout << "--------------------------------------------------------------\n";
	system("pause");
}

void sc_contact()
{
	system("cls");
	string x;

	cout << "Search Contact\n\n";
	cout << "Nama yang dicari	: ";
	getline(cin, x);

	system("cls");
	bool found{ false };

	for (auto i = 0; i < counter; ++i)
	{
		if (x == pb[i].name)
		{
			found = true;
			cout << "Search Contact\n\n";
			cout << x << endl;
			cout << "Contact ditemukan\n" << endl;
			cout << "--------------------------------------------------------------\n";
			cout << setw(4) << "#";
			cout << setw(15) << "Name";
			cout << setw(30) << "Address";
			cout << setw(13) << "Number";
			cout << endl;
			cout << "--------------------------------------------------------------\n";
			cout << setw(4) << i + 1;
			cout << setw(15) << pb[i].name;
			cout << setw(30) << pb[i].address;
			cout << setw(13) << pb[i].number;
			cout << endl;
			cout << "--------------------------------------------------------------\n";
		}
	}

	if (found == false)
	{
		cout << "Search Contact\n\n";
		cout << x << endl;
		cout << "Contact tidak ditemukan" << endl;
	}

	system("pause");
}

void ed_contact()
{
	system("cls");
	int y, z;
	cout << "Edit Contact\n\n";
	cout << "Urutan contact yang ingin diedit	: ";
	cin >> y;
	cin.ignore(1, '\n');

	z = y - 1;

	system("cls");
	if (y > counter)
	{
		cout << "Edit Contact\n\n";
		cout << "Contact tidak ditemukan" << endl;
		system("pause");
	}

	else
	{
		cout << "Edit Contact\n\n";
		cout << "- Name		: ";
		getline(cin, pb[z].name);
		cout << "- Address	: ";
		getline(cin, pb[z].address);
		cout << "- Phone		: ";
		getline(cin, pb[z].number);
	}
}

char get_menu()
{
	system("cls");
	cout << "Phone Book\n\n";
	cout << " [1] Add Contact\n";
	cout << " [2] Show Contact\n";
	cout << " [3] Search Contact\n";
	cout << " [4] Edit Contact\n";
	cout << " [5] Exit\n\n";
	cout << "Select	: ";
	string sel;
	getline(cin, sel);
	return sel[0]; // hanya mengambil karakter ke-0
}