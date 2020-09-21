#include "iostream"
#include "vector"
#include "string"
#include "Block.cpp"


class Blockchain {
    private:
        std::vector<Block> chain;
    public:
        Blockchain();
        std::vector<Block> getChain();
        void mineBlock(Block block);
        Block getLastBlock();
        std::string hashChain();
    
};

Blockchain::Blockchain() {
    std::vector<Transaction> data;
    Block genesis("genesis_last_hash", "genesis_hash", data);
    chain.insert(chain.end(), genesis);
}

std::vector<Block> Blockchain::getChain() {
    return chain;
}

void Blockchain::mineBlock(Block block) {
    chain.insert(chain.end(), block);
}

Block Blockchain::getLastBlock() {
    return chain.back();
}

std::string Blockchain::hashChain() {
    std::string hash = "";
    for (int i = 0; i < chain.size(); i++) {
        std::vector<Transaction> data = chain.at(i).getData();
        for (int j = 0; j < data.size(); j++) {
            hash = hash + data.at(j).getSender() + "//" + data.at(j).getRecepient() + "||" + std::to_string(data.at(j).getAmount());
        }
        hash = hash + "|?/" + std::to_string(i);
    }

    return hash;
}