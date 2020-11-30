#include "Interface.h"

Interface::Interface()
{
	std::cout << "Witaj w programie!" << std::endl;
	std::cout << "Wpisz HELP aby uzyskac pomoc" << std::endl << "-----" << std::endl;
}

Interface::~Interface()
{
}

void Interface::help()
{
	std::cout << "Mozliwe operacje:" << std::endl;
	std::cout << "CD <nazwa_klasy> - przejscie do odpowiedniego wezla" << std::endl;
	std::cout << "MO <imie> <nazwisko> <tytul> <email> <telefon> <ilosc_artykulow_naukowych> <<jezyk>> - dodanie obiektu - DOTYCZY TYLKO LISCI" << std::endl;
	std::cout << "DO <imie> <nazwisko> - usuwa obiekt - DOTYCZY TYLKO LISCI" << std::endl;
	std::cout << "MDO <imie> <nazwisko> <mod_imie> <mod_nazwisko> <mod_tytul> <mod_email> <mod_telefon> <mod_ilosc_artykulow_naukowych> <<jezyk>> - modyfikuje obiekt - DOTYCZY TYLKO LISCI" << std::endl;
	std::cout << "DIR - wyswietla wszystkie obiekty nalezace do danego wezla" << std::endl;
	std::cout << "SHOW <imie> <nazwisko> - wyswietla wszystkie informacje o obiekcie - DOTYCZY TYLKO LISCI" << std::endl;
	std::cout << "SAVE <nazwa_pliku>.txt - zapisuje obiekty do pliku" << std::endl;
	std::cout << "READ <nazwa_pliku>.txt - odczytuje obiekty z pliku" << std::endl;
	std::cout << "TREE - wyswietla strukture drzewa klas w projekcie" << std::endl;
	std::cout << "EXIT - wyjscie z programu" << std::endl;
}

void Interface::exit()
{
	end_app = true;
}

void Interface::getCommand()
{
	std::string text, temp, cmd;
	std::string cmd_args[9];
	getline(std::cin, text);
	int i = 0, ppos = 0;
	int args = 0;
	bool correct_cmd = false;
	while (i <= text.size()) {
		if (text[i] == (char)32 || i == text.size()) {
			temp = text.substr(ppos, i - ppos);
			ppos = i + 1;
			if (args == 0) {
				for (int j = 0; j < 11; j++) {
					if (temp == cmds[j]) {
						correct_cmd = true;
						cmd = temp;
					}
				}
				if (correct_cmd == false) {
					std::cout << "Bledna komenda! Wpisz HELP aby uzyskac pomoc..." << std::endl;
					break;
				}
			}
			else {
				cmd_args[args - 1] = temp;
			}
			args++;
		}
		i++;
	}
	if (correct_cmd == true) {
		if (cmd == "CD") {
			bool is_node = false;
			for (int j = 0; j < 11; j++) {
				if (cmd_args[0] == node[j]) {
					is_node = true;
					curr_pos = node[j];
					std::cout << "Jestes w " << curr_pos << std::endl << "-----" << std::endl;
					if (j > 3)
						is_leaf = true;
					else
						is_leaf = false;
				}
			}
			if (is_node == false) {
				std::cout << "Nie ma takiego wezla" << std::endl << "Jestes w " << curr_pos << std::endl << "-----" << std::endl;
			}
		}
		else if (cmd == "MO") {
			if (is_leaf == true) {
				if (curr_pos == "Institute_inf") {
					new Institute_inf(cmd_args[0] + " " + cmd_args[1], cmd_args[2], cmd_args[3], cmd_args[4], stoi(cmd_args[5]));
				}
				else if (curr_pos == "Institute_el") {
					new Institute_el(cmd_args[0] + " " + cmd_args[1], cmd_args[2], cmd_args[3], cmd_args[4], stoi(cmd_args[5]));
				}
				else if (curr_pos == "Institute_mch") {
					new Institute_mch(cmd_args[0] + " " + cmd_args[1], cmd_args[2], cmd_args[3], cmd_args[4], stoi(cmd_args[5]));
				}
				else if (curr_pos == "Institute_phs") {
					new Institute_phs(cmd_args[0] + " " + cmd_args[1], cmd_args[2], cmd_args[3], cmd_args[4], stoi(cmd_args[5]));
				}
				else if (curr_pos == "Institute_rc") {
					new Institute_rc(cmd_args[0] + " " + cmd_args[1], cmd_args[2], cmd_args[3], cmd_args[4], stoi(cmd_args[5]));
				}
				else if (curr_pos == "Institute_rt") {
					new Institute_rt(cmd_args[0] + " " + cmd_args[1], cmd_args[2], cmd_args[3], cmd_args[4], stoi(cmd_args[5]));
				}
				else if (curr_pos == "Study") {
					new Study(cmd_args[0] + " " + cmd_args[1], cmd_args[2], cmd_args[3], cmd_args[4], stoi(cmd_args[5]), cmd_args[6]);
				}
			}
			else {
				std::cout << "Nie mozna utworzyc obiektu ktory nie jest lisciem!" << std::endl << "-----" << std::endl;
			}
		}
		else if (cmd == "DO") {
			if (is_leaf == true) {
				if (curr_pos == "Institute_inf") {
					LeafArray<Institute_inf>::removeElement(cmd_args[0] + " " + cmd_args[1]);
				}
				else if (curr_pos == "Institute_el") {
					LeafArray<Institute_el>::removeElement(cmd_args[0] + " " + cmd_args[1]);
				}
				else if (curr_pos == "Institute_mch") {
					LeafArray<Institute_mch>::removeElement(cmd_args[0] + " " + cmd_args[1]);
				}
				else if (curr_pos == "Institute_phs") {
					LeafArray<Institute_phs>::removeElement(cmd_args[0] + " " + cmd_args[1]);
				}
				else if (curr_pos == "Institute_rc") {
					LeafArray<Institute_rc>::removeElement(cmd_args[0] + " " + cmd_args[1]);
				}
				else if (curr_pos == "Institute_rt") {
					LeafArray<Institute_rt>::removeElement(cmd_args[0] + " " + cmd_args[1]);
				}
				else if (curr_pos == "Study") {
					LeafArray<Study>::removeElement(cmd_args[0] + " " + cmd_args[1]);
				}
			}
			else {
				std::cout << "Nie mozna usunac obiektu w miejscu niebedacym lisciem!" << std::endl << "-----" << std::endl;
			}
		}
		else if (cmd == "MDO") {
			if (is_leaf == true) {
				if (curr_pos == "Institute_inf") {
					LeafArray<Institute_inf>::modifyElement(cmd_args[0] + " " + cmd_args[1], cmd_args[2] + " " + cmd_args[3], cmd_args[4], cmd_args[5], cmd_args[6], stoi(cmd_args[7]));
				}
				else if (curr_pos == "Institute_el") {
					LeafArray<Institute_el>::modifyElement(cmd_args[0] + " " + cmd_args[1], cmd_args[2] + " " + cmd_args[3], cmd_args[4], cmd_args[5], cmd_args[6], stoi(cmd_args[7]));
				}
				else if (curr_pos == "Institute_mch") {
					LeafArray<Institute_mch>::modifyElement(cmd_args[0] + " " + cmd_args[1], cmd_args[2] + " " + cmd_args[3], cmd_args[4], cmd_args[5], cmd_args[6], stoi(cmd_args[7]));
				}
				else if (curr_pos == "Institute_phs") {
					LeafArray<Institute_phs>::modifyElement(cmd_args[0] + " " + cmd_args[1], cmd_args[2] + " " + cmd_args[3], cmd_args[4], cmd_args[5], cmd_args[6], stoi(cmd_args[7]));
				}
				else if (curr_pos == "Institute_rc") {
					LeafArray<Institute_rc>::modifyElement(cmd_args[0] + " " + cmd_args[1], cmd_args[2] + " " + cmd_args[3], cmd_args[4], cmd_args[5], cmd_args[6], stoi(cmd_args[7]));
				}
				else if (curr_pos == "Institute_rt") {
					LeafArray<Institute_rt>::modifyElement(cmd_args[0] + " " + cmd_args[1], cmd_args[2] + " " + cmd_args[3], cmd_args[4], cmd_args[5], cmd_args[6], stoi(cmd_args[7]));
				}
				else if (curr_pos == "Study") {
					LeafArray<Study>::modifyStudy(cmd_args[0] + " " + cmd_args[1], cmd_args[2] + " " + cmd_args[3], cmd_args[4], cmd_args[5], cmd_args[6], stoi(cmd_args[7]), cmd_args[8]);
				}
			}
			else {
				std::cout << "Nie mozna zmodyfikowac obiektu w miejscu niebedacym lisciem!" << std::endl << "-----" << std::endl;
			}
		}
		else if (cmd == "SHOW") {
			if (is_leaf == true) {
				std::cout << "-----\n";
				if (curr_pos == "Institute_inf") {
					LeafArray<Institute_inf>::showElement(cmd_args[0] + " " + cmd_args[1]);
				}
				else if (curr_pos == "Institute_el") {
					LeafArray<Institute_el>::showElement(cmd_args[0] + " " + cmd_args[1]);
				}
				else if (curr_pos == "Institute_mch") {
					LeafArray<Institute_mch>::showElement(cmd_args[0] + " " + cmd_args[1]);
				}
				else if (curr_pos == "Institute_phs") {
					LeafArray<Institute_phs>::showElement(cmd_args[0] + " " + cmd_args[1]);
				}
				else if (curr_pos == "Institute_rc") {
					LeafArray<Institute_rc>::showElement(cmd_args[0] + " " + cmd_args[1]);
				}
				else if (curr_pos == "Institute_rt") {
					LeafArray<Institute_rt>::showElement(cmd_args[0] + " " + cmd_args[1]);
				}
				else if (curr_pos == "Study") {
					LeafArray<Study>::showElement(cmd_args[0] + " " + cmd_args[1]);
				}
			}
			else {
				std::cout << "Nie mozna wyswietlac informacji o obiekcie w miejscu niebedacym lisciem!" << std::endl << "-----" << std::endl;
			}
		}
		else if (cmd == "SAVE") {
			saveToFile(cmd_args[0]);
		}
		else if (cmd == "READ") {
			readFromFile(cmd_args[0]);
		}
		else if (cmd == "DIR") {
			showDirectory();
		}
		else if (cmd == "TREE") {
			tree();
		}
		else if (cmd == "HELP") {
			help();
		}
		else if (cmd == "EXIT") {
			exit();
		}
	}
}

void Interface::showDirectory()
{
	int amount = 0;
	if (curr_pos == "University") {
		amount += Institute_inf::getWorkerAmount();
		if (Institute_inf::getWorkerAmount() > 0) {
			std::cout << node_name[4] << ":" << std::endl;
			LeafArray<Institute_inf>::showObjects();
		}
		amount += Institute_el::getWorkerAmount();
		if (Institute_el::getWorkerAmount() > 0) {
			std::cout << node_name[5] << ":" << std::endl;
			LeafArray<Institute_el>::showObjects();
		}
		amount += Institute_mch::getWorkerAmount();
		if (Institute_mch::getWorkerAmount() > 0) {
			std::cout << node_name[6] << ":" << std::endl;
			LeafArray<Institute_mch>::showObjects();
		}
		amount += Institute_phs::getWorkerAmount();
		if (Institute_phs::getWorkerAmount() > 0) {
			std::cout << node_name[7] << ":" << std::endl;
			LeafArray<Institute_phs>::showObjects();
		}
		amount += Institute_rc::getWorkerAmount();
		if (Institute_rc::getWorkerAmount() > 0) {
			std::cout << node_name[8] << ":" << std::endl;
			LeafArray<Institute_rc>::showObjects();
		}
		amount += Institute_rt::getWorkerAmount();
		if (Institute_rt::getWorkerAmount() > 0) {
			std::cout << node_name[9] << ":" << std::endl;
			LeafArray<Institute_rt>::showObjects();
		}
		amount += Study::getWorkerAmount();
		if (Study::getWorkerAmount() > 0) {
			std::cout << node_name[10] << ":" << std::endl;
			LeafArray<Study>::showObjects();
		}
	}
	else if (curr_pos == "Deanary_el") {
		amount += Institute_inf::getWorkerAmount();
		if (Institute_inf::getWorkerAmount() > 0) {
			std::cout << node_name[4] << ":" << std::endl;
			LeafArray<Institute_inf>::showObjects();
		}
		amount += Institute_el::getWorkerAmount();
		if (Institute_el::getWorkerAmount() > 0) {
			std::cout << node_name[5] << ":" << std::endl;
			LeafArray<Institute_el>::showObjects();
		}
		amount += Study::getWorkerAmount();
		if (Study::getWorkerAmount() > 0) {
			std::cout << node_name[10] << ":" << std::endl;
			LeafArray<Study>::showObjects();
		}
	}
	else if (curr_pos == "Deanary_bm") {
		amount += Institute_mch::getWorkerAmount();
		if (Institute_mch::getWorkerAmount() > 0) {
			std::cout << node_name[6] << ":" << std::endl;
			LeafArray<Institute_mch>::showObjects();
		}
		amount += Institute_phs::getWorkerAmount();
		if (Institute_phs::getWorkerAmount() > 0) {
			std::cout << node_name[7] << ":" << std::endl;
			LeafArray<Institute_phs>::showObjects();
		}
		amount += Study::getWorkerAmount();
		if (Study::getWorkerAmount() > 0) {
			std::cout << node_name[10] << ":" << std::endl;
			LeafArray<Study>::showObjects();
		}
	}
	else if (curr_pos == "Deanary_bl") {
		amount += Institute_rc::getWorkerAmount();
		if (Institute_rc::getWorkerAmount() > 0) {
			std::cout << node_name[8] << ":" << std::endl;
			LeafArray<Institute_rc>::showObjects();
		}
		amount += Institute_rt::getWorkerAmount();
		if (Institute_rt::getWorkerAmount() > 0) {
			std::cout << node_name[9] << ":" << std::endl;
			LeafArray<Institute_rt>::showObjects();
		}
		amount += Study::getWorkerAmount();
		if (Study::getWorkerAmount() > 0) {
			std::cout << node_name[10] << ":" << std::endl;
			LeafArray<Study>::showObjects();
		}
	}
	else if (curr_pos == "Institute_inf") {
		amount += Institute_inf::getWorkerAmount();
		if (Institute_inf::getWorkerAmount() > 0) {
			std::cout << node_name[4] << ":" << std::endl;
			LeafArray<Institute_inf>::showObjects();
		}
	}
	else if (curr_pos == "Institute_el") {
		amount += Institute_el::getWorkerAmount();
		if (Institute_el::getWorkerAmount() > 0) {
			std::cout << node_name[5] << ":" << std::endl;
			LeafArray<Institute_el>::showObjects();
		}
	}
	else if (curr_pos == "Institute_mch") {
		amount += Institute_mch::getWorkerAmount();
		if (Institute_mch::getWorkerAmount() > 0) {
			std::cout << node_name[6] << ":" << std::endl;
			LeafArray<Institute_mch>::showObjects();
		}
	}
	else if (curr_pos == "Institute_phs") {
		amount += Institute_phs::getWorkerAmount();
		if (Institute_phs::getWorkerAmount() > 0) {
			std::cout << node_name[7] << ":" << std::endl;
			LeafArray<Institute_phs>::showObjects();
		}
	}
	else if (curr_pos == "Institute_rc") {
		amount += Institute_rc::getWorkerAmount();
		if (Institute_rc::getWorkerAmount() > 0) {
			std::cout << node_name[8] << ":" << std::endl;
			LeafArray<Institute_rc>::showObjects();
		}
	}
	else if (curr_pos == "Institute_rt") {
		amount += Institute_rt::getWorkerAmount();
		if (Institute_rt::getWorkerAmount() > 0) {
			std::cout << node_name[9] << ":" << std::endl;
			LeafArray<Institute_rt>::showObjects();
		}
	}
	else if(curr_pos == "Study"){
		amount += Study::getWorkerAmount();
		if (Study::getWorkerAmount() > 0) {
			std::cout << node_name[10] << ":" << std::endl;
			LeafArray<Study>::showObjects();
		}
	}
	if (amount == 0) {
		std::cout << "Tutaj nie ma obiektow" << std::endl;
	}
}

void Interface::saveToFile(std::string file_name)
{
	std::fstream file;
	file.open(file_name, std::ios::out);
	LeafArray<Institute_inf>::saveAll(file);
	LeafArray<Institute_el>::saveAll(file);
	LeafArray<Institute_mch>::saveAll(file);
	LeafArray<Institute_phs>::saveAll(file);
	LeafArray<Institute_rc>::saveAll(file);
	LeafArray<Institute_rt>::saveAll(file);
	LeafArray<Study>::saveAll(file);
	file.close();
}

void Interface::readFromFile(std::string file_name)
{
	std::string class_name;
	std::string tab[6];
	std::fstream file;
	file.open(file_name, std::ios::in);
	while (!file.eof()) {
		getline(file, class_name);
		getline(file, tab[0]);
		getline(file, tab[1]);
		getline(file, tab[2]);
		getline(file, tab[3]);
		getline(file, tab[4]);
		if (class_name == node_name[4]) {
			new Institute_inf(tab[0], tab[1], tab[2], tab[3], stoi(tab[4]));
		}
		else if (class_name == node_name[5]) {
			new Institute_el(tab[0], tab[1], tab[2], tab[3], stoi(tab[4]));
		}
		else if (class_name == node_name[6]) {
			new Institute_mch(tab[0], tab[1], tab[2], tab[3], stoi(tab[4]));
		}
		else if (class_name == node_name[7]) {
			new Institute_phs(tab[0], tab[1], tab[2], tab[3], stoi(tab[4]));
		}
		else if (class_name == node_name[8]) {
			new Institute_rc(tab[0], tab[1], tab[2], tab[3], stoi(tab[4]));
		}
		else if (class_name == node_name[9]) {
			new Institute_rt(tab[0], tab[1], tab[2], tab[3], stoi(tab[4]));
		}
		else if (class_name == node_name[10]) {
			getline(file, tab[5]);
			new Study(tab[0], tab[1], tab[2], tab[3], stoi(tab[4]), tab[5]);
		}
	}	
}

void Interface::tree() {
	std::cout << "University" << std::endl;
	std::cout << "|------> Deanary_el" << std::endl;
	std::cout << "     |------> Institute_inf" << std::endl;
	std::cout << "     |------> Institute_el" << std::endl;
	std::cout << "     |------> Study" << std::endl;
	std::cout << "|------> Deanary_bm" << std::endl;
	std::cout << "     |------> Institute_mch" << std::endl;
	std::cout << "     |------> Institute_phs" << std::endl;
	std::cout << "     |------> Study" << std::endl;
	std::cout << "|------> Deanary_bl" << std::endl;
	std::cout << "     |------> Institute_rc" << std::endl;
	std::cout << "     |------> Institute_rt" << std::endl;
	std::cout << "     |------> Study" << std::endl;
}
