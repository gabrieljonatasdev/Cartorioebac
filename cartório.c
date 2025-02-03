#include <stdio.h> //biblioteca de comunic��o de usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//Inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio 
	scanf("%s", cpf); //%S refere-se a strings 
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salvo o valor da varivel
	fclose(file); //salva o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,","); //salva o valor da vari�vel
	fclose(file); //salva o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta a infroma��o do usu�rio
	scanf("%s",nome); //%S refere-se a strings 
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,nome); //salva o valor da vari�vel
	fclose(file); //salva o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,","); //salva o valor da vari�vel
	fclose(file); //salva o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coleta a informa��o do usu�rio
	scanf("%s",sobrenome); //%S refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,sobrenome); //salva o valor da vari�vel
	fclose(file); //salva o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,","); //salva o valor da vari�vel
	fclose(file); //salva o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coleta a informa��o do usu�rio
	scanf("%s",cargo); //%S refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,cargo); //salva o valor da vari�vel
	fclose(file); //salva o arquivo
	
	system("pause"); //pausa a tela para o usuario conseguir ler as informa��es 
	
}

int consulta() //fun��o responsavel por consultar os usu�rios no sistema 
{
	setlocale(LC_ALL, "portuguese"); //configura a linguagem para portugu�s
	
	//inicio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final cria��o de vari�vel/string
	
	printf("Digite o cpf a ser consultado: "); //coletando a informa��o de usu�rio
	scanf("%s",cpf); //refere-se a strings
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //cria o arquivo e o "r" significa ler
	
	if(file == NULL) //se o arquivo for inexistente 
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //mensagem exibida ao consultar arquivo inexistenate
	}
	
	while(fgets(conteudo, 200, file) != NULL) //se o arquivo existir 
	{
		printf("\nEssas s�o as inform��es do usu�rio: "); //mensagem exibida ao consultar arquivo existente 
		printf("%s", conteudo); //refere-se a strings
		printf("\n\n"); //apenas para fins de organiza��o 
	}
	
	system("pause"); //pausa a tela para o usu�rio conseguir ler as informa��es 
	
	
}

int deletar() //fun��o responsavel por deletar os usu�rios no sistema
{
	char cpf[40]; //inicio e fim cria��o de vari�veis/strings
	
	printf("Digite o cpf do usu�rio a ser deletado: "); //coletando a informa��o do usu�rio
	scanf("%s",cpf); //refere-se a strings
	
	remove(cpf); //primer key a ser deletada 
	
	FILE *file; //cria o arquivo 
	file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler 
	
	if(file == NULL) //se o arquivo for inexistente ou exclu�do 
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //mensagemexibida ao consultar arquivo inexistente 
		system("pause"); //pausa a tela para o usu�rio conseguir ler aas informa��es 
	}
	

}


int main() //fun��o responsavel pelo menu inicial
{
	int opcao=0; //Deinindo variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); //limpa a tela
	
    	setlocale(LC_ALL, "portuguese");
	
    	printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
    	printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("Op��o: "); //fim do menu
	
    	scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
    	system("cls"); //responsavel por limpar a tela
    	
    	
    	switch(opcao) //aciona as op��es do menu e chama as fun��es 
		{
			case 1:
			registro(); //chamada da fun��o registro
			break;
			
			case 2:
			consulta(); //chamada da fun��o consulta 
			break;
			
			case 3:
			deletar(); //chamada da fun��o deletar 
			break;
				
			default:
			printf("Essa op��o n�o est� disponivel!\n");
		    system("pause");
		    break;
		    
		}		
		
    } 
}
