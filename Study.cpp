#include "Study.h"

int Study::worker_amount = 0;
std::string Study::class_name = "Studium jezykow obcych";

Study::Study(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount, const std::string& language)
	:name(name), title(title), email(email), phone(phone), thesis_amount(thesis_amount), language(language)
{
	this->worker_amount += 1;
	addElement(this);
	std::cout << "Obiekt " << name << " zostal dodany" << std::endl << "-----" << std::endl;
}

void Study::saveToFile(std::fstream& file)
{
	file << *this;
}

Study::~Study() {
	this->worker_amount -= 1;
}

void Study::showAtributes()
{
	std::cout << "Atrybut klasy " << class_name << "\nImie i nazwisko: " << name << "\nTytul: " << title << "\nUczelnia: " << University::getCollageName() << " - Wydzialy: " << Deanary_el::getDepartName() <<", " << Deanary_bm::getDepartName() << ", " << Deanary_bl::getDepartName() << "\nAdres: " << University::getCollageAddress() << "\nEmail: " << email << "\nTelefon: " << phone << "\nIlosc artykulow: " << thesis_amount << "\nJezyk: " << language << "\n-----\n";
}

int Study::getWorkerAmount()
{
	return worker_amount;
}

std::string Study::getClassName()
{
	return class_name;
}

void Study::modifyObject(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount, const std::string& language)
{
	this->name = name;
	this->title = title;
	this->email = email;
	this->phone = phone;
	this->thesis_amount = thesis_amount;
	this->language = language;
}

std::string Study::getName()
{
	return name;
}

std::string Study::getTitle()
{
	return title;
}

std::string Study::getEmail()
{
	return email;
}

std::string Study::getPhone()
{
	return phone;
}

std::string Study::getLanguage() {
	return language;
}

int Study::getThesisAmount()
{
	return thesis_amount;
}

std::ostream& operator<<(std::ostream& os, Study& el)
{
	return os << el.getClassName() << "\n" << el.getName() << "\n" << el.getTitle() << "\n" << el.getEmail() << "\n" << el.getPhone() << "\n" << el.getThesisAmount() << "\n" << el.getLanguage() << "\n";
}