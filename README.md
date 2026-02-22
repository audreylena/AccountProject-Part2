C++ Banking System – Version 2

An improved and refactored version of my original Bank Account System project.
This iteration focuses on cleaner architecture, stronger object-oriented design, and better modular code organization.

Overview

This project simulates a simple banking system using C++.
Users can create accounts, manage balances, and interact with account operations through a console interface.

The system is structured using multiple header and implementation files to demonstrate proper separation of interface and implementation.

Key Concepts Demonstrated

Object-Oriented Programming

Encapsulation and class design

Multi-file project structure

Header and source file separation

Input validation and user interaction

Makefile-based compilation

Improvements From Previous Version

Refactored class relationships for clearer structure

Improved modularization across .h and .cpp files

Cleaner separation of system logic and account logic

Improved readability and organization

Expanded functionality and validation handling

This version reflects iteration and code refinement based on lessons learned from the initial implementation.

Project Structure
├── Account.h
├── Account.cpp
├── Accounts.h
├── Accounts.cpp
├── AccountSystems.h
├── AccountSystems.cpp
├── main.cpp
└── Makefile
How to Compile and Run

Using the provided Makefile:

make
./banking_system

If compiling manually:

g++ main.cpp Account.cpp Accounts.cpp AccountSystems.cpp -o banking_system
./banking_system
What I Learned

Through building and improving this project, I strengthened my understanding of:

Designing systems with multiple interacting classes

Managing compilation across multiple source files

Refactoring code for clarity and maintainability

Writing more organized and scalable C++ programs

Status

Completed core functionality.
Future improvements could include file persistence, enhanced error handling, and expanded account types.
