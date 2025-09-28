# ScroogeCoin C++ Implementation

\<div align="center"\>

\</div\>

This repository contains a C++ implementation of **ScroogeCoin**, a simplified, centralized cryptocurrency model based on an assignment from the "Bitcoin and Cryptocurrency Technologies" course. The project builds the core logic for a central authority, Scrooge, to process transactions, validate them against a set of rules, and maintain a public ledger.

-----

## 📜 Table of Contents

  * [💡 Core Concepts](https://www.google.com/search?q=%23-core-concepts)
  * [✨ Features](https://www.google.com/search?q=%23-features)
  * [🌊 Process Flow Diagram](https://www.google.com/search?q=%23-process-flow-diagram)
  * [📂 Project Structure](https://www.google.com/search?q=%23-project-structure)
  * [⚙️ How to Build and Run](https://www.google.com/search?q=%23%EF%B8%8F-how-to-build-and-run)
  * [🤝 Contributors](https://www.google.com/search?q=%23-contributors)

-----

## 💡 Core Concepts

In ScroogeCoin, a central entity named Scrooge receives transactions, organizes them into blocks, validates them, and publishes the ledger.

  * **Transactions**: A transaction consists of inputs and outputs.
      * ***Inputs*** claim outputs from previous transactions. Each input must contain a valid digital signature to prove ownership.
      * ***Outputs*** specify a value and the public key of the recipient.
  * **UTXO (Unspent Transaction Output)**: Represents a spendable coin. The collection of all current UTXOs is managed in a `UTXOPool`.
  * **The Challenge**: Transactions within a single block can reference each other or attempt to spend the same output (a double-spend). This means transactions cannot be validated in isolation, and the main challenge is to select a mutually valid subset of transactions from a given pool.

-----

## ✨ Features

This project implements the `TxHandler` class, which serves as Scrooge's logic engine.

### `isValidTx(Transaction tx)`

A method that validates a single transaction based on **five critical rules**:

1.  All outputs claimed by the transaction's inputs must be in the current UTXO pool.
2.  The signatures on each input must be valid.
3.  No UTXO can be claimed multiple times within the same transaction.
4.  All output values must be non-negative.
5.  The sum of the input values must be greater than or equal to the sum of the output values.

### `handleTxs(Transaction[] possibleTxs)`

A method to process a block of potential transactions.

  * It returns a **mutually valid transaction set of maximal size** (one that can't be enlarged by simply adding more transactions from the pool).
  * It updates its internal UTXO pool to reflect the spent and newly created coins from the accepted transactions.

-----

## 🌊 Process Flow Diagram

The core logic of this project is in the `handleTxs` method. Because some transactions may depend on the outputs of other transactions within the same block, the handler must loop over the list multiple times. It continues looping and adding valid transactions until a full pass is completed where no new transactions can be accepted.

This diagram illustrates the workflow:

```mermaid
graph TD
    A[Start handleTxs] --> B[Initialize empty 'acceptedTxs' list];
    B --> C{Loop as long as new transactions were added in the previous pass};
    C --► Pass Begins --> D[Iterate through all 'possibleTxs'];
    D --> E{Is the current transaction<br>valid AND not yet accepted?};
    E -- Yes --> F[1. Add tx to 'acceptedTxs'<br>2. Update the UTXO Pool<br>3. Note that a change was made this pass];
    F --> D;
    E -- No --> D;
    C -- No more transactions added in a full pass --> G[Return 'acceptedTxs' list];
    G --> H[End];
```

-----

## 📂 Project Structure

```
Scrooge-Coin-with-Cpp/
|-- include/              # Header files (.hpp)
|   |-- Transaction.hpp
|   |-- TxHandler.hpp
|   |-- UTXO.hpp
|   |-- UTXOPool.hpp
|-- src/                  # Source files (.cpp)
|   |-- main.cpp
|   |-- Transaction.cpp
|   |-- TxHandler.cpp
|   |-- UTXOPool.cpp
|-- build/                # Created by CMake for compiled files
|-- CMakeLists.txt        # Build instructions for CMake
|-- README.md             # This file
```

-----

## ⚙️ How to Build and Run

### Prerequisites

  * A C++ compiler (g++, Clang, etc.)
  * CMake (version 3.10 or higher)

### Instructions

1.  **Clone the repository.**

2.  **Create a build directory.** Open a terminal in the project's root folder (`Scrooge-Coin-with-Cpp/`) and run:

    ```bash
    mkdir build
    cd build
    ```

3.  **Configure the project with CMake.**

    ```bash
    cmake ..
    ```

4.  **Compile the code.**

    ```bash
    make
    ```

5.  **Run the simulation\!**

    ```bash
    ./scrooge_coin
    ```

-----

## 🤝 Contributors

  * **Jeet Pandya** - *Initial Work* - [GitHub Profile](https://www.google.com/search?q=https://github.com/JEET090806)
