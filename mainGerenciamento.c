#include "gerenciamento.c"

int main(int argc, char const *argv[]){
	
	FILE* arqDados = fopen("dados.txt","r");

	if(arqDados == NULL){
		printf("Erro ao abrir o arquivo\n");
		exit(1);
	}

	char c;

	c = fgetc(arqDados);//Pega o 1º caracter do arquivo
	
	if(c == EOF){//Não tem caracter, fim de arquivo.
		printf("Caractere não encontrado\n");
		exit(1);
	}

	int cont = 0;//0 -> não é \n, 1-> é \n
	char aux;

	Arv* minhaArv;
	
	Diretorio* dir;
	Arquivo* arq;
	
	while(!feof(arqDados)){//Enquanto não chegar ao final do arquivo
		
		aux = fgetc(arqDados);

		if(aux == '\n'){//avalia se chegou ao final da linha
			cont = 1;
		}

		if(cont == 1){//Se chegou no final de uma linha
			
			switch(c){
				case 'D':
					dir = alocarDiretorio('U');//aloca memória para um diretório
					minhaArv = criarNo(dir);//cria um nó da árvore de diretório
					printf("Nome %c\n",((Diretorio*) minhaArv->info)->nome);
					/*
						((Diretorio*) minhaArv->info)->nome, acessar informação
						da struct diretório usando conversão, pois na struct árvore campo info é ponteiro void 
					*/
					break;
				case 'T':
					arq = alocarArquivo('F','T');//aloca memória para um arquivo de Texto
					minhaArv = criarNo(arq);//cria um nó da árvore de arquivo
					printf("Tipo %c\n",arq->tipo);//imprime o tipo do arquivo
					break;
				case 'B':
					arq = alocarArquivo('P','B');//aloca memória para um arquivo binário
					minhaArv = criarNo(arq);//cria um nó da árvore de arquivo
					printf("Tipo %c\n",arq->tipo);//imprime o tipo do arquivo
					break;
				default://Se não for diretório, arquivo texto ou binário, termine a execução.
					exit(1);
			}

			c = fgetc(arqDados);//Pega o próximo caracter
			cont = 0;//cont volta ao estado inicial, já que ele está em uma nova linha

		}
	}


	fclose(arqDados);


	return 0;
}
