#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to check validity of parking number
bool isValidParkingNumber(int parkingNumber) {
    int sum = 0;
    int checkDigit = parkingNumber % 10;
    parkingNumber /= 10;
    
    for (int i = 4; i >= 1; i--) {
        sum += (parkingNumber % 10) * i;
        parkingNumber /= 10;
    }
    
    int remainder = sum % 11;
    return (remainder == 0 && checkDigit == 0) || (remainder == 1 && checkDigit == 1) || (remainder > 1 && checkDigit == 11 - remainder);
}

// Function to calculate the total cost of parking
float calculateTotalCost(int day, int arrivalTime, int departureTime, int noOfHour, float pricePerHour, int parkingNumber) {
    float discount = 0;
    
    // Calculate discount based on arrival time and day
    if (arrivalTime >= 16 && arrivalTime < 24) {
        discount = pricePerHour * noOfHour * 0.5; // 50% discount after 16:00
    } else {
        discount = pricePerHour * noOfHour * 0.1; // 10% discount at other times
    }
    
    // Check if parking number is provided and valid
    if (parkingNumber != 0 && isValidParkingNumber(parkingNumber)) {
        if (day == 7 || (day >= 1 && day <= 5 && noOfHour <= 2) || (day == 6 && noOfHour <= 4)) {
            discount += pricePerHour * noOfHour * 0.1; // Additional 10% discount for valid parking number
        }
    }
    
    return (noOfHour * pricePerHour) - discount;
}

int main() {
    // Variables to store user input and calculations
    int day, arrivalTime, departureTime, noOfHours, parkingNumber;
    float pricePerHour;
    
    // Prompt the user to choose a day
    cout << "Choose day: \n1. Monday\n2. Tuesday\n3. Wednesday\n4. Thursday\n5. Friday\n6. Saturday\n7. Sunday\n";
    cin >> day;
    
    // Get user input for arrival and departure times
    cout << "Enter the arrival time (0-23): ";
    cin >> arrivalTime;
    cout << "Enter the departure time (0-23): ";
    cin >> departureTime;
    
    // Validate arrival and departure times
    if (arrivalTime < 0 || arrivalTime >= 24 || departureTime < 0 || departureTime >= 24 || arrivalTime >= departureTime) {
        cout << "Invalid input for arrival or departure time." << endl;
        return 1; // Exit with an error code
    }
    
    // Get user input for number of hours
    cout << "Enter the number of hours: ";
    cin >> noOfHours;
    
    // Validate number of hours
    if (noOfHours <= 0) {
        cout << "Invalid input for number of hours." << endl;
        return 1; // Exit with an error code
    }
    
    // Get user input for parking number
    cout << "Enter parking number (0 if none): ";
    cin >> parkingNumber;
    
    // Validate parking number
    if (parkingNumber != 0 && !isValidParkingNumber(parkingNumber)) {
        cout << "Invalid parking number." << endl;
        return 1; // Exit with an error code
    }
    
    // Set price per hour based on arrival time
    if (arrivalTime >= 16) {
        pricePerHour = 6.0; // Evening rate from 16:00
    } else {
        pricePerHour = 10.0; // Day rate before 16:00
    }
    
    // Calculate total cost of parking
    float totalCost = calculateTotalCost(day, arrivalTime, departureTime, noOfHours, pricePerHour, parkingNumber);
    
    // Output the result
    cout << fixed << setprecision(2);
    cout << "Total cost for parking: $" << totalCost << endl;
    
   return 0;
}
