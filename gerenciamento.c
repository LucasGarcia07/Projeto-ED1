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

Diretorio* alocarDiretorio(char* nome, int numArq, char* data, char*hora){
		Diretorio* dir;

		dir = (Diretorio*) malloc(sizeof(Diretorio));
		strcpy(dir->nome, nome);
		strcpy(dir->data, data);
		strcpy(dir->hora, hora);
		dir->numArqDir= numArqDir;

		return dir;
}

Arquivo* alocarArquivo(char* nome, char tipo){

		Arquivo* arq;

		arq = (Arquivo*) malloc(sizeof(Arquivo));
		strcpy(dir->nome, nome);
		strcpy(dir->tipo, tipo);
		strcpy(dir->data, data);
		strcpy(dir->hora, hora);

		return arq;
}

Arv* criarNo(void* val){

	Arv* novo = (Arv*) malloc(sizeof(Arv));
	novo->filho = NULL;
	novo->irmao = NULL;
	novo->info = val;

	return novo;
}

Arv* busca(Arv* arvore, char* nome1)
{
	if(strcmp(((Diretorio*)arvore->info)->nome, nome1) != 0)
	{
		if(arvore->filho != NULL)
		{
			busca(arvore->filho, nome1);
		}
		if(arvore->irmao != NULL)
		{
			busca(arvore->irmao, nome1);
		}
	}
	else
	{
		return arvore;
	}
	
}

void insereNo(Arv* noEntrada, Arv* arvore, char* nome){
	Arv* noPai = busca(arvore, nome);
	Arv* noAux;

	if(noPai->filho != NULL){
		for(noAux = noPai->filho->irmao; noAux != NULL; noAux = noAux->irmao){
			if(noAux == NULL){
				noAux->irmao = noEntrada;
			}
		}
	}
	else{
		noPai->filho = noEntrada; 
	}

}

void* renomear(Arv* arvore, char* nome, char* novoNome,char* data, char* hora,char* noPai){
	Arv* noAux = busca(arvore,nome);
	Arv* noAux2 = busca(arvore,noPai);
	if(noAux == NULL || noAux2 == NULL){
		return NULL;
	}
	if(noAux->tipo == 1){
		(((Diretorio*)noAux->info)->nome) = novoNome;
		(((Diretorio*)noAux->info)->data) = data;
		(((Diretorio*)noAux->info)->hora) = hora;
	}
	
	if(noAux->tipo == 2){
		(((Arquivo*)noAux->info)->nome) = novoNome;
		(((Arquivo*)noAux->info)->data) = data;
		(((Arquivo*)noAux->info)->hora) = hora;
		(((Diretorio*)noAux2->info)->data) = data;
		(((Diretorio*)noAux2->info)->hora) = hora;
	}	
}

void* transformar(Arv* arvore, char tipo,char* data, char* hora,char* noPai,char* nome){
	Arv* noAux = busca(arvore,nome);
	Arv* noAux2 = busca(arvore,noPai);
	if(noAux == NULL || noAux == NULL){
		return NULL;
	}

	if( (((Arquivo*)noAux->info)->tipo) == tipo){
		printf("Arquivo ja e do tipo inserido.");
		return NULL;
	}

	else{	
		(((Arquivo*)noAux->info)->tipo) = tipo;
		(((Arquivo*)noAux->info)->data) = data;
		(((Arquivo*)noAux->info)->hora) = hora;
		(((Diretorio*)noAux2->info)->data) = data;
		(((Diretorio*)noAux2->info)->hora) = hora;
	}
}

void destruir(Arv* NO){

	Arv *NOF = NO->filho;
	Arv *NOI = NO->irmao;
	free(NO);
	if(NOF != NULL)
	{
		destruir(NOF);
	}
	if(NOI != NULL)
	{	
		destruir(NOI);
	}

}


