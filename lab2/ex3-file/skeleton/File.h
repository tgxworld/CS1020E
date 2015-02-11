#ifndef file_h
#define file_h

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class File {
	private:
    	string _name;
    	int _size;
    	string _foldername;

	public:
	    File();
	    File(string name, int size, string foldername);

	    string getFileName();
	    int getSize();
	    string getFolderName();

	    void setFolderName(string foldername);
};

#endif
