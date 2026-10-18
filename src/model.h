#include <map>

class Model{
    private:

        int kgram_length = 1;

        std::map idk;

    public:

        Model(int k);

        void train(std::string filePath);

        char next(std::char* context);
};