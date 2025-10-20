#include <string>

#include "HeatFlow.hpp"


class HeatFlowPrinter{
    protected:
        HeatFlow *flow;
    public:
    explicit HeatFlowPrinter(HeatFlow *flow);
    std::string pretty_print();
};
