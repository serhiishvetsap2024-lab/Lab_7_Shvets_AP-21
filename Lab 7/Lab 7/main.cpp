#include <iostream>
#include <limits>
#include "Signal.h"
using namespace std;

int main() {
    SignalGenerator sg;
    int choice;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Add signal\n";
        cout << "2. Show all signals\n";
        cout << "3. Find by type\n";
        cout << "4. Insert signal at position\n";
        cout << "5. Remove signal\n";
        cout << "6. Swap two signals\n";
        cout << "7. Clear all\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        switch (choice) {
        case 1: {
            string type;
            double freq;
            char modChar;
            bool mod;

            cout << "Enter signal type (can include spaces): ";
            getline(cin, type);

            while (true) {
                cout << "Enter maximum frequency (Hz): ";
                cin >> freq;
                if (cin.fail() || freq <= 0) {
                    cout << "❌ The frequency must be a positive number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else break;
            }

            while (true) {
                cout << "Has modulation? (y/n): ";
                cin >> modChar;
                if (modChar == 'y' || modChar == 'Y') { mod = true; break; }
                else if (modChar == 'n' || modChar == 'N') { mod = false; break; }
                else cout << "❌ Enter 'y' or 'n' only.\n";
            }

            sg.addSignal(type, freq, mod);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        case 2:
            sg.showAll();
            break;

        case 3: {
            string search;
            cout << "Enter type to search: ";
            getline(cin, search);
            sg.findByType(search);
            break;
        }

        case 4: {
            string type;
            double freq;
            char modChar;
            bool mod;
            size_t index;

            cout << "Enter position (starting from 0): ";
            cin >> index;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter signal type: ";
            getline(cin, type);

            while (true) {
                cout << "Enter maximum frequency (Hz): ";
                cin >> freq;
                if (cin.fail() || freq <= 0) {
                    cout << "❌ The frequency must be a positive number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else break;
            }

            while (true) {
                cout << "Has modulation? (y/n): ";
                cin >> modChar;
                if (modChar == 'y' || modChar == 'Y') { mod = true; break; }
                else if (modChar == 'n' || modChar == 'N') { mod = false; break; }
                else cout << "❌ Enter 'y' or 'n' only.\n";
            }

            sg.insertSignal(index, type, freq, mod);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        case 5: {
            size_t index;
            cout << "Enter index to remove (starting from 0): ";
            cin >> index;
            sg.removeSignal(index);
            break;
        }

        case 6: {
            size_t i1, i2;
            cout << "Enter first index: ";
            cin >> i1;
            cout << "Enter second index: ";
            cin >> i2;
            sg.swapSignals(i1, i2);
            break;
        }

        case 7:
            sg.clearAll();
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
