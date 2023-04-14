#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação9 de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários do sistema
{
	//Início da criação das variáveis/strings
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//Final da criação das variáveis/strings
	
	printf("Digite o CPF a ser cadastrado:  "); //Coleta das informações do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Reponsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo no bando de dados
	file = fopen(arquivo, "w"); //Cria o arquivo na pasta onde foi salvo o sistema ("w) significa Write - escrever
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); // ("a") tem a função de editar
	fprintf(file, ", Nome:");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:  ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file, ", Sobrenome:");
	fclose(file);
	
	printf ("Digite o sobrenome a ser cadastrado:  ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file, ", Cargo:");
	fclose(file);
	
	printf ("Digite o cargo a ser cadastrado:  ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definindo linguagens
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:  ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // ("r") tem função de leitura (Read)
	
	if(file == NULL)
	{
		printf("\n\n\nNão foi possível abrir o arquivo, CPF não localizado!\n\n\n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: CPF:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser removido do sistema: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL);
	{
		printf("\n\nO usuário não foi encontrando! Por favor, insira um CPF válido\n\n");
		system("pause");
	}
	
}

int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "portuguese"); //Definindo linguagens
	
		printf("### Cartório da EBAC ###\n\n"); //Início do Menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 Registrar nomes\n");
		printf("\t2 Consultar nomes\n");
		printf("\t3 Deletar nomes\n"); 
		printf("\t4 Sair do Sistema\n\n\n");
		printf("Opção: "); //Fim do Menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //início da seleção do Menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			printf("Selecione");
			break;
			
			case 4:
			printf("\n\n\n\n ####Obrigado por utilizar o sistema!#### \n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível! Por favor, escolha uma opção válida. \n\n\n\n\n");
			system("pause");
			break;
			
		} //Fim da seleção
				
	}
	
}
