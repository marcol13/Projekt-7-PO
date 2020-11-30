#include "University.h"

std::string University::class_name = "Uczelnia wyzsza";

University::University()
{
	this->collage_name = "Politechnika Poznanska";
	this->address = "Plac Marii Sklodowskiej-Curie 5, 60-965 Poznan";
}

University::~University()
{
}

std::string University::getCollageName()
{
	return collage_name;
}

std::string University::getCollageAddress()
{
	return address;
}

std::string University::getClassName()
{
	return class_name;
}
