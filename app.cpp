#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Student
{
    string name;
    int rollNumber;
    string grade;
};

// Function prototypes
void addStudentRecord(vector<Student> &records);
void updateStudentRecord(vector<Student> &records);
void deleteStudentRecord(vector<Student> &records);
void generateCSVFile(const vector<Student> &records);
void viewStudentRecords(const vector<Student> &records);

int main()
{
    vector<Student> records;

    int choice;
    do
    {
        cout << "Student Record Management System" << endl;
        cout << "1. Add a student record" << endl;
        cout << "2. Update a student record" << endl;
        cout << "3. Delete a student record" << endl;
        cout << "4. View student records" << endl;
        cout << "5. Generate a CSV file" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudentRecord(records);
            break;
        case 2:
            updateStudentRecord(records);
            break;
        case 3:
            deleteStudentRecord(records);
            break;
        case 4:
            viewStudentRecords(records);
            break;
        case 5:
            generateCSVFile(records);
            break;
        case 6:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}

void addStudentRecord(vector<Student> &records)
{
    Student student;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter student roll number: ";
    cin >> student.rollNumber;
    cout << "Enter student grade: ";
    cin.ignore();
    getline(cin, student.grade);

    records.push_back(student);

    cout << "Student record added successfully!" << endl;
}

void updateStudentRecord(vector<Student> &records)
{
    int rollNumber;
    cout << "Enter the roll number of the student to update: ";
    cin >> rollNumber;

    bool found = false;
    for (auto &student : records)
    {
        if (student.rollNumber == rollNumber)
        {
            cout << "Enter updated student name: ";
            cin.ignore();
            getline(cin, student.name);
            cout << "Enter updated student grade: ";
            getline(cin, student.grade);

            found = true;
            cout << "Student record updated successfully!" << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Student record not found!" << endl;
    }
}

void deleteStudentRecord(vector<Student> &records)
{
    int rollNumber;
    cout << "Enter the roll number of the student to delete: ";
    cin >> rollNumber;

    bool found = false;
    for (auto it = records.begin(); it != records.end(); ++it)
    {
        if (it->rollNumber == rollNumber)
        {
            records.erase(it);
            found = true;
            cout << "Student record deleted successfully!" << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Student record not found!" << endl;
    }
}

void viewStudentRecords(const vector<Student> &records)
{
    if (records.empty())
    {
        cout << "No student records found!" << endl;
        return;
    }

    cout << "Student Records:" << endl;
    cout << "----------------" << endl;
    cout << "Name\t\tRoll Number\tGrade" << endl;

    for (const auto &student : records)
    {
        cout << student.name << "\t" << student.rollNumber << "\t\t" << student.grade << endl;
    }
}
void generateCSVFile(const vector<Student> &records)
{
    ofstream file("student_records.csv");
    if (!file.is_open())
    {
        cout << "Error creating CSV file!" << endl;
        return;
    }

    file << "Name,Roll Number,Grade" << endl;
    for (const auto &student : records)
    {
        file << student.name << "," << student.rollNumber << "," << student.grade << endl;
    }

    file.close();
    cout << "CSV file generated successfully!" << endl;
}
