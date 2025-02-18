/* Infix notation calculator--calc */
/* Adapted from https://web.mit.edu/gnu/doc/html/bison_5.html and
   the Lex and Yacc book. */

%{
/* #define YYSTYPE double */

#include <iostream>
#include <limits>

int yylex();
int yyparse();
void yyerror(const char *s);
%}

/* BISON Declarations */
%token NUMBER PLUS MINUS TIMES DIVIDE LPAREN RPAREN ERROR
%left PLUS MINUS
%left TIMES DIVIDE

/* Grammar rules */
%%

input     : expression {
                std::cout << $1 << '\n';
            }
          | ERROR {
                //yyerror("Error in expression");
                std::cout << "Error in expression\n";
            }
          ;

expression: expression PLUS expression { 
                $$ = $1 + $3;    
            }
          | expression MINUS expression { 
                $$ = $1 - $3;    
            }
          | expression TIMES expression { 
                $$ = $1 * $3;    
            }
          | expression DIVIDE expression { 
                if ($3 == 0) {
                    //yyerror("Divide by zero");
                    std::cout << "Divide by zero\n";
                    //reset_cin();
                }
                else {
                    $$ = $1 / $3;
                }
            }
          | LPAREN expression RPAREN { 
                $$ = $2;         
            }
          | NUMBER {
                $$ = $1;         
            }
          ;
%%


int main() {
    while (true) {
        yyparse();
    }
}

