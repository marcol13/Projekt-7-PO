#include "Institute_phs.h"

int Institute_phs::worker_amount = 0;
std::string Institute_phs::class_name = "Instytut fizyki";

Institute_phs::Institute_phs(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount)
	:name(name), title(title), email(email), phone(phone), thesis_amount(thesis_amount)
{
	this->worker_amount += 1;
	addElement(this);
	std::cout << "Obiekt " << name << " zostal dodany" << std::endl << "-----" << std::endl;
}

void Institute_phs::saveToFile(std::fstream& file)
{
	file << *this;
}

Institute_phs::~Institute_phs() {
	this->worker_amount -= 1;
}

void Institute_phs::showAtributes()
{
	std::cout << "Atrybut klasy " << class_name << "\nImie i nazwisko: " << name << "\nTytul: " << title << "\nUczelnia: " << getCollageName() << " - Wydzial: " << getDepartName() << "\nAdres: " << getDepartAddress() << "\nEmail: " << email << "\nTelefon: " << phone << "\nIlosc artykulow: " << thesis_amount << "\n-----\n";
}

int Institute_phs::getWorkerAmount()
{
	return worker_amount;
}

std::string Institute_phs::getClassName()
{
	return class_name;
}

void Institute_phs::modifyObject(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount)
{
	this->name = name;
	this->title = title;
	this->email = email;
	this->phone = phone;
	this->thesis_amount = thesis_amount;
}

std::string Institute_phs::getName()
{
	return name;
}

std::string Institute_phs::getTitle()
{
	return title;
}

std::string Institute_phs::getEmail()
{
	return email;
}

std::string Institute_phs::getPhone()
{
	return phone;
}

int Institute_phs::getThesisAmount()
{
	return thesis_amount;
}

std::ostream& operator<<(std::ostream& os, Institute_phs& el)
{
	return os << el.getClassName() << "\n" << el.getName() << "\n" << el.getTitle() << "\n" << el.getEmail() << "\n" << el.getPhone() << "\n" << el.getThesisAmount() << "\n";
}