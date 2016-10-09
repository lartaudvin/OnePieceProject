#pragma once

#ifndef CHARACTER_DATABASE_H
#define CHARACTER_DATABASE_H

#include <map>
#include <memory>

#include <boost/noncopyable.hpp>

class Character_Model;

class Character_Database : public boost::noncopyable
{
public:

	Character_Database();

	~Character_Database();

	//************************************
	// Method:    insert_character Insert a character in the database
	// FullName:  Database::Character_Database::insert_character
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: Character_Model input_character The character to insert
	//************************************
	void insert_character(std::unique_ptr<Character_Model>&& input_character);
	//************************************
	// Method:    getCharacterById Get a character using its id
	// FullName:  Database::Character_Database::getCharacterById
	// Access:    public 
	// Returns:   CharacterModel::Character_Model The character to get
	// Qualifier:
	// Parameter: int id The character's id
	//************************************
	Character_Model* getCharacterById(int id);
	//************************************
	// Method:    getCharacterByName Get a character using its name
	// FullName:  Database::Character_Database::getCharacterByName
	// Access:    public 
	// Returns:   CharacterModel::Character_Model The character to get
	// Qualifier:
	// Parameter: string name The character's name
	//************************************
	Character_Model* getCharacterByName(const std::string& name);

	void exportXml(const std::string& folder_path) const;

	void importXml(const std::string& folder_path);

private:

	std::map<int, std::unique_ptr<Character_Model>> m_characterList;

	using Map_Element = std::pair<int, std::unique_ptr<Character_Model>>;

	//************************************
	// Method:    getFirstFreeId Get the first id not inserted in the character map, beginning by 0
	// FullName:  Database::Character_Database::getFirstFreeId
	// Access:    private 
	// Returns:   int The first free id
	// Qualifier:
	//************************************
	int getFirstCharacterFreeId() const;

};

#endif