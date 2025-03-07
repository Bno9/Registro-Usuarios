#include <stdio.h>  // biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em memoria
#include <locale.h> // biblioteca de aloca��o de texto por regiao
#include <string.h> // biblioteca respons�vel por cuidar de strings


//fun��es s� s�o executadas quando s�o chamadas por alguma variavel

int registro() //tela para registrar usuarios
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
	file = fopen(arquivo,"w"); //cria o arquvio e o "w" escreve no arquivo
	fprintf(file,"CPF: ");
	fclose(file);
	
	file = fopen(arquivo,"a"); //escreve no arquivo, o "a" � para atualizar os dados dele
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
	
		while(laco == 1) //repeti��o para registrar outro usuario
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
                printf("Esta op��o n�o est� dispon�vel!\n\n");
                system("pause");
                break;
			}
	}
} 

int cnfregistro() //tela de confirma��o para prosseguir
{
	int resposta = 1;
	
	system("cls");
	
	printf("Digite 1 para avan�ar e 2 para voltar ao menu principal\n\n");
		
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
            printf("Esta op��o n�o est� dispon�vel!\n\n");
            system("pause");
            cnfregistro();
            system("cls");
            break;
		}	
}

int consultar() //tela para consultar usuarios
{ 
	setlocale(LC_ALL, "Portuguese"); //Colocando o idioma em portugues
	
	char cpf[40];
	char conteudo[200];
	int resposta =0;
	int laco = 1;
	
	printf ("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //se o arquivo for Nulo ele faz isso
	{
		printf("N�o foi possivel abrir esse arquivo, CPF n�o encontrado. \n");
	}

	else //caso contrario
	{
		printf("Essas s�o as informa��es do usu�rio:\n");
	}
	
		while(fgets(conteudo, 200, file) != NULL) //pega as informa��es do arquivo
	{
		printf("%s", conteudo);
		printf("\n");
	}
	
		fclose(file);
		
		system("pause");
		
		while(laco == 1) //repeti��o para consultar outro nome
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
                printf("Esta op��o n�o est� dispon�vel!\n\n");
                system("pause");
                break;
		}
	}
		system("pause");
}
	
int cnfconsultar() //tela de confirma��o para prosseguir
{
	int resposta = 1;
	
	system("cls");
	
printf("Digite 1 para avan�ar e 2 para voltar ao menu principal\n\n");
		
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
                printf("Esta op��o n�o est� dispon�vel!\n\n");
                system("pause");
                cnfconsultar();
                system("cls");
                break;
			}	
}

int deletar() //tela para deletar usuarios
{ 
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	int resposta = 1;
	int laco = 1;
	
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
		remove(cpf); //comando de remover
		printf("CPF removido com sucesso\n");
	}
	
	system("pause");
	
	while(laco == 1) //repeti��o para confirmar se quer deletar outro nome
	{
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
                printf("Esta op��o n�o est� dispon�vel!\n\n");
                system("pause");
                break;
			}
	}
		system("pause");
}
	
int cnfdeletar() //tela de confirma��o para prosseguir
{
	int resposta = 1;
	
	system("cls");
	
printf("Digite 1 para avan�ar e 2 para voltar ao menu principal\n\n");
		
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
                printf("Esta op��o n�o est� dispon�vel!\n\n");
                system("pause");
                cnfdeletar();
                system("cls");
                break;
			}	
}
	
int registroadm() //variavel de registro de administrador (essa parte do registro est� completa, mas ta faltando a fun��o de puxar o arquivo para verificar usuario e senha)
{
	
	char arq[40];
	char usuario[40];
	char senha[40];
	int laco = 1;
	int resposta = 1;
		
	printf("Digite o usuario a ser cadastrado: ");
	scanf("%s",usuario);
	
	strcpy(arq,usuario); //responsavel por copiar valores das strings
	
	FILE *file;
	
	file = fopen(arq,"a"); //escreve no arquivo
	fprintf(file,usuario); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite a senha a ser cadastrada: ");
	scanf("%s",senha);
	
	file = fopen(arq,"a");
	fprintf(file,senha);
	fclose(file);
	
	system("pause");
	
		while(laco == 1)
	{
		system("cls");
		
		printf("Deseja registrar outro administrador?\n\n");
		printf("Digite 1 para registrar e 2 para sair\n\n");
		
		scanf("%d", &resposta);
		
		system("cls");
		
		switch(resposta)
			{
			case 1:
				registroadm();
				return 0;
				break;
				
			case 2:
				return 0;
				break;
				 
			default:
                printf("Esta op��o n�o est� dispon�vel!\n\n");
                system("pause");
                break;
			}
	}		
}
	
int main() //variavel principal
{
    int opcao=0; //Definindo variavel
    int loop=1; //Criando variavel loop
    char senhadigitada[10]="a";
    char usuariodigitado[30]="a";
    int comparacao;
    int comparacao1;
    
    setlocale(LC_ALL, "Portuguese"); //Escolhendo linguagem

	system("cls"); //limpa tudo que foi escrito

	printf("### Cart�rio EBAC ###\n\n");
	
	printf("Login de administrador\nDigite o seu usuario:");
	scanf("%s",usuariodigitado);
	printf("Digite sua senha:");
	scanf("%s",senhadigitada);
	
	system("cls");
	
	comparacao = strcmp(senhadigitada, "123"); //strcmp compara as variaveis/strings
	comparacao1 = strcmp(usuariodigitado, "Breno");
	
	if(comparacao == 0 & comparacao1 == 0) //se tal coisa for igual a tal coisa, fa�a tal coisa
	{
    	for(loop=1;loop=1;) //repeti��o da tela de escolha
		{
		system ("cls");
		
		printf("Escolha um menu:\n\n");
    	printf("\t1- Registrar nomes"); printf("\t2- Consultar nomes");    printf("\t3- Deletar nomes"); printf("\t4- Registrar administrador"); printf("\t5- Mudar o usuario\n\n\n");
	 	printf("Op��o:");
		scanf("%d", &opcao); //armazenando escolha do usuario
		
		system("cls"); //clear

switch(opcao) //escolha do menu
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
    registroadm();
    break;
    
    case 5:
    main();
    break;

    default:
    printf("Escolha uma das op��es disponiveis\n\n");
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
