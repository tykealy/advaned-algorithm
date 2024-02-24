#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file1;

    file1.open("file.dat", ios::app);
    file1 << "99"
          << " tk "
          << 999
          << "\n";
    file1.close();
}