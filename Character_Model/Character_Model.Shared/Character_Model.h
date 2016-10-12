#pragma once
#ifndef CHARACTER_MODEL_H
#define CHARACTER_MODEL_H

#include <string>

#include <boost/noncopyable.hpp>

class Character_Model : public boost::noncopyable
{
public:
	Character_Model() {};
	Character_Model(const std::string& name, const std::string& fullname);

	~Character_Model();
	const std::string& getName() const;
	const std::string& getFullName() const;
	void setFullName(const std::string& name);

	void exportToXml(const std::string& folder_path) const;
	void importFromXml(const std::string& folder_path);

private:

	std::string m_name;
	std::string m_fullname;

};

#endif