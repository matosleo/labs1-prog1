#ifndef FUNCIONARIO_H 
#define FUNCIONARIO_H

#include <iostream>
#include "data.h"
#include <iomanip>

using std::string;

class Funcionario
{

private:
	string m_nome;
	double m_salario;
	Data m_data_admissao;
	static int m_total_funcionarios;
public:
	Funcionario();
	~Funcionario();

	static int getTotalFuncionarios();
	double getSalario();
	void setSalario(int);
	Data getDataAdmissao();

	friend std::ostream& operator<<(std::ostream &o, Funcionario const f);
	friend std::istream& operator>>(std::istream &i, Funcionario &f);
	friend bool operator==(const Funcionario &f1, const Funcionario &f2);
};



#endif