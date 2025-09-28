# ScroogeCoin - C++ Implementation

A robust C++ implementation of the ScroogeCoin cryptocurrency system, demonstrating advanced C++ programming concepts alongside blockchain fundamentals. Originally based on Princeton University's "Bitcoin and Cryptocurrency Technologies" course assignment, this implementation showcases modern C++ best practices.

## Overview

ScroogeCoin is a simplified cryptocurrency system where a central authority called "Scrooge" manages all transactions and maintains the blockchain ledger. This implementation demonstrates fundamental blockchain concepts including transaction validation, digital signatures, and UTXO (Unspent Transaction Output) management.

## Features

- **Object-Oriented Design**: Clean C++ class hierarchy with proper encapsulation
- **STL Integration**: Leverages C++ Standard Template Library for efficient data structures
- **Memory Management**: Smart pointers and RAII principles for safe memory handling
- **Template Programming**: Generic programming for flexible transaction handling
- **Exception Safety**: Robust error handling using C++ exception mechanisms
- **Centralized Authority**: Scrooge acts as the central authority for coin creation and validation
- **Transaction Validation**: Comprehensive validation using C++ algorithms
- **Digital Signatures**: Cryptographic verification with OpenSSL integration
- **UTXO Pool Management**: Efficient tracking using STL containers
- **Thread Safety**: Mutex-based synchronization for concurrent operations

## System Architecture

### Key Components

1. **Transaction**: Represents a transfer of coins between parties
2. **UTXO Pool**: Manages the collection of unspent transaction outputs
3. **Transaction Handler**: Validates and processes transactions
4. **Scrooge**: The central authority managing the entire system

### Transaction Rules

- Only Scrooge can create new coins
- All transactions must be digitally signed by the coin owners
- Transactions must reference valid unspent outputs
- The sum of input values must equal or exceed the sum of output values
- Double-spending is prevented through UTXO tracking

## Getting Started

### Prerequisites

- C++ compiler (C++11 or later)
- CMake (if using CMake build system)
- OpenSSL library (for cryptographic functions)

### Building the Project

```bash
# Clone the repository
git clone https://github.com/JEET090806/Scrooge-Coin-with-Cpp.git
cd Scrooge-Coin-with-Cpp

# Compile the project
g++ -std=c++11 -o scroogecoin *.cpp -lssl -lcrypto

# Or if using CMake
mkdir build && cd build
cmake ..
make
```

### Running the Application

```bash
./scroogecoin
```

## Usage Examples

### Creating a Transaction

```cpp
// Create a new transaction
Transaction tx;
tx.addInput(previousTxHash, outputIndex);
tx.addOutput(value, recipientPublicKey);
tx.addSignature(signature, inputIndex);
```

### Validating Transactions

```cpp
// Initialize transaction handler
TxHandler txHandler(utxoPool);

// Validate and process transactions
vector<Transaction> validTx = txHandler.handleTxs(proposedTransactions);
```

## Implementation Details

### Transaction Validation Process

1. **Signature Verification**: Verify all input signatures are valid
2. **UTXO Existence**: Confirm all referenced outputs exist and are unspent
3. **Double Spending Check**: Ensure no UTXO is used multiple times
4. **Value Conservation**: Verify input values ≥ output values
5. **Non-negative Values**: Ensure all output values are positive

### Data Structures

- **Transaction**: Contains inputs, outputs, and signatures
- **UTXO**: Represents an unspent transaction output
- **UTXOPool**: Hash table for efficient UTXO lookup and management

## Testing

The implementation includes comprehensive test cases covering:

- Valid transaction processing
- Invalid signature detection
- Double-spending prevention
- UTXO pool consistency
- Edge cases and error handling

```bash
# Run tests (if test framework is included)
./run_tests
```

## File Structure

```
Scrooge-Coin-with-Cpp/
├── src/
│   ├── Transaction.cpp
│   ├── Transaction.h
│   ├── UTXO.cpp
│   ├── UTXO.h
│   ├── UTXOPool.cpp
│   ├── UTXOPool.h
│   ├── TxHandler.cpp
│   ├── TxHandler.h
│   └── main.cpp
├── tests/
│   └── test_cases.cpp
├── CMakeLists.txt
└── README.md
```

## Key Concepts Demonstrated

- **Blockchain Fundamentals**: Understanding of basic blockchain principles
- **Cryptographic Signatures**: Implementation of digital signature verification
- **Transaction Validation**: Comprehensive transaction validation logic
- **UTXO Model**: Implementation of the unspent transaction output model
- **Data Structure Design**: Efficient data structures for cryptocurrency operations

## Educational Context

This project implements concepts from:
- **Course**: Bitcoin and Cryptocurrency Technologies (Princeton University)
- **Focus Areas**: 
  - Cryptographic hash functions
  - Digital signatures and public key cryptography
  - Blockchain mechanics
  - Transaction validation
  - Consensus mechanisms (simplified)

## Limitations

As an educational implementation, ScroogeCoin has several limitations compared to real cryptocurrencies:

- **Centralized Authority**: Scrooge is a single point of failure
- **No Mining**: No proof-of-work or consensus mechanism
- **Simplified Model**: Reduced complexity for learning purposes
- **No Network Layer**: No peer-to-peer networking implementation

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/new-feature`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature/new-feature`)
5. Create a Pull Request

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Princeton University's "Bitcoin and Cryptocurrency Technologies" course
- Course instructors for providing the theoretical foundation
- OpenSSL library for cryptographic functions

## References

- [Bitcoin and Cryptocurrency Technologies](https://www.coursera.org/learn/cryptocurrency) - Coursera Course
- [Bitcoin and Cryptocurrency Technologies Textbook](http://bitcoinbook.cs.princeton.edu/)
- [OpenSSL Documentation](https://www.openssl.org/docs/)

## Contact

For questions or issues regarding this implementation, please open an issue on GitHub or contact the repository maintainer.

---

*This implementation is for educational purposes only and should not be used in production environments.*
