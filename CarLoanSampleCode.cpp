#include <iostream>
#include <cmath> // allows the pow function to be used
using namespace std;
int main()
{ // variable decleration

    char packageOptions;
    double base=16800;
    double cost;
    double downPayment;
    double annualInterestRate;
    double loanLength;
    double annualIncome;
    double monthlyPayment;
    double principal;//the amount of the loan
    double monthlyInterest;
    double numberOfMonths;
    double monthlyIncome;
    

    cout <<"Option ‘P’ includes, auto transmission, power windows and locks, stereo sound system. cost: base + 1200\n";
    cout <<"Option ‘L’ includes all the above plus MP3 player, security alarm, cruise control. cost: base + 1800\n";
    cout << "Option ‘D’ includes all of the above plus deluxe detailing, pin stripes, leather seats, wind bar. cost: base + 2300\n";
    cout <<"Option ‘S’ include all the above plus seat heaters, Bose speakers, OnStar, steering wheel controls of music system, chrome rims. cost: base + 2800\n";

    // input
    cout << "enter your package option " ;
    cin>> packageOptions;
 
    cout << "enter the down payment " ;
    cin>> downPayment;


    cout << "enter the annual interest rate of the loan ";
    cin>> annualInterestRate;
    cout << "enter the leght of the loan in years ";

    cin>> loanLength;

    cout << " enter th annual income ";
    cin>>annualIncome;

    switch (packageOptions)

    {

        case 'B':

        case 'b': cost = base ;

        break;

        case 'P':

        case 'p': cost = base + 1200;
        break;
        case 'L':
        case 'l': cost = base +1800;
        break;
        case 'D':
        case 'd': cost = base + 2300;
        break;
        case 'S':
        case 's': cost = base +2800;
        break;
    }
    // PROCESING
    principal = cost - downPayment;
    annualInterestRate = annualInterestRate/100;
    loanLength = 12/loanLength;
    monthlyInterest = annualInterestRate / (12 * 100);
    numberOfMonths = loanLength * 12;
    monthlyIncome = annualIncome /12;
 
   monthlyPayment = principal *  (monthlyInterest / (1 - pow( (1 + monthlyInterest), (numberOfMonths * -1)) ) );

     if ( monthlyIncome *= 4 > monthlyPayment)
 
        cout<< " you are elgible for the loan";
    else
 
        cout<< " you are not elgible for the loan";
 
    // output
    cout << " monthly payment is: " <<monthlyPayment;
    return 0;
}
