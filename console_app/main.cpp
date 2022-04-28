#include <iostream>
#include <vector>
#include "help.h"
#include "all_functions.h"



int main(int args_count, const char* args[]) {
     auto arguments = std::vector<std::string>(args + 1, args + args_count);
    if(arguments.empty()) help();

    auto file = std::ifstream();

    for (auto argument=0;argument<arguments.size();argument++) {

        if(arguments[argument]=="--help") help();

        else if(arguments[argument]=="-f"|| arguments[argument]=="--file"){
            if(arguments.size()<=1) std::cout<<"Error:file path was not entered!\n";
            file=std::ifstream(arguments[argument+1]);
            filename=arguments[argument+1];
            find_file(file);
        }

        else if(arguments[argument]=="-n"||arguments[argument]=="--newlines")
            count_lines();

        else if(arguments[argument]=="-d"||arguments[argument]=="--digits")
            count_digits();

        else if(arguments[argument]=="-dd"||arguments[argument]=="--numbers")
            count_numbers();

        else if(arguments[argument]=="-c"||arguments[argument]=="--chars")
            count_chars();

        else if(arguments[argument]=="-w"||arguments[argument]=="--words")
            count_words();

        else if(arguments[argument]=="-s"||arguments[argument]=="--sorted"){
            if(arguments[argument-1]!="-l")
            alphabet_order();
        }

        else if(arguments[argument]=="-rs"||arguments[argument]=="--reverse-sorted"){
            if(arguments[argument-1]!="-l")
            reverse_alphabet_order();
        }

        else if(arguments[argument]=="-l"||arguments[argument]=="--by-length"){
            if(arguments[argument+1]==("-s"))
                sort_by_length();
            else if(arguments[argument+1]==("-rs"))
                reversed_sort_by_length();
        }

        else if(arguments[argument]=="-a"||arguments[argument]=="--anagrams"){
            std::vector<std::string>anagrams;
            for(int j=1; j+argument<arguments.size(); j++){
                if(arguments[argument+j].find('-')){
                    anagrams.push_back(arguments[argument + j]);
                } else break;
            }
            if(arguments[arguments.size()-1-anagrams.size()]=="-a"){
                find_anagrams(anagrams);
            }
            else {
                std::cout<<"Do not write any flags after -a!";
                break;
            }
            std::cout<<std::endl;
        }

        else if(arguments[argument]=="-p"||arguments[argument]=="--palindromes"){
            std::vector<std::string>palindromes;
            for(int j=1; j+argument<arguments.size(); j++){
                if(arguments[argument+j].find('-')) {
                    palindromes.push_back(arguments[argument + j]);
                } else break;
            }
            if(arguments[arguments.size()-1-palindromes.size()]=="-p"){
                find_palindromes(palindromes);
            }
            else {
                std::cout<<"Do not write any flags after -p!";
                break;
            }
            std::cout<<std::endl;
        }

        else if (arguments[0] == "-i" || arguments[0] == "--input" ){
            auto new_file = arguments[1];
            std::ifstream file(new_file);
            arguments.clear();
            std::string word = std::string();
            while(file >> word) arguments.push_back(word);
            if(arguments.size() > 2){
                std::cout << "Error: another arguments were found";
                return 0;
            }
        }


        else if(arguments[argument]=="-cs"||arguments[argument]=="--cyber-swap")
            swap_lines();
    }

}