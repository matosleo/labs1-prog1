#ifndef DATA_H 
#define DATA_H

#include <iostream>
#include <time.h>

class Data
{

private:
	int m_dia;
	int m_mes;
	int m_ano;
	const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

public:
	Data();
	~Data();

	int countLeapYears(int, int);
	int getDifference();

	friend std::ostream& operator<<(std::ostream &o, Data const data);
	friend std::istream& operator>>(std::istream &i, Data &data);
};

#endif

/*

Copiei e modifiquei as funções countLeapYears e getDifference do 
site https://www.geeksforgeeks.org/find-number-of-days-between-two-given-dates/

*/