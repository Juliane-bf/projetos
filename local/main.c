#include <stdio.h>
#include <stdlib.h>
#include "arv.h"


int main() {
    Abb* arvore = NULL;
	Abb* resultado;
    int opcao;
    int a = 0;

    do {
        printf("\n");
        printf("\n\n-------------------Bem Vindo--------------------\n\n");
        printf("1-> Inserir um novo elemento na arvore.\n");
        printf("2-> Remover um elemento da arvore.\n");
        printf("3-> Buscar um elemento na arvore.\n");
        printf("4-> Imprimir arvore.\n");
        printf("0-> Sair");
        printf("\n\n------------------------------------------\n\n\n->");
        printf("opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);
        printf("\n\n");
        
        switch (opcao){
		case 0:
	      	printf("\nSistema Finalizado!\n\n");
            exit(0);
        	break;
        	
		case 1:
			system("cls");
			printf("Digite o elemento para ser inserido na arvore:\n");
			scanf("%d", &a);
			arvore = inserir(arvore, a);
			printf("\n");
			fflush(stdin);
			break;

		case 2:
			system("cls");
			printf("Digite o elemento a ser removido na arvore:\n");
			scanf("%d", &a);
			fflush(stdin);
			arvore = remover(arvore, a);
			printf("\n");
			break;

		case 3:
			system("cls");
			printf ("Digite o elemento que vc deseja buscar:\n");
			scanf ("%d", &a);
			fflush(stdin);

			resultado = busca(arvore, a);
			if (resultado) {
				printf("Info no: %d\n", getInfo(resultado));
			} else {
				printf("Elemento nao encontrado\n");
			}
			break;
               	
      	case 4:
      		system("cls");
      		printf("Imprimindo arvore\n");
      		imprimir(arvore);
			fflush(stdin);
			break;		
      	}
	} while (opcao != 0);
	
    return 0;
}
