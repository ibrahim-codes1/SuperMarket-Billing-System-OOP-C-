#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class Bill {
private:
    string Item;
    int Rate, Quantity;
public:
    Bill() : Item(""), Rate(0), Quantity(0) { }

    void setItem(string item) { Item = item; }
    void setRate(int rate) { Rate = rate; }
    void setQuantity(int quant) { Quantity = quant; }

    string getItem() { return Item; }
    int getRate() { return Rate; }
    int getQuantity() { return Quantity; }
};

void addItem(Bill &b) {
    bool close = false;
    while (!close) {
        int choice;
        cout << "\t1.Add." << endl;
        cout << "\t2.Close." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            system("cls");
            string item;
            int rate, quant;

            cout << "\tEnter Item Name: ";
            cin >> item;
            b.setItem(item);

            cout << "\tEnter Rate of Item: ";
            cin >> rate;
            b.setRate(rate);

            cout << "\tEnter Quantity of Item: ";
            cin >> quant;
            b.setQuantity(quant);

            ofstream out("D:/Bill.txt", ios::app);
            if (!out) {
                cout << "\tError: File Can't Open!" << endl;
            } else {
                out << b.getItem() << ":" << b.getRate() << ":" << b.getQuantity() << endl;
            }
            out.close();
            cout << "\tItem Added Successfully" << endl;
            Sleep(2000);
        }
        else if (choice == 2) {
            system("cls");
            close = true;
            cout << "\tBack to Main Menu!" << endl;
            Sleep(2000);
        }
    }
}

void PrintBill() {
    system("cls");
    int count = 0;
    bool close = false;
    while (!close) {
        int choice;
        cout << "\t1.Add Bill." << endl;
        cout << "\t2.Close Session." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            string item;
            int quant;
            cout << "\tEnter Item: ";
            cin >> item;
            cout << "\tEnter Quantity: ";
            cin >> quant;

            ifstream in("D:/Bill.txt");
            ofstream out("D:/BillTemp.txt");
            string line;
            bool found = false;

            while (getline(in, line)) {
                stringstream ss(line);
                string ItemName;
                int ItemRate, ItemQuantity;
                char colon;

                getline(ss, ItemName, ':');
                ss >> ItemRate >> colon >> ItemQuantity;

                if (item == ItemName) {
                    found = true;
                    if (quant <= ItemQuantity) {
                        int amount = ItemRate * quant;
                        cout << "\t Item | Rate | Quantity | Amount " << endl;
                        cout << "\t" << ItemName << "\t " << ItemRate << "\t " << quant << "\t " << amount << endl;
                        int NewQuantity = ItemQuantity - quant;
                        count += amount;
                        out << ItemName << ":" << ItemRate << ":" << NewQuantity << endl;
                    } else {
                        cout << "\tSorry, " << item << " Ended!" << endl;
                        out << line << endl;
                    }
                } else {
                    out << line << endl;
                }
            }
            if (!found) {
                cout << "\tItem Not Available!" << endl;
            }
            out.close();
            in.close();
            remove("D:/Bill.txt");
            rename("D:/BillTemp.txt", "D:/Bill.txt");
        }
        else if (choice == 2) {
            close = true;
            cout << "\tCounting Total Bill..." << endl;
        }
        Sleep(2000);
    }
    system("cls");
    cout << "\tTotal Bill ------------------- : " << count << endl;
    cout << "\tThanks For Shopping!" << endl;
    Sleep(3000);
}

int main() {
    Bill b;
    bool exit = false;
    while (!exit) {
        system("cls");
        int val;
        cout << "\tWelcome To Super Market Billing System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t1.Add Item." << endl;
        cout << "\t2.Print Bill." << endl;
        cout << "\t3.Exit." << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if (val == 1) {
            system("cls");
            addItem(b);
        }
        else if (val == 2) {
            PrintBill();
        }
        else if (val == 3) {
            system("cls");
            exit = true;
            cout << "\tGood Luck!" << endl;
            Sleep(2000);
        }
    }
    return 0;
}

