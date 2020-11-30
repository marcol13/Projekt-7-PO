#pragma once
#include <iostream>
#include <vector>

template <typename T>
class LeafArray {
private:
	int array_size;

protected:
	static std::vector<T*> l_array;
	static void addElement(T* el) {
		l_array.push_back(el);
	}
	
public:
	static void showElement(const std::string& name) {
		bool in_array = false;
		for (int i = 0; i < l_array.size(); i++) {
			if (l_array[i]->getName() == name) {
				in_array = true;
				l_array[i]->showAtributes();
				break;
			}
		}
		if(in_array == false)
			std::cout << "Nie ma takiego obiektu" << std::endl << "-----" << std::endl;
	}

	static void showObjects() {
		for (auto i : l_array) {
			std::cout << i->getName() << std::endl;
		}
	}

	static void removeElement(const std::string& name) {
		bool in_array = false;
		for (int i = 0; i < l_array.size(); i++) {
			if (l_array[i]->getName() == name) {
				in_array = true;
				delete l_array[i];
				l_array.erase(l_array.begin() + i);
				break;
			}
		}
		if (in_array == false)
			std::cout << "Nie ma takiego obiektu" << std::endl << "-----" << std::endl;
		else
			std::cout << "Usunieto obiekt " << name << std::endl << "-----" << std::endl;
	}

	static void modifyElement(const std::string& name, const std::string& nName, const std::string& nTitle, const std::string& nEmail, const std::string& nPhone, int nThesis_amount) {
		bool in_array = false;
		for (int i = 0; i < l_array.size(); i++) {
			if (l_array[i]->getName() == name) {
				in_array = true;
				l_array[i]->modifyObject(nName, nTitle, nEmail, nPhone, nThesis_amount);
				break;
			}
		}
		if(in_array == false)
			std::cout << "Nie ma takiego obiektu" << std::endl << "-----" << std::endl;
		else
			std::cout << "Zmodyfikowano obiekt " << name << std::endl << "-----" << std::endl;
	}

	static void modifyStudy(const std::string& name, const std::string& nName, const std::string& nTitle, const std::string& nEmail, const std::string& nPhone, int nThesis_amount, const std::string& nLanguage) {
		bool in_array = false;
		for (int i = 0; i < l_array.size(); i++) {
			if (l_array[i]->getName() == name) {
				in_array = true;
				l_array[i]->modifyObject(nName, nTitle, nEmail, nPhone, nThesis_amount, nLanguage);
				break;
			}
		}
		if (in_array == false)
			std::cout << "Nie ma takiego obiektu" << std::endl << "-----" << std::endl;
		else
			std::cout << "Zmodyfikowano obiekt " << name << std::endl << "-----" << std::endl;
	}

	static void saveAll(std::fstream& file) {
		for (auto i : l_array) {
			i->saveToFile(file);
		}
	}
};

template <typename T>
std::vector<T*> LeafArray<T>::l_array;
