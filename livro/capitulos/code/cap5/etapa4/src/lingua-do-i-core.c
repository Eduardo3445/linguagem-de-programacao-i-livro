#include <stdbool.h> // <1>
#include <stdio.h>
#include <stdlib.h>
#include "lingua-do-i-core.h"

bool arquivoAbertoComSucesso(FILE* arquivo) {//<2>
	return arquivo != NULL;
}

/*
Efeito colateral: cabeçote de leitura vai para o início do arquivo
*/
int lerTamanhoDoArquivo(FILE* arquivo) {//<2>
	fseek(arquivo, 0, SEEK_END); // vai para o final do arquivo
	int tamanho = ftell(arquivo); // pega posição atual (final)

	fseek(arquivo, 0, SEEK_SET); // volta para o início
	return tamanho;
}

char* lerConteudoDeArquivoArberto(FILE* arquivo) {//<2>
	int tamanhoDoArquivo = lerTamanhoDoArquivo(arquivo);
	// 7.22.3.2 The calloc function
	char* conteudo = calloc(1, tamanhoDoArquivo + 1);

	// 7.21.8.1 The fread function
	fread(conteudo, tamanhoDoArquivo, 1, arquivo);

	return conteudo;
}

char* lerConteudoDoArquivo(char* nomeDoArquivo) {//<2>
	char* conteudo;

	FILE* arquivo = fopen(nomeDoArquivo, "r");
	if (arquivoAbertoComSucesso(arquivo)) {
		conteudo = lerConteudoDeArquivoArberto(arquivo);
		fclose(arquivo); // fecha arquivo
	} else {
		conteudo = NULL;
	}

	return conteudo;
}
