#include <string>
#include <vector>
#include "pch.h"
#include "DoxDocument.h"
#include "dirent.h"


#include <iostream>

#include <filesystem>
#include "io.h"
#include <fstream>
#include <streambuf>
#include <sstream>



using namespace std;



DoxDocument::DoxDocument()
{
}

DoxDocument::DoxDocument(string file)
{
	fileName = file;
	fileNames.push_back(file);
	StoreDoxContents();
}


DoxDocument::~DoxDocument()
{
}

void DoxDocument::AddFile(string file) {
	fileName = file;
	fileNames.push_back(file);
	StoreDoxContents();
}

void DoxDocument::SetFileName(string fn)
{
	fileName = fn;
}

void DoxDocument::SetEntireDox(string str) {
	entireDox = str;
}

string DoxDocument::GetEntireDox() {
	return entireDox;
}

int DoxDocument::GetIndexSize() {
	return globalWordIndex.size();
}

void DoxDocument::StoreDoxContents() {
	fileContents.push_back(DoxDocument::getContents(fileName, globalWordIndex));
	// string temp = DoxDocument::getContents(fileName, indexDox);
	//SetEntireDox(temp);
}

int DoxDocument::GetWordCount(string& strString) {


	int nSpaces = 0;
	unsigned int i = 0;

	// Skip over spaces at the beginning of the word
	while (isspace(strString.at(i)))
		i++;

	for (; i < strString.length(); i++)
	{
		if (isspace(strString.at(i)))
		{
			nSpaces++;

			// Skip over duplicate spaces & if a NULL character is found, we're at the end of the string
			/*while (isspace(strString.at(i++)))
				if (strString.at(i) == '\0')
					nSpaces--;*/
		}
	}

	// The number of words = the number of spaces + 1
	return nSpaces + 1;
}

void DoxDocument::SortWordIndex() {
	// Using sort function with lambda to so it with case
	sort(globalWordIndex.begin(), globalWordIndex.end(), [](const string& a, const string& b) -> bool {
		for (size_t c = 0; c < a.size() and c < b.size(); c++) {
			if (tolower(a[c]) != tolower(b[c]))
				return (tolower(a[c]) < tolower(b[c]));
		}
		return a.size() < b.size();
	});
}

string DoxDocument::getContents(string fileName, vector<string>& vect) {
	ifstream inFile;
	string str;

	inFile.open(fileName);

	stringstream strStream;

	strStream << inFile.rdbuf();

	str = strStream.str();

	// Starts from beginning of file
	inFile.clear();
	inFile.seekg(0, ios::beg);

	// Add to vector
	string temp;

	// checks if it is open
	if (!inFile.is_open()) {
		// cout << "could not open file";
		return "could not open file";
	}

	// parses content of file
	while (!inFile.eof()) {
		inFile >> temp;

		if (temp != fileName) {
			// removes uneeded punctuation before adding to vector
			temp.erase(remove_if(temp.begin(),
				temp.end(),
				[](char c)
			{ return c == ',' || c == '.' || c == '!' || c == ')' || c == '(' || c == '/' || c == '\\' || c == '|' || c == '"' || c == ';'
				|| c == '#' || c == ':' || c == '$'; }
			), temp.end());

			// adds cleaned word to vector
			vect.push_back(temp);

			// if successful, word is printed
			if (!inFile.fail()) {
				//cout << "added: " << temp << endl;
			}
		}
		
	}
	//cout << str << endl;

	inFile.close();

	return str;
}

void DoxDocument::LoadFolder()
{
	string folder = "";
	//vector<string> names;
	string search_path = folder + "*.dox";
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				//names.push_back(fd.cFileName);
				AddFile(fd.cFileName);
				
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
}