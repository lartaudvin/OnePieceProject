#include "Character_Model.h"
#include "boost/property_tree/xml_parser.hpp"
#include "boost/property_tree/ptree.hpp"
#include "boost/filesystem.hpp"

using namespace boost::property_tree;
using namespace boost::filesystem;
using namespace std;

Character_Model::Character_Model(const string& name)
	: m_name_id(name), m_photo_ressource_path("")
{
	m_infos = make_unique<CharacterInfos>();
}

Character_Model::Character_Model()
	: m_name_id(""), m_photo_ressource_path("")
{
	m_infos = make_unique<CharacterInfos>();
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

const std::string& Character_Model::getPhotoRessourcePath() const
{
	return m_photo_ressource_path;
}

void Character_Model::setPhotoRessourcePath(const std::string& path)
{
	m_photo_ressource_path = path;
}

void Character_Model::exportToXml(const std::string& folder_path) const
{
	if (!exists(folder_path))
	{
		create_directory(folder_path);
	}
	ptree tree;
	tree.put("name", m_name_id);
	tree.put("photo", m_photo_ressource_path);

	stringstream stream;
	stream << folder_path << "\\header.xml";
	write_xml(stream.str(), tree);

	stream = stringstream();
	stream << folder_path << "\\infos.xml";
	m_infos->export_xml(stream.str());
}

void Character_Model::importFromXml(const string& folder_path)
{
	ptree tree;
	stringstream stream;
	stream << folder_path << "\\header.xml";
	read_xml(stream.str(), tree);
	m_name_id = tree.get<string>("name");
	try{ m_photo_ressource_path = tree.get<string>("photo"); }
		catch (...) {}

	stream = stringstream();
	stream << folder_path << "\\infos.xml";
	m_infos->import_xml(stream.str());
}
