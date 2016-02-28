#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>

using namespace std;
/*
	tipo enum para definir as cores do sem�foro.
*/
enum cores {
	VERMELHO,
	AMARELO,
	VERDE
};

// constante com os nomes das cores na forma de string.
static char *CORES[] = { "VERMELHO", "AMARELO", "VERDE" };

int main()
{
	int contador = 1; //contador inicial do sem�foro
	enum cores cor = VERMELHO; // sem�foro sempre iniciar� em VERMELHO.
	printf("*** Programa semaforo ***\n");
	do {		
		// imprime na tela o estado atual do sem�foro.
		printf("Semaforo esta: \t%s\n", CORES[cor]); 
		// verifica o contador, caso tenha atingido os tr�s 
		// segundos, passa para a pr�xima cor.
		if (contador > 2) {
			switch (cor) {
			case VERMELHO: cor = AMARELO;
				break;
			case AMARELO: cor = VERDE;
				break;
			case VERDE: cor = VERMELHO;
				break;
			}
			// zera o contador.
			contador = 0;
		}
		contador++; // incrementa o contador em 1.
		// espera 1 seg.
		// a fun��o sleep faz o programa aguardar n milisegundos (1000ms=1seg).
		Sleep(1000);
	} while (true); //loop do programa.
	
    return 0;
}

