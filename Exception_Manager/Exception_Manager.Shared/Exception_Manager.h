#pragma once

#include <exception>

namespace ExceptionManager
{

	class xml_folder_not_exists_exception : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "The xml folder does not exist";
		}
	};

	class key_already_exists : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "The given key already exists";
		}
	};
}