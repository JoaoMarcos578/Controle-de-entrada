// João Marcos Castelli Código: 833251

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

typedef struct quilogramas {
	float kg;
	
	struct quilogramas *prox, *ant; //Struct para armazenar os dados
} controle;


	controle *fila = (controle *) malloc(sizeof(controle)); //Alocação de memória para a fila
	
	controle *novo = (controle *) malloc(sizeof(controle)); //Alocação de memoria para as caixas

int menu()
{
	
	
	if(!fila)
	{
		printf("Memoria indisponivel");
	}
	else
	{
		fila -> kg=0;
		fila -> prox = NULL; //Inicialização da fila
		fila -> ant = NULL;
	}
	
	
	int opcao;
	
	system("cls");
	printf("----MENU----");
	printf("\n\nEscolha uma das opcoes:\n1 - Inserir\n2 - Limpar\n3 - Listar\n4 - Ajuda"); //Menu de escolha de funções do programa
	printf("\n\nOpcao: ");
	scanf("%i", &opcao);
	return opcao;
}
void insere()
{
	
	system("cls");
				
		if(!novo)
		{
			printf("Memoria indisponivel");
		}
		else
		{
		novo -> kg=0;	//Inicialização da caixa
		novo -> prox = NULL; 
		novo -> ant = NULL;
		}
		
		printf("Informe a quantidade de KG: ");
		scanf("%f", &novo->kg);
		
		if(fila -> prox == NULL)  //Alocação das caixas
		{
			fila -> prox = novo;
			novo -> ant = fila;
		}
		else
		{
			controle *temp;
	        temp = fila -> prox;
	        
	        fila -> prox = novo;
	        novo -> prox = temp;
	        temp -> ant = novo;
	        novo -> ant = fila; 
		}
		
}
void limpa() 
{
	
	  			controle *temp;
	  
                controle *aux;

                temp = fila -> prox;

                while(temp -> prox != NULL)
                {
                	
                   aux = temp;
                   temp = aux -> prox; //Zerar a fila
                   free (aux);
                   
                }
                
                if(temp -> prox == NULL)
                {
                	
                  fila -> prox = temp -> prox; //Manter a fila
                  			
                  free(temp);
                  
                }
}
void lista()
{
	system("cls");

                controle *temp;
                
                temp = fila -> prox;
				
                if(fila->prox==NULL)
                {
                    printf("Memoria ja foi apagada ou nao foi preenchida");
                }

               while(temp->prox!=NULL)
               {
                 	 printf("Quilogramas: %.2f", temp->kg);
                		temp = temp->prox;
               }
              	printf("Quilogramas: %.2f", temp->kg);

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
