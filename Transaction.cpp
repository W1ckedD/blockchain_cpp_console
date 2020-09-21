#include "iostream"

class Transaction {
    private:
        std::string tsxSender;
        std::string tsxRecepient;
        float tsxAmount;
    public:
        Transaction(std::string sender, std::string recepient, float amount);
        std::string getSender();
        std::string getRecepient();
        float getAmount();
};

Transaction::Transaction(std:: string sender, std::string recepient, float amount) {
    tsxSender = sender;
    tsxRecepient = recepient;
    tsxAmount = amount;
}

std::string Transaction::getSender() {
    return tsxSender;
}

std::string Transaction::getRecepient() {
    return tsxRecepient;
}

float Transaction::getAmount() {
    return tsxAmount;
}
