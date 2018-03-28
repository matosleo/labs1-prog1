#ifndef CADASTRO_H
#define CADASTRO_H

#include <iostream>
#include <list>
#include <string>
#include "empresa.h"
#include "funcionario.h"

using std::list;

class Cadastro {

private:

	list<Empresa> m_lista_empresas;

public:
	Cadastro();
	~Cadastro();

	void menu();
	void criarEmpresa(list<Empresa> &lista);
	void listarEmpresas(list<Empresa> lista);
	void addFuncEmpresa(list<Empresa> &lista, string nomeEmpresa);
	void exibirFuncEmpresa(list<Empresa> lista, string nomeEmpresa);
	void exibirFuncEmpresaPorCriterio(list<Empresa> lista, string nomeEmpresa);
	void ajustaSalarioFuncEmpresa(list<Empresa> &lista, string nomeEmpresa);
	int mediaFuncionariosEmpresas();
	Empresa buscaEmpresa(string);

};


#endif