/* Count number of words in a file */

%{

#include <stdio.h>
#include <string.h>

int line_word_count = 0;
int total_word_count = 0;
/*char *yytext;*/
/*int yylex();*/

%}

%option noyywrap

/* Rules Section */
%%

([a-zA-Z0-9])* { /* Rule for counting number of words */
    line_word_count++;
    printf("%s ", yytext);
}

"\n" { 
    printf("Words per line %d\n", line_word_count);
    total_word_count += line_word_count;
    line_word_count = 0; 
}

%%

//int yywrap() {
//    return 0;
//}

int main() {
    yylex();
    printf("Total words: %d\n", total_word_count);
}
