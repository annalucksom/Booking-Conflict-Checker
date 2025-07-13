
#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start, end;
    Interval(int s, int e) : start(s), end(e) {}
};

bool doOverlap(Interval i1, Interval i2) {
    return (i1.start < i2.end && i2.start < i1.end);
}

class IntervalTreeNode {
public:
    Interval interval;
    int maxEnd;
    IntervalTreeNode *left, *right;

    IntervalTreeNode(Interval i)
        : interval(i), maxEnd(i.end), left(nullptr), right(nullptr) {}
};

class IntervalTree {
private:
    IntervalTreeNode* root;

    IntervalTreeNode* insert(IntervalTreeNode* node, Interval i) {
        if (!node)
            return new IntervalTreeNode(i);

        if (i.start < node->interval.start)
            node->left = insert(node->left, i);
        else
            node->right = insert(node->right, i);

        if (node->maxEnd < i.end)
            node->maxEnd = i.end;

        return node;
    }

    bool overlapSearch(IntervalTreeNode* node, Interval i) {
        if (!node) return false;

        if (doOverlap(node->interval, i))
            return true;

        if (node->left && node->left->maxEnd > i.start)
            return overlapSearch(node->left, i);

        return overlapSearch(node->right, i);
    }

    void inOrder(IntervalTreeNode* node) {
        if (!node) return;
        inOrder(node->left);
        cout << "[" << node->interval.start << ", " << node->interval.end << "]\n";
        inOrder(node->right);
    }

public:
    IntervalTree() : root(nullptr) {}

    bool insertInterval(Interval i) {
        if (hasConflict(i)) {
            cout << "❌ Conflict detected for booking [" << i.start << ", " << i.end << "]\n";
            return false;
        }
        root = insert(root, i);
        cout << "✅ Booking added: [" << i.start << ", " << i.end << "]\n";
        return true;
    }

    bool hasConflict(Interval i) {
        return overlapSearch(root, i);
    }

    void printBookings() {
        cout << "\n📋 All Bookings:\n";
        inOrder(root);
    }
};

int main() {
    IntervalTree bookingSystem;
    int choice;

    cout << "=== Booking Conflict Checker ===\n";
    do {
        cout << "\n1. Add Booking\n2. View Bookings\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int start, end;
            cout << "Enter start time: ";
            cin >> start;
            cout << "Enter end time: ";
            cin >> end;
            bookingSystem.insertInterval(Interval(start, end));
        } else if (choice == 2) {
            bookingSystem.printBookings();
        }
    } while (choice != 3);

    cout << "Exiting Booking System...\n";
    return 0;
}
