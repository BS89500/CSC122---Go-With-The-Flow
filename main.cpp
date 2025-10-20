#include <iostream>
#include <iomanip>
#include <map>
#include <format>
#include "src/heat_flow_printer.hpp"


int main() {
  // Your driver program goes here
  std::map<int, float> sources_and_sinks;
  sources_and_sinks[0] = 100.0;
  //sources_and_sinks[4] = 100.0;
  //std::cout << (++sources_and_sinks.begin())->second << std::endl;
  int initial_temperature = 10;
  int number_of_sections = 5;
  float K = 0.1;
  HeatFlow flow(initial_temperature, number_of_sections, K, sources_and_sinks);
  HeatFlowPrinter printer(&flow);
  flow.initializeRod();
  printer.pretty_print();

  // Prints out:
  // +------+------+------+------+------+
  // | 100  |  10  |  10  |  10  |  10  |
  // +------+------+------+------+------+

  flow.tick();
  printer.pretty_print();

  // Prints out:
  // +------+------+------+------+------+
  // | 100  |  19  |  10  |  10  |  10  |
  // +------+------+------+------+------+

  flow.tick();
  printer.pretty_print();

  // Prints out:
  // +------+--------+--------+------+------+
  // | 100  |  26.2  |  10.9  |  10  |  10  |
  // +------+--------+--------+------+------+


}