#include <iostream>
#include "../include/BookingManager.hpp"

using namespace BookingConflictChecker;

int main() {
    BookingManager manager;
    
    Booking booking1("001", "Room1", 1000, 1100);
    Booking booking2("002", "Room1", 1050, 1150);
    Booking booking3("003", "Room1", 1200, 1300);
    
    std::cout << "Adding booking1 (Room1, 10:00-11:00): " 
              << manager.addBooking(booking1) << std::endl;
              
    std::cout << "Adding booking2 (Room1, 10:50-11:50): " 
              << manager.addBooking(booking2) << std::endl;
    
    std::cout << "Adding booking3 (Room1, 12:00-13:00): "
              << manager.addBooking(booking3) << std::endl;
    
    return 0;
}
