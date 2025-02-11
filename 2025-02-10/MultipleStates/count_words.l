/* Count number of words in a file */

/* C++ declarations section */
%{

#include <iostream>
#include <string>
#include <algorithm>

int line_word_count = 0;
int total_word_count = 0;

std::string number_to_word(const std::string& str);

std::string capitalize(const std::string& str);

%}

%option noyywrap

%s CAPS

/* Rules Section */
%%


<INITIAL>[a-zA-Z']+  { /* Rule for counting number of words */
                line_word_count++;
                std::cout << '[' << yytext << ']';
            }

<INITIAL>[1-9][0-9]* { /* Make word for the number */
                std::cout << number_to_word(yytext) << ' ';
            }

<INITIAL>\.          { /* Rule to detect a period */
                std::cout << "PERIOD"; 
            }

<INITIAL>,           { /* Rule to detect a comma */
                std::cout << "COMMA"; 
            }

<INITIAL>\n          { /* Rule to detect newline character and report line statistics */
                std::cout << " => Words per line " << line_word_count << '\n';
                total_word_count += line_word_count;
                line_word_count = 0; 
            }

<INITIAL>\+          {
                BEGIN CAPS;
                //unput(*yytext);
            }

<CAPS>[a-zA-Z']+  { /* Rule for counting number of words */
                line_word_count++;
                std::cout << '[' << capitalize(yytext) << ']';
            }

<CAPS>\-  {
                BEGIN 0;
                //unput(*yytext);
            }

<CAPS>\.          { /* Rule to detect a period (call it a dot) */
                std::cout << "DOT"; 
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
        return "(*?????*)";
    }
}


std::string capitalize(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}


int main() {
    yylex();
    std::cout << "Total words: " << total_word_count << '\n';
}
