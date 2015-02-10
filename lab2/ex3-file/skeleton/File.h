#ifndef file_h
#define file_h

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class File {
	private:
    	string name;
    	int size;
    	string foldername;

	public:
	    File();
	    File(string name, int size, string foldername);

	    string getName();
	    int getSize();
	    string getFolderName();
	   
	    void setFolderName(string foldername);
};

#endif
