#include "heat_flow_printer.hpp"
#include <string>
#include <iostream>
#include <format>
#include <iomanip>
HeatFlowPrinter::HeatFlowPrinter(HeatFlow *flow) { // This must be passed in as a pointer since there is no constructor
   this->flow = flow;
};
std::string HeatFlowPrinter::pretty_print() {
   std::map<int, float> rod = flow->getRod();
   int biggest = std::format("{:.1f}",flow->getHottest()).size();
   int blockSize = 3 + biggest + 3;
   for (int j = 0; j < flow->getNumSections(); j++) {
      for (int i = 0; i < blockSize; i++) {
         if (i % (blockSize - 1) == 0) {
            std::cout << "+";
         }
         else {
            std::cout << "-";
         }
      }
   }
   std::cout << std::endl;
   for (int j = 0; j < flow->getNumSections(); j++) {
      for (int i = 0; i < blockSize; i++) {
         if (i % (blockSize - 1) == 0) {
            std::cout << "|";
         }
         else if (i == 3){
            std::cout << std::format("{:.1f}",rod[j]);
            std::cout << std::setfill(' ') << std::setw(blockSize - (3 + std::format("{:.1f}",rod[j]).size())) << "|";
            break;
         }
         else {
            std::cout << " ";
         }
      }
   }
   std::cout << std::endl;
   for (int j = 0; j < flow->getNumSections(); j++) {
      for (int i = 0; i < blockSize; i++) {
         if (i % (blockSize - 1) == 0) {
            std::cout << "+";
         }
         else {
            std::cout << "-";
         }
      }
   }
   std::cout << std::endl;
      return "Implement your code here!";
}


