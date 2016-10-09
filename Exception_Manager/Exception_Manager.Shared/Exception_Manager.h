#pragma once

#include <exception>

namespace ExceptionManager
{
	using namespace std;

	class xml_folder_not_exists_exception : public exception
	{
		virtual const char* what() const throw()
		{
			return "The xml folder does not exist";
		}
	};
}