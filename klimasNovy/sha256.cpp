#include "sha256.h"

SHA256::SHA256() {}

unsigned int SHA256::maBKDRHash(const char *str, unsigned int len, unsigned int seed)
{
    unsigned int hash = 0;
    unsigned int i = 0;

    for (i = 0; i < len; str++, i++)
    {
        hash = (hash * seed) + *str + i;
    }
    return hash;
}

std::string SHA256::hash(std::string str)
{
    std::string result;
    unsigned int _hash = maBKDRHash(str.c_str(), str.size());
    result = std::to_string(_hash);
    return result;
}