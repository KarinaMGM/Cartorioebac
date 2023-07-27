#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de textos por região
#include <string.h> //Biblioteca responsável por cuidar das string

int incluir() //Função responsável por cadastrar os usuários no sistema
{  
    //Início criação de variáveis /string
   	char arquivo[40];
	char cpf[40]; 
   	char nome[40];
   	char sobrenome[40];
   	char cargo[40];
    //Término criação de variáveis /string
   	 
   	printf("Digite o CPF: "); //Coletando informações do usuário
   	scanf("%s", cpf); //%s refere-se a string, salva a informação na strin, variável CPF
   	
   	
   	strcpy(arquivo, cpf); //Responsável por copiar os valores das String
   	
   	FILE *file; //Cria o arquivo 
   	file = fopen(arquivo, "w"); //Abre o arquivo e o "w" significa escrever-write
   	fprintf(file, cpf); //Salva o valor da variável
   	fclose(file); //Fecha o arquivo
   	
    file = fopen(arquivo, "a"); //Abre o arquivo que foi salvo e o "a" significa atualizar  
    fprintf(file, ","); //Adiciona "," depois do cpf
    printf("\n"); //Função de pular uma linha
    fclose(file); //Fecha o arquivo
    
    printf("Digite o Nome: "); //Coletando informações do usuário
   	scanf("%s", nome); //Salva a informação na string, variável NOME
   	
   	file = fopen(arquivo, "a"); //Abre o arquivo que foi salvo, e atualiza
   	fprintf(file, nome);  //Salva o valor da variável
   	fclose(file); //Fecha o arquivo
   	
   	file = fopen(arquivo, "a"); //Abre o aquivo que foi salvo, e atualiza
    fprintf(file, ","); //Adiciona "," depois do nome
    printf("\n"); //Função de pular uma linha
    fclose(file); //Fecha o arquivo
    
    printf("Digite o Sobrenome: "); //Coletando informações do usuário
    scanf("%s", sobrenome); //Salva a informação na string, variável SOBRENOME
    
    file = fopen(arquivo, "a"); //Abre o arquivo que foi salvo,e atualiza
    fprintf(file, sobrenome); //Salva o valor da variável
    fclose(file); //Fecha o arquivo
    
    file = fopen(arquivo, "a"); //Abre o arquivo 	ue foi salvo e atualiza
    fprintf(file, ","); //Adiciona a "," depois do sobrenome
    printf("\n"); //Função de pular uma linha
    fclose(file); //Fecha o arquivo
    
    printf("Digite o Cargo: "); //Coletando informações do usuário
    scanf("%s", cargo); //Salva a informação na string, variável CARGO
    
    file = fopen(arquivo, "a"); //Abre o arquivo que foi salvo, e atualiza
    fprintf(file, cargo); //Salva o valor da variável
    fclose(file); //Fecha o arquivo
    printf("\n");

    
    system("pause"); //Pausa a tela para o usuário ler a mensagem - pressione uma tecla para continuar
    
   		   
}  

int consultar() //Função responsável por consultar os usuários no sistema
{
   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem - no português o sistema assume os acentos

   char cpf[40];
   char conteudo[200];
   
   printf("Digite o CPF: \n"); //Coletando informações do usuário
   scanf("%s", cpf);//Salva a informação na string, variável CPF
   
   FILE *file; //Cria o arquivo
   file = fopen(cpf,"r"); //Abre o arquivo e o "r" significa ler - read
   
   if(file == NULL) //Análise de usuário inexistente
   {
   printf("Registro não encontrado!\n\n");
   }
   
   while(fgets(conteudo, 200, file ) != NULL) // Análise de usuário existente
   {
   printf("\nEssas são as informações do usuário: \n\n");
   printf("%s", conteudo);
   printf("\n\n");  
   fclose(file); 
   }
   
   system("pause"); //Pausa a tela para o usuário ler a mensagem - pressione uma tecla para continuar
   
}  
 
int deletar() //Função responsável por deletar os usuários no sistema
{  
	char cpf[40];
	
	printf ("Digite o CPF do usuário a ser deletado: "); //Coletando informações do usuário
	scanf("%s",cpf); // Salva o arquivo na variável
	
	printf("\n");
	
	FILE *file; //abre o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo e o "r" significa ler - read
	
	if(file == NULL) // Análise de usuário inexistente
	{
	    printf("Registro não encontrado!\n\n");
        system("pause");	 
	}
	
	else
	{
	    fclose(file); //Fecha o arquivo
		remove(cpf); //Comando de deletar
		printf("Usuário deletado com sucesso!\n\n");
		system("pause");
    }  

}


int main () //Função princial, sempre a primeira a ser executada
    {
	
	int opcao=0; //Definindo variáveis
	int laco=1; // Criando variável Laço de repetição
	
	for(laco=1;laco=1;) // Repetição, sempre volta para o menu inicial
	
	{ //Início do laço
		
		system("cls"); //Responsável por limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem - no português o sistema assume os acentos
	
	    printf("*** Banco de Dados da EBAC ***\n\n"); //Início do menu
	    printf("Escolha a opção desejada:\n\n");
	    printf("\t1- Incluir Usuário\n");
	    printf("\t2- Consultar Usuário\n");
	    printf("\t3- Deletar Usuário\n\n\n\n");
	    printf("Opção: "); //Fim do Menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuário
	
    	system("cls"); // limpar a tela 
	
	    switch(opcao) //Início da variável
	    {
	    	case 1: //Início da seleção do menu
	    	incluir(); //Chamada de funções
	        break; // Fecha a seleção 
	        
	        case 2: // Início da seleção do menu
	        consultar(); //Chamada de funções
		    break; // Fecha a seleção
			
			case 3: //Início da seleção do menu
		    deletar(); //Chamada de funções
    		break; //Fecha a seleção
    		
    		default: //Análise de opção inexistente
			printf("Essa opcão não está disponível!\n"); // Aviso ao usuário
			system("pause"); // Pausa a tela para o usuário ler a mensagem - pressione uma tecla para continuar
			break; // Fim da seleção
		}
	
	
    } //Fim do laço 	
   }
