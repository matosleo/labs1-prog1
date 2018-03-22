#ifndef DATA_H 
#define DATA_H

#include <iostream>

class Data
{

private:
	int m_dia;
	int m_mes;
	int m_ano;

public:
	Data();
	~Data();

	int getDia();
	int getMes();
	int getAno();

	friend std::ostream& operator<<(std::ostream &o, Data const data);
	friend std::istream& operator>>(std::istream &i, Data &data);
};

#endif