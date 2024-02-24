#include <iostream>
#include <math.h>
using namespace std;
const int Size = 7;
string hashArray[Size];

int hashFunction(string data)
{
    int dec = 0;
    for (int i = 0; i < data.length(); i++)
    {

        dec += int(data[i]);
    }
    return dec % Size;
}

void insert(string data)
{
    int index = hashFunction(data);
    hashArray[index] = data;
}

bool search(string data)
{
    bool state;
    int key = hashFunction(data);
    if (data == hashArray[key])
    {
        cout << "data exist at index " << key << endl;
        state = true;
    }
    else
    {
        cout << "Not found. " << endl;
        state = false;
    }
    return state;
}

void removeData(string data)
{
    bool state = false;
    int key = hashFunction(data);
    if (data == hashArray[key])
    {
        state = true;
    }
    else
    {
        state = false;
    }
    if (state == true)
    {
        hashArray[key] = "";
        cout << "Successfully removed" << endl;
    }
    else
    {
        cout << "not found." << endl;
    }
};

int main()
{
    insert("pl7");
    insert("tykea");
    insert("vaneath");
    insert("hengheng");
    for (int i = 0; i < 5; i++)
    {
        cout << "Index " << i << " = " << hashArray[i] << endl;
    }
    // removeData("tykea");

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << "Index " << i << " = " << hashArray[i] << endl;
    // }
    // search("tykea");
}
