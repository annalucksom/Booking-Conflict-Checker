#pragma once
#include "IntervalTree.hpp"
#include <unordered_map>
#include <string>

namespace BookingConflictChecker {

class Booking {
public:
    Booking(std::string bookingId, std::string resourceId, long startTime, long endTime);
    
    const std::string& getId() const;
    const std::string& getResourceId() const;
    Interval getTimeInterval() const;
    
private:
    std::string bookingId_;
    std::string resourceId_;
    Interval timeInterval_;
};

class BookingManager {
public:
    bool addBooking(const Booking& booking);
    bool removeBooking(const Booking& booking);
    bool hasConflict(const Booking& booking) const;
    
private:
    std::unordered_map<std::string, IntervalTree> resourceTrees_;
};
} 
