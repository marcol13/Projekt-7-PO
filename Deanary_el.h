#pragma once
#include <iostream>
#include "University.h"

class Deanary_el : virtual public University {
private:
    static int field_amount;
    static std::string depart_name;
    static std::string office_address;
protected:
    static std::string class_name;
public:
    Deanary_el();
    virtual ~Deanary_el();
    static std::string getClassName();
    static std::string getDepartName();
    static std::string getDepartAddress();
};