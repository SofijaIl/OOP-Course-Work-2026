#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"

class EBook : public Book {
private:
    std::string fileFormat;
    double fileSizeMB;

public:
    EBook(const std::string& title, const std::string& id,
          const std::string& author, const std::string& isbn,
          const std::string& language, int copies,
          const std::string& fileFormat, double fileSizeMB);

    std::string getFileFormat() const;
    double getFileSizeMB() const;

    void displayInfo() const override;
    std::string getType() const override;
};

#endif