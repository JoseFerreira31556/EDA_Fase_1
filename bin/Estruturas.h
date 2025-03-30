#pragma once

/**
 * ***************************************************
 * @file   Estruturas.h
 * @brief  Conjunto de Estruturas utilizadas no programa
 * @author Jose Ferreira
 * @date  15 March2025
 * ***************************************************
*/

/*
* @brief Estrutura com o conte�do de cada antena
*/
typedef struct EstruturaAntenas{
	char freq;
	int linha;
	int coluna;
	struct EstruturaAntenas* next;
}EstruturaAntenas;

/*
* @brief Estrutura onde fica guardado o �nicio da lista
*/
typedef struct GereAntenas {
	struct EstruturaAntenas* inicio;
	int numAntenas;
}GereAntenas;



