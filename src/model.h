#include <map>
#include "kgram.h"

class Model{
    private:

        int kgram_length = 1;

        std::map<std::string, Kgram> kgrams;

    public:

        Model(int k);

        void train(std::string filePath);

        char next(char* context);
};