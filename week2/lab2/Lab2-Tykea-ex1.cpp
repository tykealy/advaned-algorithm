#include <iostream>
#include <string.h>
using namespace std;

struct Score
{
    float quiz;
    float midterm;
    float final;
    float total()
    {
        return this->final + this->midterm + this->quiz;
    }
};
struct Student
{
    string name;
    int age;
    string sex;
    string ID;
    Score score;
} student[20];

void addStudent(int stAmount)
{

    cout << "Enter student name: ";
    cin >> student[stAmount].name;
    cout << "Enter student age: ";
    cin >> student[stAmount].age;
    cout << "Enter student Sex: ";
    cin >> student[stAmount].sex;
    cout << "Enter student ID: ";
    cin >> student[stAmount].ID;
    cout << "Enter quizz score: ";
    cin >> student[stAmount].score.quiz;
    cout << "Enter midTerm score: ";
    cin >> student[stAmount].score.midterm;
    cout << "Enter final score: ";
    cin >> student[stAmount].score.final;
}
void displayInfo(int i, int stAmount)
{
    if (stAmount == 0)
    {
        cout << "No student data." << endl;
    }
    else
    {
        cout << "============" << endl;
        cout << "Name: " << student[i].name << endl;
        cout << "AGE: " << student[i].age << endl;
        cout << "Sex: " << student[i].sex << endl;
        cout << "ID: " << student[i].ID << endl;
        cout << "Quiz: " << student[i].score.quiz << endl;
        cout << "Midterm: " << student[i].score.midterm << endl;
        cout << "Final: " << student[i].score.final << endl;
        cout << "Total: " << student[i].score.total() << endl;
    }
}
void studentGotMaxTotal(int stAmount)
{
    int num = 0;
    for (int i = 0; i < stAmount; i++)
    {
        if (student->score.total() == 100)
        {
            cout << "============" << endl;
            cout << "Name: " << student[i].name << endl;
            cout << "AGE: " << student[i].age << endl;
            cout << "Sex: " << student[i].sex << endl;
            cout << "ID: " << student[i].ID << endl;
            cout << "Quiz: " << student[i].score.quiz << endl;
            cout << "Midterm: " << student[i].score.midterm << endl;
            cout << "Final: " << student[i].score.final << endl;
            cout << "Total: " << student[i].score.total() << endl;
            num++;
        }
    }
    if (num == 0)
    {
        cout << "Not found." << endl;
    }
}
int searchForStudent(int stAmount)
{
    string ID;
    int index = -1;
    cout << "Enter the ID: ";
    cin >> ID;
    for (int i = 0; i < stAmount; i++)
    {
        if (ID == student[i].ID)
        {
            index = i;
        }
    }
    return index;
}
void findMinMaxAvg(int stAmount)
{
    int avg = 0;
    int min = student[0].score.total();
    int max = student[0].score.total();
    for (int i = 0; i < stAmount; i++)
    {

        avg += student[i].score.total();
    }
    for (int j = 0; j < stAmount; j++)
    {
        if (student[j].score.total() < min)
        {
            min = student[j].score.total();
        }
        if (student[j].score.total() > min)
        {
            max = student[j].score.total();
        }
    }
    avg = avg / stAmount;
    cout << "min score is" << min << endl;
    cout << "max score is" << max << endl;
    cout << "avg score is" << avg << endl;
}

int main()
{
    int menu;
    int stAmount = 0;
    int index = -1;
    while (menu != 0)
    {
        cout << "=======================================" << endl;
        cout << "                  Menu" << endl;
        cout << "=======================================" << endl;
        cout << "1. Add 2 student" << endl;
        cout << "2. Display all student information" << endl;
        cout << "3. Show students who gets the max total score" << endl;
        cout << "4. Display a student information by ID" << endl;
        cout << "5. Find min,max,and average scores for this class." << endl;
        cout << "Choose 1-5 or 0 to quit:";
        cin >> menu;
        switch (menu)
        {
        case 1:
            for (int i = 0; i <= 1; i++)
            {
                addStudent(stAmount);
                stAmount++;
            }
            break;
        case 2:
            for (int i = 0; i < stAmount; i++)
            {
                displayInfo(i, stAmount);
            }
            break;
        case 3:
            studentGotMaxTotal(stAmount);
            break;
        case 4:
            index = searchForStudent(stAmount);
            if (index == -1)
            {
                cout << "Not found." << endl;
                break;
            }
            if (index >= 0 || index <= stAmount)
            {
                cout << "============" << endl;
                cout << "Name: " << student[index].name << endl;
                cout << "AGE: " << student[index].age << endl;
                cout << "Sex: " << student[index].sex << endl;
                cout << "ID: " << student[index].ID << endl;
                cout << "Quiz: " << student[index].score.quiz << endl;
                cout << "Midterm: " << student[index].score.midterm << endl;
                cout << "Final: " << student[index].score.final << endl;
                cout << "Total: " << student[index].score.total() << endl;
            }
            else
            {
                cout << "Not found." << endl;
            };
            break;
        case 5:
            findMinMaxAvg(stAmount);
            break;
        default:
            break;
        }
    }
}