/**
*	Name			:
*	Matric-number	:
*	Plab account	:
*/
#include <iostream>
#include <cstdio>
#include "Folder.h"
using namespace std;

string getLargest(vector<Folder*> folders) {
  Folder *largestFolder = folders.front();

  for(vector<Folder*>::iterator iter = folders.begin() + 1; iter < folders.end(); ++iter) {
    if((*iter)->countSize() > largestFolder->countSize()) {
      largestFolder = *iter;
    }
  }

  return largestFolder->getName();
}

Folder * getFolderByName(vector<Folder*> &folders, string name) {
  for(vector<Folder*>::iterator iter = folders.begin(); iter < folders.end(); ++iter) {
    if((*iter)->getName() == name) {
      return *iter;
    }
  }

  cout << "Folder not found" << endl;
  throw;
};

Folder * getFolderByFilename(vector<Folder*> &folders, string filename) {
  for(vector<Folder*>::iterator iter = folders.begin(); iter < folders.end(); ++iter) {
    if((*iter)->findFile(filename)) {
      return *iter;
    }
  }

  cout << "File not found" << endl;
  throw;
};

int main() {
    // read input
    int numOfOperations;
    cin >> numOfOperations;
    vector<Folder*> folders;

    for(int i = 0; i < numOfOperations; ++i) {
      string operation;
      cin >> operation;

      if(operation == "Createfolder") {
        string foldername;
        cin >> foldername;
        // Folder folder(foldername);
        // folders.push_back(&folder);
        folders.push_back(new Folder(foldername));
      }

      if(operation == "Createfile") {
        string filename, foldername;
        int size;
        cin >> filename >> size >> foldername;
        // File file(filename, size, foldername);
        Folder *folder;
        folder = getFolderByName(folders, foldername);
        (*folder).addFile(new File(filename, size, foldername));
        // (*folder).addFile(&file);
      }

      if(operation == "Count") {
        string foldername;
        cin >> foldername;
        Folder *folder;
        folder = getFolderByName(folders, foldername);
        cout << folder->countSize() << endl;
      }

      if(operation == "Deletefile") {
        string filename;
        cin >> filename;
        Folder *folder;
        folder = getFolderByFilename(folders, filename);
        folder->deleteFile(filename);
      }

      if(operation == "Movefile") {
        string filename, foldername;
        cin >> filename >> foldername;
        Folder *oldFolder;
        oldFolder = getFolderByFilename(folders, filename);
        Folder *newFolder;
        newFolder = getFolderByName(folders, foldername);
        File *file;
        file = oldFolder->retreiveFile(filename);
        oldFolder->deleteFile(filename);
        file->setFolderName(oldFolder->getName());
        newFolder->addFile(file);
      }

      if(operation == "Findlargest") {
        cout << getLargest(folders) << endl;
      }
    }

    return 0;
}
