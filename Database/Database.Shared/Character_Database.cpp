#include "Character_Database.h"
#include <iostream>
#include <sstream>
#include "boost/filesystem.hpp"
#include "boost/algorithm/string.hpp"

#include <Character_Model/Character_Model.Shared/Character_Model.h>
#include <Exception_Manager/Exception_Manager.Shared/Exception_Manager.h>

using namespace std;
using namespace ExceptionManager;
using namespace boost::filesystem;

Character_Database::Character_Database()
	: m_characterList()
{
}

Character_Database::~Character_Database()
{
}

void Character_Database::insert_character(std::unique_ptr<Character_Model>&& input_character)
{
	try
	{
		for (auto&& character : m_characterList)
		{
			if (character->getName().compare(input_character->getName()) == 0)
			{
				throw ExceptionManager::key_already_exists();
			}
		}

		m_characterList.push_back(std::move(input_character));
	}
	catch (...)
	{
		throw;
	}
}

Character_Model* Character_Database::getCharacterAt(int id)
{
	return m_characterList[id].get();
}

Character_Model* Character_Database::getCharacterByName(const std::string& name)
{
	for (const auto& e : m_characterList)
	{
		if (e->getName() == name)
		{
			return e.get();
		}
	}

	return nullptr;
}

void Character_Database::exportXml(const std::string& folder_path) const
{
	if (!exists(folder_path))
	{
		throw xml_folder_not_exists_exception();
	}
	auto folder_boost_path = path{ folder_path };
	directory_iterator end_itr;

	for (auto itr = directory_iterator{ folder_boost_path }; itr != end_itr; ++itr)
	{
		path current_path = itr->path();
		remove_all(current_path);
	}

	for (auto it = m_characterList.cbegin(), e = m_characterList.cend(); it != e; ++it)
	{
		try
		{
			const auto& current_model = *it;
			const auto& current_name = current_model->getName();
			stringstream stream;
			stream << folder_path << "\\" << current_name;
			auto current_folder_path = stream.str();

			if (exists(current_folder_path))
			{
				create_directory(current_folder_path);
			}

			current_model->exportToXml(current_folder_path);
		}
		catch (...)
		{
			throw;
		}
	}
}

void Character_Database::importXml(const std::string& folder_path)
{
	if (!exists(folder_path))
	{
		throw xml_folder_not_exists_exception();
	}
	try
	{
		auto folder_boost_path = path{ folder_path };
		directory_iterator end_itr;

		for (auto itr = directory_iterator{ folder_boost_path }; itr != end_itr; ++itr)
		{
			path current_path = itr->path();
			if (is_directory(current_path))
			{
				auto current_model = std::make_unique<Character_Model>();
				current_model->importFromXml(current_path.string());

				vector<string> tokens;
				boost::split(tokens, current_path.string(), boost::is_any_of("\\"));
				boost::split(tokens, tokens[tokens.size() - 1], boost::is_any_of("_"));

				m_characterList.push_back({ std::move(current_model) });
			}
		}
	}
	catch (...)
	{
		throw;
	}
}

const std::string& Character_Database::getCharacterNameAt(int id) const
{
	return m_characterList.at(id)->getName();
}

void Character_Database::setCharacterNameAt(int id, const std::string& name)
{
	m_characterList.at(id)->setName(name);
}

const std::string& Character_Database::getCharacterFullNameAt(int id) const
{
	return m_characterList.at(id)->getFullName();
}

void Character_Database::setCharacterFullNameAt(int id, const std::string& fullname)
{
	m_characterList.at(id)->setFullName(fullname);
}

int Character_Database::countCharacters() const
{
	return m_characterList.size();
}
