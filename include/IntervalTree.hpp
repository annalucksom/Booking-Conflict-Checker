#pragma once
#include <vector>
#include <memory>

namespace BookingConflictChecker {

class Interval {
public:
    Interval(long start, long end);
    bool overlaps(const Interval& other) const;
    
    long getStart() const;
    long getEnd() const;

    void setStart(long start);
    void setEnd(long end);

private:
    long start_;
    long end_;
};

class IntervalTreeNode {
public:
    IntervalTreeNode(const Interval& interval);
    
    const Interval& getInterval() const;
    long getMaxEnd() const;
    
    std::unique_ptr<IntervalTreeNode>& getLeft();
    std::unique_ptr<IntervalTreeNode>& getRight();
    
    void updateMaxEnd(long newEnd);

private:
    Interval interval_;
    long max_end_;
    std::unique_ptr<IntervalTreeNode> left_;
    std::unique_ptr<IntervalTreeNode> right_;
};

class IntervalTree {
public:
    IntervalTree();
    
    void insert(const Interval& interval);
    bool remove(const Interval& interval);
    std::vector<Interval> findOverlapping(const Interval& interval) const;
    bool hasOverlap(const Interval& interval) const;
    
private:
    std::unique_ptr<IntervalTreeNode> root_;
    
    void insert(std::unique_ptr<IntervalTreeNode>& node, const Interval& interval);
    bool remove(std::unique_ptr<IntervalTreeNode>& node, const Interval& interval);
    void collectOverlapping(const IntervalTreeNode* node, 
                          const Interval& interval,
                          std::vector<Interval>& result) const;
};
} 
