#ifndef BA_H
#define BA_H

#include "Student.h"
#include <vector>
#include <string>
using namespace std;

class BA : public Student {
protected:
    vector<int> grades;

public:
    // Constructors
    BA();
     ~BA();
    BA(int id, const std::string& first, const std::string& last, int courses, const std::vector<int>& grades);
    // Rule of 5: Destructor
    //virtual ~BA();
    // Rule of 5: Copy constructor
    BA(const BA& other);
    // Rule of 5: Copy assignment operator
    BA& operator=(const BA& other);
    // Rule of 5: Move constructor
    BA(BA&& other) noexcept;
    // Rule of 5: Move assignment operator
    BA& operator=(BA&& other) noexcept;

    // Methods
    void input() override;
    void print() const override;
    double calculateAverage() const;
    bool milga() const override;
    std::string studType() const override;
    bool operator<(const Student& rhs) const override;

protected:
    const std::vector<int>& getGrades() const;
};

#endif // BA_H
