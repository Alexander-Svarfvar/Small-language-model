#include <iostream>
#include <string>
#include <map>
#include "model.h"


int main(int argc, char* argv[]){

    float pseudocount;
    int k;
    std::string filePath;
    std::string option;
    int output_length;

    if( argc == 4 ){
        k = std::stoi(argv[1]);
        filePath = argv[2];
        output_length = std::stoi(argv[3]); 
    }
    else if( argc == 6 ){
        option = argv[1];
        if(option == "-a"){
            pseudocount = std::stof(argv[2]);
            k = std::stoi(argv[3]);
            filePath = argv[4];
            output_length = std::stoi(argv[5]);
        }else{
            std::cout << "slm: Unknown option!\n";
            return 0;
        }
    }
    else {
        std::cerr << "slm: Wrong number of arguments!\n";
        return 0;
    }

    if( k <= 0 ){
        std::cerr << "slm: " << k << " is not a positive integer!\n";
        return 0;
    }

    Model model(k, pseudocount);
    model.train(filePath);

    for(int i = 0; i < output_length; i++){
        std::cout << model.next();
    }

    std::cout << '\n';

    return 0;
}