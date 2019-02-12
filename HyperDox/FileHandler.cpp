#include "pch.h"
//#include <iostream>
//#include <string>
//#include <filesystem>
//#include "io.h"
//#include <fstream>
//#include <streambuf>
//#include <sstream>
//#include "FileHandler.h"
//
//
//using namespace std;
//
//
//
//int FileHandler::GetWordCount(string& strString) {
//
//
//	int nSpaces = 0;
//	unsigned int i = 0;
//
//	// Skip over spaces at the beginning of the word
//	while (isspace(strString.at(i)))
//		i++;
//
//	for (; i < strString.length(); i++)
//	{
//		if (isspace(strString.at(i)))
//		{
//			nSpaces++;
//
//			// Skip over duplicate spaces & if a NULL character is found, we're at the end of the string
//			/*while (isspace(strString.at(i++)))
//				if (strString.at(i) == '\0')
//					nSpaces--;*/
//		}
//	}
//
//	// The number of words = the number of spaces + 1
//	return nSpaces + 1;
//}
//
//string FileHandler::getContents(string fileName, vector<string>& vect) {
//	ifstream inFile;
//	string str;
//
//	inFile.open(fileName);
//
//	stringstream strStream;
//
//	strStream << inFile.rdbuf();
//
//	str = strStream.str();
//
//	// Starts from beginning of file
//	inFile.clear();
//	inFile.seekg(0, ios::beg);
//
//	// Add to vector
//	string temp;
//
//	// checks if it is open
//	if (!inFile.is_open()) {
//		// cout << "could not open file";
//		return "could not open file";
//	}
//
//	// parses content of file
//	while (!inFile.eof()) {
//		inFile >> temp;
//
//		// removes uneeded punctuation before adding to vector
//		temp.erase(remove_if(temp.begin(),
//			temp.end(),
//			[](char c)
//		{ return c == ',' || c == '.' || c == '!' || c == ')' || c == '('; }
//		), temp.end());
//
//		// adds cleaned word to vector
//		vect.push_back(temp);
//
//		// if successful, word is printed
//		if (!inFile.fail()) {
//			cout << "added: " << temp << endl;
//		}
//	}
//	//cout << str << endl;
//
//	inFile.close();
//
//	return str;
//}