#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void setInput(int &time,double& rate,double &balance);
double computeRecursive(double Balance, double rate, double time) ;
double computeIterative(double Balance, double rate, double time);
void printTable(double Balance, double rate, double time);
int main()
{
    int choice = 0;
    int n=0;
    double rate=0.0;
    double balance=0.0;

    // cout << computeRecursive(100, 5, 5);

    do
    {
        cout << "Menu options\n"
            << "1) Compounding APY by Recursively function\n"
            << "2) Compounding APY by Loop and functions.\n"
            << "3) Quit the program.\n"
            << "Enter a valid input: ";
        cin >> choice;

        switch (choice)
        {
        
        case 1: setInput(n,rate, balance);
            cout << "Total net gain in APY compounding\n";
            cout << computeRecursive(balance,rate,n)  << "\n\n";
            printTable(balance,rate,n);
             cout <<"\n\n";
            break;
        case 2:  setInput(n,rate, balance);
             cout << "Total net gain in APY compounding\n";
             cout << computeIterative(balance,rate,n)  << "\n\n";
             printTable(balance,rate,n);
             cout <<"\n\n";
            break;
        case 3: cout << "\nQuitting program...\n\n";
            break;
        default: cout << "Enter a number listed on the menu.\n\n";
            cin.clear();
            cin.ignore(128, '\n');
        }
    } while (choice !=3);
    system("pause");
    return 0;
}


double computeRecursive(double Balance, double rate, double time) 
{ 
if ( time <= 0 ) 
{ 
  return Balance; 
} 

return computeRecursive(Balance*(1+rate/100), rate, time-1);
} 



void printTable(double Balance, double rate, double time){
float bal = Balance;
    for (int i = 0; i < time; i++)
    {
       // Compute the interest for this period
       float interest = bal*rate/100;

       // Add the interest to the balance so the interest
       // for the next period is a compound interest.
       
       cout <<"Period "<< i<<"\t"<< "Balance in each period "<<setprecision(8)<< bal<<endl;
       
       cout <<"\t\t\t"<<"Interest: "<<right <<"\t"<< interest <<  endl;
       
       bal += interest;

       
    }

}


double computeIterative(double Balance, double rate, double time)
{
    // The total balance is same as the initial balance if 
    // time is zero.
    float bal = Balance;
    for (int i = 0; i < time; i++)
    {
       // Compute the interest for this period
       float interest = bal*rate/100;

       // Add the interest to the balance so the interest
       // for the next period is a compound interest.
       bal += interest;
    }

    // The total balance after all the interests have
    // been compounded.
    return bal;
}





// Function checks for user input passed by reference with one paramater/

void setInput(int &time,double& rate,double &balance)
{
    
    cout << "\nEnter a whole number >= 1 for balance.\n"
         << "balance: ";
    cin >> balance;

    while (cin.fail() || balance < 1)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, enter a whole number >= 1 for balance.\n"
             << "balance: ";
        cin >> balance;
    }

    cout << "\nEnter a whole number 1%-10% as 1 to 10 for rate of interest.\n"
         << "rate: ";
    cin >> rate;

    while (cin.fail() || rate < -1)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, enter a whole number >= 1 for rate of interest.\n"
             << "rate of interest: ";
        cin >> rate;
    }

    cout << "\nEnter a whole number >= 1 for compounding time.\n"
         << "compounding: ";
    cin >> time;

    while (cin.fail() || time < 1)
    {
        cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, enter a whole number >= 1 for compounding time.\n"
             << "time: ";
        cin >> time;
    }
}


//  clang++-7 -pthread -std=c++17 -o main main.cpp
//  ./main
// Menu options
// 1) Compounding APY by Recursively function
// 2) Compounding APY by Loop and functions.
// 3) Quit the program.
// Enter a valid input: 1

// Enter a whole number >= 1 for balance.
// balance: 10

// Enter a whole number 1%-10% as 1 to 10 for rate of interest.
// rate: 10

// Enter a whole number >= 1 for compounding time.
// compounding: 12
// Total net gain in APY compounding
// 31.3843

// Period 0    Balance in each period 10
//             Interest:   1
// Period 1    Balance in each period 11
//             Interest:   1.1
// Period 2    Balance in each period 12.1
//             Interest:   1.21
// Period 3    Balance in each period 13.31
//             Interest:   1.3310001
// Period 4    Balance in each period 14.641001
//             Interest:   1.4641001
// Period 5    Balance in each period 16.105101
//             Interest:   1.6105101
// Period 6    Balance in each period 17.715611
//             Interest:   1.771561
// Period 7    Balance in each period 19.487171
//             Interest:   1.9487171
// Period 8    Balance in each period 21.435888
//             Interest:   2.1435888
// Period 9    Balance in each period 23.579477
//             Interest:   2.3579478
// Period 10   Balance in each period 25.937426
//             Interest:   2.5937426
// Period 11   Balance in each period 28.531168
//             Interest:   2.8531168
// Period 12   Balance in each period 31.384285
//             Interest:   3.1384284


// Menu options
// 1) Compounding APY by Recursively function
// 2) Compounding APY by Loop and functions.
// 3) Quit the program.
// Enter a valid input: 
// 2

// Enter a whole number >= 1 for balance.
// balance: 10

// Enter a whole number 1%-10% as 1 to 10 for rate of interest.
// rate: 10

// Enter a whole number >= 1 for compounding time.
// compounding: 12
// Total net gain in APY compounding
// 31.384285

// Period 0    Balance in each period 10
//             Interest:   1
// Period 1    Balance in each period 11
//             Interest:   1.1
// Period 2    Balance in each period 12.1
//             Interest:   1.21
// Period 3    Balance in each period 13.31
//             Interest:   1.3310001
// Period 4    Balance in each period 14.641001
//             Interest:   1.4641001
// Period 5    Balance in each period 16.105101
//             Interest:   1.6105101
// Period 6    Balance in each period 17.715611
//             Interest:   1.771561
// Period 7    Balance in each period 19.487171
//             Interest:   1.9487171
// Period 8    Balance in each period 21.435888
//             Interest:   2.1435888
// Period 9    Balance in each period 23.579477
//             Interest:   2.3579478
// Period 10   Balance in each period 25.937426
//             Interest:   2.5937426
// Period 11   Balance in each period 28.531168
//             Interest:   2.8531168
// Period 12   Balance in each period 31.384285
//             Interest:   3.1384284


// Menu options
// 1) Compounding APY by Recursively function
// 2) Compounding APY by Loop and functions.
// 3) Quit the program.
// Enter a valid input: 1

// Enter a whole number >= 1 for balance.
// balance: 10

// Enter a whole number 1%-10% as 1 to 10 for rate of interest.
// rate: 100

// Enter a whole number >= 1 for compounding time.
// compounding: 12
// Total net gain in APY compounding
// 40960

// Period 0    Balance in each period 10
//             Interest:   10
// Period 1    Balance in each period 20
//             Interest:   20
// Period 2    Balance in each period 40
//             Interest:   40
// Period 3    Balance in each period 80
//             Interest:   80
// Period 4    Balance in each period 160
//             Interest:   160
// Period 5    Balance in each period 320
//             Interest:   320
// Period 6    Balance in each period 640
//             Interest:   640
// Period 7    Balance in each period 1280
//             Interest:   1280
// Period 8    Balance in each period 2560
//             Interest:   2560
// Period 9    Balance in each period 5120
//             Interest:   5120
// Period 10   Balance in each period 10240
//             Interest:   10240
// Period 11   Balance in each period 20480
//             Interest:   20480
// Period 12   Balance in each period 40960
//             Interest:   40960


// Menu options
// 1) Compounding APY by Recursively function
// 2) Compounding APY by Loop and functions.
// 3) Quit the program.
// Enter a valid input: 1

// Enter a whole number >= 1 for balance.
// balance: 100

// Enter a whole number 1%-10% as 1 to 10 for rate of interest.
// rate: 12

// Enter a whole number >= 1 for compounding time.
// compounding: 4
// Total net gain in APY compounding
// 157.35194

// Period 0    Balance in each period 100
//             Interest:   12
// Period 1    Balance in each period 112
//             Interest:   13.44
// Period 2    Balance in each period 125.44
//             Interest:   15.0528
// Period 3    Balance in each period 140.4928
//             Interest:   16.859137
// Period 4    Balance in each period 157.35193
//             Interest:   18.882231


// Menu options
// 1) Compounding APY by Recursively function
// 2) Compounding APY by Loop and functions.
// 3) Quit the program.
// Enter a valid input: 2

// Enter a whole number >= 1 for balance.
// balance: 1000

// Enter a whole number 1%-10% as 1 to 10 for rate of interest.
// rate: 11

// Enter a whole number >= 1 for compounding time.
// compounding: 6
// Total net gain in APY compounding
// 1870.4147

// Period 0    Balance in each period 1000
//             Interest:   110
// Period 1    Balance in each period 1110
//             Interest:   122.1
// Period 2    Balance in each period 1232.1
//             Interest:   135.53099
// Period 3    Balance in each period 1367.631
//             Interest:   150.43941
// Period 4    Balance in each period 1518.0704
//             Interest:   166.98775
// Period 5    Balance in each period 1685.0582
//             Interest:   185.3564
// Period 6    Balance in each period 1870.4147
//             Interest:   205.74562


// Menu options
// 1) Compounding APY by Recursively function
// 2) Compounding APY by Loop and functions.
// 3) Quit the program.
// Enter a valid input: 3

// Quitting program...

// sh: 1: pause: not found
