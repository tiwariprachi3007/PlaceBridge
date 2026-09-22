#include <iostream>
#include <vector>
#include <iomanip>
#include "common.h"

using namespace std;

// Module 3: Placement Officer Module
// Responsibilities: Schedule interviews, Generate reports

void scheduleInterviews(vector<Application>& applications) {
    cout << "\n--- Schedule Interviews / Update Status ---" << endl;
    int sId = getValidInt("Enter Student ID: ");
    int jId = getValidInt("Enter Job ID: ");

    bool found = false;
    for (auto& app : applications) {
        if (app.studentId == sId && app.jobId == jId) {
            cout << "Current Status: " << app.status << endl;
            app.status = getValidString("Enter new status (e.g. Interview, Placed, Rejected): ");
            cout << "Status updated successfully!" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Application not found for given Student ID and Job ID." << endl;
    }
}

void generateReports(const vector<Student>& students, const vector<Job>& jobs, const vector<Application>& applications) {
    cout << "\n--- Placement Report ---" << endl;
    cout << left << setw(35) << "Total Students Registered:" << students.size() << endl;
    cout << left << setw(35) << "Total Jobs Posted:" << jobs.size() << endl;
    cout << left << setw(35) << "Total Applications Submitted:" << applications.size() << endl;
    
    int placedCount = 0;
    for (const auto& app : applications) {
        if (app.status == "Placed") {
            placedCount++;
        }
    }
    cout << left << setw(35) << "Total Students Placed:" << placedCount << endl;
}

void placementOfficerMenu(vector<Application>& applications, const vector<Student>& students, const vector<Job>& jobs) {
    int choice;
    bool back = false;
    while (!back) {
        cout << "\n*** Placement Officer Menu ***\n";
        cout << "1. Update Application Status\n";
        cout << "2. Generate Reports\n";
        cout << "3. Back to Main Menu\n";
        choice = getValidInt("Enter choice: ");

        if (choice == 1) {
            scheduleInterviews(applications);
        } else if (choice == 2) {
            generateReports(students, jobs, applications);
        } else if (choice == 3) {
            back = true;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}
