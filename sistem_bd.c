#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das strings

// Fun��es //

int registrar() // fun��o de cadastro do sistema
	{
		setlocale(LC_ALL, "Portuguese"); //def linguagem
	
	// inicio cria��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// fim cria��o de vari�veis
	
	
	printf("Digite o CPF � cadastrar: "); // Pedindo informa��o ao usu�rio
	scanf("%s", cpf); // %s refere-se a uma string
	
	strcpy(arquivo, cpf);         // Respons�vel poir copiar os valores das string
	
	FILE *file;                   // Cria o arquivo
	file = fopen(arquivo, "w");   // Cria o arquivo
	fprintf(file,cpf);            // Salva o valor da vari�vel
	fclose(file);                 // Fecha o arquivo
	
	file = fopen(arquivo, "a");   // Abre o arquivo
	fprintf(file,", ");           // Modifica o arquivo
	fclose(file);
	
	printf("Digite o nome � cadastrar: "); // Pedindo informa��o ao usu�rio
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");   // Abre o arquivo
	fprintf(file, nome);		  // Modifica o arquivo colocando a vari�vel nome
	fclose(file);
	
	file = fopen(arquivo, "a");   // Abre o arquivo
	fprintf(file,", ");           // Modifica o arquivo
	fclose(file);
	
	printf("Digite o sobrenome � cadastrar: "); // Pedindo informa��o ao usu�rio
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");   // Abre o arquivo
	fprintf(file, sobrenome);     // Modifica o arquivo colocando a vari�vel sobrenome
	fclose(file);
	
	file = fopen(arquivo, "a");   // Abre o arquivo
	fprintf(file,", ");           // Modifica o arquivo
	fclose(file);
	
	printf("Digite o cargo � cadastrar: "); // Pedindo informa��o ao usu�rio
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");   // Abre o arquivo
	fprintf(file, cargo);		  // Modifica o arquivo colocando a vari�vel cargo
	fclose(file);
	
	file = fopen(arquivo, "a");   // Abre o arquivo
	fprintf(file,", ");           // Modifica o arquivo
	fclose(file);
	
	system("pause"); // Pausar o sistema
	
	}
	
int consultar()
	{
		setlocale(LC_ALL, "Portuguese"); //def linguagem
	
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF � consultar: "); // Pedindo informa��o ao usu�rio
	scanf("%s", cpf);
	
	FILE *file; // Procurando na biblioteca o file
	file = fopen(cpf, "r"); // Ler o arquivo
	
	if(file == NULL) // Caso file n�o seja encontrado no sistema
	{
		printf("N�o encontrado!\n");
	}
	
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // Informa��o para o usu�rio
		printf("%s", conteudo); // Armazenando "%s"(string) em conteudo e exibindo
		printf("\n\n");
	}
	
	system("pause");
	
	
	}

int deletar()
	{
		
	char cpf[40];
	
	printf("Qual o CPF � deletar: "); // Pedindo informa��o ao usu�rio
	scanf("%s", cpf); // Recebendo e armazenando as informa��o como string em cpf
	 
	remove(cpf); // Removendo cpf
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) // Conferindo se n�o tem o cpf
	{
		printf("CPF n�o encontrado no sistema!\n");
		system("pause");
	}
	
	
		
	}
	
int teste()
	{
	printf("Testando");
	system("pause");
	}


// Fun��es //



int main()
	{
		int opcao = 0; //def vari�vel 
		int x = 1;
		
		char senha_digitada[] = "admin";
		int comparacao;
		
		printf(" -------- Cart�rio EBAC -------- \n\n");
		printf("Login de administrador!\n\nDigite sua senha: ");
		scanf("%s", senha_digitada);
		
		comparacao = strcmp(senha_digitada, "admin"); // Comparando string
		
		if (comparacao == 0)
		{
			
			for (x = 1; x = 1;)
			{
			
				system("cls"); // Respons�vel por limpar a tela
				
				setlocale(LC_ALL, "Portuguese"); //def linguagem
				
				printf(" -------- Cart�rio EBAC -------- \n\n"); //inicio do menu
				printf("Escolha a op��o desejada do menu \n\n"); // Op��es para o usu�rio escolher
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar nomes\n");
				printf("\t3 - Deletar nomes\n");
				printf("\t4 - Sair do sistema\n\n");
				printf("Op��o: "); //fim do menu
				
				scanf("%d", &opcao); //armazenando a escolha do usu�rio
				
				system("cls"); // Respons�vel por limpar a tela
				
				switch (opcao) // In�cio do switch
				{
					case 1:
						registrar(); // Chamando a fun��o 
						break; // Fim do case
						
					case 2:
						consultar(); // Chamando a fun��o 
						break; // Fim do case
					
					case 3: 
						deletar(); // Chamando a fun��o 
						break; // Fim do case
						
					case 4:
						teste(); // Chamando a fun��o
						break;	// Fim do case			
					default: // Caso n�o seja nenhuma dos case definidos
						printf("Essa op��o n�o existe!\n");
						system("pause");
						break; // Fim do case
				} // Fim do switch
			}
			
		}
		
		else
			printf("Senha Inconrreta!");
	}
