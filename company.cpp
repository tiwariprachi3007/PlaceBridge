#include <iostream>
#include <vector>
#include <iomanip>
#include "common.h"

using namespace std;

// Module 2: Company Module
// Responsibilities: Post jobs, View applications

void postJobs(vector<Job>& jobs) {
    cout << "\n--- Post a Job ---" << endl;
    Job j;
    
    while (true) {
        j.jobId = getValidInt("Enter Job ID (Integer): ");
        bool exists = false;
        for (const auto& existing : jobs) {
            if (existing.jobId == j.jobId) {
                exists = true;
                break;
            }
        }
        if (exists) {
            cout << "A job with this ID already exists. Please try again.\n";
        } else {
            break;
        }
    }

    j.companyName = getValidString("Enter Company Name: ");
    j.role = getValidString("Enter Role: ");
    j.minCgpa = getValidFloat("Enter Minimum CGPA required: ");
    
    jobs.push_back(j);
    cout << "Job posted successfully!" << endl;
}

void viewApplications(const vector<Application>& applications, const vector<Student>& students) {
    cout << "\n--- View Applications ---" << endl;
    int jId = getValidInt("Enter Job ID to view applications for: ");

    bool found = false;
    
    cout << "\n" << left << setw(15) << "Student ID" << setw(20) << "Name" 
         << setw(20) << "Branch" << setw(15) << "Status" << endl;
    cout << string(70, '-') << endl;

    for (const auto& app : applications) {
        if (app.jobId == jId) {
            // Find student details
            for (const auto& s : students) {
                if (s.id == app.studentId) {
                    cout << left << setw(15) << s.id << setw(20) << s.name 
                         << setw(20) << s.branch << setw(15) << app.status << endl;
                    found = true;
                    break;
                }
            }
        }
    }

    if (!found) {
        cout << "No applications found for this Job ID." << endl;
    }
}

void companyMenu(vector<Job>& jobs, const vector<Application>& applications, const vector<Student>& students) {
    int choice;
    bool back = false;
    while (!back) {
        cout << "\n*** Company Menu ***\n";
        cout << "1. Post Jobs\n";
        cout << "2. View Applications\n";
        cout << "3. Back to Main Menu\n";
        choice = getValidInt("Enter choice: ");

        if (choice == 1) {
            postJobs(jobs);
        } else if (choice == 2) {
            viewApplications(applications, students);
        } else if (choice == 3) {
            back = true;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}
