#pragma once
#include <iostream>
#include <fstream>
#include "Deanary_el.h"
#include "Deanary_bm.h"
#include "Deanary_bl.h"
#include "LeafArray.h"

class Study : public Deanary_el, public Deanary_bm, public Deanary_bl, public LeafArray<Study> {
private:
    static int worker_amount;
    std::string name, title, email, phone, language;
    int thesis_amount;
protected:
    static std::string class_name;
public:
    Study(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount, const std::string& language);
    ~Study();
    virtual void showAtributes();
    static int getWorkerAmount();
    static std::string getClassName();
    void modifyObject(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount, const std::string& language);
    void saveToFile(std::fstream&);
    std::string getName();
    std::string getTitle();
    std::string getEmail();
    std::string getPhone();
    std::string getLanguage();
    int getThesisAmount();
};

std::ostream& operator<<(std::ostream& os, Study& el);