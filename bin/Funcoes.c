#pragma once

/**
 * ***************************************************
 * @file   Funcoes.h
 * @brief  Implementacao das funcoes utilizadas neste programa
 * @author Jose Ferreira
 * @date  15 March2025
 * ***************************************************
*/

#include "Estruturas.h"
#include "Funcoes.h"
#include <stdio.h>
#include <malloc.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>


#pragma region Criar Antena
/**
 * .
 * @brief Funcao que serve para inserir antena na matriz
 * @param linha - Linha onde a antena vai ser inserida
 * @param coluna - Coluna onde a antena vai ser inserida
 * @param freq - Frequencia da antena
 * @return aux - Retorna o bloco de memoria criado dentro da funcao
 */
EstruturaAntenas* CriaAntena(int linha, int coluna, char freq){
	EstruturaAntenas* aux;
	aux = (EstruturaAntenas*)malloc(sizeof(EstruturaAntenas));
	if (aux == NULL) return(NULL);
	aux->linha = linha; aux->coluna = coluna; aux->freq = freq; aux->next = NULL;

	return(aux);
}
#pragma endregion

#pragma region Procurar Elemento
/**
 * .
 * @brief Funcao que procura por elementos na lista ligada
 * @param inicio - Incio da lista
 * @param linha - Linha pela qual o utilizador quer procurar
 * @param coluna - Coluna pela qual o utilizador quer procurar
 * @return aux - Encontrou o valor cujas coordenadas foram dadas por parametro
 * @return NULL - Nao encontrou nenhum valor com as coordenadas dadas por parametro
 */
bool ProcuraElemento(EstruturaAntenas* inicio, int linha, int coluna) {
	EstruturaAntenas* aux = inicio;
	
	while (aux) { //Vai percorrer a lista enquanto o aux != NULL
		if (linha == aux->linha && coluna == aux->coluna) {
			return true; //encontrou o valor e retorna o elemento
		}
		aux = aux->next;
	}
	return false; //Se entrar aqui, quer dizer que não encontrou a antena
}
#pragma endregion

#pragma region Função Insere Ordenado
/**
 * .
 * @brief Funcao responsavel por inserir as antenas ordenadas por linha e coluna
 * @param novo - Nova Antena criada com a Funcao CriaAntena
 * @param inicio - Inicio da lista
 * @param *res - Apontador para validar se a Funcao Procura Elemento encontrou ou nao um elemento repetido
 * @return inicio - Retorna a lista atualizada 
 */
EstruturaAntenas* InsereOrdenado(EstruturaAntenas* novo, EstruturaAntenas* inicio, int* res) {
	EstruturaAntenas* aux;

	aux = inicio;

	//Validar se o novo foi criado
	if (novo == NULL) {
		perror("Nao existe bloco de memoria\n");
		return inicio;
	}

	//Verificação se existe alguma antena com as mesmas coordenadas.
	if (ProcuraElemento(inicio, novo->linha, novo->coluna) == true) {
		*res = 1;
		return inicio; //Se a nova antena a ser ordenada tiver as mesmas coodernadas que uma outra, retorna a lista sem fazer alterações
	}

	//Inserção na primeira posição
	if (inicio == NULL) {
		inicio = novo; //Caso seja o primeiro elemento da lista
		novo->next = NULL;
		return inicio;
	}

	//Inserção no inicio caso as coordenadas da nova antena sejam inferiores às coordenadas da antena que está no inicio
	if (novo->linha < inicio->linha || (novo->linha == inicio->linha && novo->coluna < inicio->coluna)) {
		novo->next = inicio;
		inicio = novo;
		return inicio;
	}

	//Inserção no meio
	EstruturaAntenas* aux2;

	aux = inicio;
	aux2 = NULL;

	// Percorrer a lista para encontrar a posição correta
	while (aux->next != NULL && (aux->next->linha < novo->linha || (aux->next->linha == novo->linha && aux->next->coluna < novo->coluna))) {
		aux2 = aux;
		aux = aux->next;
	}

	// Inserção no meio ou no final da lista
	novo->next = aux->next;
	aux->next = novo;

	return inicio;	
}
#pragma endregion

#pragma region Mostrar Lista
/**
 * .
 * @brief Mostra as antenas existentes na Lista Ligada Simples
 * @param inicio - Inicio da lista
 */

void MostrarLista(EstruturaAntenas* inicio){
	EstruturaAntenas* aux;
	aux = inicio;
	int i = 0;

	printf("Lista de Antenas: \n\n");

	while (aux != NULL) {
		printf("Antena %d -- Linha %d -- Coluna %d -- Frequencia %c\n", i, aux->linha, aux->coluna, aux->freq);
		aux = aux->next;
		i++;
	}
}
#pragma endregion

#pragma region Remover Antena
/**
 * .
 * @brief - Funcao responsavel por remover antena
 * @param inicio - Inicio da lista
 * @param linha - Linha pela qual se deseja procurar
 * @param coluna - Coluna pela qual se deseja procurar
 * @return inicio - Retorna a lista com apos ser feita a remocao da antena
 * @return NULL - Retorna NULL se a lista nao existir
 */
EstruturaAntenas* RemoveElemento(EstruturaAntenas* inicio, int linha, int coluna){
	//Validar se a lista não está vazia
	if (inicio == NULL) return NULL;

	//Validar se o valor que a antena que procuramos está no inicio da lista
	if (inicio->linha == linha && inicio->coluna == coluna) {
		EstruturaAntenas* aux = inicio;
		inicio = inicio->next;
		free(aux);
	}
	else {
		EstruturaAntenas* aux = inicio;
		EstruturaAntenas* aux2 = aux;
		
		while (aux && (aux->linha != linha && aux->coluna != coluna)){
			aux2 = aux;
			aux = aux->next;

		}
		if (aux != NULL) {
			aux2->next = aux->next;
			free(aux);
		}
	}
	return inicio;
}
#pragma endregion
