#include <iostream>
using namespace std;

const int TicketTypes = 5;
const int ExtraAttractions = 3;

// Ticket type names and costs for one day
string ticketTypeNamesOneDay[TicketTypes] = {"Adult", "Child", "Senior", "Family", "Group"};
double ticketTypeCostsOneDay[TicketTypes] = {20.00, 12.00, 16.00, 60.00, 15.00};

// Ticket type names and costs for two days
double ticketTypeCostsTwoDays[TicketTypes] = {30.00, 18.00, 24.00, 90.00, 22.50};

// Extra attraction names and costs
string attractionNames[ExtraAttractions] = {"Lion Feeding", "Penguin Feeding", "Evening Barbecue (Two-Day Tickets Only)"};
double attractionCosts[ExtraAttractions] = {2.50, 2.00, 5.00};

// Structure to store booking details
struct Booking {
    string ticketType;
    int quantity;
    double cost;
};

// Function to display ticket options and extra attractions
void displayOptions() {
    cout << "Welcome to the Wildlife Park!" << endl;
    cout << "-----------------------------" << endl;

    // Display ticket options and prices for one day
    cout << "Ticket Options and Prices for One Day:" << endl;
    for (int i = 0; i < TicketTypes; ++i) {
        cout << ticketTypeNamesOneDay[i] << " : $" << ticketTypeCostsOneDay[i] << endl;
    }

    // Display ticket options and prices for two days
    cout << "\nTicket Options and Prices for Two Days:" << endl;
    for (int i = 0; i < TicketTypes; ++i) {
        cout << ticketTypeNamesOneDay[i] << " : $" << ticketTypeCostsTwoDays[i] << endl;
    }

    // Display extra attractions and costs
    cout << "\nExtra Attractions and Prices:" << endl;
    for (int i = 0; i < ExtraAttractions; ++i) {
        cout << attractionNames[i] << " : $" << attractionCosts[i] << " per person" << endl;
    }

    cout << "\nDays Available for Booking: M - Monday, T - Tuesday, W - Wednesday, Th - Thursday, F - Friday, S - Saturday, U - Sunday\n";
}

// Function to process booking
void processBooking(Booking bookings[], int& totalBookings) {
    char choice;
    do {
        cout << "\nDo you want to make a booking? (Y/N): ";
        cin >> choice;
        if (toupper(choice) == 'Y') {
            int ticketTypeIndex;
            cout << "\nEnter the ticket type (1 - " << TicketTypes << "): ";
            cin >> ticketTypeIndex;
            if (ticketTypeIndex >= 1 && ticketTypeIndex <= TicketTypes) {
                int quantity;
                cout << "Enter the quantity: ";
                cin >> quantity;
                if (quantity > 0) {
                    bookings[totalBookings].ticketType = ticketTypeNamesOneDay[ticketTypeIndex - 1];
                    bookings[totalBookings].quantity = quantity;
                    // Check if two-day ticket prices should be used
                    if (totalBookings % 2 == 0)
                        bookings[totalBookings].cost = ticketTypeCostsTwoDays[ticketTypeIndex - 1] * quantity;
                    else
                        bookings[totalBookings].cost = ticketTypeCostsOneDay[ticketTypeIndex - 1] * quantity;
                    totalBookings++;
                    cout << "Booking successful!" << endl;
                } else {
                    cout << "Invalid quantity. Please enter a positive integer." << endl;
                }
            } else {
                cout << "Invalid ticket type. Please enter a number between 1 and " << TicketTypes << "." << endl;
            }
        }
    } while (toupper(choice) == 'Y');
}

// Function to display booking details
void displayBookingDetails(const Booking bookings[], int totalBookings) {
    if (totalBookings == 0) {
        cout << "No bookings available." << endl;
    } else {
        cout << "\nBooking Details:" << endl;
        cout << "Ticket Type        Quantity   Cost" << endl;
        for (int i = 0; i < totalBookings; ++i) {
            cout << bookings[i].ticketType << "        " << bookings[i].quantity << "       $" << bookings[i].cost << endl;
        }
    }
}

// Function to check if each booking provides the best value and offer an alternative if necessary
void checkBestValue(Booking bookings[], int totalBookings) {
    // Iterate through each booking
    for (int i = 0; i < totalBookings; ++i) {
        double currentCost = bookings[i].cost;
        // Compare with alternative options
        if (bookings[i].ticketType == "Group") {
            // Calculate cost of equivalent family ticket
            double familyCost = ticketTypeCostsOneDay[3] + ticketTypeCostsOneDay[1] * min(bookings[i].quantity * 2, 3);
            if (familyCost < currentCost) {
                cout << "For Booking " << i + 1 << ", consider purchasing a Family Ticket instead of a Group Ticket for better value." << endl;
            }
        } else if (bookings[i].ticketType == "Adult") {
            // Calculate cost of equivalent family ticket
            double familyCost = ticketTypeCostsOneDay[3] + ticketTypeCostsOneDay[0] * min(bookings[i].quantity, 2);
            if (familyCost < currentCost) {
                cout << "For Booking " << i +1 << ", consider purchasing a Family Ticket instead of individual Adult Tickets for better value." << endl;
            }
        } else if (bookings[i].ticketType == "Child") {
            // Calculate cost of equivalent family ticket
            double familyCost = ticketTypeCostsOneDay[3] + ticketTypeCostsOneDay[1] * min(bookings[i].quantity, 3);
            if (familyCost < currentCost) {
                cout << "For Booking " << i + 1 << ", consider purchasing a Family Ticket instead of individual Child Tickets for better value." << endl;
            }
        } else if (bookings[i].ticketType == "Senior") {
            // Calculate cost of equivalent family ticket
            double familyCost = ticketTypeCostsOneDay[3] + ticketTypeCostsOneDay[2] * min(bookings[i].quantity, 2);
            if (familyCost < currentCost) {
                cout << "For Booking " << i + 1 << ", consider purchasing a Family Ticket instead of individual Senior Tickets for better value." << endl;
            }
        }
    }
}

int main() {
    Booking bookings[100];
    int totalBookings = 0;

    displayOptions();
    processBooking(bookings, totalBookings);
    displayBookingDetails(bookings, totalBookings);
    checkBestValue(bookings, totalBookings);

    return 0;
}

