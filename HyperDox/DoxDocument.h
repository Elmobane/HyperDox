#include <string>
#include <vector>

using namespace std;
#pragma once
class DoxDocument
{
public:
	DoxDocument();
	DoxDocument(string file);
	~DoxDocument();
	void SetFileName(string fn);
	void SetEntireDox(string str);
	string GetEntireDox();
	void StoreDoxContents();
	int GetIndexSize();
	int GetWordCount(string& strString);
	string getContents(string fileName, vector<string>& vect);
	void AddFile(string file);
	void LoadFolder();
	void SortWordIndex();

private:
	string fileName;
	vector<string> fileNames;
	vector<string> fileContents;
	vector<string> indexDox;
	vector<string> globalWordIndex;
	vector<string> links;
	string entireDox;
};

