#pragma once
#include <iostream>
#include "University.h"

class Deanary_bm : virtual public University {
private:
    static int field_amount;
    static std::string depart_name;
    static std::string office_address;
protected:
    static std::string class_name;
public:
    Deanary_bm();
    virtual ~Deanary_bm();
    static std::string getClassName();
    static std::string getDepartName();
    static std::string getDepartAddress();
};