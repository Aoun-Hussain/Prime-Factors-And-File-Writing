/*
Author: Aoun Hussain
Class: ECE 6122-A
Last Date Modified: Wed, Sep 22, 2021
Description: This is the cpp source file for the solution of problem 1, lab 1.
             This checks for all valid and invalid command line input to the file
             and returns a string of prime factors of the number in argument
             separated by commas.
*/


#include <cctype>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;


bool is_numeric(const string &strIn, unsigned long &nInputNumber)
{
    /*
    Checks if the argument is numeric and returns true/false accordingly
    */

    bool bRC = all_of(strIn.begin(), strIn.end(), [](unsigned char c)
    {
        return ::isdigit(c);                      // http://www.cplusplus.com/reference/algorithm/all_of/
    }                                             // https://www.geeksforgeeks.org/lambda-expression-in-c/
    );                                            // http://www.cplusplus.com/reference/cctype/isdigit/
    if (bRC)
    {
        nInputNumber = stoul(strIn);              // https://www.cplusplus.com/reference/string/stoul/
        return true;
    }
    else
    {
        return false;
    }

}

bool GetPrimeFactors (const unsigned long ulInputNumber, string &strOutput)
{
    /*
    Stores the prime factors of the valid command line argument in a string, if there
     are no prime factors, the function returns false, else true. Writes the string in the
     output.txt file.
    */

    unsigned long num = ulInputNumber;

    if (num == 0)
    {
        ofstream myfile ("output1.txt");
        if (myfile.is_open())
        {
            myfile << "No prime factors" << "\n";
            myfile.close();
        }
        else cout << "Unable to open file";

        cout << "No prime factors" << endl;

        return false;
    }

    while (num%2 == 0)
    {
        strOutput.append(to_string(2) + ",");
        num = num / 2;
    }

    for (int i = 3; i <= sqrt(num); i = i + 2)
    {
        while (num%i == 0)
        {
            strOutput.append(to_string(i) + ",");
            num = num / i;
        }
    }

    if (num > 2)
    {
        strOutput.append(to_string(num) + ",");
    }

    strOutput.pop_back();

    //No prime factors - if no prime factors
    if (strOutput.empty() == true)
    {
        ofstream myfile ("output1.txt");
        if (myfile.is_open())
        {
            myfile << "No prime factors"<<"\n";
            myfile.close();
        }
        else cout << "Unable to open file";

        cout << "No prime factors" << endl;

        return false;
    }
    else
    {
        ofstream myfile ("output1.txt");
        if (myfile.is_open())
        {
            myfile << strOutput << "\n";
            myfile.close();
        }
        else cout << "Unable to open file";

        return true;
    }

}

int main(int argc, char* argv[]){
    /*
    main function to call all functions to calculate prime factors and check for invalid inputs
     and write output to file
    */

    if (argc == 2)
    {
        unsigned long nInputNumber{ 0 };
        string strOutput;
        string strInput(argv[1]);
        bool bIsValid = is_numeric(strInput, nInputNumber);
        if (bIsValid)
        {
            GetPrimeFactors(nInputNumber, strOutput);
        }
        else
        {
            cout << "Invalid Input" <<endl;
            ofstream myfile ("output1.txt");
            if (myfile.is_open())
            {
                myfile << "Invalid Input" << "\n";
                myfile.close();
            }
            else cout << "Unable to open file";
        }
    }
    else
    {
        cout << "Invalid Input" <<endl;
        ofstream myfile ("output1.txt");
        if (myfile.is_open())
        {
            myfile << "Invalid Input" << "\n";
            myfile.close();
        }
        else cout << "Unable to open file";
    }

    return 0;
}

