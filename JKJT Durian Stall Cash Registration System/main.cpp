#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Structure to hold durian information
struct Durian {
    string type;
    string priceRange;
};

// Structure to hold transaction information
struct Transaction {
    int customerNo;
    string date;
    string durianType;
    double pricePerKg;
    double weight;
    double totalPrice;
};

// Constants for maximum array sizes
const int MAX_DURIANS = 50;
const int MAX_TRANSACTIONS = 1000;

// Function prototypes
void displayMainMenu();
void menuHandling();
void transactionHandling();

// Member 1 functions (Menu Handling)
void addDurian();
void updateDurian();
void deleteDurian();
int readDurianFile(Durian durians[]);
void writeDurianFile(Durian durians[], int count);
void displayDurianList(Durian durians[], int count);
bool durianExists(Durian durians[], int count, string type);

// Member 2 functions (Transaction Handling)
void addTransaction();
void filterTransactionHistory();
int readTransactionFile(Transaction transactions[]);
void writeTransactionFile(Transaction transactions[], int count);
void displayTransaction(Transaction trans);
void displayAllTransactions(Transaction transactions[], int count);
int getNextCustomerNumber();

// Utility functions
string toLowerCase(string str);
double parsePrice(string priceRange, bool getMin);
bool isValidPriceInRange(double price, string priceRange);
void waitForEnter();
void clearScreen();
void printWelcomeMessage();
void printGoodbyeMessage();

int main() {
    char choice;

    printWelcomeMessage();
    cout << "\n          >> Press Enter to continue... <<";
    cin.get(); // Just use cin.get() without cin.ignore() for the first wait

    do {
        clearScreen();
        displayMainMenu();
        cout << "\n>> Please select your choice: ";
        cin >> choice;
        choice = toupper(choice);

        switch (choice) {
        case 'A':
            menuHandling();
            break;
        case 'B':
            transactionHandling();
            break;
        case 'X':
            clearScreen();
            printGoodbyeMessage();
            break;
        default:
            cout << "\n>> Invalid choice! Please try again. <<\n";
            waitForEnter();
        }
    } while (choice != 'X');

    return 0;
}

void printWelcomeMessage() {
    clearScreen();
    cout << "+--------------------------------------------------+\n";
    cout << "|                     WELCOME TO                   |\n";
    cout << "|                                                  |\n";
    cout << "|    ****   *   *  ****   *****    ***    *   *    |\n";
    cout << "|    *   *  *   *  *   *    *      *   *  **  *    |\n";
    cout << "|    *   *  *   *  ****     *      *****  * * *    |\n";
    cout << "|    *   *  *   *  *   *    *      *   *  *  **    |\n";
    cout << "|    ****   *****  *   *  *****    *   *  *   *    |\n";
    cout << "|                                                  |\n";
    cout << "|                   STALL SYSTEM                   |\n";
    cout << "|                                                  |\n";
    cout << "+--------------------------------------------------+\n";
}

void printGoodbyeMessage() {
    cout << "+-----------------------------------------------------------------+\n";
    cout << "|                                                                 |\n";
    cout << "|    ****  *   *    ***   *   *  *   *   *   *  *****  *   *      |\n";
    cout << "|      *   *   *   *   *  **  *  *  *     * *   *   *  *   *      |\n";
    cout << "|      *   *****   *****  * * *  ***       *    *   *  *   *      |\n";
    cout << "|      *   *   *   *   *  *  **  *  *      *    *   *  *   *      |\n";
    cout << "|      *   *   *   *   *  *   *  *   *     *    *****  *****      |\n";
    cout << "|                                                                 |\n";
    cout << "|           Thank you for using JKJT Durian Stall!                |\n";
    cout << "|                     Have a great day!                           |\n";
    cout << "|                                                                 |\n";
    cout << "+-----------------------------------------------------------------+\n";
}

void displayMainMenu() {
    cout << "+----------------------------------------------------------+\n";
    cout << "|                                                          |\n";
    cout << "|      +=====================================+             |\n";
    cout << "|      |      JKJT DURIAN STALL SYSTEM       |             |\n";
    cout << "|      |         CASH REGISTRATION           |             |\n";
    cout << "|      +=====================================+             |\n";
    cout << "|                                                          |\n";
    cout << "|                 >> MAIN MENU <<                          |\n";
    cout << "|                                                          |\n";
    cout << "|      +-------------------------------------+             |\n";
    cout << "|      |  A. [#] Menu Handling               |             |\n";
    cout << "|      |                                     |             |\n";
    cout << "|      |  B. [$] Transaction Handling        |             |\n";
    cout << "|      |                                     |             |\n";
    cout << "|      |  X. [X] Exit System                 |             |\n";
    cout << "|      +-------------------------------------+             |\n";
    cout << "|                                                          |\n";
    cout << "+----------------------------------------------------------+\n";
}

void menuHandling() {
    int choice;

    do {
        clearScreen();
        cout << "+------------------------------------------------------+\n";
        cout << "|                                                      |\n";
        cout << "|              ###  +========+  ###                    |\n";
        cout << "|             ##### | DURIAN | #####                   |\n";
        cout << "|              ###  +========+  ###                    |\n";
        cout << "|                                                      |\n";
        cout << "|              >> MENU HANDLING <<                     |\n";
        cout << "|                                                      |\n";
        cout << "|        +-----------------------------------+         |\n";
        cout << "|        |  1. [+] Add Durian Type           |         |\n";
        cout << "|        |                                   |         |\n";
        cout << "|        |  2. [~] Update Durian Info        |         |\n";
        cout << "|        |                                   |         |\n";
        cout << "|        |  3. [-] Delete Durian Type        |         |\n";
        cout << "|        |                                   |         |\n";
        cout << "|        |  4. [<] Back to Main Menu         |         |\n";
        cout << "|        +-----------------------------------+         |\n";
        cout << "|                                                      |\n";
        cout << "+------------------------------------------------------+\n";
        cout << "\n>> Please select your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addDurian();
            break;
        case 2:
            updateDurian();
            break;
        case 3:
            deleteDurian();
            break;
        case 4:
            return;
        default:
            cout << "\n>> Invalid choice! Please try again. <<\n";
            waitForEnter();
        }
    } while (choice != 4);
}

void transactionHandling() {
    int choice;

    do {
        clearScreen();
        cout << "+-------------------------------------------------------+\n";
        cout << "|                                                       |\n";
        cout << "|           +==+ +==+ +==+ +==+                         |\n";
        cout << "|           |$| |$| |$| |$|                             |\n";
        cout << "|           +==+ +==+ +==+ +==+                         |\n";
        cout << "|                                                       |\n";
        cout << "|         >> TRANSACTION HANDLING <<                    |\n";
        cout << "|                                                       |\n";
        cout << "|    +-------------------------------------+            |\n";
        cout << "|    |  1. [+] Add Transaction             |            |\n";
        cout << "|    |                                     |            |\n";
        cout << "|    |  2. [?] Filter Transaction History  |            |\n";
        cout << "|    |                                     |            |\n";
        cout << "|    |  3. [<] Back to Main Menu           |            |\n";
        cout << "|    +-------------------------------------+            |\n";
        cout << "|                                                       |\n";
        cout << "+-------------------------------------------------------+\n";
        cout << "\n>> Please select your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addTransaction();
            break;
        case 2:
            filterTransactionHistory();
            break;
        case 3:
            return;
        default:
            cout << "\n>> Invalid choice! Please try again. <<\n";
            waitForEnter();
        }
    } while (choice != 3);
}

// ==================== MEMBER 1 FUNCTIONS ====================

void addDurian() {
    clearScreen();
    cout << "+----------------------------------------------------------+\n";
    cout << "|                                                          |\n";
    cout << "|               >> ADD DURIAN TYPE <<                      |\n";
    cout << "|                                                          |\n";
    cout << "+----------------------------------------------------------+\n";

    Durian durians[MAX_DURIANS];
    int durianCount = readDurianFile(durians);

    string type, priceRange;
    char addMore;

    do {
        cout << "\n>> Please enter the information below:\n";
        cout << "   Durian Type: ";
        cin.ignore();
        getline(cin, type);

        // Check if durian type already exists
        if (durianExists(durians, durianCount, type)) {
            cout << "   >> Durian type '" << type << "' already exists! <<\n";
            cout << "   Do you want to add another type of durian? (Y/N): ";
            cin >> addMore;
            continue;
        }

        cout << "   Price Range: ";
        getline(cin, priceRange);

        if (durianCount < MAX_DURIANS) {
            durians[durianCount].type = type;
            durians[durianCount].priceRange = priceRange;
            durianCount++;

            cout << "\n   [SUCCESS] Durian type added successfully!\n";
        }
        else {
            cout << "\n   >> Cannot add more durians. Maximum limit reached! <<\n";
        }

        cout << "   Do you want to add more type of durian? (Y/N): ";
        cin >> addMore;
        addMore = toupper(addMore);

    } while (addMore == 'Y' && durianCount < MAX_DURIANS);

    writeDurianFile(durians, durianCount);
    waitForEnter();
}

void updateDurian() {
    clearScreen();
    cout << "+----------------------------------------------------------+\n";
    cout << "|                                                          |\n";
    cout << "|             >> UPDATE DURIAN INFO <<                     |\n";
    cout << "|                                                          |\n";
    cout << "+----------------------------------------------------------+\n";

    Durian durians[MAX_DURIANS];
    int durianCount = readDurianFile(durians);

    if (durianCount == 0) {
        cout << "\n   >> No durian types available to update. <<\n";
        waitForEnter();
        return;
    }

    string type;
    char updateMore;

    do {
        cout << "\n>> Please enter the durian type that you want to update:\n";
        cout << "   Durian Type: ";
        cin.ignore();
        getline(cin, type);

        bool found = false;
        for (int i = 0; i < durianCount; i++) {
            if (toLowerCase(durians[i].type) == toLowerCase(type)) {
                found = true;
                cout << "\n   [FOUND] Information below:\n";
                cout << "   > " << durians[i].type << "\n";
                cout << "   > " << durians[i].priceRange << "\n\n";

                int updateChoice;
                cout << ">> Please enter the information that you want to update:\n";
                cout << "   1. Durian type\n";
                cout << "   2. Price range\n";
                cout << "   Choice: ";
                cin >> updateChoice;

                if (updateChoice == 1) {
                    cout << "   New Durian Type: ";
                    cin.ignore();
                    getline(cin, durians[i].type);
                }
                else if (updateChoice == 2) {
                    cout << "   New Price Range: ";
                    cin.ignore();
                    getline(cin, durians[i].priceRange);
                }

                cout << "\n   [SUCCESS] Successfully updated as below:\n";
                cout << "   > " << durians[i].type << "\n";
                cout << "   > " << durians[i].priceRange << "\n";
                break;
            }
        }

        if (!found) {
            cout << "\n   >> Durian type not found! <<\n";
        }

        cout << "\n   Do you want to update another information? (Y/N): ";
        cin >> updateMore;
        updateMore = toupper(updateMore);

    } while (updateMore == 'Y');

    writeDurianFile(durians, durianCount);
    waitForEnter();
}

void deleteDurian() {
    clearScreen();
    cout << "+----------------------------------------------------------+\n";
    cout << "|                                                          |\n";
    cout << "|             >> DELETE DURIAN TYPE <<                     |\n";
    cout << "|                                                          |\n";
    cout << "+----------------------------------------------------------+\n";

    Durian durians[MAX_DURIANS];
    int durianCount = readDurianFile(durians);

    if (durianCount == 0) {
        cout << "\n   >> No durian types available to delete. <<\n";
        waitForEnter();
        return;
    }

    char deleteMore;

    do {
        cout << "\n>> Here is the list of durian types in the menu:\n";
        for (int i = 0; i < durianCount; i++) {
            cout << "   [" << (i + 1) << "] " << durians[i].type << "\n";
        }

        int choice;
        cout << "\n   Please select the type of durian that you would like to delete: ";
        cin >> choice;

        if (choice >= 1 && choice <= durianCount) {
            cout << "\n   >> Deleting: " << durians[choice - 1].type << " <<\n";

            // Shift all elements after the deleted one to the left
            for (int i = choice - 1; i < durianCount - 1; i++) {
                durians[i] = durians[i + 1];
            }
            durianCount--;

            cout << "   [SUCCESS] Successfully deleted!!\n";

            cout << "\n>> Here is the latest list:\n";
            for (int i = 0; i < durianCount; i++) {
                cout << "   [" << (i + 1) << "] " << durians[i].type << "\n";
            }
        }
        else {
            cout << "\n   >> Invalid selection! <<\n";
        }

        cout << "\n   Do you want to delete another durian type? (Y/N): ";
        cin >> deleteMore;
        deleteMore = toupper(deleteMore);

    } while (deleteMore == 'Y' && durianCount > 0);

    writeDurianFile(durians, durianCount);
    waitForEnter();
}

// ==================== MEMBER 2 FUNCTIONS ====================

void addTransaction() {
    clearScreen();
    cout << "+----------------------------------------------------------+\n";
    cout << "|                                                          |\n";
    cout << "|             >> ADD TRANSACTION <<                        |\n";
    cout << "|                                                          |\n";
    cout << "+----------------------------------------------------------+\n";

    Durian durians[MAX_DURIANS];
    int durianCount = readDurianFile(durians);

    if (durianCount == 0) {
        cout << "\n   >> No durian types available. Please add durian types first. <<\n";
        waitForEnter();
        return;
    }

    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount = readTransactionFile(transactions);
    int customerNo = getNextCustomerNumber();
    char addMore;

    do {
        cout << "\n>> Available List:\n";
        for (int i = 0; i < durianCount; i++) {
            cout << "   [" << (i + 1) << "] " << durians[i].type << "\n";
            cout << "       Price Range: RM" << durians[i].priceRange << "\n";
        }

        int choice;
        cout << "\n   Please choose the durian type: ";
        cin >> choice;

        if (choice >= 1 && choice <= durianCount) {
            if (transactionCount < MAX_TRANSACTIONS) {
                Transaction trans;
                trans.customerNo = customerNo;
                trans.durianType = durians[choice - 1].type;

                do {
                    cout << "   Price per kg: ";
                    cin >> trans.pricePerKg;

                    if (!isValidPriceInRange(trans.pricePerKg, durians[choice - 1].priceRange)) {
                        // Extract clean price range for display
                        string cleanRange = durians[choice - 1].priceRange;
                        size_t rmPos = cleanRange.find("RM");
                        if (rmPos != string::npos) {
                            cleanRange = cleanRange.substr(rmPos + 2);
                        }
                        cout << "   >> Please enter the price in the range of RM" << cleanRange << "!! <<\n";
                    }
                    else {
                        break;
                    }
                } while (true);

                cout << "   Weight (kg): ";
                cin >> trans.weight;

                cout << "   Date (dd/mm/yyyy): ";
                cin >> trans.date;

                trans.totalPrice = trans.pricePerKg * trans.weight;

                cout << fixed << setprecision(2);
                cout << "\n   [SUCCESS] Total price for " << trans.weight << "kg "
                    << trans.durianType << " is RM" << trans.totalPrice << ".\n";

                transactions[transactionCount] = trans;
                transactionCount++;
            }
            else {
                cout << "\n   >> Cannot add more transactions. Maximum limit reached! <<\n";
            }
        }
        else {
            cout << "\n   >> Invalid selection! <<\n";
        }

        cout << "\n   Do you want to enter another type of durian? (Y/N): ";
        cin >> addMore;
        addMore = toupper(addMore);

    } while (addMore == 'Y' && transactionCount < MAX_TRANSACTIONS);

    writeTransactionFile(transactions, transactionCount);
    waitForEnter();
}

void filterTransactionHistory() {
    clearScreen();
    cout << "+----------------------------------------------------------+\n";
    cout << "|                                                          |\n";
    cout << "|           >> TRANSACTION HISTORY <<                      |\n";
    cout << "|                                                          |\n";
    cout << "+----------------------------------------------------------+\n";

    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount = readTransactionFile(transactions);

    if (transactionCount == 0) {
        cout << "\n   >> No transaction history available. <<\n";
        waitForEnter();
        return;
    }

    int filterChoice;
    cout << "\n>> Transaction History (Displaying All):\n";
    displayAllTransactions(transactions, transactionCount);

    cout << "\n>> Please select the attribute to filter:\n";
    cout << "   1. [*] Date\n";
    cout << "   2. [#] Durian Type\n";
    cout << "   3. [@] Customer No.\n";
    cout << "   4. [*] View All (No Filter)\n";
    cout << "   Choice: ";
    cin >> filterChoice;

    switch (filterChoice) {
    case 1: {
        string filterDate;
        cout << "   Enter date to filter (dd/mm/yyyy): ";
        cin >> filterDate;

        cout << "\n>> Filtered Results (Date: " << filterDate << "):\n";
        bool found = false;
        for (int i = 0; i < transactionCount; i++) {
            if (transactions[i].date == filterDate) {
                displayTransaction(transactions[i]);
                found = true;
            }
        }
        if (!found) {
            cout << "   >> No transactions found for date: " << filterDate << " <<\n";
        }
        break;
    }
    case 2: {
        string filterType;
        cout << "   Enter durian type to filter: ";
        cin.ignore();
        getline(cin, filterType);

        cout << "\n>> Filtered Results (Durian Type: " << filterType << "):\n";
        bool found = false;
        for (int i = 0; i < transactionCount; i++) {
            if (toLowerCase(transactions[i].durianType) == toLowerCase(filterType)) {
                displayTransaction(transactions[i]);
                found = true;
            }
        }
        if (!found) {
            cout << "   >> No transactions found for durian type: " << filterType << " <<\n";
        }
        break;
    }
    case 3: {
        int filterCustomer;
        cout << "   Enter customer number to filter: ";
        cin >> filterCustomer;

        cout << "\n>> Filtered Results (Customer No.: " << filterCustomer << "):\n";
        bool found = false;
        for (int i = 0; i < transactionCount; i++) {
            if (transactions[i].customerNo == filterCustomer) {
                displayTransaction(transactions[i]);
                found = true;
            }
        }
        if (!found) {
            cout << "   >> No transactions found for customer number: " << filterCustomer << " <<\n";
        }
        break;
    }
    case 4:
        cout << "\n>> All Transactions:\n";
        displayAllTransactions(transactions, transactionCount);
        break;
    default:
        cout << "\n   >> Invalid choice! <<\n";
    }

    waitForEnter();
}

// ==================== FILE I/O FUNCTIONS ====================

int readDurianFile(Durian durians[]) {
    ifstream file("durian.txt");
    int count = 0;

    if (file.is_open()) {
        string line;
        while (getline(file, line) && !line.empty() && count < MAX_DURIANS) {
            durians[count].type = line;
            if (getline(file, durians[count].priceRange)) {
                count++;
            }
        }
        file.close();
    }

    return count;
}

void writeDurianFile(Durian durians[], int count) {
    ofstream file("durian.txt");

    if (file.is_open()) {
        for (int i = 0; i < count; i++) {
            file << durians[i].type << "\n";
            file << durians[i].priceRange << "\n";
        }
        file.close();
    }
}

int readTransactionFile(Transaction transactions[]) {
    ifstream file("transaction.txt");
    int count = 0;

    if (file.is_open()) {
        string line;
        while (getline(file, line) && !line.empty() && count < MAX_TRANSACTIONS) {
            transactions[count].customerNo = stoi(line);

            if (getline(file, transactions[count].date) &&
                getline(file, transactions[count].durianType) &&
                getline(file, line)) {

                // Parse price and weight from same line
                size_t spacePos = line.find(' ');
                if (spacePos != string::npos) {
                    transactions[count].pricePerKg = stod(line.substr(0, spacePos));
                    transactions[count].weight = stod(line.substr(spacePos + 1));
                }

                if (getline(file, line)) {
                    transactions[count].totalPrice = stod(line);
                    count++;
                }
            }
        }
        file.close();
    }

    return count;
}

void writeTransactionFile(Transaction transactions[], int count) {
    ofstream file("transaction.txt");

    if (file.is_open()) {
        for (int i = 0; i < count; i++) {
            file << transactions[i].customerNo << "\n";
            file << transactions[i].date << "\n";
            file << transactions[i].durianType << "\n";
            file << fixed << setprecision(2) << transactions[i].pricePerKg << " " << transactions[i].weight << "\n";
            file << transactions[i].totalPrice << "\n";
        }
        file.close();
    }
}

// ==================== UTILITY FUNCTIONS ====================

void displayDurianList(Durian durians[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "[" << (i + 1) << "] " << durians[i].type << "\n";
    }
}

bool durianExists(Durian durians[], int count, string type) {
    for (int i = 0; i < count; i++) {
        if (toLowerCase(durians[i].type) == toLowerCase(type)) {
            return true;
        }
    }
    return false;
}

void displayTransaction(Transaction trans) {
    cout << "+----------------------------------------+\n";
    cout << "| > Customer No.: " << setw(18) << trans.customerNo << " |\n";
    cout << "| > Date: " << setw(27) << trans.date << " |\n";
    cout << "| > Durian Type: " << setw(19) << trans.durianType << " |\n";
    cout << "| > Price per KG: RM" << setw(16) << fixed << setprecision(2) << trans.pricePerKg << " |\n";
    cout << "| > Weight: " << setw(21) << trans.weight << "kg |\n";
    cout << "| > Total: RM " << setw(21) << trans.totalPrice << " |\n";
    cout << "+----------------------------------------+\n\n";
}

void displayAllTransactions(Transaction transactions[], int count) {
    for (int i = 0; i < count; i++) {
        displayTransaction(transactions[i]);
    }
}

int getNextCustomerNumber() {
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount = readTransactionFile(transactions);

    if (transactionCount == 0) {
        return 1;
    }

    int maxCustomer = 0;
    for (int i = 0; i < transactionCount; i++) {
        if (transactions[i].customerNo > maxCustomer) {
            maxCustomer = transactions[i].customerNo;
        }
    }
    return maxCustomer + 1;
}

string toLowerCase(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

double parsePrice(string priceRange, bool getMin) {
    string cleanRange = priceRange;

    // Remove "RM" prefix if present
    size_t rmPos = cleanRange.find("RM");
    if (rmPos != string::npos) {
        cleanRange = cleanRange.substr(rmPos + 2);
    }

    // Look for dash separator (with or without spaces)
    size_t dashPos = cleanRange.find(" - ");
    if (dashPos == string::npos) {
        dashPos = cleanRange.find("-");
        if (dashPos != string::npos) {
            if (getMin) {
                return stod(cleanRange.substr(0, dashPos));
            }
            else {
                return stod(cleanRange.substr(dashPos + 1));
            }
        }
    }
    else {
        if (getMin) {
            return stod(cleanRange.substr(0, dashPos));
        }
        else {
            return stod(cleanRange.substr(dashPos + 3));
        }
    }
    return 0.0;
}

bool isValidPriceInRange(double price, string priceRange) {
    double minPrice = parsePrice(priceRange, true);
    double maxPrice = parsePrice(priceRange, false);

    // Add small tolerance for floating point comparison
    return (price >= (minPrice - 0.001) && price <= (maxPrice + 0.001));
}

void waitForEnter() {
    cout << "\n>> Press Enter to continue... <<";
    cin.ignore();
    cin.get();
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}