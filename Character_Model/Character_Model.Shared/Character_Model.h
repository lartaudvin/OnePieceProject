#pragma once
#ifndef CHARACTER_MODEL_H
#define CHARACTER_MODEL_H

#include <string>
#include <Character_Model/Character_Model.Shared/CharacterInfos.h>
#include <Character_Model/Character_Model.Shared/Caracteristics.h>
#include "Character_Model/Character_Model.Shared/LevelBuilder.h"
#include <boost/noncopyable.hpp>
#include <memory>

class Character_Model : public boost::noncopyable
{
public:
	Character_Model();
	Character_Model(const std::string& name);

	~Character_Model();
	const std::string& getName() const;
	CharacterInfos& getInfos() const;
	Caracteristics& getCharacteristics() const;

	void exportToXml(const std::string& folder_path) const;
	void exportLevelCaracteristics(const std::string& folder_path, LevelBuilder builder) const;
	void importFromXml(const std::string& folder_path, int level);
	LevelBuilder importLevelCaracteristics(const std::string& folder_path) const;

private:

	std::string m_name_id;
	std::unique_ptr<CharacterInfos> m_infos;
	std::unique_ptr<Caracteristics> m_caracteristics;
};

#endif