#include "Login.h"
#include "stock.h"
#include <iomanip> // For setting precision and width

void main()
{
    int choice;

    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        Register(); 
        break;

    case 2:
        login(); 
        break;

    default:
        cout << "Invalid choice. Please try again.\n";
        break;
    }

    

    stock a("bitcoin", 250.0);  

    cout << fixed << setprecision(2);
    cout << "Current price: " << a.get_price() << "\t";  

    a.set_new_price();

    cout << "New price: " << a.get_price() << "\t";     
    cout << "Percentage change: " << a.get_percentage() << "%" << endl; 

}