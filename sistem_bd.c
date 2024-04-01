#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsável por cuidar das strings

// Funções //

int registrar() // função de cadastro do sistema
	{
		setlocale(LC_ALL, "Portuguese"); //def linguagem
	
	// inicio criação de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// fim criação de variáveis
	
	
	printf("Digite o CPF à cadastrar: "); // Pedindo informação ao usuário
	scanf("%s", cpf); // %s refere-se a uma string
	
	strcpy(arquivo, cpf);         // Responsável poir copiar os valores das string
	
	FILE *file;                   // Cria o arquivo
	file = fopen(arquivo, "w");   // Cria o arquivo
	fprintf(file,cpf);            // Salva o valor da variável
	fclose(file);                 // Fecha o arquivo
	
	file = fopen(arquivo, "a");   // Abre o arquivo
	fprintf(file,", ");           // Modifica o arquivo
	fclose(file);
	
	printf("Digite o nome à cadastrar: "); // Pedindo informação ao usuário
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");   // Abre o arquivo
	fprintf(file, nome);		  // Modifica o arquivo colocando a variável nome
	fclose(file);
	
	file = fopen(arquivo, "a");   // Abre o arquivo
	fprintf(file,", ");           // Modifica o arquivo
	fclose(file);
	
	printf("Digite o sobrenome à cadastrar: "); // Pedindo informação ao usuário
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");   // Abre o arquivo
	fprintf(file, sobrenome);     // Modifica o arquivo colocando a variável sobrenome
	fclose(file);
	
	file = fopen(arquivo, "a");   // Abre o arquivo
	fprintf(file,", ");           // Modifica o arquivo
	fclose(file);
	
	printf("Digite o cargo à cadastrar: "); // Pedindo informação ao usuário
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");   // Abre o arquivo
	fprintf(file, cargo);		  // Modifica o arquivo colocando a variável cargo
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
	
	printf("Digite o CPF à consultar: "); // Pedindo informação ao usuário
	scanf("%s", cpf);
	
	FILE *file; // Procurando na biblioteca o file
	file = fopen(cpf, "r"); // Ler o arquivo
	
	if(file == NULL) // Caso file não seja encontrado no sistema
	{
		printf("Não encontrado!\n");
	}
	
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: "); // Informação para o usuário
		printf("%s", conteudo); // Armazenando "%s"(string) em conteudo e exibindo
		printf("\n\n");
	}
	
	system("pause");
	
	
	}

int deletar()
	{
		
	char cpf[40];
	
	printf("Qual o CPF à deletar: "); // Pedindo informação ao usuário
	scanf("%s", cpf); // Recebendo e armazenando as informação como string em cpf
	 
	remove(cpf); // Removendo cpf
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) // Conferindo se não tem o cpf
	{
		printf("CPF não encontrado no sistema!\n");
		system("pause");
	}
	
	
		
	}
	
int teste()
	{
	printf("Testando");
	system("pause");
	}


// Funções //



int main()
	{
		int opcao = 0; //def variável 
		int x = 1;
		
		char senha_digitada[] = "admin";
		int comparacao;
		
		printf(" -------- Cartório EBAC -------- \n\n");
		printf("Login de administrador!\n\nDigite sua senha: ");
		scanf("%s", senha_digitada);
		
		comparacao = strcmp(senha_digitada, "admin"); // Comparando string
		
		if (comparacao == 0)
		{
			
			for (x = 1; x = 1;)
			{
			
				system("cls"); // Responsável por limpar a tela
				
				setlocale(LC_ALL, "Portuguese"); //def linguagem
				
				printf(" -------- Cartório EBAC -------- \n\n"); //inicio do menu
				printf("Escolha a opção desejada do menu \n\n"); // Opções para o usuário escolher
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar nomes\n");
				printf("\t3 - Deletar nomes\n");
				printf("Opção: "); //fim do menu
				
				scanf("%d", &opcao); //armazenando a escolha do usuário
				
				system("cls"); // Responsável por limpar a tela
				
				switch (opcao) // Início do switch
				{
					case 1:
						registrar(); // Chamando a função 
						break; // Fim do case
						
					case 2:
						consultar(); // Chamando a função 
						break; // Fim do case
					
					case 3: 
						deletar(); // Chamando a função 
						break; // Fim do case
						
					case 4:
						teste(); // Chamando a função
						break;	// Fim do case			
					default: // Caso não seja nenhuma dos case definidos
						printf("Essa opção não existe!\n");
						system("pause");
						break; // Fim do case
				} // Fim do switch
			}
			
		}
		
		else
			printf("Senha Inconrreta!");
	}
