#pragma once

#include <string>
#include <map>

class Kgram{
    int length;
    std::string kgram;
    std::map<char, int> next_character_count; 
    int count = 1;
    
    public:
        Kgram(int l, std::string s);

        void increase_count();

        void increase_next_character_count(char c);

};