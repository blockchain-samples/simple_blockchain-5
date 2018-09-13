#if !defined(__BLOCK_CHAIN_C__)
#define __BLOCK_CHAIN_C__

#include <cstdint>
#include <vector>
#include "block.hpp"

class BlockChain{
    private:
        uint32_t              _difficulty;
        std::vector<Block*>   _chain;
 
        Block   *_GetLastBlock() const;

    public:
        BlockChain();
        void AddBlock(Block *block);

};


#endif // __BLOCK_CHAIN_C__

