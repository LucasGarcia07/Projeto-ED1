#include "gerenciamento.h"

int qual_tipo(char val){//estava usando essa função para descobrir se era arquivo ou diretório.

	switch(val){
		case 'D':
			return 0;
			break;
		case 'T':
			return 1;
			break;
		case 'B':
			return 2;
			break;
		default:
			exit(1);
	}
}

Diretorio* alocarDiretorio(char nome){
		Diretorio* dir;

		dir = (Diretorio*) malloc(sizeof(Diretorio));
		dir->nome = nome;
		dir->numArq = 0;
		dir->numDire = 0;

		return dir;
}

Arquivo* alocarArquivo(char nome, char tipo){

		Arquivo* arq;

		arq = (Arquivo*) malloc(sizeof(Arquivo));
		arq->nome = nome;
		arq->tipo = tipo;

		return arq;
}

Arv* criarNo(void* val){

	Arv* novo = (Arv*) malloc(sizeof(Arv));
	novo->filho = NULL;
	novo->irmao = NULL;
	novo->info = val;

	return novo;
}

void insereNo(Arv* noEntrada, Arv* arvore, char texto[]){
	Arv* noPai = busca(arvore, texto[]);
	Arv* noAux;

	if(noPai->filho != NULL){
		for(noAux = noPai->filho->irmao; noAux != NULL; noAux = noAux->irmao){
			if(noAux)
		}
	}



}
teste
