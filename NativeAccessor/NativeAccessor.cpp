// NativeAccessor.cpp : Defines the exported functions for the DLL application.
//

#include "NativeAccessor.h"

#include <Character_Database.h>
#include <Character_Model.h>

using namespace std;

class Native_Accessor::NativeAccessor_Impl
{
public:
	
	NativeAccessor_Impl();
	~NativeAccessor_Impl();

	void insert_character(const std::string& name, const std::string& fullname);
	void export_xml(const std::string& path) const;
	void import_xml(const std::string& path);

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

void Native_Accessor::insert_character(const std::string&  name, const std::string&  fullname)
{
	m_pImpl->insert_character(name, fullname);
}

void Native_Accessor::export_xml(const std::string&  path) const
{
	m_pImpl->export_xml(path);
}

void Native_Accessor::import_xml(const std::string&  path)
{
	m_pImpl->import_xml(path);
}

Native_Accessor::NativeAccessor_Impl::NativeAccessor_Impl()
	: m_database(std::make_unique<Character_Database>())
{
}

Native_Accessor::NativeAccessor_Impl::~NativeAccessor_Impl()
{
}

void Native_Accessor::NativeAccessor_Impl::insert_character(const std::string&  name, const std::string&  fullname)
{
	m_database->insert_character(std::make_unique<Character_Model>(name, fullname));
}

void Native_Accessor::NativeAccessor_Impl::export_xml(const std::string&  path) const
{
	m_database->exportXml(path);
}

void Native_Accessor::NativeAccessor_Impl::import_xml(const std::string&  path)
{
	m_database->importXml(path);
}

DLLAPI void* create_native_accessor()
{
	Native_Accessor *accessor = new Native_Accessor();
	return (void*)accessor;
}

DLLAPI void insert_character_call(void* instance, const char* name, const char* fullname)
{
	const std::string string_name(name);
	const std::string string_fullname(fullname);
	Native_Accessor *accessor = (Native_Accessor*)instance;
	accessor->insert_character(string_name, string_fullname);
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
