#include "Book.h"

Book::Book():book(nullptr),size(0)
{
	bool flag = true;
	int n = 0, birthday[M];
	string fio = "", number = "";
	while (flag) {
		try
		{
			std::cout << "Menu:\n";
			std::cout << "1. Add notes\n";
			std::cout << "2. Delete notes\n";
			std::cout << "3. Change notes\n";
			std::cout << "4. Show notes\n";
			std::cout << "5. Find notes\n";
			std::cout << "6. Exit\n";
			std::cout << "Enter number of command: ";
			cin >> n;

			switch (n)
			{
			case 1:
				begin(fio, number, birthday);
				append(NOTE(fio, number, birthday));
				break;
			case 2:
				show();
				cout << "\nEnter deleted index: ";
				cin >> n;
				check(n);
				clear();
				break;
			case 3:
				show();
				cout << "\nEnter changed index: ";
				cin >> n;
				check(n);
				begin(fio, number, birthday);
				book[n].setFIO(fio);
				book[n].setNumber(number);
				book[n].setBirthday(birthday);
				sort(book, size);
				break;
			case 4:
				show();
				break;
			case 5:
				findPerson();
				break;
			case 6:
				flag = false;
				break;
			default:
				break;
			}

		}
		catch (const char* excep)
		{
			cout << excep<<"\n";
		}

	}
}

Book::~Book()
{
	if (size != 0)
		delete[] book;


}

int Book::getSize()
{
	return this->size;
}

void Book::sort(NOTE* arr, int size)
{
	if (size == 0)
		throw "Empty book";
	int i = 0, j = size - 1;
	NOTE x = arr[size / 2];

	do {
		while (arr[i] < x) i++;
		while (arr[j] > x) j--;

		if (i <= j) {
			NOTE tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;


		}
	} while (i <= j);

	if (j > 0)
		sort(arr, j + 1);
	if (i < size)
		sort(&arr[i], size - i);
}

void Book::findPerson()
{
	if (size == 0)
		throw "Empty Book";
	
	string str="",FIO = "";
	int pos = 0,cnt = 0;
	cout << "Enter surname: ";
	cin >> str;
	
	for (int i = 0; i < size; i++) {
		FIO = book[i].getFIO();
		pos = FIO.find(" ");
		FIO = FIO.substr(0,pos);
		if (str == FIO){
			cnt++;
			cout << book[i];
		}
	}
	if (cnt == 0)
		cout << "No search " << str<<"\n";
}

void Book::append(NOTE o)
{
	NOTE* arrNew = new NOTE[size + 1];

	if (size != 0) {
		for (int i = 0; i < size; i++)
			arrNew[i] = book[i];
		arrNew[size] = o;
	}
	else
		arrNew[size] = o;

	size++;
	NOTE* bufptr = book;
	book = arrNew;
	delete[] bufptr;
	sort(book, size);
}

void Book::clear()
{
	if (size == 0)
		throw "empty list";


	NOTE* bufptr = book;
	NOTE* arrNew = new NOTE[size - 1];//выделили память под новый массив
	if (size == 1) {
		delete[] book;
		book = nullptr;
		size--;
		return;
	}
	for (int i = 1; i < size; i++)//начиная со второго элемента заполняем новый массив
		arrNew[i - 1] = book[i];

	book = arrNew;
	delete[] bufptr;
	size--;
	sort(book, size);
	return;
}

void Book::show()
{
	if (size == 0)
		throw "Empty book";

	cout << "-===============Book===============-\n";
	for (int i = 0; i < size; i++) {
		cout << "----------Note:["<<i<<"]--------------\n";
		cout << book[i];
	}
	cout << "-==================================-\n";
}

void Book::begin(string& fio, string& number, int* arr)
{
	string surname = "", name = "";
	int n = 0;
	cout << "\nEnter fio: \n";
	cout << "\nEnter surname: ";
	cin >> surname;
	cout << "\nEnter name: ";
	cin >> name;
	fio = surname + " " + name;

	cout << "\nEnter telephone number: ";
	cin >> number;
	cout << "\nEnter bithday:";
	cout << "\nDay:";
	cin >> arr[0];
	cout << "\nMounth:";
	cin >> arr[1];
	cout << "\nYear:";
	cin >> arr[2];
	cout << "\n";
}

void Book::check(int& n)
{
	if (n >= size)
		n = size - 1;
	else if (n < 0)
		n = 0;;
	book[n].setNumber("000");
}
