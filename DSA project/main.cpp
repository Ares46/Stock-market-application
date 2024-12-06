#include "Login.h"

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


}