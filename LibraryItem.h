#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>

class LibraryItem {
protected:                   //not accessible from outside, but are accessible from child classes
    std::string title;
    std::string Id;
    bool available;
    std::string language; 
    int copies;   

public:
    LibraryItem(const std::string& title, const std::string& Id, const std::string& language, int copies);

    virtual ~LibraryItem() = default;        // Destructor - safe cleanup
    std::string getTitle() const;
    std::string getItemId() const;
    bool isAvailable() const;                 
    void setAvailable(bool status);           //change availability
    std::string getLanguage() const;

    virtual void displayInfo() const = 0;     //child class MUST override this 
    virtual std::string getType() const = 0;
};

#endif