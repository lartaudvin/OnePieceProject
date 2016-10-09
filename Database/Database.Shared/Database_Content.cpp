#include "pch.h"
#include "Database_Content.h"



Database::Database_Content::Database_Content()
{
	this->m_characterDatabase = new Character_Database();

	this->addCharacter("Luffy", "Monkey D. Luffy");
	this->addCharacter("Zoro", "Zoro");
	this->addCharacter("Nami", "Nami");
	this->addCharacter("Ussop", "Captain Ussop");
	this->addCharacter("Sanji", "Sanji");
	this->addCharacter("Robin", "Nico Robin");
	this->addCharacter("Chopper", "Tony Tony Chopper");
	this->addCharacter("Francky", "Cutty \'Francky\' Flamm");
	this->addCharacter("Brooks", "Brooks");
}


Database::Database_Content::~Database_Content()
{
	delete this->m_characterDatabase;
}

void Database::Database_Content::addCharacter(string name, string fullname)
{
	this->m_characterDatabase->insert_character(new Character_Model(name, fullname));
}
