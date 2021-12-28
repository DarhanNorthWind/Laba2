#pragma once
#include"NOTE.h"
#include<string>
#include<iostream>
using namespace std;
class Book
{

	NOTE* book;
	int size;

public:
	Book();
	~Book();
	int getSize();
	void sort(NOTE* arr, int size);
	void findPerson();
	void append(NOTE o);
	void clear();
	void show();
	void begin(string& fio, string& number,int* arr);
	void check(int& n);
};

