#pragma once

#ifndef CHARACTER_DATABASE_H
#define CHARACTER_DATABASE_H

#include <vector>
#include <memory>

#include <boost/noncopyable.hpp>

class Character_Model;

class Character_Database : public boost::noncopyable
{
public:

	Character_Database();

	~Character_Database();

	void insert_character(std::unique_ptr<Character_Model>&& input_character);

	Character_Model* getCharacterAt(int id);

	Character_Model* getCharacterByName(const std::string& name);

	int getCharacterPosByName(const std::string& name) const;

	void exportXml(const std::string& folder_path) const;

	void importXml(const std::string& folder_path);

	const std::string& getCharacterNameAt(int id) const;

	const std::string& getCharacterFullNameAt(int id) const;
	void setCharacterFullNameAt(int id, const std::string& fullname);

	void delete_character_by_name(std::string& name);

	int countCharacters() const;

private:

	std::vector<std::unique_ptr<Character_Model>> m_characterList;

	using Character_Element = std::unique_ptr<Character_Model>;

};

#endif