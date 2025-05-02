#include <iostream>
#include <string>

using namespace std;

const int maxItems = 10;

// Function to setup auction items
void setupAuction(string descriptions[], double reservePrices[], int numBids[], double highestBids[]) {
    cout << "Task 1: Auction setup\n";
    for (int i = 0; i < maxItems; ++i) {
        cout << "Item " << i + 1 << ":\n";
        cout << "Description: ";
        getline(cin, descriptions[i]);
        cout << "Reserve Price: ";
        cin >> reservePrices[i];
        numBids[i] = 0;
        highestBids[i] = 0.0;
        cin.ignore(); // Ignore newline character in buffer
    }
}

// Function for buyer bids
void buyerBids(double highestBids[]) {
    cout << "\nTask 2: Buyer bids\n";
    while (true) {
        int itemIndex;
        cout << "Enter the item number you want to bid on (1-" << maxItems << "), or 0 to exit: ";
        cin >> itemIndex;
        if (itemIndex == 0)
            break;
        if (itemIndex < 1 || itemIndex > maxItems) {
            cout << "Invalid item number!\n";
            continue;
        }
        cout << "Current highest bid: $" << highestBids[itemIndex - 1] << endl;
        cout << "Enter your bid: $";
        double bid;
        cin >> bid;
        if (bid <= highestBids[itemIndex - 1]) {
            cout << "Your bid must be higher than the current highest bid!\n";
            continue;
        }
        highestBids[itemIndex - 1] = bid;
        cout << "Bid successfully recorded.\n";
    }
}

// Function for end of the auction
void endAuction(const string descriptions[], const double reservePrices[], const double highestBids[]) {
    cout << "\nTask 3: End of the auction\n";
    double totalFee = 0.0;
    int numSold = 0, numUnsold = 0, numBelowReserve = 0;

    for (int i = 0; i < maxItems; ++i) {
        if (highestBids[i] >= reservePrices[i]) {
            totalFee += highestBids[i] * 0.1;
            numSold++;
        } else {
            numBelowReserve++;
            cout << "Item " << i + 1 << " (reserve price: $" << reservePrices[i] << ") did not meet the reserve price.\n";
        }
    }

    for (int i = 0; i < maxItems; ++i) {
        if (highestBids[i] < reservePrices[i]) {
            cout << "Item " << i + 1 << " (reserve price: $" << reservePrices[i] << ") received no bids.\n";
            numUnsold++;
        }
    }

    cout << "\nTotal fee for sold items: $" << totalFee << endl;
    cout << "Number of items sold: " << numSold << endl;
    cout << "Number of items that did not meet the reserve price: " << numBelowReserve << endl;
    cout << "Number of items with no bids: " << numUnsold << endl;
}

int main() {
    string descriptions[maxItems];
    double reservePrices[maxItems];
    int numBids[maxItems];
    double highestBids[maxItems];

    setupAuction(descriptions, reservePrices, numBids, highestBids);
    buyerBids(highestBids);
    endAuction(descriptions, reservePrices, highestBids);
return 0;
}
