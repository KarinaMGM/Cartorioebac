#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de textos por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das string

int incluir() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{  
    //In�cio cria��o de vari�veis /string
   	char arquivo[40];
	char cpf[40]; 
   	char nome[40];
   	char sobrenome[40];
   	char cargo[40];
    //T�rmino cria��o de vari�veis /string
   	 
   	printf("Digite o CPF: "); //Coletando informa��es do usu�rio
   	scanf("%s", cpf); //%s refere-se a string, salva a informa��o na strin, vari�vel CPF
   	
   	
   	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das String
   	
   	FILE *file; //Cria o arquivo 
   	file = fopen(arquivo, "w"); //Abre o arquivo e o "w" significa escrever-write
   	fprintf(file, cpf); //Salva o valor da vari�vel
   	fclose(file); //Fecha o arquivo
   	
    file = fopen(arquivo, "a"); //Abre o arquivo que foi salvo e o "a" significa atualizar  
    fprintf(file, ","); //Adiciona "," depois do cpf
    printf("\n"); //Fun��o de pular uma linha
    fclose(file); //Fecha o arquivo
    
    printf("Digite o Nome: "); //Coletando informa��es do usu�rio
   	scanf("%s", nome); //Salva a informa��o na string, vari�vel NOME
   	
   	file = fopen(arquivo, "a"); //Abre o arquivo que foi salvo, e atualiza
   	fprintf(file, nome);  //Salva o valor da vari�vel
   	fclose(file); //Fecha o arquivo
   	
   	file = fopen(arquivo, "a"); //Abre o aquivo que foi salvo, e atualiza
    fprintf(file, ","); //Adiciona "," depois do nome
    printf("\n"); //Fun��o de pular uma linha
    fclose(file); //Fecha o arquivo
    
    printf("Digite o Sobrenome: "); //Coletando informa��es do usu�rio
    scanf("%s", sobrenome); //Salva a informa��o na string, vari�vel SOBRENOME
    
    file = fopen(arquivo, "a"); //Abre o arquivo que foi salvo,e atualiza
    fprintf(file, sobrenome); //Salva o valor da vari�vel
    fclose(file); //Fecha o arquivo
    
    file = fopen(arquivo, "a"); //Abre o arquivo 	ue foi salvo e atualiza
    fprintf(file, ","); //Adiciona a "," depois do sobrenome
    printf("\n"); //Fun��o de pular uma linha
    fclose(file); //Fecha o arquivo
    
    printf("Digite o Cargo: "); //Coletando informa��es do usu�rio
    scanf("%s", cargo); //Salva a informa��o na string, vari�vel CARGO
    
    file = fopen(arquivo, "a"); //Abre o arquivo que foi salvo, e atualiza
    fprintf(file, cargo); //Salva o valor da vari�vel
    fclose(file); //Fecha o arquivo
    printf("\n");

    
    system("pause"); //Pausa a tela para o usu�rio ler a mensagem - pressione uma tecla para continuar
    
   		   
}  

int consultar() //Fun��o respons�vel por consultar os usu�rios no sistema
{
   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem - no portugu�s o sistema assume os acentos

   char cpf[40];
   char conteudo[200];
   
   printf("Digite o CPF: \n"); //Coletando informa��es do usu�rio
   scanf("%s", cpf);//Salva a informa��o na string, vari�vel CPF
   
   FILE *file; //Cria o arquivo
   file = fopen(cpf,"r"); //Abre o arquivo e o "r" significa ler - read
   
   if(file == NULL) //An�lise de usu�rio inexistente
   {
   printf("Registro n�o encontrado!\n\n");
   }
   
   while(fgets(conteudo, 200, file ) != NULL) // An�lise de usu�rio existente
   {
   printf("\nEssas s�o as informa��es do usu�rio: \n\n");
   printf("%s", conteudo);
   printf("\n\n");  
   fclose(file); 
   }
   
   system("pause"); //Pausa a tela para o usu�rio ler a mensagem - pressione uma tecla para continuar
   
}  
 
int deletar() //Fun��o respons�vel por deletar os usu�rios no sistema
{  
	char cpf[40];
	
	printf ("Digite o CPF do usu�rio a ser deletado: "); //Coletando informa��es do usu�rio
	scanf("%s",cpf); // Salva o arquivo na vari�vel
	
	printf("\n");
	
	FILE *file; //abre o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo e o "r" significa ler - read
	
	if(file == NULL) // An�lise de usu�rio inexistente
	{
	    printf("Registro n�o encontrado!\n\n");
        system("pause");	 
	}
	
	else
	{
	    fclose(file); //Fecha o arquivo
		remove(cpf); //Comando de deletar
		printf("Usu�rio deletado com sucesso!\n\n");
		system("pause");
    }  

}


int main () //Fun��o princial, sempre a primeira a ser executada
    {
	
	int opcao=0; //Definindo vari�veis
	int laco=1; // Criando vari�vel La�o de repeti��o
	
	for(laco=1;laco=1;) // Repeti��o, sempre volta para o menu inicial
	
	{ //In�cio do la�o
		
		system("cls"); //Respons�vel por limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem - no portugu�s o sistema assume os acentos
	
	    printf("*** Banco de Dados da EBAC ***\n\n"); //In�cio do menu
	    printf("Escolha a op��o desejada:\n\n");
	    printf("\t1- Incluir Usu�rio\n");
	    printf("\t2- Consultar Usu�rio\n");
	    printf("\t3- Deletar Usu�rio\n\n\n\n");
	    printf("Op��o: "); //Fim do Menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
    	system("cls"); // limpar a tela 
	
	    switch(opcao) //In�cio da vari�vel
	    {
	    	case 1: //In�cio da sele��o do menu
	    	incluir(); //Chamada de fun��es
	        break; // Fecha a sele��o 
	        
	        case 2: // In�cio da sele��o do menu
	        consultar(); //Chamada de fun��es
		    break; // Fecha a sele��o
			
			case 3: //In�cio da sele��o do menu
		    deletar(); //Chamada de fun��es
    		break; //Fecha a sele��o
    		
    		default: //An�lise de op��o inexistente
			printf("Essa opc�o n�o est� dispon�vel!\n"); // Aviso ao usu�rio
			system("pause"); // Pausa a tela para o usu�rio ler a mensagem - pressione uma tecla para continuar
			break; // Fim da sele��o
		}
	
	
    } //Fim do la�o 	
   }
