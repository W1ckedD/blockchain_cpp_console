#include "iostream"
#include "vector"
#include "Transaction.cpp"

class Block {
    private:
        std::string lastBlockHash;
        std::string blockHash;
        std::vector<Transaction> blockData;

    public:
        Block(std::string lastHash, std::string hash, std::vector<Transaction> data);
        std::string getLastHash();
        std::string getHash();
        std::vector<Transaction> getData();
        void addTransaction(std::string sender, std::string recepient, float amount);
        void printBlock();
};

Block::Block(std::string lastHash, std::string hash, std::vector<Transaction> data) {
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

std::vector<Transaction> Block::getData() {
    return blockData;
}

void Block::addTransaction(std::string sender, std::string recepient, float amount) {
    Transaction tsx(sender, recepient, amount);
    blockData.insert(blockData.end(), tsx);
}

void Block::printBlock() {
    for (int i = 0; i < blockData.size(); i++) {
        std::cout<<"    "<<"Transaction "<<i + 1<<": "<<std::endl;
        std::cout<<"        "<<"Sender: "<<blockData.at(i).getSender()<<std::endl;
        std::cout<<"        "<<"Recepient: "<<blockData.at(i).getRecepient()<<std::endl;
        std::cout<<"        "<<"Amount: "<<blockData.at(i).getAmount()<<std::endl;
    }
}