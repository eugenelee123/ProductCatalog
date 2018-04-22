//****************************************************************************************
//
//    INCLUDE FILES
//
//****************************************************************************************
#include    <fstream>
#include    <iostream>
#include    <string>
#include    "Catalog.h"

using namespace std;

bool    Catalog::AddCategory(uint64_t categoryNumber, const string& name)
{
	if (categorymap.empty() || categorymap.find(categoryNumber) == categorymap.end())
	{
		Product s(name);
		categorymap[categoryNumber] = s;
		return true;
	}

	else
		return false;
}

bool    Catalog::AddProduct(uint64_t categoryNumber, uint64_t productNumber, const string& name)
{
	if (categorymap[categoryNumber].productmap.empty()) {
		categorymap[categoryNumber].productmap[productNumber] = name;
		return true;
	}

	//categoryNumber must exist. if it  doesn't exist then addCategory. 
	//find if productNumber reaches end
	if (categorymap.empty() || categorymap.find(categoryNumber) == categorymap.end())
		return false;
	else if (categorymap[categoryNumber].productmap.empty() || categorymap[categoryNumber].productmap.find(productNumber) == categorymap[categoryNumber].productmap.end()) {
		categorymap[categoryNumber].productmap[productNumber] = name;
		return true;
	}
	else
		return false;
}

uint64_t Catalog::GetCategoryCount()
{
	return categorymap.size();
}

int64_t    Catalog::GetProductCount(uint64_t categoryNumber)
{
	if (categorymap.find(categoryNumber) != categorymap.end()) {
		return categorymap[categoryNumber].productmap.size();
	}
	return 0;
}

bool Catalog::Load(const string& fileName)
{
	// to be completed
	uint64_t categoryNumber, productNumber;
	std::string categoryname, productname, line, tag;
	std::fstream myfile(fileName);

	if (myfile.is_open())
	{
		while (std::getline(myfile, line))
		{
			std::istringstream ss(line);
			size_t position = line.find("Category");
			if (position != std::string::npos)
			{
				getline(ss, tag, '\t');
				ss >> categoryNumber;
				std::getline(ss, categoryname);
				AddCategory(categoryNumber, categoryname);
			}

			else if (position == std::string::npos)
			{
				ss >> productNumber;
				getline(ss, productname);
				AddProduct(categoryNumber, productNumber, productname);
			}
		}
		myfile.close();
		return true;
	}

	else
	{
		throw std::invalid_argument("Could not open file" + fileName);
		return false;
	}

}

//****************************************************************************************
//
//    Show... methods
//
//    The stream argument allows thess functions to write its output to any output stream,
//    such as cout or a file, that the caller passes. The argument's name "stream" should
//    be used just as you would use "cout":
//
//        stream << "X = " << x << endl;
//
//    The output will go where the caller intended without special action by this function.
//
//****************************************************************************************

bool    Catalog::ShowProduct(ostream& stream, uint64_t categoryNumber, uint64_t productNumber)
{

	return true;
}

bool    Catalog::ShowCategory(ostream& stream, uint64_t categoryNumber)
{
	if (categorymap.find(categoryNumber) != categorymap.end())
	{
		return true;
	}
	return false;
}

bool    Catalog::ShowAll(ostream& stream)
{

	return true;
}