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
    Point* head = result.head;

    while (head->next) {
        head = head->next;
    }

    while (rhs_head) {
        if (!duplicate(result, rhs_head)) {
            Point* temp = new Point(rhs_head->x, rhs_head->y);
            head->next = temp;
            result.size += 1;
        }
        rhs_head = rhs_head->next;
    }
    return result;
}

ScatterPlot ScatterPlot::operator+(Point* rhs) const {
    ScatterPlot result(*this);

    Point* head = result.head;
    while (head->next) {
        head = head->next;
    }

    if (!duplicate(result, rhs)) {
        head->next = rhs;
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

int ScatterPlot::operator[](int value) const {
    int count = 0;

    Point* curr = this->head;
    while (curr) {
        if (curr->x == value) {
            count++;
        }
    }

    return count;

}

ScatterPlot ScatterPlot::operator*(const ScatterPlot &rhs) const {
}
///* End Member functions*/


///* Free functions */
ScatterPlot operator+(Point* lhs, Point* rhs) {
    ScatterPlot result(2, lhs);
    result.getHead()->next = rhs;
    return result;
}

ScatterPlot operator+(Point* lhs, const ScatterPlot &rhs) {
    ScatterPlot result(rhs);

    Point* rhs_head = rhs.getHead();
    if (rhs_head) {
        lhs->next = rhs_head;
        rhs_head = lhs;
    }
    else {
        rhs_head = lhs;
    }
    return result;
}

std::ostream& operator<<(std::ostream& lhs, ScatterPlot &plot) {
    Point* head = plot.getHead();
    int size = plot.getSize();

    int count = 0;
    while (head) {
        lhs << "(" << (head)->x << "," << (head)->y << ")";
        if (count < size) {
            lhs << ", ";
        }
        count++;
        head = head->next;
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


