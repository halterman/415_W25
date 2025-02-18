// Arithmetic expression parser
//
//   Original grammar:
//     E -> T | E + T
//     T -> F | T * F
//     F -> ( E ) | d
//
//   Adapted grammar without left recursion:
//     E  -> T E1
//     E1 -> + T E1 | e
//     T  -> F T1
//     T1 -> * F T1 | e
//     F  -> ( E ) | d
//
//   E, E1, T, T1, and F are nonterminal symbols.
//   d, +, *, (, ), and e (empty string) are terminal symbols.

#include "parser_framework.h"

NonTerminal E, T, E1, F, T1;


// Nonterminal E
bool E() {
    auto save = mark();   // Remember current position in the string
    // Try to match E -> T E1
    if (T() && E1()) {      
        return true;      // Matched E -> T E1
    }
    // Could not parse using this rule;
    restore(save);        // backtrack to previous position and
    return false;         // report failure
}


// Nonterminal E1
bool E1() {
    auto save = mark();   // Remember current position in the string
    // E1 -> + T E1
    if (scan('+') && T() && E1()) {
        return true;
    }
    // Could not parse using this rule;
    restore(save);        // backtrack and try alternate rule
    // Match E1 -> e   
    return true;          // Nonterminal satisfied by empty string
}


// Nonterminal T
bool T() {
    auto save = mark();   // Remember current position in the string
    // Try to match rule T -> F T1
    if (F() && T1()) {
        return true;      // Matched rule T -> F T1
    }
    // Could not parse using this rule;
    restore(save);        // backtrack to previous position and
    return false;         // report failure
}


// Nonterminal T1
bool T1() {
    auto save = mark();   // Remember current position in the string
    // Try to match rule T1 -> * F T1
    if (scan('*') && F() && T1()) {
        return true;      // Matched rule T1 -> * F T1
    }
    // Could not parse using this rule;
    restore(save);        // backtrack and try alternate rule
    // Match rule T1 -> e   
    return true;          // Nonterminal satisfied by empty string
}


// Nonterminal F
bool F() {
    auto save = mark();   // Remember current position in the string
    // Try to match rule F -> ( E )
    if (scan('(') && E() && scan(')')) {
        return true;      // Matched rule F -> ( E )
    }
    // Could not parse using this rule;
    restore(save);        // backtrack and try alternate rule
    // Try to match rule F -> d
    if (scan('d')) {
        return true;      // Matched rule F -> d
    }
    // Could not parse using this rule;
    restore(save);        // backtrack to previous position and
    return false;         // report failure
}


int main() {
    interactive_parse(E);
}

