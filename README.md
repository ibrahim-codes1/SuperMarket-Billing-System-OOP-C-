🛒 Super Market Billing System

A lightweight, console-based Billing and Inventory Management System built using C++. This project allows shopkeepers to easily add items and generate bills for customers.

✨ Features
Item Management: Add new items with Name, Rate, and Quantity.
Automatic Inventory Update: Whenever a bill is generated, the stock is automatically updated in the file.
Persistent Storage: All data is saved in Bill.txt, so the data is not lost when the program is closed.
Real-time Billing: Calculates the total amount and checks whether the item is available in stock or not.

🛠️ Tech Stack
Language: C++
Concepts: OOP (Classes & Objects), File Handling (fstream), String Manipulation (sstream)
Platform: Windows (uses windows.h for UI effects)

📋 Prerequisites
To run this project:
You must have Windows OS (because the project uses windows.h and system("cls")).
A C++ compiler such as MinGW or GCC.
Important Note
The code uses the file path D:/Bill.txt. Therefore, your computer should have a D Drive, or you can modify the file path in the code according to your system.
🚀 How to Run
1. Download the Code
Save the main.cpp file on your system.
2. Compile the Code
Open Terminal or Command Prompt and run:
g++ main.cpp -o BillingSystem
4. Run the Program
./BillingSystem

📖 Usage Guide
Add Item: First, select option 1 to add stock items.
Print Bill: Select option 2, enter the item name and quantity. The program will check stock availability and generate the bill.
Exit: Press option 3 to close the program.

📂 File Structure
main.cpp → Contains the main logic and class definitions.
D:/Bill.txt → Stores all inventory data
Format: Item:Rate:Quantity
