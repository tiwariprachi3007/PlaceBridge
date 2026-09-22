#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <limits>
#include <iostream>

struct Student {
    int id;
    std::string name;
    std::string branch;
    float cgpa;
};

struct Job {
    int jobId;
    std::string companyName;
    std::string role;
    float minCgpa;
};

struct Application {
    int studentId;
    int jobId;
    std::string status; // e.g. "Applied", "Interview Scheduled", "Placed"
};

// Utility functions for input validation
int getValidInt(const std::string& prompt);
float getValidFloat(const std::string& prompt);
std::string getValidString(const std::string& prompt);

#endif // COMMON_H
