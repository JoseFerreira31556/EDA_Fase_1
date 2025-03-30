/**
 * ***************************************************
 * @file   main.c
 * @brief  Ficheiro main onde o programa corre
 * @author Jose Ferreira
 * @date  15 March2025
 * ***************************************************
*/

#include "Funcoes.h"
#include "Estruturas.h"
#include <stdio.h>
#include <malloc.h>
#include <errno.h>



void main() {

#pragma region CRIARLISTA
	EstruturaAntenas* novo = NULL;
	EstruturaAntenas* inicio = NULL;
	int* res = NULL;
	

	novo = CriaAntena(2, 2, 'A');
	inicio = InsereOrdenado(novo, inicio, &res);
	printf("%d\n", res);
	if (res == 1) {
		printf("Foi encontrada uma antena com as mesmas coordenadas, pff tente novamente!\n\n");
	}
	else {
		printf("Antena inserida na lista com sucesso!\n\n");
	}

	novo = CriaAntena(1, 3, 'B');
	inicio = InsereOrdenado(novo, inicio, &res);
	printf("%d\n", res);
	if (res == 1) {
		printf("Foi encontrada uma antena com as mesmas coordenadas, pff tente novamente!\n\n");
	}
	else {
		printf("Antena inserida na lista com sucesso!\n\n");
	}
	
	novo = CriaAntena(2, 5, 'B');
	inicio = InsereOrdenado(novo, inicio, &res);
	printf("%d\n", res);
	if (res == 1) {
		printf("Foi encontrada uma antena com as mesmas coordenadas, pff tente novamente!\n\n");
	}
	else {
		printf("Antena inserida na lista com sucesso!\n\n");
	}

	novo = CriaAntena(2, 1, 'B');
	inicio = InsereOrdenado(novo, inicio, &res);
	printf("%d\n", res);
	if (res == 1) {
		printf("Foi encontrada uma antena com as mesmas coordenadas, pff tente novamente!\n\n");
	}
	else {
		printf("Antena inserida na lista com sucesso!\n\n");
	}

	MostrarLista(inicio);

	inicio = RemoveElemento(inicio, 1, 3);
	MostrarLista(inicio);
#pragma endregion
}
