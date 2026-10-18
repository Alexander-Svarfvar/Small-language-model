#include "kgram.h"
#include <random>
#include <iostream>

void Kgram::increase_total_count(){
    total_count++;
}

void Kgram::increase_character_count(char c){
    if(character_counts.count(c)){
        character_counts[c] += 1;
    }else{
        character_counts.insert({c, 1});
    }
}

int Kgram::get_total_count(){
    return total_count;
}

int Kgram::get_character_count(char c){
    if(character_counts.count(c)){
        return character_counts.at(c);
    }else{
        return 0;
    }
}