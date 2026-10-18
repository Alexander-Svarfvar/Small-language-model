#include "model.h"
#include <iostream>
#include <fstream>

Model::Model(int k){
    kgram_length = k;
}

void Model::train(std::string filePath){
    
    std::ifstream file(filePath);

    std::string current_kgram = "";

    for(char c; file.get(c); ){

        if(kgrams.count(current_kgram)){
            kgrams.at(current_kgram).increase_count();
            kgrams.at(current_kgram).increase_character_count(c);
        }else{
            Kgram temp_kgram(kgram_length, current_kgram);
            kgrams.insert({current_kgram, temp_kgram});
            kgrams.at(current_kgram).increase_character_count(c);
        }

        if(current_kgram.length() >= kgram_length){
            current_kgram = current_kgram.substr(1,kgram_length) + c;
        }else{
            current_kgram += c;
        }
    }
}

char Model::next(){
    char c = kgrams.at(context).get_character_from_dist();

    if(context.length() >= kgram_length){
            context = context.substr(1,kgram_length) + c;
        }else{
            context += c;
        }

    return c;
}