#ifndef folder_h
#define folder_h

#include <cstdlib>
#include <cstring>
#include <vector>
#include "File.h"
using namespace std;

class Folder {
	private:
		string name;
    	vector<File*> files;

	public:
	    Folder();
		Folder(string name);
    	
    	string getName();
    	
    	void addFile(File* file);
    	void deleteFile(File* file);
    	int countSize();
};

#endif
