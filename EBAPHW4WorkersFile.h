
//eitanbrown 346816549
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
//by default
    string fileName;        
    // The name of the file
    fstream iofile;         
    //The object that will handle the file from worker (2 par)
    FILE_STATUS status;     
    //The state of the file: error, closed, open for reading, or open for writing
    int size;               
    // The current number of workers stored in the file

    //Helper methods
    bool openNewFileForWriting() {
        if (status != CLOSED) {
            cout << "ERROR" << endl;
            return false;
        }
        iofile.open(fileName, ios::out);
        if (iofile.is_open()) {
            status = OPEN_W;
            return true;
        } 
        else {
            status = ERROR;
            cout << "ERROR" << endl;
            return false;
        }
    }

    bool openFileForReading() {
        if (status != CLOSED) {
            cout << "ERROR" << endl;
            return false;
        }
        iofile.open(fileName, ios::in);
        if (iofile.is_open()) {
            status = OPEN_R;
            return true;
        } else {
            status = ERROR;
            cout << "ERROR" << endl;
            return false;
        }
    }

    void closeFile() {
        if (iofile.is_open()) {
            iofile.close();
        }
        status = CLOSED;
    }

public:
    // Assignment ctor: receives an instance of string that contains filename and initializes the fields thus:
    //fileName will be assigned the value of the argument, size will be assigned 0.
    //file status will be set to CLOSED 
    //A new empty file is to be created and closed with the name provided in
    //the argument. This can be done by calling openNewFileForWriting and then calling closeFile.
    WorkersFile(const string& fname) : fileName(fname), size(0), status(CLOSED) {
        //the empty file and close file so empty
        openNewFileForWriting();
        closeFile();
    }

    // Copy constructor - of assignment above - but don't have to make another empty file
    WorkersFile(const WorkersFile& other) : fileName(other.fileName), size(other.size), status(CLOSED) {
      
    }

    // Destructor - no DMA delete just close file
    ~WorkersFile() {
        closeFile();
    }
    
    // operator>> input from istream
    //Receives a WorkersFile as a right operand (& but not const).
    //Inputs a loop of Workers where the values of the three fields are
    //inputted consecutively separated by spaces, and writes each of the the
    //workers into the physical file represented by the field iofile belonging
    //to the right operand.
    //The input loop terminates after an empty worker (with id number 0) is
    //inputted. The following == test can be used (with the operator defined in Worker):
    //Each worker will be inputted using the input operator>> defined in Worker.
    //returns a reference to the input object (istream&).
    friend istream& operator>>(istream& input, WorkersFile& wf) {
        if (!wf.openNewFileForWriting()) 
        return input;
        Worker w;
        while (input >> w) {
            if (0 == w) break;
            wf.iofile << w << endl;
            wf.size++;
        }
        wf.closeFile();
        return input;
    }

    // operator<< output to ostream
    //Receives a WorkersFile as a right operand (& but not const).
    //Note: Usually the right operand of this operator is const.
    //Because in this particular case the fstream needs to be modified throughout it cannot be const here.
    //Reads all the workers in the physical file represented by the field iofil and outputs them. 
    //Each worker is to be saved in a Worker instance and then outputted using the operator<< implemented for Worker.
    //Returns a reference to the output object (ostream&).
    friend ostream& operator<<(ostream& output, WorkersFile& wf) {
        if (!wf.openFileForReading()) return output;
        Worker w;
        while (wf.iofile >> w) {
            output << w << endl;
        }
        wf.closeFile();
        return output;
    }

    // sort method
    //def = true 
    //if true remains: workers sorted via ascending order and false via descending
    //we put workers into array and then normal sorting from there
    void sort(bool ascending = true) {
        if (!openFileForReading()) {
            return;
        }
        // Reading workers into an array
        Worker* workers = new Worker[size];
        int count = 0;
        Worker w;
        while (iofile >> w && count < size) {
            workers[count++] = w;
        }
        closeFile();
        // Sorting using a simple sorting algorithm that we all know and love, can you guess which one
        for (int i = 0; i < count - 1; ++i) {
            for (int j = 0; j < count - i - 1; ++j) {
                if ((ascending && workers[j] < workers[j + 1]) ||
                    (!ascending && workers[j + 1] < workers[j])) {
                    Worker temp = workers[j];
                    workers[j] = workers[j + 1];
                    workers[j + 1] = temp;
                }
            }
        }
        //put back into a file 
        openNewFileForWriting();
        for (int i = 0; i < count; ++i) {
            iofile << workers[i] << endl;
        }
        closeFile();
        //deletes created dma
        delete[] workers;
    }

    // operator[] for extracting a Worker by index
    //Receives the index of a worker.
    //Returns a Worker instance with the fields set to the values in the corresponding line in the file.
    //Note: Usually operator[] returns a reference to allow for modification and to prevent copying needlessly. 
    //In this case because the access is to a physical file this is not possible and a
    //Worker instance must be returned (Worker, not Worker&)
    Worker operator[](int index) {
        if (!openFileForReading()) return Worker();

        Worker w;
        for (int i = 0; i <= index; ++i) {
            if (!(iofile >> w)) {
                closeFile();
                return Worker();
            }
        }
        closeFile();
        return w;
    }

    // operator+= to add a bonus to all workers
    //Receives a right operand float as the bonus for all the workers
    //The method reads all the workers into a local array of Workers, adds the
    //bonus to each of the workers and writes them into the file with the new values.
    WorkersFile& operator+=(float bonus) {
        if (!openFileForReading()) return *this;
        //dma as before
        Worker* workers = new Worker[size];
        int count = 0;
        Worker w;
        while (iofile >> w && count < size) {
            workers[count++] = w;
        }
        closeFile();
        //as loop while is in - we add the bonus to worker we are at
        for (int i = 0; i < count; ++i) {
            workers[i] += bonus;
        }
        //then put new values for workers into array
        openNewFileForWriting();
        for (int i = 0; i < count; ++i) {
            iofile << workers[i] << endl;
        }
        //essentially destr
        closeFile();
        //delete for dma
        delete[] workers;
        return *this;
    }

    // operator+ to merge with another file
    //Receives a WorkersFile reference as the right operand.
    //The method creates and returns a new instance of WorkersFile which
    //contains the workers from the right operand file appended to the
    //workers from the left operand file (first left then right).
    WorkersFile operator+(WorkersFile& other) 
    {
    WorkersFile mergedFile("merged_" + fileName + "_" + other.fileName);

    // Open the merged file for writing
    if (!mergedFile.openNewFileForWriting()) {
        return mergedFile;
    }

    // Read workers from the current file and write to mergedFile
    if (openFileForReading()) {
        Worker w;
        while (iofile >> w) {
            mergedFile.iofile << w << endl;
            mergedFile.size++;
        }
        closeFile();
    }

    // Read workers from the other file and write to mergedFile
    if (other.openFileForReading()) {
        Worker w;
        while (other.iofile >> w) {
            mergedFile.iofile << w << endl;
            mergedFile.size++;
        }
        other.closeFile();
    }

    // Close the merged file
    mergedFile.closeFile();

    return mergedFile;
}

};
#endif
