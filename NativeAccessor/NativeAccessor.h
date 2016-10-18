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

	void insert_character(const std::string& name);
	void export_xml(const std::string& path) const;
	void import_xml(const std::string& path, int level);
	int count_characters() const;
	std::string get_name_at(int id) const;
	int get_character_pos_by_name(std::string& name) const;
	void remove_character_by_name(std::string& name) const;
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
	//The implementator of the class used to hide all the methods of the C++ database
	class NativeAccessor_Impl;
	std::unique_ptr<NativeAccessor_Impl> m_pImpl;

};

#if __cplusplus
extern "C" {
#endif

	DLLAPI void* create_native_accessor();
	DLLAPI int insert_character_call(void* instance, const char* name);
	DLLAPI void export_xml_call(void* instance, const char* path);
	DLLAPI void import_xml_call(void* instance, const char* path, int level);
	DLLAPI void delete_native_accessor(void* instance);
	DLLAPI int count_characters_call(void* instance);
	DLLAPI void get_name_at_call(void* instance, char* name, int len, int id);
	DLLAPI int get_character_pos_by_name_call(void* instance, const char* name);
	DLLAPI void remove_character_by_name_call(void* instance, const char* name);
	DLLAPI void get_firstname_at_call(void* instance, int id, char* firstname, int len);
	DLLAPI void set_firstname_at_call(void* instance, int id, const char* firstname);
	DLLAPI void get_lastname_at_call(void* instance, int id, char* lastname, int len);
	DLLAPI void set_lastname_at_call(void* instance, int id, const char* lastname);
	DLLAPI void get_surname_at_call(void* instance, int id, char* surname, int len);
	DLLAPI void set_surname_at_call(void* instance, int id, const char* surname);
	DLLAPI void get_description_at_call(void* instance, int id, char* description, int len);
	DLLAPI void set_description_at_call(void* instance, int id, const char* description);
	DLLAPI void add_or_set_level_at(void* instance, int id, int level_label, int force, int intelligence, int charisme, int constitution, int dexterite);
	DLLAPI int getLevelCount(void* instance, int id);
	DLLAPI int getForce(void* instance, int id, int level);
	DLLAPI int getIntelligence(void* instance, int id, int level);
	DLLAPI int getCharisme(void* instance, int id, int level);
	DLLAPI int getConstitution(void* instance, int id, int level);
	DLLAPI int getDexterite(void* instance, int id, int level);

#if __cplusplus
}
#endif