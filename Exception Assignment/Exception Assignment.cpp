// Exception Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>

char character(char start, int offset);

using namespace std;

class invalidCharacterException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Invalid character exception";
    }
};

int main()
{
    try
    {
		character('a', 5);
    }
    catch (const invalidCharacterException& e)
    {
		cout << e.what() << endl;
    }

	cout << "\n done "<< endl;
}

char character(char start, int offset)
{
    if(!isalpha(start))
    {
        throw invalidCharacterException();
    }
}

