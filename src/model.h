#pragma once

#include <map>
#include "kgram.h"

class Model{
    private:

        std::string context = "";

        int kgram_length;

        std::map<std::string, Kgram> kgrams;

    public:

        Model(int k);

        void train(std::string filePath);

        char next();
};