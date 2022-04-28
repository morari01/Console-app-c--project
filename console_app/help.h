#ifndef ARINA_MOROZOVA_S22931_HELP_H
#define ARINA_MOROZOVA_S22931_HELP_H
#include <fstream>
#include <algorithm>
#include <dir.h>
#include <conio.h>

auto help(){
    std::cout<<"The 'PJAText2' application is used to perform various operations on the contents of text files.\n"<<
    "Choose the command you want to execute for your file.\n" <<
    "If you need help, type --help; \n" <<
    "If you want to upload a file, type -f or --file; \n" <<
    "If you want to display the number of lines from the source file, type -n or --newlines; \n" <<
    "If you want to display the number of digits from the source file, type -d or --digits; \n" <<
    "If you want to display the number of numbers from the source file, type -dd or --numbers; \n" <<
    "If you want to display the number of characters from the source file, type -c or --chars; \n" <<
    "If you want to display the number of words from the source file, type -w or --words; \n" <<
    "If you want to display all words from the source file in alphabetical order, type -s or --sorted; \n" <<
    "If you want to display all words from the source file in reversed alphabetical order, type -rs or --reverse-sorted;\n"<<
    "If you want to display all words from the source file in ascending order by length, type -l before -s; \n" <<
    "If you want to display all words from the source file in descending order by length type -l before -rs; \n" <<
    "If you want to display all words that are anagrams, type -a or --anagrams; \n" <<
    "If you want to display all words that are palindromes, type -p or --palindromes; \n" <<
    "If you want to save output to file, type -o or --output and its name; \n" <<
    "If you want to modify the operation of the program in a way:instead of specifying the rest of the flags as arguments,\n"
    "the application gets the flags and their data from the input file mentioned earlier, type -i or --input; \n"<<
    "If you want to swap lines in a file and change letters i and o to 1 and 0 type -swap or --swap-lines;\n";
}
#endif //ARINA_MOROZOVA_S22931_HELP_H
