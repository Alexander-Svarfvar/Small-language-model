#include "model.h"
#include <iostream>
#include <fstream>

Model::Model(int k){
    kgram_length = k;
}

void Model::train(std::string filePath){
    
    std::ifstream file(filePath);

    char context[kgram_length];

    for(int i = 0; i < kgram_length; i++){
        file.get(context[i]);
        std::cout << context[i];
    }

}