#include "Institute_mch.h"

int Institute_mch::worker_amount = 0;
std::string Institute_mch::class_name = "Instytut mechatroniki";

Institute_mch::Institute_mch(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount)
	:name(name), title(title), email(email), phone(phone), thesis_amount(thesis_amount)
{
	this->worker_amount += 1;
	addElement(this);
	std::cout << "Obiekt " << name << " zostal dodany" << std::endl << "-----" << std::endl;
}

void Institute_mch::saveToFile(std::fstream& file)
{
	file << *this;
}

Institute_mch::~Institute_mch() {
	this->worker_amount -= 1;
}

void Institute_mch::showAtributes()
{
	std::cout << "Atrybut klasy " << class_name << "\nImie i nazwisko: " << name << "\nTytul: " << title << "\nUczelnia: " << getCollageName() << " - Wydzial: " << getDepartName() << "\nAdres: " << getDepartAddress() << "\nEmail: " << email << "\nTelefon: " << phone << "\nIlosc artykulow: " << thesis_amount << "\n-----\n";
}

int Institute_mch::getWorkerAmount()
{
	return worker_amount;
}

std::string Institute_mch::getClassName()
{
	return class_name;
}

void Institute_mch::modifyObject(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount)
{
	this->name = name;
	this->title = title;
	this->email = email;
	this->phone = phone;
	this->thesis_amount = thesis_amount;
}

std::string Institute_mch::getName()
{
	return name;
}

std::string Institute_mch::getTitle()
{
	return title;
}

std::string Institute_mch::getEmail()
{
	return email;
}

std::string Institute_mch::getPhone()
{
	return phone;
}

int Institute_mch::getThesisAmount()
{
	return thesis_amount;
}

std::ostream& operator<<(std::ostream& os, Institute_mch& el)
{
	return os << el.getClassName() << "\n" << el.getName() << "\n" << el.getTitle() << "\n" << el.getEmail() << "\n" << el.getPhone() << "\n" << el.getThesisAmount() << "\n";
}