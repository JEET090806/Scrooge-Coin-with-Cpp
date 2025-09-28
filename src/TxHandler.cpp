#include "TxHandler.hpp"
#include <unordered_set> // To keep track of things we've seen

// The constructor simply copies the starting UTXO pool.
TxHandler::TxHandler(const UTXOPool& pool) : utxoPool(pool) {}

bool TxHandler::isValidTx(const Transaction& tx) const {
    double inputSum = 0;
    std::unordered_set<UTXO, UTXOHasher> spentUTXOs;

    // Loop through every input in the transaction
    for (const auto& input : tx.getInputs()) {
        UTXO utxo = {input.prevTxHash, input.outputIndex};

        // RULE 1: The coin being spent must exist in our ledger.
        if (!utxoPool.contains(utxo)) {
            return false;
        }

        // RULE 2 (Signature check): We are skipping the actual crypto signature check
        // to keep it simple. We just assume it's valid.

        // RULE 3: The same coin cannot be spent twice in the same transaction.
        if (spentUTXOs.count(utxo)) {
            return false; // Already spent in this tx!
        }
        spentUTXOs.insert(utxo);

        // Add the value of the spent coin to our input sum.
        inputSum += utxoPool.getOutput(utxo).value;
    }

    double outputSum = 0;
    // Loop through every new coin being created
    for (const auto& output : tx.getOutputs()) {
        // RULE 4: New coins cannot have a negative value.
        if (output.value < 0) {
            return false;
        }
        outputSum += output.value;
    }

    // RULE 5: The total value of coins being spent must not be less than the
    // total value of new coins being created. (No creating money from thin air!)
    if (inputSum < outputSum) {
        return false;
    }

    // If we passed all the rules, the transaction is valid!
    return true;
}

std::vector<Transaction> TxHandler::handleTxs(const std::vector<Transaction>& possibleTxs) {
    std::vector<Transaction> acceptedTxs;

    bool changed = true;
    while (changed) {
        changed = false;
        for (const auto& tx : possibleTxs) {
            // Check if we already accepted this tx
            bool alreadyAccepted = false;
            for(const auto& accepted : acceptedTxs) {
                if (accepted.getHash() == tx.getHash()) {
                    alreadyAccepted = true;
                    break;
                }
            }
            if (alreadyAccepted) continue;

            // If the transaction is valid...
            if (isValidTx(tx)) {
                // ...add it to our list of accepted transactions.
                acceptedTxs.push_back(tx);
                changed = true;

                // And update our ledger!
                // 1. Remove the coins that were spent.
                for (const auto& input : tx.getInputs()) {
                    utxoPool.removeUTXO({input.prevTxHash, input.outputIndex});
                }
                // 2. Add the new coins that were created.
                for (int i = 0; i < tx.getOutputs().size(); ++i) {
                    utxoPool.addUTXO({tx.getHash(), i}, tx.getOutputs()[i]);
                }
            }
        }
    }
    return acceptedTxs;
}