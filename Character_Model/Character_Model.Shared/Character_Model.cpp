#include "Character_Model.h"
#include "boost/property_tree/xml_parser.hpp"
#include "boost/property_tree/ptree.hpp"
#include "boost/filesystem.hpp"

using namespace boost::property_tree;
using namespace boost::filesystem;
using namespace std;

Character_Model::Character_Model(const string& name)
	: m_name_id(name)
{
	m_infos = make_unique<CharacterInfos>();
	LevelBuilder builder;
	m_caracteristics = make_unique<Caracteristics>(builder.getCharacteristicByLevel(1));
}

Character_Model::Character_Model()
	: m_name_id("")
{
	m_infos = make_unique<CharacterInfos>();
	m_caracteristics = make_unique<Caracteristics>(Caracteristics(3, 3, 3, 3, 3));
}

Character_Model::~Character_Model()
{
}

const string& Character_Model::getName() const
{
	return m_name_id;
}

CharacterInfos& Character_Model::getInfos() const
{
	return *m_infos;
}

Caracteristics& Character_Model::getCharacteristics() const
{
	return *m_caracteristics;
}

void Character_Model::exportToXml(const std::string& folder_path) const
{
	if (!exists(folder_path))
	{
		create_directory(folder_path);
	}
	ptree tree;
	tree.put("name", m_name_id);

	stringstream stream;
	stream << folder_path << "\\header.xml";
	write_xml(stream.str(), tree);

	stream = stringstream();
	stream << folder_path << "\\infos.xml";
	m_infos->export_xml(stream.str());
}

void Character_Model::exportLevelCaracteristics(const std::string& folder_path, LevelBuilder builder) const
{
	stringstream stream = stringstream();
	stream << folder_path << "\\caracteristics.xml";
	builder.exportLevels(stream.str());
}

void Character_Model::importFromXml(const std::string& folder_path, int level)
{
	ptree tree;
	stringstream stream;
	stream << folder_path << "\\header.xml";
	read_xml(stream.str(), tree);
	m_name_id = tree.get<string>("name");

	stream = stringstream();
	stream << folder_path << "\\infos.xml";
	m_infos->import_xml(stream.str());

	stream = stringstream();
	stream << folder_path << "\\caracteristics.xml";
	try
	{
		LevelBuilder builder;
		builder.importLevels(stream.str());
		m_caracteristics = std::make_unique<Caracteristics>(builder.getCharacteristicByLevel(level));
	}
	catch (...)
	{
	}
}

LevelBuilder Character_Model::importLevelCaracteristics(const std::string& folder_path) const
{
	stringstream stream;
	stream << folder_path << "\\caracteristics.xml";
	LevelBuilder builder;
	try
	{
		builder.importLevels(stream.str());
	}
	catch (...)
	{

	}
	return builder;
}
