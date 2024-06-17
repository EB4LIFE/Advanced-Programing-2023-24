class MA : public BA {
private:
    bool research;
public:
    MA(int id, string firstName, string lastName, int numCourses, int* grades, int gradesSize, bool research)
        : BA(id, firstName, lastName, numCourses, grades, gradesSize), research(research) {}

    bool milga() const override {
        if (numCourses < 7) return false;
        if (!research) return false;
        int sum = 0;
        for (int i = 0; i < gradesSize; i++) {
            sum += grades[i];
        }
        double avg = sum / (double)gradesSize;
        return avg > 90;
    }

    void print() const override {
        BA::print();
        cout << "Research: " << (research ? "Yes" : "No") << endl;
    }
};
