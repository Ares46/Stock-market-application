#include "user.h"
#include <iomanip>
#include "link_list_shares.h"

user::user(string n)
{
    username = n;
    cout << "Welcome " << n << "!" << endl;
    balance = 0;
}

void user::set_balance(double a)
{
    balance += a;
    cout << "Your balance is $: " << balance << endl;
}

double user::get_balance()
{
    return balance;
}

void user::buy(link_list* l)
{
    bool found = false;
    string n;
    node* current = l->head;

    // Search for the stock
    while (!found) {
        cout << "Please enter the stock you want to buy: ";
        cin >> n;

        current = l->head;  // Reset to head each time
        while (current != NULL) {
            if (current->data->get_name() == n) {
                found = true;
                break;  // Stock found
            }
            current = current->next;
        }

        if (!found) {
            cout << "Stock doesn't exist. Please try again." << endl;
        }
    }

    int b;
    double total_cost;

    // Enter quantity and process purchase
    cout << "Enter the number of shares you want to buy: ";
    cin >> b;

    total_cost = b * current->data->get_price();
    if (total_cost > balance) {
        cout << "Insufficient balance!" << endl;
    }
    else {
        balance -= total_cost;
        share* a = new share(current->data, b);  // Create the new share object
        users_shares.insert(a);  // Insert into user's shares list
        cout << "Purchase successful!" << endl;
    }
}


void user::display_users_shares() {
    if (users_shares.head == nullptr) {
        cout << "You have no shares." << endl;
        return;
    }

    cout << left << setw(20) << "Stock Name"
        << setw(10) << "Price"
        << setw(20) << "Shares Owned"
        << setw(20) << "Percentage Change" << endl;

    share* current = users_shares.head;
    while (current != nullptr) {
        // Output the stock name, price, and shares owned
        cout << left << setw(20) << current->get_product().get_name()
            << fixed << setprecision(2) // Ensure two decimal places for the price
            << setw(10) << current->get_product().get_price() 
            << setw(20) << (current->get_product().get_price() * current->get_quantaty());

        // Color the percentage based on its value
        double percentage = current->get_product().get_percentage(); // Use getter here
        if (percentage < 0) {
            cout << "\033[31m"; // Red color for negative percentages
        }
        else {
            cout << "\033[32m"; // Green color for positive percentages
        }

        // Print the percentage and reset color
        cout << setw(20) << percentage << "%" << "\033[0m" << endl;

        current = current->next;
    }
}