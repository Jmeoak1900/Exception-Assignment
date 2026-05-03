// Exception Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>

char character(char start, int offset);

using namespace std;

class invalidRangeException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Invalid range exception";
    }
};

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
		cout << character('H', -1) << endl;
    }
    catch (const invalidCharacterException& e)
    {
		cout << e.what() << endl;
    }
    catch (const invalidRangeException& e)
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

	char end = start + offset;
    if(!isupper(start))
    {
        if (end < 'a' || end > 'z')
        {
            throw invalidRangeException();
        }
    }else
    {
        if (end < 'A' || end > 'Z')
        {
            throw invalidRangeException();
        }
    }

	return end;
	
}

