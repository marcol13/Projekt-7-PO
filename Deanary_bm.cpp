#include "Deanary_bm.h"

std::string Deanary_bm::class_name = "Dziekanat budowa maszyn";
std::string Deanary_bm::depart_name = "Budowa Maszyn";
std::string Deanary_bm::office_address = "Piotrowo 3, 60-965 Poznan";
int Deanary_bm::field_amount = 3;

Deanary_bm::Deanary_bm()
{
}

Deanary_bm::~Deanary_bm()
{
}

std::string Deanary_bm::getClassName()
{
	return class_name;
}

std::string Deanary_bm::getDepartName()
{
	return depart_name;
}

std::string Deanary_bm::getDepartAddress()
{
	return office_address;
}
