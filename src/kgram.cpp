#include "kgram.h"
#include <random>
#include <iostream>

//used for generating random integers with uniform distribution.
std::random_device rd;
std::mt19937 gen(rd());

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

int Kgram::get_count(char c){
    return character_counts.at(c);
}

//Returns a random character from character_counts weighted by their counts.
char Kgram::get_character_from_dist(){

    std::uniform_int_distribution<> distr(1, total_count);

    int goal = distr(gen);
    int sum = 0;

    //
    for(const auto &cc : character_counts){
        sum += cc.second;
        if(sum >= goal){
            return cc.first;
        }
    }

    return '/';
}