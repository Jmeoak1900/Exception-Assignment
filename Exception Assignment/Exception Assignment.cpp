// Jonah Meoak
// CIS 1202 M01
// May 3 2026
// Character offset program demo thing with exception handling

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
    char start[] = {'a','a','Z','?','A'};
	int num[] = { 1, -1, -1, 5, 32 };
    for (size_t i = 0; i < 5; i++)
    {
        try
        {
            cout << character(start[i], num[i]) << endl;
        }
        catch (const invalidCharacterException& e)
        {
            cout << e.what() << endl;
        }
        catch (const invalidRangeException& e)
        {
            cout << e.what() << endl;
        }
    }
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

