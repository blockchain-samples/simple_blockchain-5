#if !defined(__BLOCK_C__)
#define __BLOCK_C__

#include <cstdint>
#include <sstream>
#include <iostream>

#include "SHA256/sha256.hpp"

class Block
{
  private:
    unsigned int _index;
    int64_t _nonce;
    std::string _data;
    std::string _hash;
    time_t _time;

    std::string _prevHash;

    std::string _CalculateHash() const;

  public:
    Block(unsigned int indexIn, const std::string &dataIn);

    void MineBlock(unsigned int difficulty);

    // GET SET
    std::string GetPrevHash() const;
    void SetPrevHash(std::string value);

    std::string GetHash() const;
};

#endif // __BLOCK_C__
