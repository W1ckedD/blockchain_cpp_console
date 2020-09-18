#include "iostream"
#include "vector"
#include "Data.cpp"

class Block {
    private:
        std::string lastBlockHash;
        std::string blockHash;
        std::vector<Data> blockData;

    public:
        Block(std::string lastHash, std::string hash, std::vector<Data> data);
        std::string getLastHash();
        std::string getHash();
        std::vector<Data> getData();
};

Block::Block(std::string lastHash, std::string hash, std::vector<Data> data) {
    lastBlockHash = lastHash;
    blockHash = hash;
    blockData = data;
}

std::string Block::getLastHash() {
    return lastBlockHash;
}

std::string Block::getHash() {
    return blockHash;
}

std::vector<Data> Block::getData() {
    return blockData;
}