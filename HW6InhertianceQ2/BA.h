class BA : public Student {
private:
    int* grades;
    int gradesSize;
public:
    BA(int id, string firstName, string lastName, int numCourses, int* grades, int gradesSize)
        : Student(id, firstName, lastName, numCourses), gradesSize(gradesSize) {
        this->grades = new int[gradesSize];
        for (int i = 0; i < gradesSize; i++) {
            this->grades[i] = grades[i];
        }
    }
    
    ~BA() {
        delete[] grades;
    }

    bool milga() const override {
        if (numCourses < 10) return false;
        int sum = 0;
        for (int i = 0; i < gradesSize; i++) {
            sum += grades[i];
        }
        double avg = sum / (double)gradesSize;
        return avg > 95;
    }

    void print() const override {
        cout << "ID: " << id << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Number of Courses: " << numCourses << endl;
        cout << "Grades: ";
        for (int i = 0; i < gradesSize; i++) {
            cout << grades[i] << " ";
        }
        cout << endl;
    }
};
