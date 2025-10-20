#include <map>
#include <string>
#include "HeatFlow.hpp"
#include <iostream>

HeatFlow::HeatFlow(int initialT, int numSections, float K, std::map<int, float> sources_and_sinks) {
    this->initialT = initialT;
    this->numSections = numSections;
    this->K = K;
    this->sources_and_sinks = sources_and_sinks;
}
void HeatFlow::tick() {
    std::map<int, float> tempRod = getRod();
    for (int i = 0; i < numSections; i++) {
        for (int j = 0; j < ss.size(); j++) {
            if (i != ss[j]) {
                if (i == 0) {
                    rod[i] = tempRod[i] + K * (rod[i + 1] - 2 * rod[i] + tempRod[i]);
                }
                else if (i == numSections - 1) {
                    rod[i] = tempRod[i] + K * (rod[i] - 2 * rod[i] + tempRod[i - 1]);
                }
                else {
                    rod[i] = tempRod[i] + K * (rod[i + 1] - 2 * rod[i] + tempRod[i - 1]);
                }
            }
            else {
                rod[i] = tempRod[i];
                break;
            }
        }
    }

}
void HeatFlow::initializeRod() {
    for (int i = 0; i < numSections; i++) {
        rod.insert(std::make_pair(i, initialT));
    }
    for (std::map<int,float>::iterator iter = sources_and_sinks.begin(); iter != sources_and_sinks.end(); iter++) {
        rod[iter->first] = iter->second;
        ss.push_back(iter->first);
    }
}

std::map<int, float> HeatFlow::getRod() {
    return rod;
}
int HeatFlow::getNumSections() {
    return numSections;
}
float HeatFlow::getHottest() {
    return sources_and_sinks[0];
}


