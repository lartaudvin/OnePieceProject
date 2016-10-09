#pragma once

#include <stdexcept>
#include <string>
#include <memory>

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


private:

	class NativeAccessor_Impl;
	std::unique_ptr<NativeAccessor_Impl> m_pImpl;

};

#if __cplusplus
extern "C" {
#endif

	DLLAPI void* create_native_accessor();
	DLLAPI void insert_character_call(void* instance, const char* name, const char* fullname);
	DLLAPI void export_xml_call(void* instance, const char* path);
	DLLAPI void import_xml_call(void* instance, const char* path);
	DLLAPI void delete_native_accessor(void* instance);

#if __cplusplus
}
#endif