#include <stdio.h>

int main(void) {

    char* nomeDoArquivo = "arquivo-binario.bin";
    FILE* arquivo = fopen(nomeDoArquivo, "wb");
    if (arquivo != NULL) {
      // arquivo aberto com sucesso...
      // inicia escrita no arquivo

      // fecha arquivo
    } else {
      // exibe mensagem de erro
    }

}
