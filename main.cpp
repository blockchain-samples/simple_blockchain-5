#include "blockchain.hpp"

int main(int ac, char **av)
{
    BlockChain *chain = new BlockChain();

    std::cout << "Mining block 1..." << std::endl;
    chain->AddBlock(new Block(1, "Block 1 Data"));

    std::cout << "Mining block 2..." << std::endl;
    chain->AddBlock(new Block(2, "Block 2 Data"));

    std::cout << "Mining block 3..." << std::endl;
    chain->AddBlock(new Block(3, "Block 3 Data"));

    return 0;
}