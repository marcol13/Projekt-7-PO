#include "Deanary_el.h"

std::string Deanary_el::class_name = "Dziekanat elektronika";
std::string Deanary_el::depart_name = "Elektronika";
std::string Deanary_el::office_address = "Piotrowo 3A, 60-965 Poznan";
int Deanary_el::field_amount = 3;


Deanary_el::Deanary_el()
{
}

Deanary_el::~Deanary_el()
{
}

std::string Deanary_el::getClassName()
{
	return class_name;
}

std::string Deanary_el::getDepartName()
{
	return depart_name;
}

std::string Deanary_el::getDepartAddress()
{
	return office_address;
}
