#include <iostream>
#include <list>
#include <string>
#include "funcionario.h"
#include "empresa.h"

void criarEmpresa(std::list<Empresa> &lista);
void listarEmpresas(std::list<Empresa> lista);
void addFuncEmpresa(std::list<Empresa> &lista, std::string nomeEmpresa);
void exibirFuncEmpresa(std::list<Empresa> lista, std::string nomeEmpresa);
void exibirFuncEmpresaPorCriterio(std::list<Empresa> lista, std::string nomeEmpresa);
void ajustaSalarioFuncEmpresa(std::list<Empresa> &lista, std::string nomeEmpresa);
int mediaFuncionariosEmpresas();

int main(int argc, char const *argv[])
{

	std::list<Empresa> lista_empresas;

	int opcao;

	do {
		std::cout << std::endl
		<< " 1 - Criar Empresa\n"
		<< " 2 - Adicionar Funcionário\n"
		<< " 3 - Exibir Funcionarios\n"
		<< " 4 - Ajustar Aumento Salarial\n"
		<< " 5 - Média Funcionarios/Empresas\n"
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
				std::cout << std::endl
				<< " 1 - Exibir Todos\n"
				<< " 2 - Contratados recente\n"
				<< "\n"
				<< " Opção: ";
				int escolha;
				std::cin >> escolha;
				
				if(escolha  == 1)
				{
					listarEmpresas(lista_empresas);
					if(lista_empresas.size() > 0)
					{
						std::cout << "Qual empresa deseja listar os funcionários? Digite o nome" << std::endl;
						std::string nomeEmpresa;
						std::cin >> nomeEmpresa;
						exibirFuncEmpresa(lista_empresas, nomeEmpresa);
					}
				}
				else if (escolha  == 2)
				{
					listarEmpresas(lista_empresas);
					if(lista_empresas.size() > 0)
					{
						std::cout << "Qual empresa deseja LISTAR os funcionários? Digite o nome" << std::endl;
						std::string nomeEmpresa;
						std::cin >> nomeEmpresa;
						exibirFuncEmpresaPorCriterio(lista_empresas, nomeEmpresa);
					}

				}
				else
				{
					std::cout << std::endl << "opção inválida!" << std::endl;
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

			case 5:
			{
				if(lista_empresas.size() > 0)
				{
					std::cout << std::endl << "As empresas tem em média " << mediaFuncionariosEmpresas() << " funcionários contratados" << std::endl;
				}
				else
				{
					std::cout << std::endl << "Não há empresas cadastradas!" << std::endl;
				}
				break;
			}

			case 0:
			{
				std::cout << std::endl <<  "Até logo!" << std::endl;
				break;
			}

			default:
			{
				std::cout << std::endl << "!ERRO!\n"
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
		std::cout << std::endl << "Esta empresa já existe!" << std::endl;
	} 
	else
	{
		lista.push_back(e);
		std::cout << std::endl << "Empresa adicionada com sucesso!" << std::endl;
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
		std::cout << std::endl << "Não há empresas cadastradas!" << std::endl;
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
		std::cout << std::endl << "Não foi possível encontrar " << nomeEmpresa << " em nossos dados. Tente novamente." << std::endl;
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
		std::cout << std::endl << "Não foi possível encontrar " << nomeEmpresa << " em nossos dados. Tente novamente." << std::endl;
	}	
}

void exibirFuncEmpresaPorCriterio(std::list<Empresa> lista, std::string nomeEmpresa)
{
	bool achou = false;
	for(std::list<Empresa>::iterator it = lista.begin(); it != lista.end(); ++it)
	{
		if((it->getNome().compare(nomeEmpresa)) == 0)
		{
			it->listarFuncionariosPorCriterio();	
			achou = true;
		}
	}
	if(!achou)
	{ 
		std::cout << std::endl << "Não foi possível encontrar " << nomeEmpresa << " em nossos dados. Tente novamente." << std::endl;
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
			std::cout << std::endl << "Ajuste feito com sucesso!" << std::endl;
			achou = true;
		}
	}
	if(!achou)
	{ 
		std::cout << std::endl << "Não foi possível encontrar " << nomeEmpresa << " em nossos dados. Tente novamente." << std::endl;
	}	
}

int mediaFuncionariosEmpresas()
{
	return Funcionario::getTotalFuncionarios()/Empresa::getTotalEmpresas(); 
}