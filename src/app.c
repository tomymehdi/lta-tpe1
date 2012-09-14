#include "app.h"

void start(int argc,char ** argv){
  if (argc == 2) {
      char * input = argv[1];
      int ready_to_read = 0;
      FILE * pFile = NULL;

      if (strstr(input, ".gr") != NULL) {
        pFile = fopen(input, "r");
        if (pFile == NULL) {
          printf("Archivo no encontrado\n");
          return;
        }
        stdin = pFile;
        ready_to_read = GRAMMAR;
        start_adts(ready_to_read);
      } else if (strstr(input, ".dot") != NULL) {
        pFile = fopen(input, "rx3");
        if (pFile == NULL) {
          printf("Archivo no encontrado\n");
          return;
        }
        stdin = pFile;
        ready_to_read = AUTOMATHA;
        start_adts(ready_to_read);
      }

      if (ready_to_read) {
        yylex();
        transform(ready_to_read);
      }
  }
}

void setInputType(int type) {
  switch (type) {
  case GRAMMAR:
    parseGramar = 1;
    break;
  case AUTOMATHA:
    parseAutomatha = 1;
    break;
  }
}