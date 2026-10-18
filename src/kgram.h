#pragma once

#include <string>
#include <map>

class Kgram{

    std::map<char, int> character_counts; 
    int total_count = 1;
    
    public:

        void increase_total_count();

        void increase_character_count(char c);

        int get_count(char c);

        char get_character_from_dist();

};