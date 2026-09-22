#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "common.h"

using namespace std;

// Module 4: File Handling & Integration
// Responsibilities: Data Storage, Linking Modules together

extern void studentMenu(vector<Student>& students, const vector<Job>& jobs, vector<Application>& applications);
extern void companyMenu(vector<Job>& jobs, const vector<Application>& applications, const vector<Student>& students);
extern void placementOfficerMenu(vector<Application>& applications, const vector<Student>& students, const vector<Job>& jobs);

int getValidInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } else {
            cout << "Invalid input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

float getValidFloat(const string& prompt) {
    float value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } else {
            cout << "Invalid input. Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

string getValidString(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}

void loadData(vector<Student>& students, vector<Job>& jobs, vector<Application>& applications) {
    cout << "Loading system data from files..." << endl;
    
    ifstream sFile("students.txt");
    if (sFile.is_open()) {
        string line;
        while (getline(sFile, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string item;
            Student s;
            if (getline(ss, item, '|')) s.id = stoi(item);
            getline(ss, s.name, '|');
            getline(ss, s.branch, '|');
            if (getline(ss, item, '|')) s.cgpa = stof(item);
            students.push_back(s);
        }
        sFile.close();
    }

    ifstream jFile("jobs.txt");
    if (jFile.is_open()) {
        string line;
        while (getline(jFile, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string item;
            Job j;
            if (getline(ss, item, '|')) j.jobId = stoi(item);
            getline(ss, j.companyName, '|');
            getline(ss, j.role, '|');
            if (getline(ss, item, '|')) j.minCgpa = stof(item);
            jobs.push_back(j);
        }
        jFile.close();
    }

    ifstream aFile("applications.txt");
    if (aFile.is_open()) {
        string line;
        while (getline(aFile, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string item;
            Application a;
            if (getline(ss, item, '|')) a.studentId = stoi(item);
            if (getline(ss, item, '|')) a.jobId = stoi(item);
            getline(ss, a.status, '|');
            applications.push_back(a);
        }
        aFile.close();
    }
}

void saveData(const vector<Student>& students, const vector<Job>& jobs, const vector<Application>& applications) {
    cout << "Saving system data to files..." << endl;
    
    ofstream sFile("students.txt");
    for (const auto& s : students) {
        sFile << s.id << "|" << s.name << "|" << s.branch << "|" << s.cgpa << "\n";
    }
    sFile.close();

    ofstream jFile("jobs.txt");
    for (const auto& j : jobs) {
        jFile << j.jobId << "|" << j.companyName << "|" << j.role << "|" << j.minCgpa << "\n";
    }
    jFile.close();

    ofstream aFile("applications.txt");
    for (const auto& a : applications) {
        aFile << a.studentId << "|" << a.jobId << "|" << a.status << "\n";
    }
    aFile.close();
}

void displayMainMenu() {
    cout << "\n======================================" << endl;
    cout << "   PlaceBridge - Placement System" << endl;
    cout << "======================================" << endl;
    cout << "1. Student Module" << endl;
    cout << "2. Company Module" << endl;
    cout << "3. Placement Officer Module" << endl;
    cout << "4. Save & Exit" << endl;
}

int main() {
    vector<Student> students;
    vector<Job> jobs;
    vector<Application> applications;

    loadData(students, jobs, applications); // Load data on startup
    
    int choice;
    bool running = true;

    while (running) {
        displayMainMenu();
        choice = getValidInt("Enter your choice: ");

        switch (choice) {
            case 1:
                studentMenu(students, jobs, applications);
                break;
            case 2:
                companyMenu(jobs, applications, students);
                break;
            case 3:
                placementOfficerMenu(applications, students, jobs);
                break;
            case 4:
                cout << "Exiting PlaceBridge. Goodbye!" << endl;
                saveData(students, jobs, applications); // Save data on exit
                running = false;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
