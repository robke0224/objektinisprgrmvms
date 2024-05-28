#include "vektorius.h"
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"




TEST_CASE("Vector Default Constructor", "[vector]") {
    Vector<int> v;
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
    REQUIRE(v.empty());
}

TEST_CASE("Vector Copy Constructor", "[vector]") {
    Vector<int> v1(5, 10);
    Vector<int> v2(v1);
    REQUIRE(v1.size() == v2.size());
    REQUIRE(v1.capacity() == v2.capacity());
    for (int i = 0; i < v1.size(); ++i) {
        REQUIRE(v1[i] == v2[i]);
    }
}

TEST_CASE("Vector Move Constructor", "[vector]") {
    Vector<int> v1(5, 10);
    Vector<int> v2(std::move(v1));
    REQUIRE(v1.size() == 0);
    REQUIRE(v1.capacity() == 0);
    REQUIRE(v1.empty());
    REQUIRE(v2.size() == 5);
    REQUIRE(v2.capacity() == 5);
    for (int i = 0; i < 5; ++i) {
        REQUIRE(v2[i] == 10);
    }
}

TEST_CASE("Vector Assign Function", "[vector]") {
    Vector<int> v;
    v.assign(5, 10);
    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() == 5);
    for (int i = 0; i < 5; ++i) {
        REQUIRE(v[i] == 10);
    }
}

TEST_CASE("Vector At Function", "[vector]") {
    Vector<int> v(5, 10);
    for (int i = 0; i < 5; ++i) {
        REQUIRE(v.at(i) == 10);
    }
    REQUIRE_THROWS_AS(v.at(10), std::out_of_range);
}

TEST_CASE("Vector Front Function", "[vector]") {
    Vector<int> v = { 1, 2, 3, 4, 5 };
    REQUIRE(v.front() == 1);
}

TEST_CASE("Vector Back Function", "[vector]") {
    Vector<int> v = { 1, 2, 3, 4, 5 };
    REQUIRE(v.back() == 5);
}

TEST_CASE("Vector Size", "[vector]") {
    Vector<int> v;
    REQUIRE(v.size() == 0);
    v.push_back(10);
    REQUIRE(v.size() == 1);
}

TEST_CASE("Vector Resize", "[vector]") {
    Vector<int> v;
    v.resize(5);
    REQUIRE(v.size() == 5);
    v.resize(3);
    REQUIRE(v.size() == 3);
}

TEST_CASE("Vector Capacity", "[vector]") {
    Vector<int> v;
    v.resize(10);
    REQUIRE(v.capacity() >= v.size());
}

TEST_CASE("Vector Empty", "[vector]") {
    Vector<int> v;
    REQUIRE(v.empty());
    v.push_back(5);
    REQUIRE_FALSE(v.empty());
}

TEST_CASE("Vector Reserve", "[vector]") {
    Vector<int> v;
    v.reserve(100);
    REQUIRE(v.capacity() >= 100);
}

TEST_CASE("Vector Clear", "[vector]") {
    Vector<int> v;
    v.push_back(5);
    v.clear();
    REQUIRE(v.empty());
}

TEST_CASE("Equal Vectors", "[vector]") {
    Vector<int> v1{ 1, 2, 3 };
    Vector<int> v2{ 1, 2, 3 };
    REQUIRE(v1 == v2);
}

TEST_CASE("Not Equal Vectors", "[vector]") {
    Vector<int> v1{ 1, 2, 3 };
    Vector<int> v2{ 1, 2, 4 };
    REQUIRE(v1 != v2);
}