# Network Security Lab

This repository contains simple C++ implementations of classical encryption and decryption algorithms for undergraduate Network Security Lab coursework.

## 📚 Implemented Ciphers

| No. | Cipher                | Main Concept                               |
| --- | --------------------- | ------------------------------------------ |
| 1   | Additive Cipher       | Shifting letters using a fixed key         |
| 2   | Multiplicative Cipher | Multiplying letter positions by a key      |
| 3   | Affine Cipher         | Combining multiplication and addition      |
| 4   | Autokey Cipher        | Generating later key values from plaintext |

## 📁 Suggested project structure

Organize the source files as follows:

```text
network-security-lab/
├── README.md
├── additive.cpp
├── multiplicative.cpp
├── affine.cpp
└── autokey.cpp
```

The filenames above are suggested names. Rename the source files or commands to match your actual repository.

## ⚙️ Requirements

You need a C++ compiler such as `g++`.

Check whether it is installed by running:

```bash
g++ --version
```

If the command is not recognized, install a C++ compiler or configure its PATH before continuing.

## 📄 License

Unless a license is added to this repository, all rights remain with the copyright holder. You may add an MIT License if you want others to reuse and modify the code under its terms.
