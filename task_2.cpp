#include <iostream>
#include <string>
using namespace std;

int getNumberOfParticipants() {
    int participants;
    cout << "Enter the number of senior citizens: ";
    cin >> participants;

    if (participants >= 10 && participants <= 36) {
        return participants;
    } else {
        cout << "Invalid number of participants. The number of participants should be between 10 to 36." << endl;

    }
}

void calculateExpenses(int participants, float &coachExpense, float &pricePerParticipants) {
    char choice;
    int coachHire, mealPrice, ticketPrice;

    if (participants >= 12 && participants <= 16) {
        coachHire = 150;
        mealPrice = 14;
        ticketPrice = 21;
    } else if (participants >= 17 && participants <= 26) {
        coachHire = 190;
        mealPrice = 13.5;
        ticketPrice = 20;
    } else if (participants >= 27 && participants <= 36) {
        coachHire = 225;
        mealPrice = 13;
        ticketPrice = 19;
    }

    cout << "The cost of Hiring Coach is " << coachHire << "$\nPer Head cost of Meal is " << mealPrice
         << "$\nPer Head Ticket price is " << ticketPrice << "$." << endl;

    do {
        if (participants < 16 || participants < 26 || participants < 36) {
            cout << "Do anyone else want to go? (Y/N): ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                participants++;
            } else if (choice == 'N' || choice == 'n') {
                cout << "OK" << endl;
            } else {
                cout << "Invalid choice. Please select Y for yes or N for No." << endl;
            }
        } else {
            break;
        }
    } while (choice != 'N' && choice != 'n' && choice != 'Y' && choice != 'y');

    coachExpense = (mealPrice + ticketPrice) / participants;
    pricePerParticipants = mealPrice + ticketPrice + (coachHire) / participants + coachExpense;
}

void getParticipantNames(int participants, string *name) {
    for (int i = 0; i < participants; i++) {
        cout << "Enter the name of Participant " << i + 1 << ": ";
        cin >> name[i];
    }
}

void displayParticipantDetails(int participants, string *name, float pricePerParticipants) {
    cout << "Details of Participants:\n";
    for (int i = 0; i < participants; i++) {
        cout << "Name: " << name[i] << ", Amount to be paid: " << pricePerParticipants << "$ (including coachExpense)\n";
    }
}

void calculateAndDisplayResult(int participants, float pricePerParticipants) {
    double totalMoney = pricePerParticipants * participants;
    cout << "Total cost is " << totalMoney << "$" << endl;

    double estimatedCost = pricePerParticipants * participants;
    double profitOrLoss = totalMoney - estimatedCost;

    if (profitOrLoss >= 0) {
        cout << "The outing has made a profit of " << profitOrLoss << "$." << endl;
    } else {
        cout << "The outing has broken even." << endl;
    }
}

int main() {
    int participants = getNumberOfParticipants();
    float coachExpense = 0.0;
    float pricePerParticipants = 0.0;
    string name[participants];

    calculateExpenses(participants, coachExpense, pricePerParticipants);
    getParticipantNames(participants, name);
    displayParticipantDetails(participants, name, pricePerParticipants);
    calculateAndDisplayResult(participants, pricePerParticipants);

    return 0;
}
