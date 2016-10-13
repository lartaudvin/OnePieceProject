#include "pch.h"
#include "CharacterInfos.h"
#include "boost/property_tree/xml_parser.hpp"
#include "boost/property_tree/ptree.hpp"
#include "boost/filesystem.hpp"

using namespace boost::property_tree;
using namespace boost::filesystem;


CharacterInfos::CharacterInfos()
{
}


CharacterInfos::~CharacterInfos()
{
}

const std::string& CharacterInfos::getFirstName() const
{
	return m_first_name;
}

void CharacterInfos::setFirstName(const std::string& firstname)
{
	m_first_name = firstname;
}

const std::string& CharacterInfos::getLastName() const
{
	return m_last_name;
}

void CharacterInfos::setLastName(const std::string& lastname)
{
	m_last_name = lastname;
}

const std::string& CharacterInfos::getSurname() const
{
	return m_surname;
}

void CharacterInfos::setSurname(const std::string& surname)
{
	m_surname = surname;
}

const std::string& CharacterInfos::getDescription() const
{
	return m_description;
}

void CharacterInfos::setDescription(const std::string& description)
{
	m_description = description;
}

void CharacterInfos::export_xml(const std::string path) const
{
	ptree tree;
	tree.put("firstname", m_first_name);
	tree.put("lastname", m_last_name);
	tree.put("surname", m_surname);
	tree.put("description", m_description);

	write_xml(path, tree);
}

void CharacterInfos::import_xml(const std::string path)
{
	ptree tree;
	read_xml(path, tree);
	try
	{
		m_first_name = tree.get<std::string>("firstname");
	}
	catch (...) {}
	try
	{
		m_last_name = tree.get<std::string>("lastname");
	}
	catch (...) {}
	try
	{
		m_surname = tree.get<std::string>("surname");
	}
	catch (...) {}
	try
	{
		m_description = tree.get<std::string>("description");
	}
	catch (...) {}
}

