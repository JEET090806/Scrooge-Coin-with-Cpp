#include "TxHandler.hpp"
#include <iostream>

int main() {
    std::cout << "--- ScroogeCoin Simple Simulation ---" << std::endl;

    // 1. Create the very first transaction (the "Genesis Transaction")
    Transaction genesisTx;
    genesisTx.addOutput(100.0, "Alice"); // Create a coin of 100 for Alice
    genesisTx.addOutput(50.0, "Bob");   // Create a coin of 50 for Bob
    genesisTx.finalize(); // Give it a unique hash
    std::string genesisTxHash = genesisTx.getHash();

    // 2. Create the initial ledger (UTXO Pool) and add the genesis coins
    UTXOPool initialPool;
    initialPool.addUTXO({genesisTxHash, 0}, genesisTx.getOutputs()[0]); // Alice's coin
    initialPool.addUTXO({genesisTxHash, 1}, genesisTx.getOutputs()[1]); // Bob's coin

    // 3. Create a transaction handler with this initial ledger
    TxHandler txHandler(initialPool);

    // 4. Create a new transaction: Alice pays Charlie 20 coins
    Transaction tx1;
    tx1.addInput(genesisTxHash, 0); // Alice spends her 100-value coin
    tx1.addOutput(20.0, "Charlie");   // 20 for Charlie
    tx1.addOutput(80.0, "Alice");     // 80 back to Alice as change
    tx1.finalize();

    // 5. Create another transaction: Bob tries to pay David, but with a non-existent coin
    Transaction tx2_invalid;
    tx2_invalid.addInput("fake_hash", 0); // This coin doesn't exist!
    tx2_invalid.addOutput(10.0, "David");
    tx2_invalid.finalize();

    // 6. Put all possible transactions into a list
    std::vector<Transaction> allTxs = {tx1, tx2_invalid};

    // 7. Ask the handler to process them
    std::cout << "\nProcessing transactions..." << std::endl;
    std::vector<Transaction> acceptedTxs = txHandler.handleTxs(allTxs);

    std::cout << "\n--- Results ---" << std::endl;
    if (acceptedTxs.empty()) {
        std::cout << "No transactions were accepted." << std::endl;
    } else {
        std::cout << "Accepted Transaction Hashes:" << std::endl;
        for (const auto& tx : acceptedTxs) {
            std::cout << " - " << tx.getHash() << std::endl;
        }
    }

    return 0;
}