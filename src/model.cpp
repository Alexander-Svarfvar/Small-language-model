#include "model.h"
#include <iostream>
#include <fstream>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

Model::Model(int k){
    kgram_length = k;
}

Model::Model(int k, float a){
    alpha = a;
    kgram_length = k;
}

void Model::train(std::string filePath){
    
    std::ifstream file(filePath);

    std::string current_kgram = "";

    for(char c; file.get(c); ){

        if(alphabet.find(c) == std::string::npos){
            alphabet += c;
        }
        if(kgrams.count(current_kgram)){
            kgrams.at(current_kgram).increase_total_count();
            kgrams.at(current_kgram).increase_character_count(c);
        }else{
            Kgram temp_kgram;
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

    int n_w;
    if(kgrams.count(context)){
        n_w = kgrams.at(context).get_total_count();
    }else{
        n_w = 0;
    }

    int abs_sigma = alphabet.length(); 
    double sum = 0;

    std::uniform_real_distribution<double> distribution(0.0,n_w + abs_sigma*alpha);

    double goal = distribution(gen);

    char c;

    for( int i = 0; i < abs_sigma; i++ ){

        c = alphabet[i];

        int n_w_c;
        if(kgrams.count(context)){
            n_w_c = kgrams.at(context).get_character_count(c);
        }else{
            n_w_c = 0;
        }

        sum += n_w_c + alpha;
        if(sum >= goal){
            break;
        }
    }

    //shifts context window over by one.
    if(context.length() >= kgram_length){
        context = context.substr(1,kgram_length) + c;
    }else{
        context += c;
    }

    return c;
}