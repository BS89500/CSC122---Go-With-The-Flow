#include <string>
#include <map>
#include <vector>

class HeatFlow{
    private:
        int initialT;
        int numSections;
        float K;
        std::map<int, float> sources_and_sinks;
        std::map<int, float> rod;
        std::vector<int> ss;

    public:
    HeatFlow(int initialT, int numSections, float K, std::map<int, float> sources_and_sinks);
    void tick();
    void initializeRod();
    std::map<int, float> getRod();
    int getNumSections();
    float getHottest();
};
