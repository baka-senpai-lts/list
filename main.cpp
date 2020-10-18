#include <iostream>
#include "list.hpp"

using namespace std;

int main()
{
    List<string> list;

    string input = " ";

    do
    {
        getline(cin, input);
        if(input != "") list.append(input);
    } while(input != "");

    for(int i = 0; i < list.length(); i++)
    {
        cout << list[i] << endl;
    }
}