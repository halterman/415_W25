/* Infix notation calculator--calc */
/* Adapted from https://web.mit.edu/gnu/doc/html/bison_5.html and
   the Lex and Yacc book. */

%{

#include <iostream>
#include <limits>
#include "arithtree.h"

#define YYSTYPE TreeNode *

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
                auto node = $1;
                node->draw('-', 0);
                std::cout << node->evaluate() << '\n';
                delete node;
            }
          | ERROR {
                //yyerror("Error in expression");
                std::cout << "Error in expression\n";
            }
          ;

expression: expression PLUS expression { 
                $$ = new AdditionNode($1, $3);    
            }
          | expression MINUS expression { 
                $$ = new SubtractionNode($1, $3);    
            }
          | expression TIMES expression { 
                $$ = new MultiplicationNode($1, $3);    
            }
          | expression DIVIDE expression { 
                if ($3 == 0) {
                    //yyerror("Divide by zero");
                    std::cout << "Divide by zero\n";
                    //reset_cin();
                }
                else {
                    $$ = new DivisionNode($1, $3);
                }
            }
          | LPAREN expression RPAREN { 
                $$ = $2;         
            }
          | NUMBER {
                /* This is a hack. The scanner returns a pointer 
                   to a tree node, but we know here it will be the
                   integer number, so we cast from a pointer to a 
                   number. */
                $$ = new NumberNode(reinterpret_cast<long long int>(yylval));         
            }
          ;
%%


int main() {
    while (true) {
        yyparse();
    }
}

