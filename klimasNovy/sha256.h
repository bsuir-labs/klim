#pragma once
#include <string>

class SHA256 //: public Hash
{
public:
    SHA256();
    unsigned int maBKDRHash(const char *str, unsigned int len, unsigned int seed = 1337);
    std::string hash(std::string);
};
