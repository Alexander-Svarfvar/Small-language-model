#include <iostream>
#include <string>
#include <map>
#include "model.h"


int main(int argc, char* argv[]){

    float pseudocount;
    int k;
    std::string filePath;
    int output_length;

    if( argc == 4 ){
        k = std::stoi(argv[1]);
        filePath = argv[2];
        output_length = std::stoi(argv[3]); 
    }
    else if( argc == 6 ){
        if(argv[1] == "-a"){
            pseudocount = std::stof(argv[2]);
            k = std::stoi(argv[3]);
            filePath = argv[4];
            output_length = std::stoi(argv[5]);
        }
    }
    else {
        std::cerr << "Wrong number of arguments!";
    }


    Model model(k);
    model.train(filePath);
}