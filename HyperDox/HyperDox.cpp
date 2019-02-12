// HyperDox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "dirent.h"
#include <iostream>
#include <string>
#include <filesystem>
#include "io.h"
#include <fstream>
#include <streambuf>
#include <sstream>
#include "DoxDocument.h"
//#include "fileapi.h"
//#include <Windows.h>

using namespace std;


vector<string> get_all_files_names_within_folder(string folder)
{
	vector<string> names;
	string search_path = folder + "/*.dox";
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				names.push_back(fd.cFileName);
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
	return names;
}

int main()
{
	ifstream doxDoc;
	string fileName = "Zoos.dox";
	vector<string> indexDox;
	string temp;
	string entireDox;
	string str;
	vector<string> fileList;

	DoxDocument dd;

	dd.SetFileName(fileName);

	dd.StoreDoxContents();

	cout << dd.GetIndexSize() << endl;

	//cout << dd.GetEntireDox() << endl;

	//fileList = get_all_files_names_within_folder("C:\\test\\");


	/*doxDoc.open(fileName);

	if (!doxDoc.is_open()) {
		cout << "Could not open: " << fileName << endl;
	}*/

	//str = getContents(fileName, indexDox);

	//cout << indexDox.size();

	//for (size_t i = 0; i < str.length(); i++)
	//{
	//	
	//	//getline(doxDoc, temp);

	//	//str >> temp;

	//	indexDox.push_back(temp);
	//}

	//doxDoc.close();

	/*for (string i : indexDox) {
		cout << i;
	}*/

	

	//cout << "Words: " << GetWordCount(str);

}


