#include "empresa.h"
#include <string>

int Empresa::m_total_empresas = 0;

Empresa::Empresa()
{
	m_nome = "Empresa sem nome";
	m_cnpj = "Sem CNPJ";
	m_total_empresas++;
}

Empresa::~Empresa(){}


string
Empresa::getNome()
{
	return m_nome;
}

string
Empresa::getCnpj()
{
	return m_cnpj;
}

void 
Empresa::addFuncionario()
{
	Funcionario f;
	std::cin >> f;
	bool existe = false;
	if(m_lista_funcionarios.size() > 0)
	{
		for(std::list<Funcionario>::iterator it = m_lista_funcionarios.begin(); it != m_lista_funcionarios.end(); ++it)
		{
			if(*it == f)
			{
				existe = true;
			}
		}
	}
	if(existe)
	{
		std::cout << "Este funcionário já existe!" << std::endl;
	} 
	else
	{
		m_lista_funcionarios.push_back(f);
		std::cout << "Funcionário adicionado com sucesso!" << std::endl;
	}
}

void 
Empresa::listarFuncionarios()
{
	if(m_lista_funcionarios.size() > 0)
	{
		std::cout << "*** Lista de funcionários da empresa " << m_nome << " ***" << std::endl;
		for(std::list<Funcionario>::iterator it = m_lista_funcionarios.begin(); it != m_lista_funcionarios.end(); ++it)
		{
			std::cout << *it << std::endl;
		}
	}
	else
	{
		std::cout << "Não há funcionários para listar" << std::endl;
	}
}

void 
Empresa::addAumento(int porcentagem)
{
	if(m_lista_funcionarios.size() > 0)
	{
		int ajuste;

		for(std::list<Funcionario>::iterator it = m_lista_funcionarios.begin(); it != m_lista_funcionarios.end(); ++it)
		{
			ajuste = ((it->getSalario() * porcentagem) / 100) + it->getSalario();
			it->setSalario(ajuste);
		}
	}
	else
	{
		std::cout << "Não há funcionários para ajustar o salário" << std::endl;
	}		
}


std::ostream& 
operator<<(std::ostream &o, Empresa const f)
{
	o << f.m_nome << " | " << "CNPJ: " << f.m_cnpj  << " | " << f.m_lista_funcionarios.size() << " funcionários" << std::endl;
	return o;
}

std::istream& 
operator>>(std::istream &i, Empresa &f)
{
	std::cout << "Digite o nome da empresa: ";
	i >> f.m_nome;
	std::cout << "Digite o CNPJ: ";
	i >> f.m_cnpj;
	return i;
}

bool 
operator==(const Empresa &e1, const Empresa &e2)
{
	return (e1.m_nome.compare(e2.m_nome)) == 0;
}