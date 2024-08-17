#include<stdio.h> //biblioteca de comunicação com o usuário
#include<stdlib.h> //biblioteca de alocação de espaço em memória
#include<locale.h> //biblioteca de texto por região
#include<string.h> //biblioteca responsável pelas strings

int registro() //função responsável por cadastrar os usuários
{
	setlocale(LC_ALL, "Portuguese"); //coloca o idioma e os acentos no codigo
	
	//inicio da criação de variáveis/strings
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coleta informações do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valors das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"."); //coloquei um ponto final para ficar com uma gramática mais formal
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usuário a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Arquivo inexistente!\n");
	}
	
	while(fgets(conteudo, 200,file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("Usuário não se encontra no sistema!\n"); //mensagem caso não encontre um usuário
	}
	
	remove(cpf);

	if(file != NULL)
	{
		printf("Usuário deletado com sucesso!\n"); //mensagem caso encontre um usuário
	}
	
	system("pause");
	
}

int main()
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	char senhadigitada[10] = "a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	while(1)//inico do loop de comparação/validação entre senhas
	{
		printf("Login de Administrador!\n\nDigite a sua senha: ");
		scanf("%s", senhadigitada);
		
		comparacao = strcmp(senhadigitada, "admin");
		if (comparacao == 0)
		{
			printf("Acesso permitido!\n\n");
			break;
		}
		else
		{
			printf("Senha incorreta! Tente novamente.\n\n");
			system("pause");
		}
    }
	
		while (1)//começo do loop do menu
		{
	
			system("cls"); //responsável por limpar a tela
		
			setlocale(LC_ALL,"Portuguese"); //coloca o idioma e os acentos no codigo
	
			printf("### Cartório da EBAC ###\n\n"); //\n serve para pular linha
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n"); //\t serve para dar um espaçamento no inicio da frase
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: ");
	
			scanf("%d", &opcao); //armazenando a escolha do usuário
	
			system("cls");
		
			//inicio da seleções do menu
		
			switch(opcao)
			{
				case 1:
				registro();
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;	
				
				default:
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;
			}//fim da seleção do menu
		}//fim do loop do menu
	return 0;
		
}
