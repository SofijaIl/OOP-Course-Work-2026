#ifndef LOAN_H
#define LOAN_H

#include <string>

class Loan {
private:
    std::string memberId;
    std::string itemId;
    std::string dueDate;
public:
    Loan(const std::string& memberId, const std::string& itemId,
         const std::string& dueDate);

    std::string getMemberId() const;
    std::string getItemId() const;
    std::string getDueDate() const;

    void displayInfo() const;
};

#endif