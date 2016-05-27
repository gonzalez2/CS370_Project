//CS370
//Project Sorting Checks
/*
This Program takes an input file of checks with BankID,AccountID, and CheckNumber
and sort the check in order. I used the C++ qsort to sort the checks.
(http://www.cplusplus.com/reference/cstdlib/qsort/ ) more info on qsort.
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    
    int base = 1000; //has to match the numbers of checks you want to sort
    int checks[1000][3]; //has to match base
    
    //Test File
    ifstream input("test5-1000.txt");

    //Import data into the 2D array
    for_each(begin(checks), end(checks),
                  [&](int (&checks)[3]){ input >> checks[0];
                                         input >> checks[1];
                                         input >> checks[2];
                  });
    
    //Print Array Before Sorted
    if(base <= 1000){
    cout << "Before Sort..." << '\n';
    for_each(begin(checks), end(checks),
                  [](const int(&checks)[3]) { cout << checks[0] << ','
                                                   << checks[1] << ','
                                                   << checks[2] << '\n';});
    cout << endl;
    }
    
    //Sort Array Using qsort
    qsort(checks, base, sizeof(*checks),
               [](const void *arg1, const void *arg2)->int
               {
                   int const *left = static_cast<int const*>(arg1);
                   int const *right = static_cast<int const*>(arg2);
                   return (left[0] < right[0]) ? -1
                   :((right[0] < left[0]) ? 1
                       :(left[1] < right[1] ? -1
                           :((right[1] < left[1] ? 1 : 0))));
               });
    
    //Print Sorted Array
    if(base <= 1000){
    cout << "After Sort..." << '\n';
    for_each(begin(checks), end(checks),
                  [](const int(&checks)[3]) { cout << checks[0] << ','
                                                   << checks[1] << ','
                                                   << checks[2] << '\n';});
    }
    return 0;
}