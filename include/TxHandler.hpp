#ifndef TX_HANDLER_HPP
#define TX_HANDLER_HPP

#include "Transaction.hpp"
#include "UTXOPool.hpp"
#include <vector>

class TxHandler {
private:
    UTXOPool utxoPool; // Each TxHandler has its own copy of the ledger

public:
    // Constructor to create a handler with a starting ledger
    TxHandler(const UTXOPool& pool);

    // Checks if a single transaction is valid
    bool isValidTx(const Transaction& tx) const;

    // Processes a list of possible transactions and returns the ones that are valid
    std::vector<Transaction> handleTxs(const std::vector<Transaction>& possibleTxs);
};

#endif // TX_HANDLER_HPP