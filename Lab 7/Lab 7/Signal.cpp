#include "Signal.h"
#include <iostream>
#include <limits>

using namespace std;


void SignalGenerator::addSignal(const string& type, double freq, bool mod) {
    Signal s = { type, freq, mod };
    signals.push_back(s);
}


void SignalGenerator::showAll() const {
    if (signals.empty()) {
        cout << "\nList is empty.\n";
        return;
    }

    cout << "\nSignal list:\n";
    for (size_t i = 0; i < signals.size(); ++i) {
        cout << i + 1 << ". Type: " << signals[i].type
            << ", Max frequency: " << signals[i].maxFreq << " Hz"
            << ", Modulation: " << (signals[i].modulation ? "yes" : "no") << endl;
    }
}

void SignalGenerator::findByType(const string& searchType) const {
    bool found = false;
    cout << "\nSearching for signals of type \"" << searchType << "\":\n";
    for (const auto& s : signals) {
        if (s.type == searchType) {
            cout << " - Frequency: " << s.maxFreq << " Hz, "
                << "Modulation: " << (s.modulation ? "yes" : "no") << endl;
            found = true;
        }
    }
    if (!found) cout << "No matches found.\n";
}


void SignalGenerator::clearAll() {
    signals.clear();
    cout << "All data cleared.\n";
}


bool SignalGenerator::insertSignal(size_t index, const string& type, double freq, bool mod) {
    if (index > signals.size()) {
        cout << "❌ Invalid index.\n";
        return false;
    }
    Signal s = { type, freq, mod };
    signals.insert(signals.begin() + index, s);
    return true;
}


bool SignalGenerator::removeSignal(size_t index) {
    if (index >= signals.size()) {
        cout << "❌ Invalid index.\n";
        return false;
    }
    signals.erase(signals.begin() + index);
    return true;
}


bool SignalGenerator::swapSignals(size_t index1, size_t index2) {
    if (index1 >= signals.size() || index2 >= signals.size()) {
        cout << "❌ Invalid indexes.\n";
        return false;
    }
    swap(signals[index1], signals[index2]);
    return true;
}
