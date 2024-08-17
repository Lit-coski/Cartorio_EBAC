#include<stdio.h> //biblioteca de comunica��o com o usu�rio
#include<stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include<locale.h> //biblioteca de texto por regi�o
#include<string.h> //biblioteca respons�vel pelas strings

int registro() //fun��o respons�vel por cadastrar os usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //coloca o idioma e os acentos no codigo
	
	//inicio da cria��o de vari�veis/strings
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coleta informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valors das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da vari�vel
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
	fprintf(file,"."); //coloquei um ponto final para ficar com uma gram�tica mais formal
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usu�rio a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Arquivo inexistente!\n");
	}
	
	while(fgets(conteudo, 200,file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("Usu�rio n�o se encontra no sistema!\n"); //mensagem caso n�o encontre um usu�rio
	}
	
	remove(cpf);

	if(file != NULL)
	{
		printf("Usu�rio deletado com sucesso!\n"); //mensagem caso encontre um usu�rio
	}
	
	system("pause");
	
}

int main()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	char senhadigitada[10] = "a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	while(1)//inico do loop de compara��o/valida��o entre senhas
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
	
		while (1)//come�o do loop do menu
		{
	
			system("cls"); //respons�vel por limpar a tela
		
			setlocale(LC_ALL,"Portuguese"); //coloca o idioma e os acentos no codigo
	
			printf("### Cart�rio da EBAC ###\n\n"); //\n serve para pular linha
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n"); //\t serve para dar um espa�amento no inicio da frase
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: ");
	
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
			system("cls");
		
			//inicio da sele��es do menu
		
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
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
			}//fim da sele��o do menu
		}//fim do loop do menu
	return 0;
		
}
