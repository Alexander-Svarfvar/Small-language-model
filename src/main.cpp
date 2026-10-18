#include <iostream>
#include <string>
#include <map>


int main(int argc, char* argv[]){

    if( argc == 4 ){
        int k = argv[1];
        std::string filePath = argv[2];
        int output_length = argv[3]; 
    }
    else if( argc == 6 ){
        if(argv[1] == "-a"){
            float pseudocount = argv[2];
            int k = argv[3];
            std::string filePath = argv[4];
            int output_length = argv[5];
        }
    }
    else {
        std::cerr << "Wrong number of arguments!"
    }
}