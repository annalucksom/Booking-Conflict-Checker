#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../include/IntervalTree.hpp"

TEST_CASE("Interval overlaps check") {
    BookingConflictChecker::Interval i1(10, 20);
    BookingConflictChecker::Interval i2(15, 25); 
    BookingConflictChecker::Interval i3(20, 30); 
    BookingConflictChecker::Interval i4(25, 35); 
    
    SECTION("Overlapping intervals") {
        REQUIRE(i1.overlaps(i2));
        REQUIRE(i2.overlaps(i1));
    }
    
    SECTION("Non-overlapping intervals") {
        REQUIRE_FALSE(i1.overlaps(i3));
        REQUIRE_FALSE(i1.overlaps(i4));
    }
}

TEST_CASE("Interval Tree operations") {
    BookingConflictChecker::IntervalTree tree;
    
    SECTION("Empty tree operations") {
        REQUIRE(tree.findOverlapping({5, 10}).empty());
        REQUIRE_FALSE(tree.hasOverlap({5, 10}));
    }
    
    SECTION("Tree insertion and search") {
        tree.insert({10, 20});
        tree.insert({15, 25});
        tree.insert({30, 40});
        
        auto overlaps1 = tree.findOverlapping({12, 18});
        REQUIRE(overlaps1.size() == 2);
        
        auto overlaps2 = tree.findOverlapping({35, 45});
        REQUIRE(overlaps2.size() == 1);
        
        REQUIRE_FALSE(tree.hasOverlap({50, 60}));
    }
}
