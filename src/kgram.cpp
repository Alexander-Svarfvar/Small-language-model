#include "kgram.h"

Kgram::Kgram(int l, std::string s){
    length = l;
    kgram = s;
}

void Kgram::increase_count(){
    count++;
}

void Kgram::increase_next_character_count(char c){
    if(next_character_count.count(c)){
        next_character_count[c] += 1;
    }else{
        next_character_count.insert({c, 1});
    }
}