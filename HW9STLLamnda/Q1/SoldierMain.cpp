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
    stop,                  // End program
    addNewSoldier,         // Add new soldier
    medalList,             // Print all soldiers entitled to a medal
    mostSociometric,       // Find soldier with highest sociometric score
    countMedalPrivate,     // Count private soldiers entitled to a medal
    noCombatCommander,     // List commanders not in combat
    overSoldier,           // Check for soldiers with more than 15 operations
    removeOfficer          // Remove officers with 0 operations
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
                addSoldier(soldiers);  // Add new soldier
                break;

            case medalList:
                printMedalRecipients(soldiers);  // Print entitled for a medal
                break;

            case mostSociometric:
            {
                Officer* topOfficer = findTopSociometricOfficer(soldiers); // Find officer with most sociometric score
                if (!topOfficer) {
                    break; // No officers in the army
                }
                cout << "Officer soldier with most sociometric score: ";
                cout << topOfficer->getFirstName() << ' ' << topOfficer->getLastName() << endl;
                break;
            }

            case countMedalPrivate:
            {
                cout << "number of privates that received medals: "; // Count private soldiers entitled for a medal
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
                    cout << "there is a soldier that takes more than 15 operations\n";
                }
                else {
                    cout << "no soldier takes more than 15 operations\n";
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
                soldiers.erase(newEnd, soldiers.end()); // Ensure to actually remove the elements
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

    // Clean up allocated memory
    for (Soldier* soldier : soldiers) {
        delete soldier;
    }

    return 0;
}

void addSoldier(vector<Soldier*>& soldiers) {
    int choice, id, numOperations, sociometricScore;
    string firstName, lastName;

    cout << "enter 1 to add a private soldier\n";
    cout << "enter 2 to add a commander soldier\n";
    cout << "enter 3 to add a officer soldier\n";
    cin >> choice;

    cout << "enter id, first name, last name and number of operations\n";
    cin >> id >> firstName >> lastName >> numOperations;

    if (choice == 3) {
        cout << "enter number of sociometric score\n";
        cin >> sociometricScore;
        soldiers.push_back(new Officer(id, firstName, lastName, numOperations, sociometricScore));
    }
    else if (choice == 2) {
        vector<int> grades(numOperations);
        cout << "enter " << numOperations << " grades\n";
        for (int i = 0; i < numOperations; ++i) {
            cin >> grades[i];
        }
        bool isCombat;
        cout << "enter 1 if the soldier is combat and 0 if not\n";
        cin >> isCombat;
        soldiers.push_back(new Commander(id, firstName, lastName, numOperations, grades, isCombat));
    }
    else if (choice == 1) {
        vector<int> grades(numOperations);
        cout << "enter " << numOperations << " grades\n";
        for (int i = 0; i < numOperations; ++i) {
            cin >> grades[i];
        }
        soldiers.push_back(new PrivateSoldier(id, firstName, lastName, numOperations, grades));
    }
    else {
        cout << "Invalid choice\n";
    }
}

void printMedalRecipients(const vector<Soldier*>& soldiers) {
    for (const auto& soldier : soldiers) {
        if (soldier->medal()) {
            soldier->print();
        }
    }
}

Officer* findTopSociometricOfficer(const vector<Soldier*>& soldiers) {
    Officer* topOfficer = nullptr;
    for (const auto& soldier : soldiers) {
        if (soldier->soldierType() == "officer") {
            Officer* officer = static_cast<Officer*>(soldier);
            if (!topOfficer || officer->getSociometricScore() > topOfficer->getSociometricScore()) {
                topOfficer = officer;
            }
        }
    }
    return topOfficer;
}
