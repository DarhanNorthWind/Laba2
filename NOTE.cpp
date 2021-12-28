#include "NOTE.h"

NOTE::NOTE():fio(""),number("")
{
	for (int i = 0; i < M; i++)
		this->birthday[i] = 0;
}

NOTE::NOTE(const NOTE& obj):fio(obj.fio),number(obj.number)
{
	for (int i = 0; i < M; i++)
		this->birthday[i] = obj.birthday[i];
}

NOTE::NOTE(string fio, string number, int* birthday)
{
	this->fio = fio;
	this->number = number;
	for (int i = 0; i < M; i++)
		this->birthday[i] = birthday[i];
	
}

string NOTE::getFIO()
{
	return string(this->fio);
}

string NOTE::getNumber()
{
	return string(this->number);
}

int* NOTE::getBirthday()
{
	return birthday;
}

void NOTE::setNumber(string number)
{
	this->number = number;
}

void NOTE::setFIO(string fio)
{
	this->fio = fio;
}

void NOTE::setBirthday(int* birthday)
{
	for (int i = 0; i < M; i++)
		this->birthday[i] = birthday[i];
}

NOTE& NOTE::operator=(const NOTE& obj)
{

	this->fio = obj.fio;
	this->number = obj.number;
	for (int i = 0; i < M; i++)
		this->birthday[i] = obj.birthday[i];

	return *this;
}

std::ostream& operator<<(std::ostream& out, const NOTE& o)
{

	out << "FIO: " << o.fio << "\n";
	out << "Telephone: " << o.number << "\n";
	out << "Birthday: ";
	for (int i = 0; i < M; i++)
		out << o.birthday[i] << " ";
	out << "\n";
	return out;
}

bool operator<(const NOTE& o1, const NOTE& o2)
{
	return o1.number.substr(0, 3) < o2.number.substr(0, 3) ? true : false;
}

bool operator>(const NOTE& o1, const NOTE& o2)
{
	return o1.number.substr(0, 3) > o2.number.substr(0, 3) ? true : false;
}

bool operator==(const NOTE& o1, const NOTE& o2)
{
	return o1.number.substr(0, 3) == o2.number.substr(0, 3) ? true : false;
}

bool operator!=(const NOTE& o1, const NOTE& o2)
{
	return o1.number.substr(0, 3) != o2.number.substr(0, 3) ? true : false;
}
