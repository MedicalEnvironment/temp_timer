#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    // Start the timer
    auto start = chrono::high_resolution_clock::now();

    // Open the output file
    ofstream outfile("temperatures.txt");

    int count = 0;
    double totalTime = 0;

    while (true) {
        int number;
        string inputLine;

        // Get input from the user
        cout << "Enter temperature and notes (if any), separated by space: ";
        getline(cin, inputLine);

        // Create a stringstream to parse the input line
        istringstream iss(inputLine);

        // Extract temperature
        iss >> number;

        // Check if notes are present
        string notes;
        if (iss) {
            // Extract the remaining part of the line as notes
            getline(iss, notes);
        } else {
            // No notes provided
            notes = "No notes";
        }

        // Calculate the time elapsed since the start of the program
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        totalTime = duration.count();

        // Write the temperature, notes, and time to the output file
        outfile << "Time in seconds: " << totalTime << ", " << "Temperature: " << number << ", Notes: " << notes << endl;

        cout << "Time: " << totalTime << endl;
        cout << "Temperature: " << number << endl;
        cout << "Notes: " << notes << endl;

        // Increment the count
        count++;
    }

    // Close the output file
    outfile.close();

    return 0;
}
