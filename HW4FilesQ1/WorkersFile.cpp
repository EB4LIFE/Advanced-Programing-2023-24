#include "WorkersFile.h"

// Helper function to open a new file for writing
bool WorkersFile::openNewFileForWriting() {
    if (status != CLOSED) {
        cout << "ERROR" << endl;
        return false;
    }
    iofile.open(fileName, ios::out);
    if (iofile.is_open()) {
        status = OPEN_W;
        return true;
    } else {
        status = ERROR;
        cout << "ERROR" << endl;
        return false;
    }
}

// Helper function to open a file for reading
bool WorkersFile::openFileForReading() {
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

// Helper function to close the file
void WorkersFile::closeFile() {
    if (iofile.is_open()) {
        iofile.close();
    }
    status = CLOSED;
}

// Constructor
WorkersFile::WorkersFile(const string& fname) : fileName(fname), size(0), status(CLOSED) {
    openNewFileForWriting();
    closeFile();
}

// Copy constructor
WorkersFile::WorkersFile(const WorkersFile& other) : fileName(other.fileName), size(other.size), status(CLOSED) {
}

// Destructor
WorkersFile::~WorkersFile() {
    closeFile();
}

// Input operator>>
istream& operator>>(istream& input, WorkersFile& wf) {
    if (!wf.openNewFileForWriting()) return input;
    Worker w;
    while (input >> w) {
        if (0 == w) break;
        wf.iofile << w << endl;
        wf.size++;
    }
    wf.closeFile();
    return input;
}

// Output operator<<
ostream& operator<<(ostream& output, WorkersFile& wf) {
    if (!wf.openFileForReading()) return output;
    Worker w;
    while (wf.iofile >> w) {
        output << w << endl;
    }
    wf.closeFile();
    return output;
}

// Sort method
void WorkersFile::sort(bool ascending) {
    if (!openFileForReading()) return;

    Worker* workers = new Worker[size];
    int count = 0;
    Worker w;
    while (iofile >> w && count < size) {
        workers[count++] = w;
    }
    closeFile();

    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            bool condition = ascending ? !workers[j + 1].compare(workers[j]) : workers[j + 1].compare(workers[j]);
            if (!condition) {
                Worker temp = workers[j];
                workers[j] = workers[j + 1];
                workers[j + 1] = temp;
            }
        }
    }

    if (!openNewFileForWriting()) {
        delete[] workers;
        return;
    }
    for (int i = 0; i < count; ++i) {
        iofile << workers[i] << endl;
    }
    closeFile();
    delete[] workers;
}

// Operator[] for extracting a Worker by index
Worker WorkersFile::operator[](int index) {
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

// Operator+= to add a bonus to all workers
WorkersFile& WorkersFile::operator+=(float bonus) {
    if (!openFileForReading()) return *this;

    Worker* workers = new Worker[size];
    int count = 0;
    Worker w;
    while (iofile >> w && count < size) {
        workers[count++] = w;
    }
    closeFile();

    for (int i = 0; i < count; ++i) {
        workers[i] += bonus;
    }

    openNewFileForWriting();
    for (int i = 0; i < count; ++i) {
        iofile << workers[i] << endl;
    }
    closeFile();
    delete[] workers;
    return *this;
}

// Operator+ to merge with another file
WorkersFile WorkersFile::operator+(WorkersFile& other) {
    WorkersFile mergedFile("merged_" + fileName + "_" + other.fileName);

    if (!mergedFile.openNewFileForWriting()) {
        return mergedFile;
    }

    if (openFileForReading()) {
        Worker w;
        while (iofile >> w) {
            mergedFile.iofile << w << endl;
            mergedFile.size++;
        }
        closeFile();
    }

    if (other.openFileForReading()) {
        Worker w;
        while (other.iofile >> w) {
            mergedFile.iofile << w << endl;
            mergedFile.size++;
        }
        other.closeFile();
    }

    mergedFile.closeFile();
    return mergedFile;
}
