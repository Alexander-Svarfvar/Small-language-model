#include <iostream>
#include <string>
#include <map>


int main(int argc, char* argv[]){

    if( argc == 4 ){
        int k = std::stoi(argv[1]);
        std::string filePath = argv[2];
        int output_length = std::stoi(argv[3]); 
    }
    else if( argc == 6 ){
        if(argv[1] == "-a"){
            float pseudocount = std::stof(argv[2]);
            int k = std::stoi(argv[3]);
            std::string filePath = argv[4];
            int output_length = std::stoi(argv[5]);
        }
    }
    else {
        std::cerr << "Wrong number of arguments!"
    }
}