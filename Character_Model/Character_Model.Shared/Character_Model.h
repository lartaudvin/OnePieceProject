#pragma once
#ifndef CHARACTER_MODEL_H
#define CHARACTER_MODEL_H

#include <string>
#include <Character_Model/Character_Model.Shared/CharacterInfos.h>
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

	void exportToXml(const std::string& folder_path) const;
	void importFromXml(const std::string& folder_path);
	const std::string& getPhotoRessourcePath() const;
	void setPhotoRessourcePath(const std::string& path);

private:

	std::string m_name_id;
	std::unique_ptr<CharacterInfos> m_infos;
};

#endif