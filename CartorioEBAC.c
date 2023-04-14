#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o9 de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios do sistema
{
	//In�cio da cria��o das vari�veis/strings
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//Final da cria��o das vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado:  "); //Coleta das informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Repons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo no bando de dados
	file = fopen(arquivo, "w"); //Cria o arquivo na pasta onde foi salvo o sistema ("w) significa Write - escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); // ("a") tem a fun��o de editar
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
	file = fopen(cpf,"r"); // ("r") tem fun��o de leitura (Read)
	
	if(file == NULL)
	{
		printf("\n\n\nN�o foi poss�vel abrir o arquivo, CPF n�o localizado!\n\n\n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: CPF:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser removido do sistema: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL);
	{
		printf("\n\nO usu�rio n�o foi encontrando! Por favor, insira um CPF v�lido\n\n");
		system("pause");
	}
	
}

int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "portuguese"); //Definindo linguagens
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do Menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 Registrar nomes\n");
		printf("\t2 Consultar nomes\n");
		printf("\t3 Deletar nomes\n"); 
		printf("\t4 Sair do Sistema\n\n\n");
		printf("Op��o: "); //Fim do Menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //in�cio da sele��o do Menu
		{
			case 1:
			registro(); //chamada de fun��es
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
			printf("Essa op��o n�o est� dispon�vel! Por favor, escolha uma op��o v�lida. \n\n\n\n\n");
			system("pause");
			break;
			
		} //Fim da sele��o
				
	}
	
}
