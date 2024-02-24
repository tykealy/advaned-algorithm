#include <iostream>

#include <fstream>
using namespace std;
int main()
{
    fstream file1;
    string name, id;
    int num;

    file1.open("file.dat", ios::in);
    while (!file1.eof())
    {
        file1 >> id >> name >> num;
        cout << id << " " << name << " " << num << endl;
    }

    file1.close();
}