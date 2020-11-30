#pragma once
#include <iostream>
#include <fstream>
#include "Deanary_el.h"
#include "LeafArray.h"

class Institute_inf : public Deanary_el, public LeafArray<Institute_inf> {
private:
    static int worker_amount;
    std::string name, title, email, phone;
    int thesis_amount;
protected:
    static std::string class_name;
public:
    Institute_inf(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount);
    ~Institute_inf();
    virtual void showAtributes();
    static int getWorkerAmount();
    static std::string getClassName();
    void modifyObject(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount);
    void saveToFile(std::fstream&);
    std::string getName();
    std::string getTitle();
    std::string getEmail();
    std::string getPhone();
    int getThesisAmount();
};

std::ostream& operator<<(std::ostream& os, Institute_inf& el);