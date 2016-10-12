// NativeTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Database\Database.Shared\Character_Database.h"
#include "Character_Model\Character_Model.Shared\Character_Model.h"
#include "Exception_Manager\Exception_Manager.Shared\Exception_Manager.h"

using namespace std;

int main()
{
	string character_path = "F:\\Users\\Vince\\Documents\\Visual Studio 2015\\Projects\\One Piece Project\\Resources\\Characters";
	Character_Database *database = new Character_Database();

	database->insert_character(std::make_unique<Character_Model>("Luffy", "Monkey D. Luffy"));
	database->setCharacterFullNameAt(0, "toto");

	delete database;

    return 0;
}

