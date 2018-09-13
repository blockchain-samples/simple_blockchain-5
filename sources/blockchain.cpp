#include "blockchain.hpp"

BlockChain::BlockChain()
{
    _chain.emplace_back(new Block(0, "Genesis Block"));
    _difficulty = 6;
}

//PUBLIC
void BlockChain::AddBlock(Block *block)
{
    block->SetPrevHash(this->_GetLastBlock()->GetHash());
    block->MineBlock(this->_difficulty);
    this->_chain.push_back(block);
}

//PRIVATE
Block *BlockChain::_GetLastBlock() const
{
    return this->_chain.back();
}