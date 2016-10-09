#include "Character_Model.h"
#include "boost/property_tree/xml_parser.hpp"
#include "boost/property_tree/ptree.hpp"
#include "boost/filesystem.hpp"

using namespace boost::property_tree;
using namespace boost::filesystem;
using namespace std;

Character_Model::Character_Model(const string& name, const string& fullname)
	: m_name(name), m_fullname(fullname)
{
}

Character_Model::~Character_Model()
{
}

const string& Character_Model::getName() const
{
	return m_name;
}

const string& Character_Model::getFullName() const
{
	return m_fullname;
}

void Character_Model::exportToXml(const std::string& folder_path) const
{
	if (!exists(folder_path))
	{
		create_directory(folder_path);
	}
	ptree tree;
	tree.put("name", m_name);
	tree.put("fullname", m_fullname);

	stringstream stream;
	stream << folder_path << "\\description.xml";

	write_xml(stream.str(), tree);
}

void Character_Model::importFromXml(const string& folder_path)
{
	ptree tree;
	stringstream stream;
	stream << folder_path << "\\description.xml";
	read_xml(stream.str(), tree);
	m_name = tree.get<string>("name");
	m_fullname = tree.get<string>("fullname");
}
