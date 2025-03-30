#pragma once

/**
 * ***************************************************
 * @file   Funcoes.h
 * @brief  Prototipos das funcoes utilizadas no programa
 * @author Jose Ferreira
 * @date  15 March2025
 * ***************************************************
*/

#include "Estruturas.h"
#include <stdbool.h>

EstruturaAntenas* CriaAntena(int linha, int coluna, char freq);
EstruturaAntenas* InsereOrdenado(EstruturaAntenas* inicio, EstruturaAntenas* novo, int* res);
void MostrarLista(EstruturaAntenas* inicio);
bool ProcuraElemento(EstruturaAntenas* inicio, int linha, int coluna);
EstruturaAntenas* RemoveElemento(EstruturaAntenas* inicio, int linha, int coluna);
