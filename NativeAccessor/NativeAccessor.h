#pragma once

#include <stdexcept>
#include <string>
#include <memory>
#include <vector>

#include "NativeAccessorAPI.h"
class Character_Database;

class Native_Accessor
{
public:
	Native_Accessor();
	~Native_Accessor();

	void insert_character(const std::string& name, const std::string& fullname);
	void export_xml(const std::string& path) const;
	void import_xml(const std::string& path);
	int count_characters() const;
	std::string get_name_at(int id) const;
	std::string get_fullname_at(int id) const;
	void set_fullname_at(int id, const std::string& fullname);
	int get_character_pos_by_name(std::string& name) const;
	void remove_character_by_name(std::string& name) const;

private:
	//The implementator of the class used to hide all the methods of the C++ database
	class NativeAccessor_Impl;
	std::unique_ptr<NativeAccessor_Impl> m_pImpl;

};

#if __cplusplus
extern "C" {
#endif

	DLLAPI void* create_native_accessor();
	DLLAPI int insert_character_call(void* instance, const char* name, const char* fullname);
	DLLAPI void export_xml_call(void* instance, const char* path);
	DLLAPI void import_xml_call(void* instance, const char* path);
	DLLAPI void delete_native_accessor(void* instance);
	DLLAPI int count_characters_call(void* instance);
	DLLAPI void get_name_at_call(void* instance, char* name, int len, int id);
	DLLAPI void get_fullname_at_call(void* instance, char* fullname, int len, int id);
	DLLAPI void set_fullname_at_call(void* instance, int id, const char* fullname);
	DLLAPI int get_character_pos_by_name_call(void* instance, const char* name);
	DLLAPI void remove_character_by_name_call(void* instance, const char* name);

#if __cplusplus
}
#endif