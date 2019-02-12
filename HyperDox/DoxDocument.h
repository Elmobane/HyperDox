#include <string>
#include <vector>

using namespace std;
#pragma once
class DoxDocument
{
public:
	DoxDocument();
	~DoxDocument();
	void SetFileName(string fn);
	void SetEntireDox(string str);
	string GetEntireDox();
	void StoreDoxContents();
	int GetIndexSize();
	int GetWordCount(string& strString);
	string getContents(string fileName, vector<string>& vect);

private:
	string fileName;
	vector<string> indexDox;
	string entireDox;
};

