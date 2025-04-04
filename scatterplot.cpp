//
// Created by Ismayil Taghi-Zada on 3/28/25.
//

#include "scatterplot.h"

int ScatterPlot::getSize() const {
    return size;
}

Point* ScatterPlot::getHead() const {
    return head;
}
std::ostream& operator<<(std::ostream& lhs, ScatterPlot &plot) {
    Point* head = plot.getHead();
    int size = plot.getSize();
    for (int i = 0; i < size; i++) {
        lhs << "(" << (head+i)->x << "," << (head+i)->y << ")";
        if (i < size - 1) {
            lhs << ", ";
        }
    }
    lhs << std::endl;

    return lhs;
}

std::istream& operator>>(std::istream& lhs, Point &point) {
    int x = 0, y = 0;
    lhs >> x >> y;
    point = Point(x, y);
    return lhs;
}

ScatterPlot ScatterPlot::operator+(const ScatterPlot &rhs) const {
}

ScatterPlot ScatterPlot::operator+(const Point &rhs) const {
}

ScatterPlot & ScatterPlot::operator=(const ScatterPlot &rhs) {
}

bool ScatterPlot::operator==(const ScatterPlot &rhs) const {
}

ScatterPlot & ScatterPlot::operator+=(const ScatterPlot &rhs) {
}

int ScatterPlot::operator[](int index) const {
}

ScatterPlot ScatterPlot::operator*(const ScatterPlot &rhs) const {
}

ScatterPlot operator+(const Point &lhs, const Point &rhs) {
    Point lhs1(lhs);
    return lhs1 += rhs;
}

ScatterPlot operator+(const Point &lhs, const ScatterPlot &rhs) {
    Point lhs1(lhs);
    return lhs1 += rhs;
}
