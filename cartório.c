#include <stdio.h> //biblioteca de comunicção de usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//Inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário 
	scanf("%s", cpf); //%S refere-se a strings 
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salvo o valor da varivel
	fclose(file); //salva o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,","); //salva o valor da variável
	fclose(file); //salva o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta a infromação do usuário
	scanf("%s",nome); //%S refere-se a strings 
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,nome); //salva o valor da variável
	fclose(file); //salva o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,","); //salva o valor da variável
	fclose(file); //salva o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coleta a informação do usuário
	scanf("%s",sobrenome); //%S refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,sobrenome); //salva o valor da variável
	fclose(file); //salva o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,","); //salva o valor da variável
	fclose(file); //salva o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coleta a informação do usuário
	scanf("%s",cargo); //%S refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,cargo); //salva o valor da variável
	fclose(file); //salva o arquivo
	
	system("pause"); //pausa a tela para o usuario conseguir ler as informações 
	
}

int consulta() //função responsavel por consultar os usuários no sistema 
{
	setlocale(LC_ALL, "portuguese"); //configura a linguagem para português
	
	//inicio criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final criação de variável/string
	
	printf("Digite o cpf a ser consultado: "); //coletando a informação de usuário
	scanf("%s",cpf); //refere-se a strings
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //cria o arquivo e o "r" significa ler
	
	if(file == NULL) //se o arquivo for inexistente 
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //mensagem exibida ao consultar arquivo inexistenate
	}
	
	while(fgets(conteudo, 200, file) != NULL) //se o arquivo existir 
	{
		printf("\nEssas são as informções do usuário: "); //mensagem exibida ao consultar arquivo existente 
		printf("%s", conteudo); //refere-se a strings
		printf("\n\n"); //apenas para fins de organização 
	}
	
	system("pause"); //pausa a tela para o usuário conseguir ler as informações 
	
	
}

int deletar() //função responsavel por deletar os usuários no sistema
{
	char cpf[40]; //inicio e fim criação de variáveis/strings
	
	printf("Digite o cpf do usuário a ser deletado: "); //coletando a informação do usuário
	scanf("%s",cpf); //refere-se a strings
	
	remove(cpf); //primer key a ser deletada 
	
	FILE *file; //cria o arquivo 
	file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler 
	
	if(file == NULL) //se o arquivo for inexistente ou excluído 
	{
		printf("O usuário não se encontra no sistema!.\n"); //mensagemexibida ao consultar arquivo inexistente 
		system("pause"); //pausa a tela para o usuário conseguir ler aas informações 
	}
	

}


int main() //função responsavel pelo menu inicial
{
	int opcao=0; //Deinindo variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); //limpa a tela
	
    	setlocale(LC_ALL, "portuguese");
	
    	printf("### Cartório da EBAC ###\n\n"); //inicio do menu
    	printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("Opção: "); //fim do menu
	
    	scanf("%d", &opcao); //armazenando a escolha do usuário
	
    	system("cls"); //responsavel por limpar a tela
    	
    	
    	switch(opcao) //aciona as opções do menu e chama as funções 
		{
			case 1:
			registro(); //chamada da função registro
			break;
			
			case 2:
			consulta(); //chamada da função consulta 
			break;
			
			case 3:
			deletar(); //chamada da função deletar 
			break;
				
			default:
			printf("Essa opção não está disponivel!\n");
		    system("pause");
		    break;
		    
		}		
		
    } 
}
