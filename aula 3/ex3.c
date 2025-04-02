// o codigo apresenta vazamento de memoria pois na alocaco dinamica (new int[100]) nao fora desalocada (free) se uma execao for feita nesse meio do codigo


/*#include <iostream>
#include <memory>
#include <stdexcept>

void processo() {
    std::unique_ptr<int[]> recurso(new int[100]); // evitar vazamento

    try {
        // Simulando um erro
        throw std::runtime_error("Erro intencional!");
    } catch (const std::exception& e) {
        std::cerr << "Exceção capturada: " << e.what() << std::endl;
    }
}

int main() {
    try {
        processo();
    } catch (...) {
        std::cerr << "Exceção não tratada!" << std::endl;
    }

    return 0;
}
*/


// em C temos o free que libera a memoria porem em C++ temos os smart pointers que liberam automaticamente a memoria
// std::unique_ptr eh um ponteiro que sai do codigo/escopo onde ocorre e a memoria eh liberada

// C

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buffer; // Variável global para armazenar o estado do programa

void processo() {
    int* recurso = (int*)malloc(100 * sizeof(int));
    if (recurso == NULL) {
        printf("Falha ao alocar memória!\n");
        return;
    }

    if (setjmp(buffer) == 0) {
        // Simulando erro no meio do código
        printf("Executando código...\n");
        longjmp(buffer, 1); // Simulando uma exceção
    }

    free(recurso); // LIBERANDO MEM
}

int main() {
    if (setjmp(buffer) != 0) {
        printf("ERRO - LIMPANDO...\n");
        return 1;
    }

    processo();

    return 0;
}
