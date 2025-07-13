
# Booking Conflict Checker using Interval Tree (C++)

This project is a console-based application that helps manage booking slots and detect scheduling conflicts efficiently using an **Interval Tree** data structure.

## 💡 Features
- Add bookings with start and end times
- Automatically checks for conflicting bookings
- Display all current valid bookings
- Efficient interval management with an Interval Tree

## 🛠️ Technologies Used
- Language: C++
- Data Structure: Interval Tree
- Platform: Console (Terminal)

## 🚀 How to Run

### Compile
```bash
g++ booking_conflict_checker.cpp -o BookingChecker
```

### Execute
```bash
./BookingChecker
```

## 📋 Sample Output
```
=== Booking Conflict Checker ===

1. Add Booking
2. View Bookings
3. Exit
Enter choice: 1
Enter start time: 10
Enter end time: 20
✅ Booking added: [10, 20]

Enter choice: 1
Enter start time: 15
Enter end time: 25
❌ Conflict detected for booking [15, 25]

Enter choice: 2
📋 All Bookings:
[10, 20]
```

## 📦 Project Structure
```
BookingConflictChecker/
├── booking_conflict_checker.cpp  # Main source code
└── README.md                     # Project overview
```

## 🏷️ Tags
`C++` `Interval Tree` `Booking System` `Mini Project` `Data Structures`

## 👨‍💻 Author
Developed as a simple and educational demo for managing interval-based bookings.

## 📄 License
This project is open-source and available under the [MIT License](LICENSE).
