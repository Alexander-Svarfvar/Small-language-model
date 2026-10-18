#pragma once

#include <string>
#include <map>

class Kgram{
    int length;
    std::string kgram;
    std::map<char, int> character_count; 
    int count = 1;
    
    public:

        Kgram(int l, std::string s);

        void increase_count();

        void increase_character_count(char c);

        int get_count(char c);

        char get_character_from_dist();

};