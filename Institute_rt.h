#pragma once
#include <iostream>
#include <fstream>
#include "Deanary_bl.h"
#include "LeafArray.h"

class Institute_rt : public Deanary_bl, public LeafArray<Institute_rt> {
private:
    static int worker_amount;
    std::string name, title, email, phone;
    int thesis_amount;
protected:
    static std::string class_name;
public:
    Institute_rt(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount);
    ~Institute_rt();
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

std::ostream& operator<<(std::ostream& os, Institute_rt& el);