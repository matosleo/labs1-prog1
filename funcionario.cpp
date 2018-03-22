#include "funcionario.h"
#include <string>
#include <iomanip> 

int Funcionario::m_total_funcionarios = 0;

Funcionario::Funcionario()
{
	m_total_funcionarios++;
}

Funcionario::~Funcionario(){}

string
Funcionario::getNome()
{
	return m_nome;
}

double
Funcionario::getSalario()
{
	return m_salario;
}

void
Funcionario::setSalario(int novoSalario)
{
	m_salario = novoSalario;
}

Data
Funcionario::getDataAdmissao()
{
	return m_data_admissao;
}

std::ostream& 
operator<<(std::ostream &o, Funcionario const f)
{
	o << f.m_nome << " - R$" << std::fixed << std::setprecision(2) << f.m_salario << " - " << f.m_data_admissao;
	return o;
}

std::istream& 
operator>>(std::istream &i, Funcionario &f)
{
	std::cout << "Entre com o nome: ";
	i >> f.m_nome;
	std::cout << "Entre com o salário: ";
	i >> f.m_salario;
	std::cout << "Entre com a data de admissao: " << std::endl;
	i >> f.m_data_admissao;
	return i;
}

bool 
operator==(const Funcionario &f1, const Funcionario &f2)
{
	return (f1.m_nome.compare(f2.m_nome)) == 0;
}