#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/HeatFlow.hpp"

TEST_CASE( "Zero" ) {
    std::map<int, float> sources_and_sinks;
    sources_and_sinks[0] = 0;

    int initial_temperature = 10;
    int number_of_sections = 5;
    float K = 0.1;

    HeatFlow flow(initial_temperature, number_of_sections, K, sources_and_sinks);
    flow.initializeRod();

    std::map<int, float> expected;
    std::map<int, float> rod = flow.getRod();
    expected[0] = 0;
    expected[1] = 10.0;
    expected[2] = 10.0;
    expected[3] = 10.0;
    expected[4] = 10.0;
    REQUIRE(rod[0] == expected[0]);
    REQUIRE(rod[1] == expected[1]);
    REQUIRE(rod[2] == expected[2]);
    REQUIRE(rod[3] == expected[3]);
    REQUIRE(rod[4] == expected[4]);
}

TEST_CASE( "One" ) {
    std::map<int, float> sources_and_sinks;
    sources_and_sinks[0] = 100;

    int initial_temperature = 10;
    int number_of_sections = 5;
    float K = 0.1;

    HeatFlow flow(initial_temperature, number_of_sections, K, sources_and_sinks);
    flow.initializeRod();

    std::map<int, float> expected;
    std::map<int, float> rod = flow.getRod();
    expected[0] = 100.0;
    expected[1] = 10.0;
    expected[2] = 10.0;
    expected[3] = 10.0;
    expected[4] = 10.0;
    REQUIRE(rod[0] == expected[0]);
    REQUIRE(rod[1] == expected[1]);
    REQUIRE(rod[2] == expected[2]);
    REQUIRE(rod[3] == expected[3]);
    REQUIRE(rod[4] == expected[4]);
}

TEST_CASE( "Many" ) {
    std::map<int, float> sources_and_sinks;
    sources_and_sinks[0] = 100;

    int initial_temperature = 10;
    int number_of_sections = 5;
    float K = 0.1;

    HeatFlow flow(initial_temperature, number_of_sections, K, sources_and_sinks);
    flow.initializeRod();
    flow.tick();
    std::map<int, float> expected;
    std::map<int, float> rod = flow.getRod();
    expected[0] = 100.0;
    expected[1] = 19.0;
    expected[2] = 10.0;
    expected[3] = 10.0;
    expected[4] = 10.0;
    REQUIRE(rod[0] == expected[0]);
    REQUIRE(rod[1] == expected[1]);
    REQUIRE(rod[2] == expected[2]);
    REQUIRE(rod[3] == expected[3]);
    REQUIRE(rod[4] == expected[4]);

    flow.tick();
    rod = flow.getRod();
    expected[0] = 100.0;
    expected[1] = 26.2;
    expected[2] = 10.9;
    expected[3] = 10.0;
    expected[4] = 10.0;
    REQUIRE(rod[0] == expected[0]);
    REQUIRE(rod[1] == expected[1]);
    REQUIRE(rod[2] == expected[2]);
    REQUIRE(rod[3] == expected[3]);
    REQUIRE(rod[4] == expected[4]);
}