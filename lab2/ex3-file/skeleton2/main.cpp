#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include "Folder.h"
using namespace std;

/**
*	Find largest folder from a list of folders
*	Pre-condition  :
*	Post-condition :
*/ 
string findLargest(vector<Folder*> folders) {
  vector<Folder*>::iterator iter = folders.begin();
  vector<Folder*>::iterator largestIter = iter;

  for(iter = iter + 1; iter < folders.end(); ++iter) {
    if((*largestIter)->countSize() < (*iter)->countSize()) {
      largestIter = iter;
    }
  }  

	return (*largestIter)->getName();
}

Folder* findFolderByName(vector<Folder*> folders, string folderName) {
  for(vector<Folder*>::iterator iter = folders.begin(); iter < folders.end(); ++iter) {
    if((*iter)->getName() == folderName) {
      return *iter;
    } 
  }

  cout << "No folder named: " <<  folderName << " found." << endl;
  throw;
}

bool deleteFile(vector<Folder*> folders, string filename) {
  for(vector<Folder*>::iterator iter = folders.begin(); iter < folders.end(); ++iter) {
    if((*iter)->deleteFile(filename)) {
      return true;
    }
  }

  cout << "No file named: " << filename << " found." << endl;
  throw;
}

Folder* findFolderByFilename(vector<Folder*> folders, string filename) {
  for(vector<Folder*>::iterator iter = folders.begin(); iter < folders.end(); ++iter) {
    if((*iter)->findFile(filename)) {
      return *iter;
    }
  }

  cout << "No such file named: " << filename << " found." << endl;
  throw;
}

int main() {
  // read input
  int numOperations;
  cin >> numOperations;
  vector<Folder*> folders;

  string operation;
  while(cin >> operation) {
    if(operation == "Createfile") {
      string filename, foldername;
      int size;

      cin >> filename >> size >> foldername;
      //File file(filename, size, foldername);
      Folder* folder = findFolderByName(folders, foldername);
      folder->addFile(new File(filename, size, foldername)); 
    } else if(operation == "Createfolder") {
      string foldername;
      cin >> foldername;
      folders.push_back(new Folder(foldername));
    } else if(operation == "Deletefile") {
      string filename;
      cin >> filename;
      deleteFile(folders, filename);
    } else if(operation == "Movefile") {
      string filename, foldername;
      cin >> filename >> foldername;
      Folder* oldfolder;
      oldfolder = findFolderByFilename(folders, filename);
      File* file = oldfolder->retrieveFile(filename);
      oldfolder->deleteFile(filename);
      file->setFolderName(foldername);
      Folder* newfolder = findFolderByName(folders, foldername);
      newfolder->addFile(file);
    } else if(operation == "Count") {
      string foldername;
      cin >> foldername;
      Folder* folder = findFolderByName(folders, foldername);
      cout << folder->countSize() << endl;
    } else if(operation == "Findlargest") {
      cout << findLargest(folders) << endl;
    }
  }
    
  // output
  return 0;
}
