#include <stdlib.h>
#include <stdio.h>
#include "arv.h"

struct abb {
	int info;
	Abb* esq;
	Abb* dir;	
};

Abb* inserir(Abb* arvore, int info) {
	Abb* novo = (Abb*) malloc(sizeof(Abb));
	novo->esq = NULL;
	novo->dir = NULL;
	novo->info = info;

	if (arvore == NULL) {
		return novo;
	}

	Abb* no = NULL;
	Abb* filho = arvore;

	while(filho != NULL) {
		no = filho;

		if (novo->info < filho->info) {
			filho = filho->esq; 
		} else {
			filho = filho->dir;	
		}
	}

	if (novo->info < no->info) {
		no->esq = novo;
	} else {
		no->dir = novo;
	}

	return arvore;
}

Abb* encontrarMenorValor(Abb* arvore) {
	while (arvore->esq) {
		arvore = arvore->esq;
	}
	return arvore;
}

Abb* remover(Abb* arvore, int valor) {
	if (arvore == NULL) {
		return arvore;
	}

	if (valor < arvore->info) {
		arvore->esq = remover(arvore->esq, valor);
	} else if (valor > arvore->info) {
		arvore->dir = remover(arvore->dir, valor);
	} else {
		Abb* no;

		if (arvore->esq == NULL) {
			no = arvore->dir;
			free(arvore);
			arvore = no;
		} else if (arvore->dir == NULL) {
			no = arvore->dir;
			free(arvore);
			arvore = no;
		} else {
			no = encontrarMenorValor(arvore->dir);
			arvore->info = no->info;
			remover(arvore->dir, no->info);
		}
	}

	return arvore;
}

int getInfo(Abb* arvore) {
	return arvore->info;
}
	
Abb* busca(Abb* arvore, int valor) {
	if(arvore == NULL){
		return NULL;
	}

	if(valor < arvore->info) {
		return busca(arvore->esq, valor);
	}
	
	if(valor > arvore->info) {
		return busca(arvore->dir, valor);
	}

	return arvore;
}
	
void imprimir(Abb* arvore) {
	if (arvore != NULL) {
		imprimir(arvore->esq);
		printf("%d\n", arvore->info);
		imprimir(arvore->dir);
	}
}


