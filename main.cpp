#include <iostream>
#include <memory>
#include <string>
#include <limits>

#include "Library.h"
#include "Book.h"
#include "EBook.h"
#include "Magazine.h"
#include "Newspaper.h"
#include "Member.h"
#include "Utils.h"

void showMenu() {
    std::cout << "\n===== LIBRARY MENU =====" << std::endl;
    std::cout << "1.  Display all items" << std::endl;
    std::cout << "2.  Search by title" << std::endl;
    std::cout << "3.  Sort items by title" << std::endl;
    std::cout << "4.  Add a Book" << std::endl;
    std::cout << "5.  Add an EBook" << std::endl;
    std::cout << "6.  Add a Magazine" << std::endl;
    std::cout << "7.  Add a Newspaper" << std::endl;
    std::cout << "8.  Add a Member" << std::endl;
    std::cout << "9.  Borrow an item" << std::endl;
    std::cout << "10. Return an item" << std::endl;
    std::cout << "11. Display all members" << std::endl;
    std::cout << "12. Display all loans" << std::endl;
    std::cout << "13. Count available items" << std::endl;
    std::cout << "0.  Exit" << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "Choose: ";
}

int main() {

    Library library;

    // --- preload some data so library is not empty ---
    library.addItem(std::make_unique<Book>(
        "The Hobbit", "B001", "J.R.R. Tolkien", "9780044403371", "Lithuanian", 2));
    library.addItem(std::make_unique<Book>(
        "Clean Code", "B002", "Robert Cecil Martin", "978-0132350884", "English", 3));
    library.addItem(std::make_unique<EBook>(
        "The C++ Programming Language", "E001",
        "Bjarne Stroustrup", "978-0321563842", "English", 1, "PDF", 12.5));
    library.addItem(std::make_unique<Magazine>(
        "National Geographic", "M001", "Nat Geo Partners", 215, "English", 5));
    library.addItem(std::make_unique<Newspaper>(
        "The Times", "N001", "Times Media Limited", "2026-05-09", "English", 10));
    library.addMember(Member("Alice Smith", "MEM001"));
    library.addMember(Member("Bob Jones", "MEM002"));

    std::cout << "Welcome to the Library System!" << std::endl;
    std::cout << "Library loaded with default items and members." << std::endl;

    int choice = -1;

    while (choice != 0) {

        showMenu();
        std::cin >> choice;

        // handle bad input (letters instead of numbers)
        if (std::cin.fail()) {
            std::cin.clear();                                                          //so cin can be used again
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');        //removes evrthing remaining in the input, until a newline
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;                                                                  //asks for input again
        }
        std::cin.ignore(); // clear leftover newline after number

        // ---- handle each choice ----
        if (choice == 1) {
            // --- display all items ---
            std::cout << "\n=== All Items ===" << std::endl;
            library.displayAllItems();

        } else if (choice == 2) {
            // --- search ---
            std::cout << "Enter title (or word from it) always start with a capital letter: ";
            std::string title;
            std::getline(std::cin, title);
            std::cout << "\n=== Search Results ===" << std::endl;
            library.searchByTitle(title);
        } 
        else if (choice == 3) {
            // --- sort ---
            library.sortByTitle();
            library.displayAllItems();
        } 
        else if (choice == 4) {
            // --- add book ---
            std::string title, id, author, isbn, language;
            int copies;

            std::cout << "Title: ";       std::getline(std::cin, title);
            std::cout << "create new ID (B - for book, for e. g. B003): "; std::getline(std::cin, id);
            std::cout << "Author: ";      std::getline(std::cin, author);
            std::cout << "ISBN: ";        std::getline(std::cin, isbn);
            std::cout << "Language: ";    std::getline(std::cin, language);
            std::cout << "Copies: ";      std::cin >> copies;
            std::cin.ignore();

            try {
                library.addItem(std::make_unique<Book>(
                    title, id, author, isbn, language, copies));
                std::cout << "Book added successfully." << std::endl;
            } 
            catch (const std::invalid_argument& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
         else if (choice == 5) {
            // --- add ebook ---
            std::string title, id, author, isbn, language, format;
            int copies;
            double size;

            std::cout << "Title: ";       std::getline(std::cin, title);
            std::cout << "ID (e.g. E002): "; std::getline(std::cin, id);
            std::cout << "Author: ";      std::getline(std::cin, author);
            std::cout << "ISBN: ";        std::getline(std::cin, isbn);
            std::cout << "Language: ";    std::getline(std::cin, language);
            std::cout << "Copies: ";      std::cin >> copies; std::cin.ignore();
            std::cout << "File format (PDF/EPUB): "; std::getline(std::cin, format);
            std::cout << "File size (MB): "; std::cin >> size; std::cin.ignore();

            try {
                library.addItem(std::make_unique<EBook>(
                    title, id, author, isbn, language, copies, format, size));
                std::cout << "EBook added successfully." << std::endl;
            } 
            catch (const std::invalid_argument& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
         else if (choice == 6) {
            // --- add magazine ---
            std::string title, id, publisher, language;
            int issueNum, copies;

            std::cout << "Title: ";         std::getline(std::cin, title);
            std::cout << "ID (e.g. M002): "; std::getline(std::cin, id);
            std::cout << "Publisher: ";     std::getline(std::cin, publisher);
            std::cout << "Issue number: ";  std::cin >> issueNum; std::cin.ignore();
            std::cout << "Language: ";      std::getline(std::cin, language);
            std::cout << "Copies: ";        std::cin >> copies; std::cin.ignore();

            try {
                library.addItem(std::make_unique<Magazine>(
                    title, id, publisher, issueNum, language, copies));
                std::cout << "Magazine added successfully." << std::endl;
            } 
            catch (const std::invalid_argument& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
        else if (choice == 7) {
            // --- add newspaper ---
            std::string title, id, publisher, date, language;
            int copies;

            std::cout << "Title: ";         std::getline(std::cin, title);
            std::cout << "ID (e.g. N002): "; std::getline(std::cin, id);
            std::cout << "Publisher: ";     std::getline(std::cin, publisher);
            std::cout << "Date (YYYY-MM-DD): "; std::getline(std::cin, date);
            std::cout << "Language: ";      std::getline(std::cin, language);
            std::cout << "Copies: ";        std::cin >> copies; std::cin.ignore();

            try {
                library.addItem(std::make_unique<Newspaper>(
                    title, id, publisher, date, language, copies));
                std::cout << "Newspaper added successfully." << std::endl;
            } 
            catch (const std::invalid_argument& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        } 
        else if (choice == 8) {
            // --- add member ---
            std::string name, memberId;

            std::cout << "Member name, surname: ";   std::getline(std::cin, name);
            std::cout << "Member ID (e.g. MEM003): "; std::getline(std::cin, memberId);

            try {
                library.addMember(Member(name, memberId));
                std::cout << "Member added successfully." << std::endl;
            } catch (const std::invalid_argument& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        } 
        else if (choice == 9) {
            // --- borrow ---
            std::string memberId, itemId, dueDate;

            std::cout << "Member ID: ";   std::getline(std::cin, memberId);
            std::cout << "Item ID: ";     std::getline(std::cin, itemId);
            std::cout << "Due date (YYYY-MM-DD): "; std::getline(std::cin, dueDate);

            try {                                  //Code that may fail
                library.borrowItem(memberId, itemId, dueDate);
            } 
            catch (const std::runtime_error& e) {  //Handle the error
                std::cout << "Error: " << e.what() << std::endl;
            }
        } 
        else if (choice == 10) {
            // --- return ---
            std::string memberId, itemId;

            std::cout << "Member ID: "; std::getline(std::cin, memberId);
            std::cout << "Item ID: ";   std::getline(std::cin, itemId);

            try {
                library.returnItem(memberId, itemId);
            } 
            catch (const std::runtime_error& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        } 
        else if (choice == 11) {
            // --- display members ---
            std::cout << "\n=== Members ===" << std::endl;
            library.displayAllMembers(); 
        } 
        else if (choice == 12) {
            // --- display loans ---
            std::cout << "\n=== Active Loans ===" << std::endl;
            library.displayAllLoans();
        }
         else if (choice == 13) {
            // --- count available ---
            std::cout << "\nAvailable items: " << library.countAvailable() << std::endl;
        }
         else if (choice == 0) {
            std::cout << "Goodbye!" << std::endl;
        }
         else {
            std::cout << "Unknown command. Choose 0-13." << std::endl;
        }
    }
    return 0;
}