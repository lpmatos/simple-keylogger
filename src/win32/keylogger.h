/* #############################################################################
## DESCRIPTION: Keylogger Header File.
## NAME: keylogger.h
## AUTHOR: Lucca Pessoa da Silva Matos
## DATE: 14.04.2020
## VERSION: 1.1
##############################################################################*/

#ifndef KEYLOGGER_H
#define KEYLOGGER_H

#include <time.h>
#include <stdbool.h>

void helper(void);
void cabecalho(void);
void set_portuguese(void);

int keylogger(FILE *file_pointer,
      const char *file_name,
      time_t time_start,
      time_t time_now,
      time_t time_lastkey);

bool check_file_pointer_exist(FILE *file_pointer);

#endif
