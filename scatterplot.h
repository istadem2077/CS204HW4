//
// Created by Ismayil Taghi-Zada on 3/28/25.
//

#ifndef SCATTERPLOT_H
#define SCATTERPLOT_H
#include <ostream>
#include <istream>

struct Point {
    int x;
    int y;
    Point* next;

    Point(int x, int y) : x(x), y(y), next(nullptr) {}
    Point(int x, int y, Point* next) : x(x), y(y), next(next) {}
    Point() : x(NULL), y(NULL), next(nullptr) {}
};

class ScatterPlot {
private:
    int size;
    Point *head;
    bool duplicate(const ScatterPlot& result, Point* rhs) const;
    bool equal(const ScatterPlot& lhs, Point* rhs) const;
public:
    ScatterPlot() :size(0), head(nullptr) {};
    ScatterPlot(const ScatterPlot &other); // deepcopy
    ~ScatterPlot();

    ScatterPlot operator+(const ScatterPlot& rhs) const;
    ScatterPlot operator+(Point* rhs) const;

    ScatterPlot& operator=(const ScatterPlot& rhs);
    bool operator==(const ScatterPlot& rhs) const;
    ScatterPlot& operator+=(const ScatterPlot& rhs);
    int operator[](int index) const;

    ScatterPlot operator*(const ScatterPlot& rhs) const;

    int getSize() const;
    Point* getHead() const;
};

std::ostream& operator<<(std::ostream& lhs, const ScatterPlot &plot);
std::istream& operator>>(std::istream& lhs, const Point &point);
ScatterPlot operator+(const Point& lhs, const Point& rhs);
ScatterPlot operator+(const Point& lhs, const ScatterPlot& rhs);

#endif //SCATTERPLOT_H
