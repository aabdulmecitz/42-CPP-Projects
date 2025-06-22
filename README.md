# C++ Modules

<p align="center">
  <img src="https://media2.giphy.com/media/v1.Y2lkPTc5MGI3NjExd3N0Y2NkZWw5bjF5ZTZxeTJ4YTBiaGJtaHVmbGlmd2didnpyMWwzeCZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/qqDVCetD9mhYLyoies/giphy.gif" alt="Coding GIF"/>
</p>

This repository contains a series of C++ modules, each focusing on different aspects of the language, from the very basics to more advanced concepts. These exercises are part of the 42 school curriculum.

## Cpp00: A-maze-ing

This module covers the fundamentals of C++, including classes, member functions, and basic input/output.

*   **ex00: Megaphone**: A simple program that converts command-line arguments to uppercase. If no arguments are provided, it prints "* LOUD AND UNBEARABLE FEEDBACK NOISE *".
*   **ex01: My Awesome PhoneBook**: A basic phonebook implementation.
    *   It uses a `Contact` class to store details like first name, last name, nickname, phone number, and darkest secret.
    *   The `PhoneBook` class manages an array of up to 8 contacts.
    *   It responds to three commands:
        *   `ADD`: Prompts for and saves a new contact. If the phonebook is full, the oldest contact is replaced.
        *   `SEARCH`: Displays a list of saved contacts with truncated information, then prompts for an index to show full details for a specific contact.
        *   `EXIT`: Quits the program.
*   **ex02: The Job Of Your Dreams**: A simulation of bank account management.
    *   The `Account` class tracks deposits and withdrawals.
    *   It uses static members to keep track of the total number of accounts, the total balance across all accounts, and the total number of deposits and withdrawals.
    *   Timestamps are logged for every transaction, demonstrating the use of `std::chrono`.

## Cpp01: Memory allocation, references, pointers to members

This module delves into memory management, pointers, references, and the `new` and `delete` keywords.

*   **ex00: BraiiiiiiinnnzzzZ**: Demonstrates the difference between stack and heap memory allocation for objects.
    *   A `Zombie` object is created on the stack.
    *   The `newZombie()` function allocates a `Zombie` on the heap.
    *   The `randomChump()` function creates a temporary `Zombie` on the stack.
*   **ex01: Moar brainz!**: Introduces dynamic allocation of an array of objects.
    *   The `zombieHorde()` function creates a horde of `N` `Zombie` objects in a single allocation on the heap. Each zombie is initialized with a unique name.
*   **ex02: HI THIS IS BRAIN**: Illustrates the core concepts of pointers and references.
    *   It declares a string, a pointer to the string, and a reference to the string.
    *   It then prints the memory addresses and the values held by each, highlighting that a reference is an alias for a variable and shares the same memory address.
*   **ex03: Unnecessary violence**: A program that showcases the practical differences between using references and pointers as members in a class.
    *   `HumanA` is armed at construction with a `Weapon` reference, meaning it must always have a weapon.
    *   `HumanB` is initialized with a `Weapon` pointer, allowing it to start unarmed and acquire a weapon later.
*   **ex04: Sed is for losers**: A utility that replaces occurrences of a string within a file.
    *   It takes a filename and two strings, `s1` and `s2`, as arguments.
    *   It reads the content of the input file, replaces all occurrences of `s1` with `s2`, and writes the result to a new file named `<filename>.replace`.
*   **ex05: Harl**: A program that uses an array of pointers to member functions to handle different levels of complaints.
    *   The `Harl` class has private member functions for `DEBUG`, `INFO`, `WARNING`, and `ERROR` levels.
    *   A public `complain()` method calls the appropriate function based on the input string.
*   **ex06: Harl Filter**: An improved version of Harl that filters messages based on a specified level.
    *   It takes a single command-line argument representing the minimum complaint level.
    *   It then displays messages for that level and all more critical levels, using a `switch` statement with fall-through logic.

