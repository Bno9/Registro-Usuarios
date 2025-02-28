#include <stdio.h>  // biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço em memoria
#include <locale.h> // biblioteca de alocação de texto por regiao
#include <string.h> // biblioteca responsável por cuidar de strings


//funções só são executadas quando são chamadas por alguma variavel


int registro()
{ 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int laco = 1;
	int resposta = 1;
		
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
	
		while(laco == 1)
	{
		system("cls");
		printf("Deseja registrar outro usuario?\n\n");
		printf("Digite 1 para registrar e 2 para sair\n\n");
		
		scanf("%d", &resposta);
		
		system("cls");
		
		switch(resposta)
			{
			case 1:
				registro();
				return 0;
				break;
				
			case 2:
				return 0;
				break;
				 
			default:
                printf("Esta opção não está disponível!\n\n");
                system("pause");
                break;
			}
	}
} 

int cnfregistro()
{
	int resposta = 1;
	system("cls");
	
printf("Digite 1 para avançar e 2 para voltar ao menu principal\n\n");
		
		scanf("%d", &resposta);
		
		system("cls");
		
		switch(resposta)
			{
			case 1:
				registro();
				break;
				
			case 2:
				return 0;
				break;
				 
			default:
                printf("Esta opção não está disponível!\n\n");
                system("pause");
                cnfregistro();
                system("cls");
                break;
			}	
	}
	
	
int consultar()
{ 
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	int resposta =0;
	int laco = 1;
	
	printf ("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir esse arquivo, CPF não encontrado. \n");
	}

	else 
	{
		printf("Essas são as informações do usuário:\n");
	}
		while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n");
	}
		fclose(file);
		
		system("pause");
		
		while(laco == 1)
		{
		system("cls");
		printf("Deseja consultar outro nome?\n");
		printf("Digite 1 para consultar e 2 para sair\n\n");	
		
		scanf("%d", &resposta);
		
		system("cls");
		
		switch(resposta)
		{
			case 1:
				consultar();
				return 0;
				break;
				
			case 2:
				return 0;
				break;
				 
			default:
                printf("Esta opção não está disponível!\n\n");
                system("pause");
                break;
		}
		}
		
		system("pause");
	}
	
	
	int cnfconsultar()
{
	int resposta = 1;
	
	system("cls");
	
printf("Digite 1 para avançar e 2 para voltar ao menu principal\n\n");
		
		scanf("%d", &resposta);
		
		system("cls");
		
		switch(resposta)
			{
			case 1:
				consultar();
				break;
				
			case 2:
				return 0;
				break;
				 
			default:
                printf("Esta opção não está disponível!\n\n");
                system("pause");
                cnfconsultar();
                system("cls");
                break;
			}	
	}

int deletar()
{ 
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	int resposta = 1;
	int laco = 1;
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
		
	if(file == NULL)
	{
		printf("Esse usuário não está registrado. \n");
	}	
	
	else
	{
		remove(cpf);
		printf("CPF removido com sucesso\n");
	}
	
	system("pause");
	
	
	while(laco == 1){
		system("cls");
		printf("Deseja deletar outro nome?\n");
		printf("Digite 1 para deletar e 2 para sair\n\n");
		
		scanf("%d", &resposta);
		
		system("cls");
		
		switch(resposta)
			{
			case 1:
				deletar();
				return 0;
				break;
				
			case 2:
				return 0;
				break;
				 
			default:
                printf("Esta opção não está disponível!\n\n");
                system("pause");
                break;
			}
		}
		
		system("pause");
}
	
	
int cnfdeletar()
{
	int resposta = 1;
	
	system("cls");
	
printf("Digite 1 para avançar e 2 para voltar ao menu principal\n\n");
		
		scanf("%d", &resposta);
		
		system("cls");
		
		switch(resposta)
			{
			case 1:
				deletar();
				break;
				
			case 2:
				return 0;
				break;
				 
			default:
                printf("Esta opção não está disponível!\n\n");
                system("pause");
                cnfdeletar();
                system("cls");
                break;
			}	
	}
	
int main() //variavel
{
    int opcao=0; //Definindo variavel
    int loop=1; //Criando variavel loop
    char senhadigitada[10]="a";
    char usuariodigitado[30]="a";
    int comparacao;
    int comparacao1;
    
    setlocale(LC_ALL, "Portuguese"); //Escolhendo linguagem

	system("cls");

	printf("### Cartório EBAC ###\n\n");
	
	
	printf("Login de administrador\nDigite o seu usuario:");
	scanf("%s",usuariodigitado);
	printf("Digite sua senha:");
	scanf("%s",senhadigitada);
	
	system("cls");
	
	comparacao = strcmp(senhadigitada, "123");
	comparacao1 = strcmp(usuariodigitado, "Breno");
	
	if(comparacao == 0 & comparacao1 == 0)
	{
    	for(loop=1;loop=1;)
		{
		system ("cls");
		
		printf("Escolha um menu:\n\n");
    	printf("\t1- Registrar nomes"); printf("\t2- Consultar nomes");    printf("\t3- Deletar nomes"); printf("\t4- Mudar o usuario\n\n\n");
	 	printf("Opção:");
		scanf("%d", &opcao); //armazenando escolha do usuario
		system("cls"); //clear

switch(opcao)
{

    case 1: 
  	cnfregistro();
    break;

    case 2:
    cnfconsultar();
    break;

    case 3:
    cnfdeletar();
    break;
    
    case 4:
    main();
    break;

    default:
    printf("Escolha uma das opções disponiveis\n\n");
    system("pause");
    break;
} //fim escolhas
    } //fim loop
		} //fim if
		else
		{
		printf("Usuario ou senha incorretos. Tente novamente\n\n");
		system("pause");
		system("cls");
		main();
	} //fim else
        } //fim variavel
