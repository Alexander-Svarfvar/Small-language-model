#include <model.h>
#include <iostream>

Model::Model(int k){
    kgram_length = k;
}

Model::train(std::string filePath){
    std::ifstream file[filePath];

    char context[k];

    for(int i = 0; i < k; i++){
        file.Get(context[i]);
        std::cout << context[i];
    }

}