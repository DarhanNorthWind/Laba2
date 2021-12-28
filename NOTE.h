#pragma once
#include <string>
#include <iostream>
#define M 3
using namespace std;
class NOTE
{
	string fio;
	string number;
	int birthday[M];

public:

	NOTE();
	NOTE(const NOTE& obj);
	NOTE(string fio, string number, int* birthday);

	string getFIO();
	string getNumber();
	int* getBirthday();

	void setNumber(string number);
	void setFIO(string fio);
	void setBirthday(int* birthday);
	NOTE& operator=(const NOTE& obj);
	friend std::ostream& operator<<(std::ostream& out, const NOTE& o);
	friend bool operator<(const NOTE& ob1, const NOTE& ob2);
	friend bool operator>(const NOTE& ob1, const NOTE& ob2);
	friend bool operator==(const NOTE& ob1, const NOTE& ob2);
	friend bool operator!=(const NOTE& ob1, const NOTE& ob2);

};

