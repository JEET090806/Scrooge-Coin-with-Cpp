#include "Transaction.hpp"
#include <cstdlib> // For rand()
#include <ctime>   // For time()

// Constructor
Transaction::Transaction() {
    // Seed the random number generator
    srand(time(NULL));
}

void Transaction::addInput(std::string prevTxHash, int outputIndex) {
    inputs.push_back({prevTxHash, outputIndex});
}

void Transaction::addOutput(double value, std::string address) {
    outputs.push_back({value, address});
}

// We'll "fake" a hash by just creating a random number.
// In a real system, this would be a complex cryptographic hash.
void Transaction::finalize() {
    this->hash = std::to_string(rand());
}