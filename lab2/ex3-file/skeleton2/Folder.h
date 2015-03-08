#ifndef folder_h
#define folder_h
#include <cstdlib>
#include <cstring>
#include <vector>
#include "File.h"
using namespace std;

class Folder {
	private:
		string _name;
    vector<File*> _files;

	public:
	  Folder();
		Folder(string name);
    	
    string getName();
    	
    void addFile(File* file);
    bool deleteFile(string filename);
    int countSize();
    File* retrieveFile(string filename);
    bool findFile(string filename);
};

#endif
