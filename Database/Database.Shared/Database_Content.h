#pragma once
#ifndef DATABASE_CONTENT_H
#define DATABASE_CONTENT_H
#include "Character_Database.h"
#include <string>

using namespace std;

namespace Database
{
	class Database_Content
	{
	public:
		Database_Content();
		~Database_Content();

	private:
		Character_Database *m_characterDatabase;
		void addCharacter(string name, string fullname);
	};
}
#endif