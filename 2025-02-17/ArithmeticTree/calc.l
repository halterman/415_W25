
/* Count number of words in a file */

/* C++ declarations section */
%{

#include <iostream>
#include <string>
#include "calc.tab.hpp"
extern int yylval;
void reset_cin();

%}

%option noyywrap

ws     [ ]
tab    \t
eol    \n


/* Rules Section */
%%

{ws}        {}

{tab}       {}


[1-9][0-9]* { /* Number */
              yylval = std::stoi(yytext);
              return NUMBER;
            }

{eol}       { 
              return 0; 
            } 

\+          { 
              return PLUS; 
            } 

\-          { 
              return MINUS; 
            } 

\*          { 
              return TIMES; 
            } 

\/          { 
              return DIVIDE; 
            } 

\(          { 
              return LPAREN; 
            } 

\)          { 
              return RPAREN; 
            } 

q|Q         {
                std::exit(0);
            }

.           { 
               /*yytext[0];*/ 
            }

%%

//int yywrap() {
//    return 0;
//}


void yyerror(const char *s) {
    std::cout << s << '\n';
}

