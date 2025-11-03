#ifndef SIGNAL_H
#define SIGNAL_H

#include <string>
#include <vector>

struct Signal {
    std::string type;   
    double maxFreq;     
    bool modulation;  
};

class SignalGenerator {
private:
    std::vector<Signal> signals; 

public:
    
    void addSignal(const std::string& type, double freq, bool mod);
    void showAll() const;
    void findByType(const std::string& searchType) const;
    void clearAll();

   
    bool insertSignal(size_t index, const std::string& type, double freq, bool mod);
    bool removeSignal(size_t index);
    bool swapSignals(size_t index1, size_t index2);
};

#endif
