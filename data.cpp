/*

Copiei e modifiquei as funções countLeapYears e getDifference do 
site https://www.geeksforgeeks.org/find-number-of-days-between-two-given-dates/

*/

#include "data.h" 


Data::Data(){}

Data::~Data(){}


// This function counts number of leap years before the
// given date
int 
Data::countLeapYears(int mes, int ano)
{
    int years = ano;
 
    // Check if the current year needs to be considered
    // for the count of leap years or not
    if (mes <= 2)
        years--;
 
    // An year is a leap year if it is a multiple of 4,
    // multiple of 400 and not a multiple of 100.
    return years / 4 - years / 100 + years / 400;
}

// This function returns number of days between two given
// dates
int 
Data::getDifference()
{

	time_t now = time(0);

	tm* localtm = localtime(&now);

	int diaAtual = localtm->tm_mday, mesAtual = localtm->tm_mon + 1, anoAtual = localtm->tm_year + 1900;


    // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1'
 
    // initialize count using years and day
    long int n1 = m_ano*365 + m_dia;
 
    // Add days for months in given date
    for (int i = 0; i < m_mes - 1; i++)
        n1 += monthDays[i];
 
    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(m_mes, m_ano);
 
    // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'
 
    long int n2 = anoAtual*365 + diaAtual;
    for (int i = 0; i < mesAtual - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(mesAtual, anoAtual);
 
    // return difference between two counts
    return (n2 - n1);
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