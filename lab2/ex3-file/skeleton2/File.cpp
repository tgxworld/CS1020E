#include "File.h"

File::File() {
}

File::File(string name, int size, string foldername) {
  this->_name = name;
  this->_size = size;
  this->_foldername = foldername;
}

string File::getName() {
	return this->_name;
}

int File::getSize() {
	return this->_size;
}

string File::getFolderName() {
	return this->_foldername;
}

void File::setFolderName(string foldername) {
  this->_foldername = foldername;
}
