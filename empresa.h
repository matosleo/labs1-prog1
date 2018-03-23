#ifndef EMPRESA_H 
#define EMPRESA_H

#include <iostream>
#include <list>
#include "funcionario.h"
#include <iomanip>

using std::list;

using std::string;

class Empresa
{

private:
	string m_nome;
	string m_cnpj;
	list<Funcionario> m_lista_funcionarios;
	static int m_total_empresas;

public:
	Empresa();
	~Empresa();

	string getNome();
	static int getTotalEmpresas();

	void addFuncionario();
	void listarFuncionarios();
	void listarFuncionariosPorCriterio();
	void addAumento(int porcentagem);
	
	friend std::ostream& operator<<(std::ostream &o, Empresa const f);
	friend std::istream& operator>>(std::istream &i, Empresa &f);
	friend bool operator==(const Empresa &e1, const Empresa &e2);
};

#endif