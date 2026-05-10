#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include "LibraryItem.h"

class Newspaper : public LibraryItem {
private:
    std::string publisher;
    std::string date;

public:
    Newspaper(const std::string& title, const std::string& id,
              const std::string& publisher, const std::string& date, const std::string& language, int copies);

    std::string getPublisher() const;
    std::string getDate() const;

    void displayInfo() const override;
    std::string getType() const override;
};

#endif