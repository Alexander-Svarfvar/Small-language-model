#include "kgram.h"
#include <random>
#include <iostream>

std::random_device rd;
std::mt19937 gen(rd());

Kgram::Kgram(int l, std::string s){
    length = l;
    kgram = s;
}

void Kgram::increase_count(){
    count++;
}

void Kgram::increase_character_count(char c){
    if(character_count.count(c)){
        character_count[c] += 1;
    }else{
        character_count.insert({c, 1});
    }
}

int Kgram::get_count(char c){
    return character_count.at(c);
}

char Kgram::get_character_from_dist(){

    int sum = 0;
    std::uniform_int_distribution<> distr(1, count);

    int goal = distr(gen);
    for(const auto &cc : character_count){
        sum += cc.second;
        if(sum >= goal){
            return cc.first;
        }
    }

    return '}';
}