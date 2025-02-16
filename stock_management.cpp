#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

class stockexchange {
    string shop, owner, upi_id;
    int itemsno;
    string items[1000];
    float itemsrate[1000];
    int no[1000];

public:
    void stocksinfo() {
        cout << "Shop name: ";
        cin >> shop;
        cout << "Owner: ";
        cin >> owner;
        cout << "UPI ID: ";
        cin >> upi_id;
        cout << "Number of items available: ";
        cin >> itemsno;
        cout << "Shri/Shrimati " << owner << ", please enter your items and their respective details:\n";
        
        for (int i = 0; i < itemsno; i++) {
            cout << "Name of item " << i + 1 << ": ";
            cin >> items[i];
            cout << "Price of item " << i + 1 << ": ";
            cin >> itemsrate[i];
            cout << "Number of items " << i + 1 << " available: ";
            cin >> no[i];
            cout << endl;
        }
    }

    void stocksmenu() {
        cout << "The items available in " << shop << "'s shop are as below:\n";
        cout << string(74, '\21') << endl;
        cout << "ITEM NAME\tPRICE (in dollars)\tNUMBER OF ITEMS AVAILABLE\n";
        
        for (int i = 0; i < itemsno; i++) {
            cout << items[i] << "\t" << itemsrate[i] * 0.012 << "$\t" << no[i] << "\n";
        }
        cout << string(74, '\21') << endl;
    }

    void newstock() {
        cout << "Name of item " << itemsno + 1 << ": ";
        cin >> items[itemsno];
        cout << "Price of item " << itemsno + 1 << ": ";
        cin >> itemsrate[itemsno];
        cout << "Number of items " << itemsno + 1 << " available: ";
        cin >> no[itemsno];
        cout << endl;
        itemsno += 1;
    }

    void reviewstock() {
        string n;
        int nk = 0, t;
        cout << "Enter the item name of the desired stock: ";
        cin >> n;
        
        for (int i = 0; i < itemsno; i++) {
            if (n == items[i]) {
                cout << "The desired item name is: " << items[i] << "\nRate: " << itemsrate[i] * 0.012 << "$\nNumber available: " << no[i] << "\n";
                nk = 1;
                t = i;
                break;
            }
        }
        
        if (nk == 0) {
            cout << "Invalid stock name. Please recheck.\n";
        } else {
            string km;
            cout << "Do you want to change the item details? Enter 'yes' or 'no': ";
            cin >> km;
            
            if (km == "yes") {
                string nam;
                float dar;
                int enni;
                
                cout << "Enter new item name or 'n/a': ";
                cin >> nam;
                if (nam != "n/a") {
                    items[t] = nam;
                }
                
                cout << "Enter new price or '-1': ";
                cin >> dar;
                if (dar != -1) {
                    itemsrate[t] = dar;
                }
                
                cout << "Enter new item quantity or '-1': ";
                cin >> enni;
                if (enni != -1) {
                    no[t] = enni;
                }
            }
        }
    }
};

int main() {
    int t = 1;
    string decision;
    stockexchange Krish;
    Krish.stocksinfo();
    
    while (t != 0) {
        cout << "\nOptions:\n1. Update stock (enter 'update')\n2. Review stock (enter 'review')\n3. View stock menu (enter 'menu')\n4. Exit (enter 'exit')\n";
        cin >> decision;
        
        if (decision == "menu") {
            Krish.stocksmenu();
        } else if (decision == "review") {
            Krish.reviewstock();
        } else if (decision == "update") {
            Krish.newstock();
        } else if (decision == "exit") {
            Krish.stocksmenu();
            t = 0;
        } else {
            cout << "Invalid command. Please try again.\n";
        }
    }
    
    return 0;
}
