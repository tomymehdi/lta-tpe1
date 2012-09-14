%option noyywrap

%{
  #include "app.h"


  int parsingGrammar = 0;
  int parsingAutomatha = 0;
%}


%%


%%



int main(int argc, char ** argv) {
  start(argc, argv);
}