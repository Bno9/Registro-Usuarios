#include <stdio.h>  // biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em memoria
#include <locale.h> // biblioteca de aloca��o de texto por regiao
#include <string.h> // biblioteca respons�vel por cuidar de strings


//fun��es s� s�o executadas quando s�o chamadas por alguma variavel

int registro()
{ 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf); //responsavel por copiar valores das strings
	
	FILE *file;
	file = fopen(arquivo,"w");
	fprintf(file,"CPF: ");
	fclose(file);
	
	file = fopen(arquivo,"a"); //escreve no arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\nNome: ");
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file," ");
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo: ");
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
} 

int consultar()
{ 
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf ("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir esse arquivo, CPF n�o encontrado. \n");
	}

	else 
	{
		printf("Essas s�o as informa��es do usu�rio:\n");
	}
		while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n");
	}
		fclose(file);
		system("pause");
	}

int deletar()
{ 
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
		
	if(file == NULL)
	{
		printf("Esse usu�rio n�o est� registrado. \n");
	}	
	
	else
	{
		remove(cpf);
		printf("CPF removido com sucesso\n");
	}
		system("pause");
}



int main() //variavel
{
    int opcao=0; //Definindo variavel
    int loop=1; //Criando variavel loop

    for(loop=1;loop=1;)
	{
		system ("cls");
		setlocale(LC_ALL, "Portuguese"); //Escolhendo linguagem
		
		printf("### Cart�rio EBAC ###\n\n");
		printf("Escolha um menu:\n\n");
    	printf("\t1- Registrar nomes"); printf("\t2- Consultar nomes");    printf("\t3- Deletar nomes \n\n\n");
	 	printf("Op��o:");
		scanf("%d", &opcao); //armazenando escolha do usuario
		system("cls"); //clear

switch(opcao)
{

    case 1: 
  	registro();
    break;

    case 2:
    consultar();
    break;

    case 3:
    deletar();
    break;

    default:
    printf("Escolha uma das op��es disponiveis\n\n");
    system("pause");
    break;
} //fim escolhas
    } //fim loop
        } //fim variavel
