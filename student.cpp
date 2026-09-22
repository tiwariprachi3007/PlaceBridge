#include <iostream>
#include <vector>
#include <iomanip>
#include "common.h"

using namespace std;

// Module 1: Student Module
// Responsibilities: Registration, Apply for jobs

void studentRegistration(vector<Student>& students) {
    cout << "\n--- Student Registration ---" << endl;
    Student s;
    
    while (true) {
        s.id = getValidInt("Enter Student ID (Integer): ");
        bool exists = false;
        for (const auto& existing : students) {
            if (existing.id == s.id) {
                exists = true;
                break;
            }
        }
        if (exists) {
            cout << "A student with this ID already exists. Please try again.\n";
        } else {
            break;
        }
    }

    s.name = getValidString("Enter Name: ");
    s.branch = getValidString("Enter Branch: ");
    s.cgpa = getValidFloat("Enter CGPA: ");
    
    students.push_back(s);
    cout << "Student registered successfully!" << endl;
}

void applyForJobs(vector<Student>& students, const vector<Job>& jobs, vector<Application>& applications) {
    cout << "\n--- Apply for Jobs ---" << endl;
    int studentId = getValidInt("Enter your Student ID: ");

    // Find student
    bool found = false;
    float s_cgpa = 0;
    for (const auto& s : students) {
        if (s.id == studentId) {
            found = true;
            s_cgpa = s.cgpa;
            break;
        }
    }

    if (!found) {
        cout << "Student ID not found!" << endl;
        return;
    }

    cout << "\nAvailable Jobs for your CGPA (" << s_cgpa << "):" << endl;
    
    bool jobsAvailable = false;
    cout << left << setw(10) << "Job ID" << setw(20) << "Company" 
         << setw(20) << "Role" << setw(10) << "Min CGPA" << endl;
    cout << string(60, '-') << endl;

    for (const auto& j : jobs) {
        if (s_cgpa >= j.minCgpa) {
            cout << left << setw(10) << j.jobId << setw(20) << j.companyName 
                 << setw(20) << j.role << setw(10) << j.minCgpa << endl;
            jobsAvailable = true;
        }
    }

    if (!jobsAvailable) {
        cout << "No jobs available for your current CGPA." << endl;
        return;
    }

    int jobId = getValidInt("\nEnter Job ID to apply: ");
    
    // Check if the job actually exists and is applicable
    bool validJob = false;
    for (const auto& j : jobs) {
        if (j.jobId == jobId && s_cgpa >= j.minCgpa) {
            validJob = true;
            break;
        }
    }
    
    if (!validJob) {
        cout << "Invalid Job ID or you do not meet the minimum CGPA requirement." << endl;
        return;
    }

    // Check for duplicate application
    for (const auto& app : applications) {
        if (app.studentId == studentId && app.jobId == jobId) {
            cout << "You have already applied for this job." << endl;
            return;
        }
    }

    Application app;
    app.studentId = studentId;
    app.jobId = jobId;
    app.status = "Applied";
    applications.push_back(app);

    cout << "Application submitted successfully!" << endl;
}

void studentMenu(vector<Student>& students, const vector<Job>& jobs, vector<Application>& applications) {
    int choice;
    bool back = false;
    while (!back) {
        cout << "\n*** Student Menu ***\n";
        cout << "1. Register\n";
        cout << "2. Apply for Jobs\n";
        cout << "3. Back to Main Menu\n";
        choice = getValidInt("Enter choice: ");

        if (choice == 1) {
            studentRegistration(students);
        } else if (choice == 2) {
            applyForJobs(students, jobs, applications);
        } else if (choice == 3) {
            back = true;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}
