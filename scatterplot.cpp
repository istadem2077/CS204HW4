//
// Created by Ismayil Taghi-Zada on 3/28/25.
//

#include "scatterplot.h"

///* Constructors */
ScatterPlot::~ScatterPlot() {

}

ScatterPlot::ScatterPlot(const ScatterPlot &other) { // deepcopy constructor

}
///* End Constructors */


///* Member functions */
int ScatterPlot::getSize() const {
    return size;
}

Point* ScatterPlot::getHead() const {
    return head;
}

bool ScatterPlot::duplicate(const ScatterPlot& result, Point *rhs) const {
    Point* curr = result.head;
    while (curr) {
        if (curr->x == rhs->x && curr->y == rhs->y) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool ScatterPlot::equal(const ScatterPlot& result, Point *rhs) const {
    Point* curr = result.head;
    while (curr) {
        if (curr->x != rhs->x && curr->y != rhs->y) {
            return false;
        }
        curr = curr->next;
    }
    return true;
}

ScatterPlot ScatterPlot::operator+(const ScatterPlot &rhs) const {
    ScatterPlot result(*this);
    Point* rhs_head = rhs.head;
    while (rhs_head) {
        if (!duplicate(result, rhs_head)) {
            Point* temp = new Point(rhs_head->x, rhs_head->y, result.head);
            result.head = temp;
            result.size += 1;
        }
        rhs_head = rhs_head->next;
    }
    return result;
}

ScatterPlot ScatterPlot::operator+(Point* rhs) const {
    ScatterPlot result(*this);

    if (!duplicate(result, rhs)) {
        Point* temp = new Point((rhs->x), (rhs->y), result.head);
        result.head = temp;
        result.size += 1;
    }
    return result;
}

ScatterPlot & ScatterPlot::operator=(const ScatterPlot &rhs) {
    if (this != &rhs) {
        Point* current = this->head;
        while (current) {
            Point* temp = current;
            current = current->next;
            delete temp;
        }

        this->head = nullptr;
        this->size = 0;

        Point* temp = rhs.head;
        while (temp) {
            Point* newNode = new Point(temp->x, temp->y, this->head);
            this->head = newNode;
            temp = temp->next;
            this->size += 1;
        }
    }
    return *this;
}

bool ScatterPlot::operator==(const ScatterPlot &rhs) const {
    if (this->size != rhs.size) {
        return false;
    }

    Point* curr = rhs.head;
    while (curr) {
        if (!equal(*this, curr)) {
            return false;
        }
        curr = curr->next;
    }
    return true;
}

ScatterPlot & ScatterPlot::operator+=(const ScatterPlot &rhs) {
    *this = *this + rhs;
    return *this;
}

int ScatterPlot::operator[](int index) const {

}

ScatterPlot ScatterPlot::operator*(const ScatterPlot &rhs) const {
}
///* End Member functions*/


///* Free functions */
ScatterPlot operator+(const Point &lhs, const Point &rhs) {

}

ScatterPlot operator+(const Point &lhs, const ScatterPlot &rhs) {

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
///* End Free functions */


