#include <iostream>
#include <ctime>
#include "Tracker.h"
#include <fstream>
#include <iomanip>


using namespace std;

void spacer() {
    for (int i = 0; i < 2; i++) {
        cout << setw(50) << "*" << "                  " << "*" << "\n";
    }
}


int main()
{

    //title 

    cout << setw(69) << "Hot and Cold Tracker" << "\n";


    spacer();

    Tracker Austin;

    Austin.clock();

   
    //prompt for input 
    
    double input = 0.0;
    string inputt = "";
    cout << setw(59) << "Input time" << "\n";

    cin >> input;

    spacer();

    if (input >= 10.0) {
        Austin.addHot(input);
    }
    else
        Austin.addCold(input);

        

    
}

