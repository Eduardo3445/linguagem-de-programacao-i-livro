#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lingua-do-i-core.h"

void verificaConteudosSaoIguais(char* conteudo, char* esperado){
	assert(conteudo != NULL && "conteúdo não pode ser NULL");

	assert( strcmp(conteudo, esperado) == 0
			&& "conteúdo deve ser igual ao esperado");
}

char* NOME_DO_ARQUIVO = "musica-trecho.txt";
char* CONTEUDO_ESPERADO = "Oh! Deus, perdoe este pobre coitado";
void testLerConteudoDoArquivo(){
	char* conteudo = lerConteudoDoArquivo(NOME_DO_ARQUIVO);
	verificaConteudosSaoIguais(conteudo, CONTEUDO_ESPERADO);
}

char* MENSAGEM_ORIGINAL = "Minhas vogais, tudo aqui.";
char* TRADUCAO_ESPERADA= "Minhis vigiis, tidi iqii.";
char* MENSAGEM_ORIGINAL2 = "Oh! Deus, será que o senhor se zangou";
char* TRADUCAO_ESPERADA2= "Ih! Diis, sirí qii i sinhir si zingii";
void testTraducaoParaLinguaDoI(){
	char* mensagemTraduzida = traduzParaLingaDoI(MENSAGEM_ORIGINAL);
	verificaConteudosSaoIguais(mensagemTraduzida, TRADUCAO_ESPERADA);
	verificaConteudosSaoIguais(traduzParaLingaDoI(MENSAGEM_ORIGINAL2), TRADUCAO_ESPERADA2);
}

int main(void) {
	testLerConteudoDoArquivo();
	testTraducaoParaLinguaDoI();


	return EXIT_SUCCESS;
}
