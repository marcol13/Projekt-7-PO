#include "Institute_rc.h"

int Institute_rc::worker_amount = 0;
std::string Institute_rc::class_name = "Instytut budowy drog";

Institute_rc::Institute_rc(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount)
	:name(name), title(title), email(email), phone(phone), thesis_amount(thesis_amount)
{
	this->worker_amount += 1;
	addElement(this);
	std::cout << "Obiekt " << name << " zostal dodany" << std::endl << "-----" << std::endl;
}

void Institute_rc::saveToFile(std::fstream& file)
{
	file << *this;
}

Institute_rc::~Institute_rc() {
	this->worker_amount -= 1;
}

void Institute_rc::showAtributes()
{
	std::cout << "Atrybut klasy " << class_name << "\nImie i nazwisko: " << name << "\nTytul: " << title << "\nUczelnia: " << getCollageName() << " - Wydzial: " << getDepartName() << "\nAdres: " << getDepartAddress() << "\nEmail: " << email << "\nTelefon: " << phone << "\nIlosc artykulow: " << thesis_amount << "\n-----\n";
}

int Institute_rc::getWorkerAmount()
{
	return worker_amount;
}

std::string Institute_rc::getClassName()
{
	return class_name;
}

void Institute_rc::modifyObject(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount)
{
	this->name = name;
	this->title = title;
	this->email = email;
	this->phone = phone;
	this->thesis_amount = thesis_amount;
}

std::string Institute_rc::getName()
{
	return name;
}

std::string Institute_rc::getTitle()
{
	return title;
}

std::string Institute_rc::getEmail()
{
	return email;
}

std::string Institute_rc::getPhone()
{
	return phone;
}

int Institute_rc::getThesisAmount()
{
	return thesis_amount;
}

std::ostream& operator<<(std::ostream& os, Institute_rc& el)
{
	return os << el.getClassName() << "\n" << el.getName() << "\n" << el.getTitle() << "\n" << el.getEmail() << "\n" << el.getPhone() << "\n" << el.getThesisAmount() << "\n";
}