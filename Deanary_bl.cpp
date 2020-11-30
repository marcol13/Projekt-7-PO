#include "Deanary_bl.h"

std::string Deanary_bl::class_name = "Dziekanat budownictwo ladowe";
std::string Deanary_bl::depart_name = "Budownictwo Ladowe";
std::string Deanary_bl::office_address = "Piotrowo 3, 60-965 Poznan";
int Deanary_bl::field_amount = 3;

Deanary_bl::Deanary_bl()
{
}

Deanary_bl::~Deanary_bl()
{
}

std::string Deanary_bl::getClassName()
{
	return class_name;
}

std::string Deanary_bl::getDepartName()
{
	return depart_name;
}

std::string Deanary_bl::getDepartAddress()
{
	return office_address;
}
