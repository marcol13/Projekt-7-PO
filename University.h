#pragma once
#include <iostream>
#include <fstream>

class University {
private:
    std::string collage_name;
    std::string address;
protected:
    static std::string class_name;
public: 

    University();
    virtual ~University();
    virtual void showAtributes() = 0;
    std::string getCollageName();
    std::string getCollageAddress();
    static std::string getClassName();
};