#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"

class Magazine : public LibraryItem {
private:
    std::string publisher;
    int issueNum;

public:
    Magazine(const std::string& title, const std::string& id,
             const std::string& publisher, int issueNum, const std::string& language, int copies);

    std::string getPublisher() const;
    int getIssueNum() const;
    void displayInfo() const override;
    std::string getType() const override;
};
#endif