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
		m_characterList.insert({ getFirstCharacterFreeId(), std::move(input_character) });
	}
	catch (...)
	{
		throw;
	}
}

Character_Model* Character_Database::getCharacterById(int id)
{
	return m_characterList[id].get();
}

Character_Model* Character_Database::getCharacterByName(const std::string& name)
{
	for (const auto& e : m_characterList)
	{
		if (e.second->getName() == name)
		{
			return e.second.get();
		}
	}

	return nullptr;
	/*
	auto e = std::find_if(
		m_characterList.begin(),
		m_characterList.end(),
		[&name](const Map_Element& v) -> bool {
			return v.second->getName() == name;
		}
	);

	return *e->second;
	*/
}

int Character_Database::getFirstCharacterFreeId() const
{
	for (int result = 0; /*for-ever*/; result++)
	{
		try
		{
			auto&& e = m_characterList.at(result);
		}
		catch (const out_of_range&)
		{
			return result;
		}
	}

	return -1;
}

void Character_Database::exportXml(const std::string& folder_path) const
{
	if (!exists(folder_path))
	{
		throw xml_folder_not_exists_exception();
	}
	for (auto it = m_characterList.cbegin(), e = m_characterList.cend(); it != e; ++it)
	{
		try
		{
			const auto& current_model = it->second;
			const auto& current_name = current_model->getName();
			stringstream stream;
			stream << folder_path << "\\" << it->first << "_" << current_name;
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
				int id = stoi(tokens[0]);

				try
				{
					auto&& e = m_characterList.at(id);
				}
				catch (const out_of_range&)
				{
					id = this->getFirstCharacterFreeId();
				}
				catch (...)
				{
					throw;
				}

				m_characterList.insert({ id, std::move(current_model) });
			}
		}
	}
	catch (...)
	{
		throw;
	}
}
