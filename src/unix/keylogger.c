/* #############################################################################
## DESCRIPTION: Keylogger Functions Definition.
## NAME: keylogger.c
## AUTHOR: Lucca Pessoa da Silva Matos
## DATE: 14.04.2020
## VERSION: 1.1
##############################################################################*/

// =============================================================================
// LIBRARYS
// =============================================================================

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "keylogger.h"

// =============================================================================
// FUNCTIONS
// =============================================================================

void set_portuguese(void){
  setlocale(LC_ALL, "Portuguese");
}

// =============================================================================

void helper(void){
  printf(
    "\n"
    "Usage:\n"
    "     sudo ./keyloger [ -s | -f file] [-h]\n"
    "\n"
    "Options:\n"
    "  -f    file    Path to the output file.\n"
    "  -s            Print to stdout.\n"
    "  -h            This help message.\n");
  exit(EXIT_FAILURE);
}

// =============================================================================

void cabecalho(void){
  printf("\n**************************************************");
  printf("\n*                                                *");
  printf("\n*                                                *");
  printf("\n* IMPLEMENTANDO SIMPLES KEYLOGGER - LUCCA PESSOA *");
  printf("\n*                                                *");
  printf("\n*                                                *");
  printf("\n**************************************************\n\n");
}
