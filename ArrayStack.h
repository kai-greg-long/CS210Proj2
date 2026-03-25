#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class ArrayStack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        data.pop_back();
    }

    T top() const {
        if (!data.empty()) {
            return data.back();
        } else {
            throw std::out_of_range("ArrayStack is empty");
        }
    }

    bool empty() const {
        if (!data.empty()) {
            for (T nodes : data) {
                pop();
            }
            return true;
        } else {
            throw std::out_of_range("ArrayStack is empty");
            return false;
        }
    }

    int size() const {
        int size = 0;

        if (!data.empty()) {
            for (T nodes : data) {
                size++;
            }
            return size;
        } else {
            throw std::out_of_range("ArrayStack is empty");
            return 0;
        }
    }
};

#endif
