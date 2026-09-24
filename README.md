# Address Book Management System

A terminal-based Address Book Management System developed in C.  
The project allows users to manage contacts and store contact information using CSV file handling.

## Features

- Add new contacts
- List all contacts
- Search contacts
- Edit contacts
- Delete contacts
- Save contacts to a CSV file
- Load existing contacts from the CSV file
- Input validation for phone numbers and email addresses

## Project Structure

```text
AddressBook-C/
│
├── main.c
├── addressbook.h
├── addcontact.c
├── editcontact.c
├── deletecontact.c
├── listcontact.c
├── searchcontact.c
├── todatabase.c
├── database.csv
└── .gitignore
```

## Compilation

Compile all C source files using GCC:

```bash
gcc *.c -o addressbook
```

## Run

Run the compiled program:

```bash
./addressbook
```

## How to Use

1. Compile the source files using GCC.
2. Run the generated executable.
3. Select an option from the menu.
4. Add, search, edit, delete, or list contacts.
5. Contact information is stored in `database.csv`.

## Data Storage

The project uses a CSV file to store contact information.

The `database.csv` file allows contacts to be retained between program executions.

## Concepts Practiced

This project was developed to practice:

- C Programming
- Structures
- Arrays
- Pointers
- Functions
- File Handling
- CSV File Handling
- String Handling
- Input Validation
- Modular Programming

## Requirements

- GCC Compiler
- Linux / WSL / Unix-like environment

## Author

**Kushal M**
