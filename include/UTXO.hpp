#ifndef UTXO_HPP
#define UTXO_HPP

#include <string>

// A struct is like a class, but its members are public by default.
// Perfect for simple data containers like this.
struct UTXO {
    std::string txHash; // The hash of the transaction that created this coin
    int index;          // The position of this coin in that transaction's outputs

    // We need a way to compare two UTXOs to see if they are the same coin
    bool operator==(const UTXO& other) const {
        return txHash == other.txHash && index == other.index;
    }
};

// This is a helper "hasher" struct. It teaches the unordered_map (which we'll use
// in UTXOPool) how to store and find our UTXO objects quickly.
struct UTXOHasher {
    size_t operator()(const UTXO& utxo) const {
        // A simple way to combine the hash of the string and the index
        return std::hash<std::string>()(utxo.txHash) ^ (std::hash<int>()(utxo.index) << 1);
    }
};

#endif // UTXO_HPP