#include "iostream"
#include "vector"
#include "Blockchain.cpp"

int main() {
	Blockchain blockchain;
	Transaction t1("Edward", "Kate", 12.5);
	std::vector<Transaction> transactions = {t1};
	Block block(blockchain.getLastBlock().getHash(), "thisblockhash", transactions);
	blockchain.mineBlock(block);
	for (int i = 0; i < blockchain.getChain().size(); i++) {
		std::cout<<"Block "<<i + 1<<": "<<std::endl;
		blockchain.getChain().at(i).printBlock();
	}
	return 0;
}
