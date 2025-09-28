#include "UTXOPool.hpp"

void UTXOPool::addUTXO(const UTXO& utxo, const Transaction::Output& output) {
    pool[utxo] = output;
}

void UTXOPool::removeUTXO(const UTXO& utxo) {
    pool.erase(utxo);
}

bool UTXOPool::contains(const UTXO& utxo) const {
    // .count() returns 1 if the item is in the map, and 0 otherwise.
    return pool.count(utxo) > 0;
}

Transaction::Output UTXOPool::getOutput(const UTXO& utxo) const {
    // .at() finds the item in the map.
    return pool.at(utxo);
}