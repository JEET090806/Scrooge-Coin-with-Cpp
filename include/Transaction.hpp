#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>
#include <vector>

class Transaction {
public:
    // An input is a pointer to a coin you are spending
    struct Input {
        std::string prevTxHash; // Hash of the transaction where the coin was created
        int outputIndex;      // Which output from that transaction (0, 1, 2...)
    };

    // An output is a new coin you are creating
    struct Output {
        double value;         // How much the coin is worth
        std::string address;  // Who can spend this coin (their public key)
    };

private:
    std::string hash;
    std::vector<Input> inputs;
    std::vector<Output> outputs;

public:
    // Constructor to make it easy to create a transaction
    Transaction();

    // Methods to build the transaction
    void addInput(std::string prevTxHash, int outputIndex);
    void addOutput(double value, std::string address);
    
    // "Finalize" the transaction by giving it a unique hash
    void finalize();

    // Getters to see the transaction's data
    std::string getHash() const { return hash; }
    const std::vector<Input>& getInputs() const { return inputs; }
    const std::vector<Output>& getOutputs() const { return outputs; }
};

#endif // TRANSACTION_HPP