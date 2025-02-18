// Framework used by all recursive descent parsers

#include <iostream>
#include <algorithm>
#include "parser_framework.h"

unsigned cursor;
string parse_string;

// Return true if the symbol at the current position in the string
// matches the expected symbol, and advance to the next position
// in the string; otherwise, return false and do not advance
// to the next position.
bool scan(char symbol) {
    if (cursor < parse_string.length() && parse_string[cursor] == symbol) {
        cursor++;   // Symbol in string matches expected symbol
        return true;
    }
    return false;
}


// Returns the global cursor's current position within the string
// to parse.
unsigned mark() {
    return cursor;
}


// Moves the global cursor to the position indicated by pos.
void restore(unsigned pos) {
    cursor = pos;
}


// Determine if a string str is an element of the language
// represented by the grammar. The parameter start is the
// start symbol for the grammar.
bool parse(NonTerminal start, const string &str) {
    // Set global variables
    parse_string = str;  // The string to parse
    cursor = 0;          // Start parsing at front of string (index zero)
    // Parse
    return start() && cursor == parse_string.length();
}


// Remove spaces and tabs from string s, if any exist.
static string strip_whitespace(string& s) {
    string result = "";
    for (char ch : s) {
        if (ch != ' ' and ch != '\n') {
            result += ch;
        }
    }
    return result;
}


// Allows the user to enter via the keyboard a string to parse.
void interactive_parse(NonTerminal f) {
    while (true) {
        // Get input string from user
        string in_str;
        std::cout << "==> ";
        std::getline(std::cin, in_str);

        // Should we quit?
        if (::toupper(in_str[0]) == 'Q') {
            break;  // Quit the program
        }

        // Remove whitespace from the string
        in_str = strip_whitespace(in_str);
        //std::remove_if(in_str.begin(), in_str.end(), ::isspace);

        // Parse the input string
        if (parse(f, in_str)) {
            std::cout << "Ok\n";
        }
        else {
            std::cout << "Parse error\n";
        }
    }
}

