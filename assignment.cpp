#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int age;
    int reg_no;
    string name;
    string parentage;
    int semester;
    int roll_no;
    int attendance;
    int marks[5];

public:
    // Get details of the student
    void inputDetails()
    {
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter registration number: ";
        cin >> reg_no;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter parentage: ";
        cin >> parentage;
        cout << "Enter semester: ";
        cin >> semester;
        cout << "Enter roll number: ";
        cin >> roll_no;
        cout << "Enter attendance (classes attended): ";
        cin >> attendance;
        cout << "Enter marks for 5 subjects: ";
        for (int i = 0; i < 5; i++)
        {
            cin >> marks[i];
        }
    }

    // Show all details of the student
    void displayDetails() const
    {
        cout << "Age: " << age << "\n";
        cout << "Registration Number: " << reg_no << "\n";
        cout << "Name: " << name << "\n";
        cout << "Parentage: " << parentage << "\n";
        cout << "Semester: " << semester << "\n";
        cout << "Roll Number: " << roll_no << "\n";
        cout << "Attendance: " << attendance << "\n";
        cout << "Marks: ";
        for (int i = 0; i < 5; i++)
        {
            cout << marks[i] << " ";
        }
        cout << "\n";
    }

    // Calculate average percentage of marks
    float calculatePercentage()
    {
        int totalMarks = 0;
        for (int i = 0; i < 5; i++)
        {
            totalMarks += marks[i];
        }
        return float(totalMarks) / 5;
    }

    // Check if the student has attendance shortage (< 75%)
    void displayAttendanceShortage(int total_classes)
    {
        float attendancePercentage = (float(attendance) / total_classes) * 100;
        if (attendancePercentage < 75)
        {
            cout << "Roll Number: " << roll_no << ", Name: " << name
                 << ", Attendance: " << attendance << " (Shortage: " << attendancePercentage << "%)\n";
        }
    }

    // Display students with 90% or higher marks
    void displayHighAchievers()
    {
        if (calculatePercentage() >= 90)
        {
            cout << "Roll Number: " << roll_no << ", Name: " << name
                 << ", Percentage: " << calculatePercentage() << "%\n";
        }
    }

    // Get roll number and percentage
    int getRollNo() { return roll_no; }
    float getPercentage() { return calculatePercentage(); }
};

// Display top 5 students based on percentage
void displayTop5Students(Student students[], int numStudents)
{
    // Sort students by percentage in descending order
    for (int i = 0; i < numStudents - 1; i++)
    {
        for (int j = 0; j < numStudents - i - 1; j++)
        {
            if (students[j].getPercentage() < students[j + 1].getPercentage())
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // Display top 5 students
    cout << "\nTop 5 Students:\n";
    for (int i = 0; i < 5 && i < numStudents; i++)
    {
        cout << "Roll Number: " << students[i].getRollNo()
             << ", Name: " << students[i].name
             << ", Percentage: " << students[i].getPercentage() << "%\n";
    }
}

int main()
{
    int totalClasses;
    int numStudents;

    // Number of students and total classes conducted
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cout << "Enter the total number of classes: ";
    cin >> totalClasses;

    Student students[numStudents];

    // Input details of each student
    for (int i = 0; i < numStudents; i++)
    {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        students[i].inputDetails();
    }

    // Show details and check for attendance shortage and 90%+ marks
    for (int i = 0; i < numStudents; i++)
    {
        cout << "\nDetails of student " << i + 1 << ":\n";
        students[i].displayDetails();
        students[i].displayAttendanceShortage(totalClasses);
        students[i].displayHighAchievers();
    }

    // Display top 5 students
    displayTop5Students(students, numStudents);

    return 0;
}
