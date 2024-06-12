// Eitan Brown 346816549
#pragma once
#ifndef WORKERSFILE_H
#define WORKERSFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include "Worker.h"
using namespace std;

enum FILE_STATUS { ERROR, CLOSED, OPEN_R, OPEN_W };

class WorkersFile {
private:
    string fileName;
    fstream iofile;
    FILE_STATUS status;
    int size;

    bool openNewFileForWriting();
    bool openFileForReading();
    void closeFile();

public:
    WorkersFile(const string& fname);
    WorkersFile(const WorkersFile& other);
    ~WorkersFile();
    
    friend istream& operator>>(istream& input, WorkersFile& wf);
    friend ostream& operator<<(ostream& output, WorkersFile& wf);
    
    void sort(bool ascending = true);
    Worker operator[](int index);
    WorkersFile& operator+=(float bonus);
    WorkersFile operator+(WorkersFile& other);
};

#endif // WORKERSFILE_H
