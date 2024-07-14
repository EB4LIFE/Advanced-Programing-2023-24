//346816549
//Eitan Brown -commenr for studying purposes
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Soldier.h"
#include "PrivateSoldier.h"
#include "Commander.h"
#include "Officer.h"

using namespace std;

enum option {
    stop,                  //0-End program
    addNewSoldier,         //1-Add new soldier
    medalList,             //2-Print all soldiers entitled to a medal
    mostSociometric,       //3-Find soldier with highest sociometric score
    countMedalPrivate,     //4-Count private soldiers entitled to a medal
    noCombatCommander,     //5-List commanders not in combat
    overSoldier,           //6-Check for soldiers with more than 15 operations
    removeOfficer          //7-Remove officers with 0 operations
};

void addSoldier(vector<Soldier*>& soldiers);
void printMedalRecipients(const vector<Soldier*>& soldiers);
Officer* findTopSociometricOfficer(const vector<Soldier*>& soldiers);

int main() {
    vector<Soldier*> soldiers;
    int op;
    cout << "enter 0-7\n";
    cin >> op;

    try {
        while (op != stop) {
            switch (op) {
            case addNewSoldier:
                addSoldier(soldiers);  
                break;

            case medalList:
                printMedalRecipients(soldiers);  
                break;

            case mostSociometric:
            {
                Officer* topOfficer = findTopSociometricOfficer(soldiers);
                if (!topOfficer) {
                    break; 
                }
                cout << "Officer with the highest sociometric score: ";
                cout << topOfficer->getFirstName() << ' ' << topOfficer->getLastName() << endl;
                break;
            }

            case countMedalPrivate:
            {
                cout << "number of privates that received medals: "; 
                cout << count_if(soldiers.begin(), soldiers.end(), [](Soldier* s) {
                    return (s->soldierType() == "private" && s->medal());
                    });
                cout << endl;
                break;
            }

            case noCombatCommander:
            {
                cout << "list of noncombat commanders: ";
                for_each(soldiers.begin(), soldiers.end(), [](Soldier* s) {
                    if (s->soldierType() == "commander" && !static_cast<Commander*>(s)->getCombat()) {
                        cout << s->getFirstName() << " " << s->getLastName() << " ";
                    }
                    });
                cout << endl;
                break;
            }

            case overSoldier:
            {
                if (any_of(soldiers.begin(), soldiers.end(), [](Soldier* s) { return s->getNumOperations() > 15; })) {
                    cout << "there is at least one soldier that did more than 15 operations\n";
                }
                else {
                    cout << "no soldier did more than 15 operations\n";
                }
                break;
            }

            case removeOfficer:
            {
                auto newEnd = remove_if(soldiers.begin(), soldiers.end(), [](Soldier* s) {
                    return (s->soldierType() == "officer" && s->getNumOperations() == 0);
                    });
                for_each(soldiers.begin(), newEnd, [](Soldier* s) {
                    s->print();
                    });
                soldiers.erase(newEnd, soldiers.end()); 
                break;
            }
            }
            cout << "enter 0-7\n";
            cin >> op;
        }
    }
    catch (const char* msg) {
        cout << msg << endl;
    }

    //Clean up the dynamic allocated memory
    for (Soldier* soldier : soldiers) {
        delete soldier;
    }

    return 0;
}

void addSoldier(vector<Soldier*>& soldiers) {
    int choice, id, numOperations, sociometricScore;
    string firstName, lastName;
   //prompt for user choice
    cout << "choose a soldier\n";
    cout << "enter 1 to add a private\n";
    cout << "enter 2 to add a commander\n";
    cout << "enter 3 to add an officer\n";
    cin >> choice;
   //no matter the choice they always input the basic four
    cout << "enter id, first name, last name and number of operations\n";
    cin >> id >> firstName >> lastName >> numOperations;
    
   //if user chose the officer
    if (choice == 3) {
        cout << "enter the sociometric score\n";
        cin >> sociometricScore;
        //Create a new Officer object and add it to the end of the soldiers vector
        soldiers.push_back(new Officer(id, firstName, lastName, numOperations, sociometricScore));
    }
    
     //if user chose the commander
    else if (choice == 2) {
        vector<int> grades;
        if (numOperations > 0) {
        grades.resize(numOperations);
        cout << "enter " << numOperations << " grades\n";
        for (int i = 0; i < numOperations; ++i) {
            cin >> grades[i];
        }
        }
        bool isCombat;
        cout << "enter 1 if the soldier is combat and 0 if not\n";
        cin >> isCombat;
        //Create a new Commander object and add it to the end of the soldiers vector
        soldiers.push_back(new Commander(id, firstName, lastName, numOperations, grades, isCombat));
    }
    
    //if user chose the private
    else if (choice == 1) {
        vector<int> grades;
        if (numOperations > 0) {
        grades.resize(numOperations);
        cout << "enter " << numOperations << " grades\n";
        for (int i = 0; i < numOperations; ++i) {
            cin >> grades[i];
        }
        }
        //Create a new PrivateSoldier object and add it to the end of the soldiers vector
        soldiers.push_back(new PrivateSoldier(id, firstName, lastName, numOperations, grades));
    }
    else {
        cout << "Invalid choice\n";
    }
}
//Simple: We check if soldier earned a medal 
//if so: print the soldier.
void printMedalRecipients(const vector<Soldier*>& soldiers) {
    for (const auto& soldier : soldiers) {
        if (soldier->medal()) {
            soldier->print();
        }
    }
}

Officer* findTopSociometricOfficer(const vector<Soldier*>& soldiers) {
    //We initialize a ptr to the top officer and set it to initially set to nullptr
    Officer* topOfficer = nullptr;
    //Iterate through each soldier in the vector as we look for top officer with best score
    for (const auto& soldier : soldiers) {
        //First we Check if the soldier is of type "officer" using soldier type function
        if (soldier->soldierType() == "officer") {
            //Cast the soldier pointer to an Officer (type) ptr
            Officer* officer = static_cast<Officer*>(soldier);
            
            // If topOfficer is not set or the current officer score is > curr topofficer
            if (!topOfficer || officer->getSociometricScore() > topOfficer->getSociometricScore()) {
                //Update topOfficer to point to the current officer
                topOfficer = officer;
            }
        }
    }
    // Return the pointer to the top officer
    return topOfficer;
}
