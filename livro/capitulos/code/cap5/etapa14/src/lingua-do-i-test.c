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

FILE * criaArquivoTemporario(){
	return tmpfile();
}

void verificaConteudoFoiSalvo(FILE* arquivo,
		char* conteudo_esperado){
	char* conteudo = lerConteudoDeArquivoArberto(arquivo);
	assert( strcmp(conteudo, conteudo_esperado) == 0
			&& "Conteúdo do arquivo não corresponde ao esperado");
}

char* CONTEUDO_QUALQUER = "abracadabra";
void testSalvaConteudoEmArquivo(){
	FILE * arquivoDestino = criaArquivoTemporario();
	salvaConteudo(arquivoDestino, CONTEUDO_QUALQUER);
	verificaConteudoFoiSalvo(arquivoDestino, CONTEUDO_QUALQUER);

	fclose(arquivoDestino);
}

char* MENSAGEM_ORIGINAL= "Minhas vogais, tudo aqui.";
char* TRADUCAO_ESPERADA= "Minhis vigiis, tidi iqii.";
char* MENSAGEM_ORIGINAL2= "Oh! Deus, será que o senhor se zangou";
char* TRADUCAO_ESPERADA2= "Ih! Diis, sirá qii i sinhir si zingii";
void testTraducaoParaLinguaDoI(){
	char* mensagemTraduzida = traduzParaLingaDoI(MENSAGEM_ORIGINAL);
	verificaConteudosSaoIguais(mensagemTraduzida, TRADUCAO_ESPERADA);
	verificaConteudosSaoIguais(
		traduzParaLingaDoI(MENSAGEM_ORIGINAL2), TRADUCAO_ESPERADA2);
}

void verificaEntradaFoiEntradaPadrao(FILE* entrada){
	assert(entrada == stdin && "Entrada deveria ser Entrada Padrão");
}

void verificaEntradaFoiArquivoValido(FILE* entrada){
	assert(entrada != NULL && entrada!= stdin &&
			"Entrada deveria ser um arquivo válido");
}

void verificaEntradaFoiInvalida(FILE* entrada){
	assert(entrada == NULL && "Entrada deve ser inválida");
}

int ARGC_SEM_PARAMETROS = 1;
const char* ARGV_SEM_PARAMETROS[] = {"lingua-do-i"};
void testDefinirEntradaPadrao(){
	FILE* entrada = determinaEntrada(ARGC_SEM_PARAMETROS,
		ARGV_SEM_PARAMETROS);
	verificaEntradaFoiEntradaPadrao(entrada);
}

int ARGC_COM_1_PARAMETRO = 2;
const char* ARGV_ARQUIVO_VALIDO[] =
	{"lingua-do-i", "musica-trecho.txt"};
const char* ARGV_ARQUIVO_INEXISTENTE[] =
	{"lingua-do-i", "inexistente.xyz"};
void testDefinirEntradaDeArquivo(){
	FILE* entrada = determinaEntrada(ARGC_COM_1_PARAMETRO,
		ARGV_ARQUIVO_VALIDO);
	verificaEntradaFoiArquivoValido(entrada);
}

void testDefinirEntradaDeArquivoInexistente(){
	FILE* entrada = determinaEntrada(ARGC_COM_1_PARAMETRO,
		ARGV_ARQUIVO_INEXISTENTE);
	verificaEntradaFoiInvalida(entrada);
}

int main(void) {
	testLerConteudoDoArquivo();
	testSalvaConteudoEmArquivo();
	testTraducaoParaLinguaDoI();

	testDefinirEntradaPadrao();
	testDefinirEntradaDeArquivo();
	testDefinirEntradaDeArquivoInexistente();

	return EXIT_SUCCESS;
}
