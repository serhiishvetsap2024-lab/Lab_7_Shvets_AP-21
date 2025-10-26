#include <iostream>
#include <string>
#include <vector>
#include <limits> 
using namespace std;

struct Signal {
    string type;       
    double maxFreq;   
    bool modulation;   
};

class SignalGenerator {
private:
    vector<Signal> signals;

public:
    void addSignal(const string& type, double freq, bool mod) {
        Signal s = { type, freq, mod };
        signals.push_back(s);
    }

    void showAll() const {
        if (signals.empty()) {
            cout << "\nList is empty.\n";
            return;
        }

        cout << "\nList of Signals:\n";
        for (size_t i = 0; i < signals.size(); ++i) {
            cout << i + 1 << ". Type: " << signals[i].type
                << ", Max Freq: " << signals[i].maxFreq << " Hz"
                << ", Modulation: " << (signals[i].modulation ? "Yes" : "No") << endl;
        }
    }

    void findByType(const string& searchType) const {
        bool found = false;
        cout << "\nSearching for Sygnal type \"" << searchType << "\":\n";
        for (const auto& s : signals) {
            if (s.type == searchType) {
                cout << " - Freq: " << s.maxFreq << " Hz, "
                    << "Modulation: " << (s.modulation ? "Yes" : "No") << endl;
                found = true;
            }
        }
        if (!found) cout << "Nothing Found.\n";
    }

    void clearAll() {
        signals.clear();
        cout << "All Data Clear.\n";
    }
};

int main() {
    setlocale(LC_ALL, "ukr");

    SignalGenerator sg;
    int choice;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Add Sygnal\n";
        cout << "2. Show All Sygnals\n";
        cout << "3. Found Sygnal By Type\n";
        cout << "4. Clear the List\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR Choise. Try Again.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        switch (choice) {
        case 1: {
            string type;
            double freq;
            char modChar;
            bool mod;

            cout << "Enter Sygnal Type (may be a few words): ";
            getline(cin, type);

          
            while (true) {
                cout << "Enter Max Freq (HZ): ";
                cin >> freq;
                if (cin.fail() || freq <= 0) {
                    cout << "ERROR! The frequency must be a positive number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else break;
            }

            
            while (true) {
                cout << "Modulation? (y/n): ";
                cin >> modChar;
                if (modChar == 'y' || modChar == 'Y') {
                    mod = true;
                    break;
                }
                else if (modChar == 'n' || modChar == 'N') {
                    mod = false;
                    break;
                }
                else {
                    cout << "Enter just 'y' or 'n'.\n";
                }
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
            cout << "Enter type for searching: ";
            getline(cin, search);
            sg.findByType(search);
            break;
        }

        case 4:
            sg.clearAll();
            break;

        case 0:
            cout << "Program is done. Exit.\n";
            break;

        default:
            cout << "Invalid Choise.\n";
        }

    } while (choice != 0);

    return 0;
}
