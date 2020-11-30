#include "Institute_rt.h"

int Institute_rt::worker_amount = 0;
std::string Institute_rt::class_name = "Instytut kolejnictwa";

Institute_rt::Institute_rt(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount)
	:name(name), title(title), email(email), phone(phone), thesis_amount(thesis_amount)
{
	this->worker_amount += 1;
	addElement(this);
	std::cout << "Obiekt " << name << " zostal dodany" << std::endl << "-----" << std::endl;
}

void Institute_rt::saveToFile(std::fstream& file)
{
	file << *this;
}

Institute_rt::~Institute_rt() {
	this->worker_amount -= 1;
}

void Institute_rt::showAtributes()
{
	std::cout << "Atrybut klasy " << class_name << "\nImie i nazwisko: " << name << "\nTytul: " << title << "\nUczelnia: " << getCollageName() << " - Wydzial: " << getDepartName() << "\nAdres: " << getDepartAddress() << "\nEmail: " << email << "\nTelefon: " << phone << "\nIlosc artykulow: " << thesis_amount << "\n-----\n";
}

int Institute_rt::getWorkerAmount()
{
	return worker_amount;
}

std::string Institute_rt::getClassName()
{
	return class_name;
}

void Institute_rt::modifyObject(const std::string& name, const std::string& title, const std::string& email, const std::string& phone, int thesis_amount)
{
	this->name = name;
	this->title = title;
	this->email = email;
	this->phone = phone;
	this->thesis_amount = thesis_amount;
}

std::string Institute_rt::getName()
{
	return name;
}

std::string Institute_rt::getTitle()
{
	return title;
}

std::string Institute_rt::getEmail()
{
	return email;
}

std::string Institute_rt::getPhone()
{
	return phone;
}

int Institute_rt::getThesisAmount()
{
	return thesis_amount;
}

std::ostream& operator<<(std::ostream& os, Institute_rt& el)
{
	return os << el.getClassName() << "\n" << el.getName() << "\n" << el.getTitle() << "\n" << el.getEmail() << "\n" << el.getPhone() << "\n" << el.getThesisAmount() << "\n";
}