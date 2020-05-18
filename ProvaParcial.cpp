// João Marcos Castelli Código: 833251

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

typedef struct quilogramas {
	float kg;
	
	struct quilogramas *prox, *ant; //Struct para armazenar os dados de quilogramas
} controle;

typedef struct produtor{
	int prod;
	
	struct produtor *p, *a;  //Struct pra armazenar o CPF dos produtores
} ctrl;

	controle *pilha = (controle *) malloc(sizeof(controle)); //Alocação de memória para a pilha
	ctrl *fila = (ctrl *) malloc(sizeof(ctrl));	//Alocção de memória para a fila

int menu()
{
	
	
	if(!pilha)
	{
		printf("Memoria indisponivel");
	}
	else
	{
		pilha -> kg=0;
		pilha -> prox = NULL; //Inicialização da pilha
		pilha -> ant = NULL;
	}
	
	if(!fila)
	{
		printf("Memoria indisponivel");
	}
	else
	{
		fila -> prod=0;
		fila -> p = NULL; //Inicialização da fila
		fila -> a = NULL;
	}
	
	int opcao;
	
	system("cls");
	printf("----MENU----");
	printf("\n\nEscolha uma das opcoes:\n1 - Inserir\n2 - Limpar\n3 - Listar\n4 - Ajuda"); //Menu de escolha de funções do programa
	printf("\n\nOpcao: ");
	scanf("%i", &opcao);
	return opcao;
	
}
void insere() //Função de inserção na fila ou pilha
{
	int opt;
	
	system("cls");
	printf("Escolha o metodo de insercao:\n1 - Quilogramas\n2 - CPF do Produtor\n\nOpcao: "); //Escolha de CPF ou Quilogramas
	scanf("%i", &opt);
	
	if(opt == 1)
	{
		system("cls");
		
		controle *novo = (controle *) malloc(sizeof(controle));
		
		if(!novo)
		{
			printf("\n\nSem memoria RAM disponivel\n\n");
		}
		else
		{
			novo -> kg=0;
			novo -> prox = NULL;
			novo -> ant = NULL;
		}
		printf("\n\nDigite a quantidade de quilogramas: "); //Inserção de dados na pilha
		scanf("%f", &novo->kg);
		
		if(pilha -> prox = NULL)
		{
			pilha -> prox = novo;
			novo -> ant = pilha;
		}
		else
		{
			controle *temp;
			
	        temp = pilha -> prox;
	        pilha -> prox = novo;
	        novo -> prox = temp;
	        temp -> ant = novo;
	        novo -> ant = pilha;
		}
		
	}
	else if(opt == 2)
	{
		
		system("cls");
		
		ctrl *nv = (ctrl *) malloc(sizeof(ctrl));
		
		if(!nv)
		{
			printf("\n\nSem memoria RAM disponivel\n\n");
		}
		else
		{
			nv -> prod = 0;
			nv -> p = NULL;
			nv -> a = NULL;
		}
		printf("\n\nDigite o CPF do produtor: "); //Inserção de dados na fila
		scanf("%i", &nv -> prod);
				
		if(fila -> p = NULL)
		{
			fila -> p = nv;
			nv -> a = fila;
		}
		else
		{
			ctrl *tempt;
			
	        tempt = fila -> p;
	        fila -> p = nv;
	        nv -> p = tempt;
	        tempt -> a = nv;
	        nv -> a = fila;
		}
	}
	else
	{
		printf("Opcao invalida");
	}
	system("pause");
}
void limpa()
{
	system("cls");
	
	int opt;
	
	printf("Qual memoria voce deseja esvaziar?\n1 - Quilogramas\n2 - Produtores");
	scanf("%i", &opt);
	
	if(opt == 1)
	{
				controle *temp;
                controle *aux;

                temp = pilha -> prox;

                while(temp -> prox != NULL)
                {
                   aux = temp;
                   temp = aux -> prox;						//Função de esvaziar a pilha
                   free(aux);
                }
                if(temp -> prox == NULL)
                {
                  pilha -> prox = temp -> prox;
                  free(temp);
                }
	}
	else if(opt == 2)
	{
				ctrl *tempt;
                ctrl *auxt;

                tempt = fila -> p;

                while(tempt -> p != NULL)
                {
                   auxt = tempt;
                   tempt = auxt -> p;				//Função de esvaziar a fila
                   free(auxt);
                }
                if(tempt -> p == NULL)
                {
                  fila -> p = tempt -> p;
                  free(tempt);
                }
	}
	else
	{
		printf("Opcao invalida");
	}
	
}
void lista()
{
	
	int opt;
	
	system("cls");
	
	printf("Escolha qual das opcoes deseja consultar\n1 - KG\n2 - Produtor\n\nOpcao: ");
	scanf("%i", &opt);
	
					system("cls");
	
	if(opt == 1)
	{
			controle *temp;
			temp = pilha -> prox;
			
			if(pilha -> prox == NULL)
			{
				printf("Memoria sem registro");
			}
			
			while(temp -> prox != NULL)
			{
				printf("Quantidade de KG: %.2f\n", temp -> kg);			//Função para printar a pilha
				temp = temp->prox;
			}
			printf("\nQuantidade de KG: %.2f\n", temp -> kg);
	}
	else if(opt == 2)
	{
			ctrl *tempt;
			tempt = fila -> p;
			
			if(fila -> p == NULL)
			{
				printf("Memoria sem registro");
			}
			
			while(tempt -> p != NULL)
			{
				printf("CPF do produtor: %i\n", tempt -> prod);			//Função para printar a fila
				tempt = tempt->p;
			}
			printf("CPF do produtor: %i\n", tempt -> prod);
	}
	else
	{
		printf("Opcao invalida");
	}
	system("pause");
}
void ajuda()
{
						//Espaço de interação com o usuário para esclarecimento das funções do programa
	system("cls");
	printf("Este programa destinado ao controle de entrada de produtos agricolas foi criado com as seguintes funcoes:\n");
	printf("Inserir: esta funcao e responsavel por guardar as informacoes fornecidas em uma estrutura de filas, e pilhas, os quilogramas em estrutura de pilhas e as produtores em estruturas de filas.\n");
	printf("Remover: essa funcao e responsavel por remover itens desejados, lembrando que so e possivel remover o ultimo item que foi inserido, nao sendo possivel remover algo que esta no meio da fila ou pilha.\n");
	printf("Limpar: esta funcao limpa todos os dados no sistema.\n");
	printf("Listar: esta opcao lista os itens armazenados no sistema.\n");
	printf("Ajuda: esta e uma opcao criada com o intuito de fornecer suporte e esclarecer mais sobre o programa para o usuario.\n");
	printf("\nEu escolhi este ramo de mercado pois e o ramo no qual meu pai atua.\n\n");
	
	system("pause");
}

main()
{
	int opcao;
	
		do{
			opcao = menu();
			
			switch(opcao)
			{
				case 1: insere();
					break;
				case 2: limpa();
					break;
				case 3: lista();
					break;										//Escolha do menu
				case 4: ajuda();
					break;
				case 0: exit(0);
					default:
						{
							printf("\n\n---Opcao Invalida---");
							system("pause");
						}
			}
		}while(opcao != 0);
}
