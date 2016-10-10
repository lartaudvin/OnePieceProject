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

	void insert_character(const std::string& name, const std::string& fullname);
	void export_xml(const std::string& path) const;
	void import_xml(const std::string& path);
	std::string get_name_at(int id) const;
	void set_name_at(int id, const std::string& name);
	std::string get_fullname_at(int id) const;
	void set_fullname_at(int id, const std::string& fullname);
	int count_characters();

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

void Native_Accessor::insert_character(const std::string& name, const std::string& fullname)
{
	try
	{
		m_pImpl->insert_character(name, fullname);
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
	return m_pImpl->get_name_at(id);
}

void Native_Accessor::set_name_at(int id, const std::string& name)
{
	m_pImpl->set_name_at(id, name);
}

std::string Native_Accessor::get_fullname_at(int id) const
{
	return m_pImpl->get_fullname_at(id);
}

void Native_Accessor::set_fullname_at(int id, const std::string& fullname)
{
	m_pImpl->set_fullname_at(id, fullname);
}

Native_Accessor::NativeAccessor_Impl::NativeAccessor_Impl()
	: m_database(std::make_unique<Character_Database>())
{
}

Native_Accessor::NativeAccessor_Impl::~NativeAccessor_Impl()
{
}

void Native_Accessor::NativeAccessor_Impl::insert_character(const std::string& name, const std::string& fullname)
{
	try
	{
		m_database->insert_character(std::make_unique<Character_Model>(name, fullname));
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

std::string Native_Accessor::NativeAccessor_Impl::get_name_at(int id) const
{
	return m_database->getCharacterNameAt(id);
}

void Native_Accessor::NativeAccessor_Impl::set_name_at(int id, const std::string& name)
{
	m_database->setCharacterNameAt(id, name);
}

std::string Native_Accessor::NativeAccessor_Impl::get_fullname_at(int id) const
{
	return m_database->getCharacterFullNameAt(id);
}

void Native_Accessor::NativeAccessor_Impl::set_fullname_at(int id, const std::string& fullname)
{
	return m_database->setCharacterFullNameAt(id, fullname);
}

int Native_Accessor::NativeAccessor_Impl::count_characters()
{
	return m_database->countCharacters();
}

DLLAPI void* create_native_accessor()
{
	Native_Accessor *accessor = new Native_Accessor();
	return (void*)accessor;
}

DLLAPI int insert_character_call(void* instance, const char* name, const char* fullname)
{
	const std::string string_name(name);
	const std::string string_fullname(fullname);
	Native_Accessor *accessor = (Native_Accessor*)instance;
	try
	{
		accessor->insert_character(string_name, string_fullname);
	}
	catch (ExceptionManager::key_already_exists* e)
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

DLLAPI void set_name_at_call(void* instance, int id, const char* name)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	accessor->set_name_at(id, string(name));
}

DLLAPI void get_fullname_at_call(void* instance, char* fullname, int len, int id)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	memcpy(fullname, accessor->get_name_at(id).c_str(), len);
}

DLLAPI void set_fullname_at_call(void* instance, int id, const char* fullname)
{
	Native_Accessor *accessor = (Native_Accessor*)instance;
	accessor->set_fullname_at(id, string(fullname));
}
