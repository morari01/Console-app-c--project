#ifndef ARINA_MOROZOVA_S22931_ALL_FUNCTIONS_H
#define ARINA_MOROZOVA_S22931_ALL_FUNCTIONS_H

#include <fstream>
#include <algorithm>
#include <dir.h>
#include <conio.h>
#include <set>
#include <sstream>
#include "help.h"

std::string filename;

/**
 * Function expects a file path from user. If it exists, file is opening.
 * Otherwise a message about error appears.
 * @return
 */
auto find_file(std::ifstream &file){
    file.open(filename);
    if(!file.is_open()) std::cout<<"Error: wrong file path!\n";
}


/**
 * Function counts the number of lines in the file.
 * @return count_lines Function returns the number of lines.
 */
auto count_lines(){
    std::ifstream file(filename);
    int
    count_lines = 0;
    std::string line;
    if(file.is_open()) {
        while (std::getline(file, line)) count_lines++;
        std::cout << "Number of lines in a file: " << count_lines << std::endl;
    } else std::cout<<"Error: file was not opened!"<<std::endl;
    return count_lines;
}


/**
 * Function counts the number of digits in the file.
 * @return count_digits Function returns the number of digits.
 */
auto count_digits(){
    std::ifstream file(filename);
    int count_digits=0;
    std::string line;
    if(file.is_open()) {
        while (std::getline(file, line)) {
            for (int i = 0; i < line.size(); i++) {
                if (line.at(i) >= '0' && line.at(i) <= '9')
                    count_digits++;
            }
        } std::cout << "Number of digits in a file: " << count_digits << std::endl;
    } else std::cout<<"Error: file was not opened!"<<std::endl;
    return count_digits;
}


/**
 * Function counts the number of numbers in the file.
 * @return count_numbers Function returns the number of numbers.
 */
auto count_numbers(){
    std::ifstream file(filename);
    int count_numbers = 0;
    std::string word;
    if(file.is_open()) {
        while( file >> word) {
            auto is_number = false;
            for (int i = 0; i < word.size(); i++) {
                if (isdigit(word[i]) || word[i] == '.' || word[i] == ',') is_number = true;
                else {is_number = false;
                    break;
                }
            } if(is_number) count_numbers++;
        } std::cout << "Number of numbers in a file: " << count_numbers << "\n";
    } else std::cout<<"Error: file was not opened!"<<std::endl;
    return count_numbers;
}


/**
 * Function counts the number of chars in the file.
 * @return count_chars Function returns the number of chars.
 */
auto count_chars(){
    std::ifstream file(filename);
    int count_chars=0;
    if(file.is_open()) {
        while (file.get() && !file.fail()) count_chars++;
        std::cout << "Number of chars in a file: " << count_chars << "\n";
    } else std::cout<<"Error: file was not opened!"<<std::endl;
    return count_chars;
}


/**
 * Function counts the number of words in the file.
 * @return count_words Function returns the number of words.
 */
auto count_words(){
    std::ifstream file(filename);
    int count_words=0;
    if(file.is_open()){
        char word[50];
        while(file>>word) count_words++;
        std::cout << "Number of words in a file: " << count_words << "\n";
    } else std::cout<<"Error: file was not opened!"<<std::endl;
    return count_words;
}


/**
 * Function save all words from file to vector. Then this vector sorts them by alphabet order.
 * @return alphabet Function returns a vector, which contains all words in alphabet order.
 */
auto alphabet_order(){
    std::ifstream file(filename);
    std::vector<std::string>alphabet;
    if(file.is_open()){
        std::string str;

        while(file >> str)
            alphabet.push_back(str);

        std::sort(alphabet.begin(), alphabet.end());
        std::cout << "Words in alphabet order: " << "\n";
        for(auto i:alphabet) std::cout << i << " ";
        std::cout<<std::endl;
    } else std::cout<<"Error: file was not opened!"<<std::endl;
    return alphabet;
}


/**
 * Function save all words from file to vector. Then this vector sorts them by reversed alphabet order.
 * @return reversed_alphabet Function returns a vector, which contains all words in reversed alphabet order.
 *
 */
auto reverse_alphabet_order(){
    std::ifstream file(filename);
    std::vector<std::string> reversed_alphabet;
    if(file.is_open()) {
        std::string str;
        while (file >> str)
            reversed_alphabet.push_back(str);

        std::sort(reversed_alphabet.begin(), reversed_alphabet.end(), std::less<std::string>());
        std::cout << "Words in reversed alphabet order: " << "\n";
        for (auto i:reversed_alphabet) std::cout << i << " ";
        std::cout << std::endl;
    } else std::cout<<"Error: file was not opened!"<<std::endl;
    return reversed_alphabet;
}


/**
 * Function modifies the operation of the function of sorting words in alphabetical order.
 * The function takes all words from file and writes them to a vector.
 * Then vector sorts words by their length from the smallest to the largest word.
 * @return length Function returns a vector, which contains all words by their length.
 */
auto sort_by_length(){
    std::ifstream file(filename);
    std::vector<std::string> length;
    if(file.is_open()) {
        std::string str;

        while (file >> str) length.push_back(str);

        std::sort(length.begin(), length.end(), [](std::string s1, std::string s2) { return s1.length() < s2.length(); });

        std::cout << "Words sorted by length: " << "\n";
        for (auto i:length) std::cout << i << " ";
        std::cout << std::endl;
    } else std::cout<<"Error: file was not opened!"<<std::endl;
    return length;
}


/**
 * Function modifies the operation of the function of sorting words in reversed alphabetical order.
 * The function takes all words from file and writes them to a vector.
 * Then vector sorts words by their length from the largest to the smallest word.
 * @return reversed_length Function returns a vector, which contains all words by their reversed length.
 */
auto reversed_sort_by_length(){
    std::ifstream file(filename);
    std::vector<std::string> reversed_length;
    if(file.is_open()) {
        std::string str;

        while (file >> str) reversed_length.push_back(str);

        std::sort(reversed_length.begin(), reversed_length.end(), [](std::string s1, std::string s2) { return s1.length() > s2.length(); });

        std::cout << "Words sorted by length reversed: " << "\n";
        for (auto i:reversed_length) std::cout << i << " ";
        std::cout << std::endl;
    } else std::cout<<"Error: file was not opened!"<<std::endl;
    return reversed_length;
}


/**
 * Function by checking the length of words and sorting them, checking if they are anagrams.
 * @param str1 The function takes as a parameter two strings.
 * @param str2 The function takes as a parameter two strings.
 * @return Function returns true of false depends on if two words are anagrams or not.
 */
bool is_anagram(std::string str1, std::string str2){
    int word1 = str1.length();
    int word2 = str2.length();
    if (word1 != word2) return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (int i = 0; i < word1; i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}
/**
 * Function takes a vector of words from user and all words from file and with the help of previous function
 * bool is_anagram checks if these words are anagrams.
 * @param vec Function takes as parameter a vector of words that the user writes after the -a flag.
 * @return anagrams Function returns a set of words, which are anagrams.
 */
auto find_anagrams(const std::vector<std::string>&vec){

    std::ifstream file(filename);
    std::set<std::string>anagrams;
    if(file.is_open()) {
        for (auto word1 = std::string(); file >> word1;) {
            for (auto &word2 : vec) {
                if (is_anagram(word1, word2)) {
                    anagrams.insert(word1);
                }
            }
        }
        std::cout << "Words anagrams from file: " << "\n";
        for (auto all_anagrams:anagrams) std::cout << all_anagrams << "\n";
    } else std::cout<<"Error: file was not opened!"<<std::endl;
    return anagrams;
}


 /**
  * Function takes a vector of words from user and all words from file and checks if these words are anagrams.
  * @param vec Function takes as parameter a vector of words that the user writes after the -p flag.
  * @return palindrome Function returns a vector of words, which are palindromes.
  */
auto find_palindromes(const std::vector<std::string>&vec){
    std::ifstream file(filename);
    std::vector<std::string>palindrome;
    if(file.is_open()){
        std::string words;
        while(file >> words) palindrome.push_back(words);
            palindrome.insert(palindrome.end(), vec.begin(), vec.end());
            std::cout << "Words palindromes from file: " << "\n";
            for(std::string i:palindrome){
                if(i == std::string(i.rbegin(), i.rend()))
                    std::cout << i << "\n";
            }
    }
    else std::cout<<"Error: file was not opened!"<<std::endl;
    return palindrome;
}


//--my function
/**
 * Function swaps two lines chosen by user from a file and replaces all "i" to "1" and "o" to "0".
 * @return vec Function returns a vector, which contains all text from file.
 */
auto swap_lines(){
    std::ifstream file(filename);
    std::string word;
    std::vector<std::string>vec;
    if(file.is_open()) {
        std::string s;
        while (std::getline(file, word)) {
            std::replace(word.begin(), word.end(), 'i', '1');
            std::replace(word.begin(), word.end(), 'o', '0');
            vec.push_back(word);
        }
        int p1, p2;
        std::cout << "Write a number of line from 0 to " << vec.size()-1 << std::endl;
        std::cin >> p1;
        std::cout << "Write a number of line from 0 to " << vec.size()-1 << std::endl;
        std::cin >> p2;
        if (p1 < vec.size() && p2 < vec.size()) {
            s = vec[p1];
            vec[p1] = vec[p2];
            vec[p2] = s;
            for (auto g:vec) {
                std::cout << g << " ";
            }
        }
        else std::cout<<"You entered the wrong number!" << std::endl;
    }
    else std::cout<<"Error: file was not opened!"<<std::endl;
    return vec;
}


#endif //ARINA_MOROZOVA_S22931_ALL_FUNCTIONS_H
