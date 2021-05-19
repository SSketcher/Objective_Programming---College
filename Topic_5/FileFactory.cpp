#include "FileFactory.h"
#include "CsvFIle.h"
#include "BinaryFile.h"
#include <sstream>
#include <vector>


FileFactory::FileFactory()			//Constructor
{
}


FileFactory::~FileFactory()			//Destktor
{
}

IFile *FileFactory::OpenFile(std::string path, std::string openMode)			//Method recognizing the type of file to open
{
	vector<string> temp;
	string s;
	stringstream ss(path);
	while (getline(ss, s, '.'))
	{
		temp.push_back(s);
	}

	if (temp.back() == "csv") return new CsvFIle(path, openMode);
	if (temp.back() == "bin") return new BinaryFile(path, openMode);
}

