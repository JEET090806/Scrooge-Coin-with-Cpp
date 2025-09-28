#ifndef UTXO_POOL_HPP
#define UTXO_POOL_HPP

#include "UTXO.hpp"
#include "Transaction.hpp"
#include <unordered_map> // A fast way to store and look up key-value pairs

class UTXOPool {
private:
    // The pool is a map where each UTXO (the key) points to its Output (the value).
    // This lets us quickly find a coin's value and who owns it.
    std::unordered_map<UTXO, Transaction::Output, UTXOHasher> pool;

public:
    void addUTXO(const UTXO& utxo, const Transaction::Output& output);
    void removeUTXO(const UTXO& utxo);
    bool contains(const UTXO& utxo) const;
    Transaction::Output getOutput(const UTXO& utxo) const;
};

#endif // UTXO_POOL_HPP