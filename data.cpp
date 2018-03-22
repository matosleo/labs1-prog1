#include "data.h" 


Data::Data(){}

Data::~Data(){}

int 
Data::getDia()
{
	return m_dia;
}

int 
Data::getMes()
{
	return m_mes;
}

int 
Data::getAno()
{
	return m_ano;
}

std::ostream& 
operator<<(std::ostream &o, Data const data)
{
	o << data.m_dia << "/" << data.m_mes << "/" << data.m_ano;
	return o;
}

std::istream& 
operator>>(std::istream &i, Data &data)
{
	std::cout << "Dia: ";
	i >> data.m_dia;
	std::cout << "Mês: ";
	i >> data.m_mes;
	std::cout << "Ano: ";
	i >> data.m_ano;
	return i;
}