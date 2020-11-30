#pragma once
#include <iostream>
#include <fstream>
#include "Deanary_bm.h"
#include "LeafArray.h"

class Institute_mch : public Deanary_bm, public LeafArray<Institute_mch> {
private:
    static int worker_amount;
    std::string name, title, email, phone;
    int thesis_amount;
protected:
    static std::string class_name;
public:
    Institute_mch(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount);
    ~Institute_mch();
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

std::ostream& operator<<(std::ostream& os, Institute_mch& el);