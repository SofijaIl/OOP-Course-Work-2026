# OOP Course Work 2026: Library Management System

Done by: Sofija Iljinaite, student of ITfu-25/1

## What This Project Does

A C++ console application for managing a library.
It stores different item types (books, ebooks, magazines, newspapers),
lets members borrow and return items, tracks active loans,
and supports searching and sorting by title.
The program runs as an interactive menu — the user chooses
an action by number and the program asks for the required input.


## Class Structure
LibraryItem → Book → EBook (2 levels)
LibraryItem → Magazine
LibraryItem → Newspaper


## Classes

- `LibraryItem` — abstract base class, declares pure virtual displayInfo() and getType()
- `Book` — adds author and ISBN
- `EBook` — extends Book, adds file format and file size
- `Magazine` — adds publisher and issue number
- `Newspaper` — adds publisher and date
- `Member` — library user, tracks borrowed item IDs
- `Loan` — records which member borrowed which item and the due date
- `Library` — manages all collections and operations


## Project Files

- `main.cpp` — interactive menu, program entry point
- `LibraryItem.h` / `LibraryItem.cpp` — abstract base class
- `Book.h` / `Book.cpp` — book implementation
- `EBook.h` / `EBook.cpp` — ebook implementation
- `Magazine.h` / `Magazine.cpp` — magazine implementation
- `Newspaper.h` / `Newspaper.cpp` — newspaper implementation
- `Member.h` / `Member.cpp` — library member implementation
- `Loan.h` / `Loan.cpp` — loan record implementation
- `Library.h` / `Library.cpp` — library container and algorithms
- `Utils.h` — generic helper template for printing collections


## How to Build
g++ -std=c++17 *.cpp -o app

## How to Run
.\app


## How the Program Works

1. `main.cpp` creates a `Library` object and preloads default data
2. An interactive menu is shown with 13 options
3. The user enters a number to choose an action
4. The program asks for the required input (title, ID, language, copies etc.)
5. The action is executed and the menu appears again
6. When `displayInfo()` is called, the correct overridden version
   is selected based on the real object type — Book, EBook, Magazine or Newspaper
7. The user enters 0 to exit


## Features

- Add books, ebooks, magazines and newspapers with language and copy count
- Add library members
- Borrow and return items with due date tracking
- Search items by partial title match
- Sort all items alphabetically by title
- Display all items, members and active loans
- Count available items
- Interactive numbered menu — no need to edit code to use the system


## Criteria Met

1. **Polymorphism** — LibraryItem → Book → EBook gives two levels of inheritance.
   Pure virtual displayInfo() is overridden in every derived class.
2. **Separate files** — every class has its own .h and .cpp file
3. **STL container** — std::vector<std::unique_ptr<LibraryItem>> in Library
4. **Algorithms** — std::sort, std::find_if, std::count_if
5. **Exceptions** — invalid input rejected in every constructor,
   runtime errors thrown when item not found or already borrowed
6. **Useful domain** — real library borrowing system with interactive menu
7. **Bonus** — Utils.h defines a generic template function printAll()
The program loads default items and members automatically, then presents
an interactive menu. The user chooses an action by number and the program
asks for all required input to complete it.

## Criteria Mapping

### 1. Polymorphism with at least two levels of inheritance and at least four separate classes

Implemented through this inheritance chain:

- `LibraryItem`
- `Book : public LibraryItem`
- `EBook : public Book`
- `Magazine : public LibraryItem`
- `Newspaper : public LibraryItem`

Two inheritance levels:
- level 1: `LibraryItem -> Book`, `LibraryItem -> Magazine`, `LibraryItem -> Newspaper`
- level 2: `Book -> EBook`

Polymorphism is used through:
- pure virtual functions `displayInfo()` and `getType()` in `LibraryItem`
- overridden `displayInfo()` and `getType()` in every derived class
- storage of derived objects through base-class pointers:
  Expl: `std::vector<std::unique_ptr<LibraryItem>>`
  This is a vector of pointers to the base class `LibraryItem`. 
  However, it contains objects of child classes —`Book`, `eBook`, `Magazine`,`Newspaper`.


### 2. Classes declared and defined in separate header/source files

Implemented by separating declarations and definitions:
- declarations in `.h` files
- definitions in `.cpp` files

Examples:
- `LibraryItem.h` and `LibraryItem.cpp`
- `Book.h` and `Book.cpp`


### 3. At least one standard library container and at least two algorithms

Standard library container used:
- `std::vector<std::unique_ptr<LibraryItem>>` in `Library`

Algorithms used:
- `std::sort` in `Library::sortByTitle()`
- `std::find_if` in `Library::borrowItem()`, `Library::returnItem()`, `Library::searchByTitle()`
- `std::count_if` in `Library::countAvailable()`


### 4. Error management with at least 1 exception handling case

Exception handling is used in multiple places.

Validation with exceptions:
- empty title throws `std::invalid_argument` in `LibraryItem`
- empty ID throws `std::invalid_argument` in `LibraryItem`
- empty language throws `std::invalid_argument` in `LibraryItem`
- zero or negative copies throws `std::invalid_argument` in `LibraryItem`
- empty author throws `std::invalid_argument` in `Book`
- empty ISBN throws `std::invalid_argument` in `Book`
- negative file size throws `std::invalid_argument` in `EBook`
- negative issue number throws `std::invalid_argument` in `Magazine`
- item not found throws `std::runtime_error` in `Library::borrowItem()`
- item already borrowed throws `std::runtime_error` in `Library::borrowItem()`
- member not found throws `std::runtime_error` in `Library::borrowItem()`
- loan not found throws `std::runtime_error` in `Library::returnItem()`

Handling exceptions:
- `main.cpp` uses `try` / `catch` blocks for all add and borrow/return operations


### 5. The software should perform a reasonably useful function

The program performs a useful real-world task: managing a library system.
It can:
- keep different item types in one system
- track which members have borrowed which items
- record and display due dates for borrowed items
- search the catalogue by partial title
- sort the catalogue alphabetically
- count how many items are currently available


## Bonus: User-Defined Generic Functionality

The bonus requirement is implemented in `Utils.h`:

```cpp
template <typename T>
void printAll(const T& collection)
```

This is a custom template function that works with any collection. Instead of writing a separate print function for books, magazines and newspapers — 1 template handles all of them. As long as the items inside have a `displayInfo()` method, the function will work.


## Example Summary of Output

When the program runs successfully, the menu allows:

- 5 default items loaded at startup (2 books, 1 ebook, 1 magazine, 1 newspaper)
- 2 default members loaded at startup
- items displayed before and after sorting
- partial title search returning all matching results
- successful borrow with due date recorded
- failed borrow of already borrowed item caught by exception
- successful return marking item as available again
- active loans displayed with member ID, item ID and due date

## Conclusion

This project fulfills all the coursework requirements and includes the bonus template. The code shows how different item types can share a common base class, how the right method gets called automatically at runtime, how STL containers and algorithms work in practice, and how exceptions protect against bad input — all wrapped in a working interactive library system.