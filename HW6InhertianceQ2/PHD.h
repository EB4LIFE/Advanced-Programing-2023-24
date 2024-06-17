class PHD : public Student {
private:
    int researchHours;
public:
    PHD(int id, string firstName, string lastName, int numCourses, int researchHours)
        : Student(id, firstName, lastName, numCourses), researchHours(researchHours) {}

    bool milga() const override {
        return numCourses >= 2 && researchHours > 25;
    }

    void print() const override {
        cout << "ID: " << id << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Number of Courses: " << numCourses << endl;
        cout << "Hours: " << researchHours << endl;
    }
};
