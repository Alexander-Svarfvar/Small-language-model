#pragma once

#include <map>
#include "kgram.h"

class Model{
    private:

        std::string alphabet = "";

        std::string context = "";

        int kgram_length;

        float alpha = 0;

        std::map<std::string, Kgram> kgrams;

    public:

        Model(int k);

        Model(int k, float a);

        void train(std::string filePath);

        char next();
};