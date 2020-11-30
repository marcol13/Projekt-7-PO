#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

#include "Institute_inf.h"
#include "Institute_el.h"
#include "Institute_mch.h"
#include "Institute_phs.h"
#include "Institute_rc.h"
#include "Institute_rt.h"
#include "Study.h"

class Interface{
private:
	std::string cmds[11] = { "CD", "MO", "DO", "MDO", "DIR", "SHOW", "SAVE", "READ", "TREE", "EXIT", "HELP" };
	std::string node[11] = { "University", "Deanary_el", "Deanary_bm", "Deanary_bl", "Institute_inf", "Institute_el", "Institute_mch", "Institute_phs", "Institute_rc", "Institute_rt", "Study" };
	std::string node_name[11] = {University::getClassName(), Deanary_el::getClassName(), Deanary_bm::getClassName(), Deanary_bl::getClassName(), Institute_inf::getClassName(), Institute_el::getClassName(), Institute_mch::getClassName(), Institute_phs::getClassName(), Institute_rc::getClassName(), Institute_rt::getClassName(), Study::getClassName()};
	std::string curr_pos = node[0];

protected:
	bool is_leaf = false;

public:
	bool end_app = false;
	Interface();
	~Interface();
	void help();
	void exit();
	void getCommand();
	void showDirectory();
	void saveToFile(std::string);
	void readFromFile(std::string);
	void tree();
};