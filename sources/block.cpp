#include "block.hpp"

Block::Block(unsigned int indexIn, const std::string &dataIn)
    : _index(indexIn),
      _nonce(-1),
      _data(dataIn),
      _time(time(nullptr))
{
    this->_prevHash = "";
}

//PUBLIC

void        Block::MineBlock(unsigned int difficulty){
    char cstr[difficulty + 1];
    for (unsigned int  i = 0; i < difficulty; ++i)
        cstr[i] = '0';
    cstr[difficulty] = '\0';
 
    std::string str(cstr);
 
    do {
        this->_nonce++;
        this->_hash = _CalculateHash();
    } while (this->_hash.substr(0, difficulty) != str);
 
    std::cout << "Block mined: " << this->_hash << std::endl;
}

//PRIVATE

inline std::string Block::_CalculateHash() const {
    std::stringstream ss;
    ss << this->_index << this->_time << this->_data << this->_nonce << this->_prevHash;
 
    return sha256(ss.str());
}

//GET SET

std::string Block::GetHash() const
{
    return this->_hash;
}

std::string Block::GetPrevHash() const {
    return this->_prevHash;
}

void        Block::SetPrevHash(std::string value){
    this->_prevHash = value;
}
