# PlaceBridge 🎓

**PlaceBridge** is a modular Campus Placement Management System developed in C++. It bridges the communication gap between graduating students, recruiting companies, and campus placement officers. The system manages student registrations, job postings, application submissions with eligibility checking, interview scheduling, and placement reporting with persistent file storage.

---

## 🚀 Features

### 1. 👨‍🎓 Student Module
- **Registration**: Register with unique Student ID, Name, Branch, and CGPA.
- **CGPA-based Job Eligibility**: Automatically filter and display job vacancies where the student meets or exceeds the minimum CGPA requirement.
- **Job Application**: Apply for available jobs with duplicate application prevention.

### 2. 🏢 Company Module
- **Job Posting**: Post job openings with unique Job ID, Company Name, Role, and Minimum CGPA criteria.
- **Applicant Tracking**: View a formatted list of all student applicants for any posted job vacancy.

### 3. 📋 Placement Officer Module
- **Application Status Management**: Update application statuses (e.g., *Interview Scheduled*, *Placed*, *Rejected*).
- **Placement Analytics & Reports**: Generate real-time summary statistics:
  - Total Students Registered
  - Total Jobs Posted
  - Total Applications Received
  - Total Students Placed

### 4. 💾 File Persistence & Input Validation
- **Persistent Storage**: Data is automatically loaded on launch and saved on exit in pipe-delimited text files (`students.txt`, `jobs.txt`, `applications.txt`).
- **Robust Input Handling**: Prevents infinite loops or buffer errors from invalid inputs through validation routines (`getValidInt`, `getValidFloat`, `getValidString`).

---

## 📁 Project Structure

```
PlaceBridge/
├── common.h               # Core data structures (Student, Job, Application) & prototypes
├── student.cpp            # Student registration and job application logic
├── company.cpp            # Job postings and applicant review
├── placement_officer.cpp  # Interview scheduling and placement reports
├── main.cpp               # Interactive menu loop, data persistence (load/save)
├── .gitignore             # Ignore compiled binaries and runtime data files
├── LICENSE                # MIT License
└── README.md              # Project documentation
```

---

## 🛠️ Build & Run Instructions

### Prerequisites
- C++ compiler with C++17 support (`g++`, `clang++`, or MSVC)

### Compilation (GCC / MinGW)
Open a terminal in the project directory and run:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp student.cpp company.cpp placement_officer.cpp -o PlaceBridge
```

### Execution

On **Windows**:
```cmd
PlaceBridge.exe
```

On **Linux / macOS**:
```bash
./PlaceBridge
```

---

## 📄 License
This project is licensed under the [MIT License](LICENSE).