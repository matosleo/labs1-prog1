#include <iostream>
#include <list>
#include <string>
#include "funcionario.h"
#include "empresa.h"

void criarEmpresa(std::list<Empresa> &lista);
void listarEmpresas(std::list<Empresa> lista);
void addFuncEmpresa(std::list<Empresa> &lista, std::string nomeEmpresa);
void exibirFuncEmpresa(std::list<Empresa> lista, std::string nomeEmpresa);
void ajustaSalarioFuncEmpresa(std::list<Empresa> &lista, std::string nomeEmpresa);

int main(int argc, char const *argv[])
{

	std::list<Empresa> lista_empresas;

	int opcao;

	do {
		std::cout
		<< " 1 - Criar Empresa\n"
		<< " 2 - Adicionar Funcionário\n"
		<< " 3 - Exibir Funcionarios\n"
		<< " 4 - Ajustar Aumento Salarial\n"
		<< " 0 - Sair\n"
		<< "\n"
		<< " Opção: ";
		std::cin >> opcao;

		switch(opcao) {
			case 1:
			{
				criarEmpresa(lista_empresas);
				break;
			}
			
			case 2:
			{
				listarEmpresas(lista_empresas);
				if(lista_empresas.size() > 0)
				{
					std::cout << "Qual empresa deseja adicionar o funcionário? Digite o nome" << std::endl;
					std::string nomeEmpresa;
					std::cin >> nomeEmpresa;
					addFuncEmpresa(lista_empresas, nomeEmpresa);
				}
				break;			
			}

			case 3:
			{
				listarEmpresas(lista_empresas);
				if(lista_empresas.size() > 0)
				{
					std::cout << "Qual empresa deseja listar os funcionários? Digite o nome" << std::endl;
					std::string nomeEmpresa;
					std::cin >> nomeEmpresa;
					exibirFuncEmpresa(lista_empresas, nomeEmpresa);
				}
				break;	
			}

			case 4:
			{
				listarEmpresas(lista_empresas);
				if(lista_empresas.size() > 0)
				{
					std::cout << "Escolha a empresa que deseja fazer os ajustes? Digite o nome" << std::endl;
					std::string nomeEmpresa;
					std::cin >> nomeEmpresa;
					ajustaSalarioFuncEmpresa(lista_empresas, nomeEmpresa);
					
				}	
				break;
			}

			case 0:
			{
				std::cout << "Até logo!" << std::endl;
				break;
			}

			default:
			{
				std::cout << "!ERRO!\n"
				<< "Digite uma opção válida"
				<< std::endl;
				break;
			}
		}

	} while(opcao != 0);


	return 0;
}

void criarEmpresa(std::list<Empresa> &lista)
{
	Empresa e;
	std::cin >> e;
	bool existe = false;
	if(lista.size() > 0)
	{
		for(std::list<Empresa>::iterator it = lista.begin(); it != lista.end(); ++it)
		{
			if(*it == e)
			{
				existe = true;
			}
		}
	}
	if(existe)
	{
		std::cout << "Esta empresa já existe!" << std::endl;
	} 
	else
	{
		lista.push_back(e);
		std::cout << "Empresa adicionada com sucesso!" << std::endl;
	}
}

void listarEmpresas(std::list<Empresa> lista)
{
	int i = 1;
	if(lista.size() > 0)
	{
		for(std::list<Empresa>::iterator it = lista.begin(); it != lista.end(); ++it)
		{
			std::cout << i << " - " << *it << std::endl;
			i++;
		}
	}
	else
	{
		std::cout << "Não há empresas cadastradas!" << std::endl;
	}
}

/*

*/
void addFuncEmpresa(std::list<Empresa> &lista, std::string nomeEmpresa)
{
	bool achou = false;
	for(std::list<Empresa>::iterator it = lista.begin(); it != lista.end(); ++it)
	{
		if((it->getNome().compare(nomeEmpresa)) == 0)
		{
			it->addFuncionario();
			achou = true;
		}
	}
	if(!achou)
	{ 
		std::cout << "Não foi possível encontrar " << nomeEmpresa << " em nossos dados. Tente novamente." << std::endl;
	}
}

void exibirFuncEmpresa(std::list<Empresa> lista, std::string nomeEmpresa)
{
	bool achou = false;
	for(std::list<Empresa>::iterator it = lista.begin(); it != lista.end(); ++it)
	{
		if((it->getNome().compare(nomeEmpresa)) == 0)
		{
			it->listarFuncionarios();
			achou = true;
		}
	}
	if(!achou)
	{ 
		std::cout << "Não foi possível encontrar " << nomeEmpresa << " em nossos dados. Tente novamente." << std::endl;
	}	
}

void ajustaSalarioFuncEmpresa(std::list<Empresa> &lista, std::string nomeEmpresa)
{
	bool achou = false;
	for(std::list<Empresa>::iterator it = lista.begin(); it != lista.end(); ++it)
	{
		if((it->getNome().compare(nomeEmpresa)) == 0)
		{
			int porcentagem;
			std::cout << "Digite a porcentagem que deseja ajustar: ";
			std::cin >> porcentagem;
			it->addAumento(porcentagem);
			std::cout << "Ajuste feito com sucesso!" << std::endl;
			achou = true;
		}
	}
	if(!achou)
	{ 
		std::cout << "Não foi possível encontrar " << nomeEmpresa << " em nossos dados. Tente novamente." << std::endl;
	}	
}