// NativeAccessor.cpp : Defines the exported functions for the DLL application.
//

#include "NativeAccessor.h"

#include <Character_Database.h>
#include <Character_Model.h>
#include <Exception_Manager/Exception_Manager.Shared/Exception_Manager.h>
#include <LevelBuilder.h>
#include <map>

using namespace std;

class Native_Accessor::NativeAccessor_Impl
{
public:
	
	NativeAccessor_Impl();
	~NativeAccessor_Impl();

	void insert_character(const std::string& name);
	void export_xml(const std::string& path) const;
	void import_xml(const std::string& path, int level);
	std::string get_name_id_at(int id) const;
	int count_characters() const;
	int get_character_pos_by_name_id(const std::string& name) const;
	void remove_character_by_name_id(std::string& name);
	std::string get_firstname_at(int id) const;
	void set_firstname_at(int id, const std::string& firstname);
	std::string get_lastname_at(int id) const;
	void set_lastname_at(int id, const std::string& lastname);
	std::string get_surname_at(int id) const;
	void set_surname_at(int id, const std::string& surname);
	std::string get_description_at(int id) const;
	void set_description_at(int id, const std::string& description);
	void add_or_set_level_at(int id, int level_label, int force, int intelligence, int charisme, int constitution, int dexterite);
	int getLevelCount(int id) const;
	int getForce(int id, int level) const;
	int getIntelligence(int id, int level) const;
	int getCharisme(int id, int level) const;
	int getConstitution(int id, int level) const;
	int getDexterite(int id, int level) const;

private:

	std::unique_ptr<Character_Database> m_database;
	std::map<int, unique_ptr<LevelBuilder>> m_level_builders;
};

Native_Accessor::Native_Accessor()
	: m_pImpl(std::make_unique<NativeAccessor_Impl>())
{
}

Native_Accessor::~Native_Accessor()
{
}

void Native_Accessor::insert_character(const std::string& name)
{
	try
	{
		m_pImpl->insert_character(name);
	}
	catch (...)
	{
		throw;
	}
}

void Native_Accessor::export_xml(const std::string&  path) const
{
	m_pImpl->export_xml(path);
}

void Native_Accessor::import_xml(const std::string& path, int level)
{
	m_pImpl->import_xml(path, level);
}

int Native_Accessor::count_characters() const
{
	return m_pImpl->count_characters();
}

std::string Native_Accessor::get_name_at(int id) const
{
	return m_pImpl->get_name_id_at(id);
}

int Native_Accessor::get_character_pos_by_name(std::string& name) const
{
	return m_pImpl->get_character_pos_by_name_id(name);
}

void Native_Accessor::remove_character_by_name(std::string& name) const
{
	return m_pImpl->remove_character_by_name_id(name);
}

std::string Native_Accessor::get_firstname_at(int id) const
{
	return m_pImpl->get_firstname_at(id);
}

void Native_Accessor::set_firstname_at(int id, const std::string& firstname)
{
	m_pImpl->set_firstname_at(id, firstname);
}

std::string Native_Accessor::get_lastname_at(int id) const
{
	return m_pImpl->get_lastname_at(id);
}

void Native_Accessor::set_lastname_at(int id, const std::string& lastname)
{
	m_pImpl->set_lastname_at(id, lastname);
}

std::string Native_Accessor::get_surname_at(int id) const
{
	return m_pImpl->get_surname_at(id);
}

void Native_Accessor::set_surname_at(int id, const std::string& surname)
{
	m_pImpl->set_surname_at(id, surname);
}

std::string Native_Accessor::get_description_at(int id) const
{
	return m_pImpl->get_description_at(id);
}

void Native_Accessor::set_description_at(int id, const std::string& description)
{
	m_pImpl->set_description_at(id, description);
}

void Native_Accessor::add_or_set_level_at(int id, int level_label, int force, int intelligence, int charisme, int constitution, int dexterite)
{
	m_pImpl->add_or_set_level_at(id, level_label, force, intelligence, charisme, constitution, dexterite);
}

int Native_Accessor::getLevelCount(int id) const
{
	return m_pImpl->getLevelCount(id);
}

int Native_Accessor::getForce(int id, int level) const
{
	return m_pImpl->getForce(id, level);
}

int Native_Accessor::getIntelligence(int id, int level) const
{
	return m_pImpl->getIntelligence(id, level);
}

int Native_Accessor::getCharisme(int id, int level) const
{
	return m_pImpl->getCharisme(id, level);
}

int Native_Accessor::getConstitution(int id, int level) const
{
	return m_pImpl->getConstitution(id, level);
}

int Native_Accessor::getDexterite(int id, int level) const
{
	return m_pImpl->getDexterite(id, level);
}

Native_Accessor::NativeAccessor_Impl::NativeAccessor_Impl()
	: m_database(std::make_unique<Character_Database>())
{
}

Native_Accessor::NativeAccessor_Impl::~NativeAccessor_Impl()
{
}

void Native_Accessor::NativeAccessor_Impl::insert_character(const std::string& name)
{
	try
	{
		m_database->insert_character(std::make_unique<Character_Model>(name));
		int pos = this->get_character_pos_by_name_id(name);
		m_level_builders.insert(std::make_pair(pos, std::make_unique<LevelBuilder>(LevelBuilder())));
	}
	catch (...)
	{
		throw;
	}
}

void Native_Accessor::NativeAccessor_Impl::export_xml(const std::string&  path) const
{
	m_database->exportXml(path);
	for each (auto&& builder in m_level_builders)
	{
		m_database->getCharacterAt(builder.first)->exportLevelCaracteristics(path, *builder.second);
	}
}

void Native_Accessor::NativeAccessor_Impl::import_xml(const std::string& path, int level)
{
	m_database->importXml(path, level);
	int characterCount = m_database->countCharacters();
	for (int i = 0; i < characterCount; i++)
	{
		LevelBuilder builder{ m_database->getCharacterAt(i)->importLevelCaracteristics(path) };
		m_level_builders.insert(std::make_pair(i, make_unique<LevelBuilder>(builder)));
	}
}

std::string Native_Accessor::NativeAccessor_Impl::get_name_id_at(int id) const
{
	return m_database->getCharacterNameIdAt(id);
}

int Native_Accessor::NativeAccessor_Impl::count_characters() const
{
	return m_database->countCharacters();
}

int Native_Accessor::NativeAccessor_Impl::get_character_pos_by_name_id(const std::string& name) const
{
	return m_database->getCharacterPosByName(name);
}

void Native_Accessor::NativeAccessor_Impl::remove_character_by_name_id(std::string& name)
{
	int pos = this->get_character_pos_by_name_id(name);
	m_database->delete_character_by_name(name);
	m_level_builders.erase(pos);
}

std::string Native_Accessor::NativeAccessor_Impl::get_firstname_at(int id) const
{
	return m_database->getCharacterAt(id)->getInfos().getFirstName();
}

void Native_Accessor::NativeAccessor_Impl::set_firstname_at(int id, const std::string& firstname)
{
	m_database->getCharacterAt(id)->getInfos().setFirstName(firstname);
}

std::string Native_Accessor::NativeAccessor_Impl::get_lastname_at(int id) const
{
	return m_database->getCharacterAt(id)->getInfos().getLastName();
}

void Native_Accessor::NativeAccessor_Impl::set_lastname_at(int id, const std::string& lastname)
{
	m_database->getCharacterAt(id)->getInfos().setLastName(lastname);
}

std::string Native_Accessor::NativeAccessor_Impl::get_surname_at(int id) const
{
	return m_database->getCharacterAt(id)->getInfos().getSurname();
}

void Native_Accessor::NativeAccessor_Impl::set_surname_at(int id, const std::string& surname)
{
	m_database->getCharacterAt(id)->getInfos().setSurname(surname);
}

std::string Native_Accessor::NativeAccessor_Impl::get_description_at(int id) const
{
	return m_database->getCharacterAt(id)->getInfos().getDescription();
}

void Native_Accessor::NativeAccessor_Impl::set_description_at(int id, const std::string& description)
{
	m_database->getCharacterAt(id)->getInfos().setDescription(description);
}

void Native_Accessor::NativeAccessor_Impl::add_or_set_level_at(int id, int level_label, int force, int intelligence, int charisme, int constitution, int dexterite)
{
	try
	{
		m_level_builders.at(id)->addOrSetLevel(level_label, force, intelligence, charisme, constitution, dexterite);
	}
	catch (const std::out_of_range&)
	{
		LevelBuilder builder;
		builder.addOrSetLevel(level_label, force, intelligence, charisme, constitution, dexterite);
		m_level_builders.insert(make_pair(id, make_unique<LevelBuilder>(builder)));
	}
	catch (...)
	{

	}
}

int Native_Accessor::NativeAccessor_Impl::getForce(int id, int level) const
{
	return m_level_builders.at(id)->getCharacteristicByLevel(level).getBaseForce();
}

int Native_Accessor::NativeAccessor_Impl::getLevelCount(int id) const
{
	return m_level_builders.at(id)->count();
}

int Native_Accessor::NativeAccessor_Impl::getIntelligence(int id, int level) const
{
	return m_level_builders.at(id)->getCharacteristicByLevel(level).getBaseIntelligence();
}

int Native_Accessor::NativeAccessor_Impl::getCharisme(int id, int level) const
{
	return m_level_builders.at(id)->getCharacteristicByLevel(level).getBaseCharisme();
}

int Native_Accessor::NativeAccessor_Impl::getConstitution(int id, int level) const
{
	return m_level_builders.at(id)->getCharacteristicByLevel(level).getBaseConstitution();
}

int Native_Accessor::NativeAccessor_Impl::getDexterite(int id, int level) const
{
	return m_level_builders.at(id)->getCharacteristicByLevel(level).getBaseDexterite();
}

DLLAPI void* create_native_accessor()
{
	Native_Accessor *accessor = new Native_Accessor();
	return (void*)accessor;
}

DLLAPI int insert_character_call(void* instance, const char* name)
{
	const std::string string_name(name);
	Native_Accessor *accessor = (Native_Accessor*)instance;
	try
	{
		accessor->insert_character(string_name);
	}
	catch (ExceptionManager::key_already_exists*)
	{
		return -1;
	}

	return 0;
}

DLLAPI void export_xml_call(void* instance, const char* path)
{
	const std::string string_path(path);
	Native_Accessor *accessor = (Native_Accessor*)instance;
	accessor->export_xml(string_path);
}

DLLAPI void import_xml_call(void* instance, const char* path, int level)
{
	const std::string string_path(path);
	Native_Accessor *accessor = (Native_Accessor*)instance;
	accessor->import_xml(string_path, level);
}

DLLAPI void delete_native_accessor(void *instance)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	delete accessor;
}

DLLAPI int count_characters_call(void* instance)
{
	Native_Accessor *accessor = (Native_Accessor *)instance;
	return accessor->count_characters();
}

DLLAPI void get_name_at_call(void* instance, char* name, int len, int id)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	memcpy(name, accessor->get_name_at(id).c_str(), len);
}

DLLAPI int get_character_pos_by_name_call(void* instance, const char* name)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	return accessor->get_character_pos_by_name(string(name));
}

DLLAPI void remove_character_by_name_call(void* instance, const char* name)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	accessor->remove_character_by_name(std::string(name));
}

DLLAPI void get_firstname_at_call(void* instance, int id, char* firstname, int len)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	memcpy(firstname, accessor->get_firstname_at(id).c_str(), len);
}

DLLAPI void set_firstname_at_call(void* instance, int id, const char* firstname)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	accessor->set_firstname_at(id, string(firstname));
}

DLLAPI void get_lastname_at_call(void* instance, int id, char* lastname, int len)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	memcpy(lastname, accessor->get_lastname_at(id).c_str(), len);
}

DLLAPI void set_lastname_at_call(void* instance, int id, const char* lastname)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	accessor->set_lastname_at(id, string(lastname));
}

DLLAPI void get_surname_at_call(void* instance, int id, char* surname, int len)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	memcpy(surname, accessor->get_surname_at(id).c_str(), len);
}

DLLAPI void set_surname_at_call(void* instance, int id, const char* surname)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	accessor->set_surname_at(id, string(surname));
}

DLLAPI void get_description_at_call(void* instance, int id, char* description, int len)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	memcpy(description, accessor->get_description_at(id).c_str(), len);
}

DLLAPI void set_description_at_call(void* instance, int id, const char* description)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	accessor->set_description_at(id, string(description));
}

DLLAPI void add_or_set_level_at(void* instance, int id, int level_label, int force, int intelligence, int charisme, int constitution, int dexterite)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	accessor->add_or_set_level_at(id, level_label, force, intelligence, charisme, constitution, dexterite);
}

DLLAPI int getLevelCount(void* instance, int id)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	return accessor->getLevelCount(id);
}

DLLAPI int getForce(void* instance, int id, int level)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	return accessor->getForce(id, level);
}

DLLAPI int getIntelligence(void* instance, int id, int level)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	return accessor->getIntelligence(id, level);
}

DLLAPI int getCharisme(void* instance, int id, int level)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	return accessor->getCharisme(id, level);
}

DLLAPI int getConstitution(void* instance, int id, int level)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	return accessor->getConstitution(id, level);
}

DLLAPI int getDexterite(void* instance, int id, int level)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	return accessor->getDexterite(id, level);
}
