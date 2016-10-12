#pragma once
#include <string>
class CharacterInfos
{
public:
	CharacterInfos();
	~CharacterInfos();

	const std::string& getFirstName() const;
	void setFirstName(const std::string& name);
	const std::string& getLastName() const;
	void setLastName(const std::string& lastname);
	const std::string& getSurname() const;
	void setSurname(const std::string& surname);
	const std::string& getDescription() const;
	void setDescription(const std::string& description);

	void export_xml(const std::string path) const;
	void import_xml(const std::string path);

private:
	std::string m_first_name;
	std::string m_last_name;
	std::string m_surname;
	std::string m_description;
};

