// Framework used by all recursive descent parsers

#include <string>


// A NonTerminal is a function representing a non-terminal symbol in the grammar.
typedef bool NonTerminal(); 

using std::string;


// Return true if the symbol at the current position in the string
// matches the expected symbol, and advance to the next position
// in the string; otherwise, return false and do not advance
// to the next position.
bool scan(char symbol);


// Returns the global cursor's current position within the string to parse.
unsigned mark();


// Moves the global cursor to the position indicated by pos.
void restore(unsigned pos);


// Determine if a string str is an element of the language
// represented by the grammar. The parameter start is the
// start symbol for the grammar.
bool parse(NonTerminal start, const string &str);


// Allows the user to enter via the keyboard a string to parse.
void interactive_parse(NonTerminal f);

