#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

class Book : public LibraryItem {
protected:
    std::string author;
    std::string isbn;        //International Standard Book Number
    

public:
    Book(const std::string& title, const std::string& id,
         const std::string& author, const std::string& isbn, const std::string& language, int copies);

    std::string getAuthor() const;
    std::string getIsbn() const;

    void displayInfo() const override;
    std::string getType() const override;
};

#endif