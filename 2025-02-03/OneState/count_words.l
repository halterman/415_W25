/* Count number of words in a file */

/* C++ declarations section */
%{

#include <iostream>
#include <string>

int line_word_count = 0;
int total_word_count = 0;

std::string number_to_word(const std::string& str);

%}

%option noyywrap

/* Rules Section */
%%


[a-zA-Z']+  { /* Rule for counting number of words */
                line_word_count++;
                std::cout << '[' << yytext << ']';
            }

[1-9][0-9]* { /* Make word for the number */
                std::cout << number_to_word(yytext) << ' ';
            }

\.          { /* Rule to detect a period */
                std::cout << "PERIOD"; 
            }

,           { /* Rule to detect a comma */
                std::cout << "COMMA"; 
            }

\n          { /* Rule to detect newline character and report line statistics */
                std::cout << " => Words per line " << line_word_count << '\n';
                total_word_count += line_word_count;
                line_word_count = 0; 
            }

%%

//int yywrap() {
//    return 0;
//}

std::string number_to_word(const std::string& str) {
    if (str == "1") {
        return "(one)";
    } else if (str == "2") {
        return "(two)";
    } else if (str == "3") {
        return "(three)";
    } else if (str == "4") {
        return "(four)";
    } else if (str == "5") {
        return "(five)";
    } else {
        return "( ????? )";
    }
}


int main() {
    yylex();
    std::cout << "Total words: " << total_word_count << '\n';
}
