// NativeTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "Database\Database.Shared\Character_Database.h"
#include "Character_Model\Character_Model.Shared\Character_Model.h"

using namespace std;

int main()
{
	string character_path = "F:\\Users\\Vince\\Documents\\Visual Studio 2015\\Projects\\One Piece Project\\Resources\\Characters";
	Database::Character_Database *database = new Database::Character_Database();

	//database->insert_character(new CharacterModel::Character_Model("Luffy", "Monkey D. Luffy"));
	//database->insert_character(new CharacterModel::Character_Model("Zoro", "Zoro"));

	database->importXml(character_path);

	delete database;

    return 0;
}

