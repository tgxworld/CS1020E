#include "Folder.h"

Folder::Folder() {
}

Folder::Folder(string name) {
  this->_name = name;
}

string Folder::getName() {
  return this->_name;
}

/**
*	Add a file to the folder
*	Pre-condition  :
*	Post-condition :
*/ 
void Folder::addFile(File* file) {
  this->_files.push_back(file); 
}

/**
*	Delete a file from a folder
*	Pre-condition  :
*	Post-condition :
*/ 
bool Folder::deleteFile(string filename) {
  for(vector<File*>::iterator iter = this->_files.begin(); iter < this->_files.end(); ++iter) {
    if((*iter)->getName() == filename) {
      this->_files.erase(iter);
      return true;
    }
  }

  return false;
}



/**
*	Count the total size of a folder
*	Pre-condition  :
*	Post-condition :
*/ 
int Folder::countSize() {
  int sum = 0;
  
  for(vector<File*>::iterator iter = this->_files.begin(); iter < this->_files.end(); ++iter) {
    sum += (*iter)->getSize();
  }

  return sum;
}

File* Folder::retrieveFile(string filename) {
  for(vector<File*>::iterator iter = this->_files.begin(); iter < this->_files.end(); ++iter) {
    if((*iter)->getName() == filename) {
      return *iter;
    }
  }

  cout << "File named " << filename << " is not in Folder named " << this->getName() << "." << endl;
  throw;
}

bool Folder::findFile(string filename) {
  for(vector<File*>::iterator iter = this->_files.begin(); iter < this->_files.end(); ++iter) {
    if((*iter)->getName() == filename) {
      return true;
    }
  } 

  return false;
}
