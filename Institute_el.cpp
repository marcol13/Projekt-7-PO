#include "Institute_el.h"

int Institute_el::worker_amount = 0;
std::string Institute_el::class_name = "Instytut elektroniki";

Institute_el::Institute_el(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount)
	:name(name), title(title), email(email), phone(phone), thesis_amount(thesis_amount)
{
	this->worker_amount += 1;
	addElement(this);
	std::cout << "Obiekt " << name << " zostal dodany" << std::endl << "-----" << std::endl;
}

void Institute_el::saveToFile(std::fstream& file)
{
	file << *this;
}

Institute_el::~Institute_el() {
	this->worker_amount -= 1;
}

void Institute_el::showAtributes()
{
	std::cout << "Atrybut klasy " << class_name << "\nImie i nazwisko: " << name << "\nTytul: " << title << "\nUczelnia: " << getCollageName() << " - Wydzial: " << getDepartName() << "\nAdres: " << getDepartAddress() << "\nEmail: " << email << "\nTelefon: " << phone << "\nIlosc artykulow: " << thesis_amount << "\n-----\n";
}

int Institute_el::getWorkerAmount()
{
	return worker_amount;
}

std::string Institute_el::getClassName()
{
	return class_name;
}

void Institute_el::modifyObject(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount)
{
	this->name = name;
	this->title = title;
	this->email = email;
	this->phone = phone;
	this->thesis_amount = thesis_amount;
}

std::string Institute_el::getName()
{
	return name;
}

std::string Institute_el::getTitle()
{
	return title;
}

std::string Institute_el::getEmail()
{
	return email;
}

std::string Institute_el::getPhone()
{
	return phone;
}

int Institute_el::getThesisAmount()
{
	return thesis_amount;
}

std::ostream& operator<<(std::ostream& os, Institute_el& el)
{
	return os << el.getClassName() << "\n" << el.getName() << "\n" << el.getTitle() << "\n" << el.getEmail() << "\n" << el.getPhone() << "\n" << el.getThesisAmount() << "\n";
}