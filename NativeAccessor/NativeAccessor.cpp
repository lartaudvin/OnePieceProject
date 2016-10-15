// NativeAccessor.cpp : Defines the exported functions for the DLL application.
//

#include "NativeAccessor.h"

#include <Character_Database.h>
#include <Character_Model.h>
#include <Exception_Manager/Exception_Manager.Shared/Exception_Manager.h>

using namespace std;

class Native_Accessor::NativeAccessor_Impl
{
public:
	
	NativeAccessor_Impl();
	~NativeAccessor_Impl();

	void insert_character(const std::string& name);
	void export_xml(const std::string& path) const;
	void import_xml(const std::string& path);
	std::string get_name_id_at(int id) const;
	int count_characters() const;
	int get_character_pos_by_name_id(std::string& name) const;
	void remove_character_by_name_id(std::string& name) const;
	std::string get_firstname_at(int id) const;
	void set_firstname_at(int id, const std::string& firstname);
	std::string get_lastname_at(int id) const;
	void set_lastname_at(int id, const std::string& lastname);
	std::string get_surname_at(int id) const;
	void set_surname_at(int id, const std::string& surname);
	std::string get_description_at(int id) const;
	void set_description_at(int id, const std::string& description);

private:

	std::unique_ptr<Character_Database> m_database;

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

void Native_Accessor::import_xml(const std::string&  path)
{
	m_pImpl->import_xml(path);
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
	}
	catch (...)
	{
		throw;
	}
}

void Native_Accessor::NativeAccessor_Impl::export_xml(const std::string&  path) const
{
	m_database->exportXml(path);
}

void Native_Accessor::NativeAccessor_Impl::import_xml(const std::string&  path)
{
	m_database->importXml(path);
}

std::string Native_Accessor::NativeAccessor_Impl::get_name_id_at(int id) const
{
	return m_database->getCharacterNameIdAt(id);
}

int Native_Accessor::NativeAccessor_Impl::count_characters() const
{
	return m_database->countCharacters();
}

int Native_Accessor::NativeAccessor_Impl::get_character_pos_by_name_id(std::string& name) const
{
	return m_database->getCharacterPosByName(name);
}

void Native_Accessor::NativeAccessor_Impl::remove_character_by_name_id(std::string& name) const
{
	m_database->delete_character_by_name(name);
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

DLLAPI void import_xml_call(void* instance, const char* path)
{
	const std::string string_path(path);
	Native_Accessor *accessor = (Native_Accessor*)instance;
	accessor->import_xml(string_path);
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
