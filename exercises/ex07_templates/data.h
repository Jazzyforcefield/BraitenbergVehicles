/**
 * @file data.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef DATA_H_
#define DATA_H_

#include <cstdio>
#include <iostream>
#include <string>

class Data {
public:
  Data() : size_(0) {}
  void AddDatum(int d){
    data_points_[size_] = d;
    ++size_;
  }
  friend std::ostream& operator<<(std::ostream& os, const Data& data) {
    for (int i=0; i<data.size_; i++) {
      os << data.data_points_[i] << ", ";
    }
    return os;
  }
  void SelectionSort();
  int get_size() const { return size_; }
private:
  int data_points_[10];
  int size_;
};

void Data::SelectionSort() {
  int min=0;
  for (int i=0; i<(size_-1); i++) {
    min = i;
    for (int j=i+1; j<size_; j++) {
      if (data_points_[j] < data_points_[min]) {
        min = j;
      }
    }
    int temp = data_points_[min];
    data_points_[min] = data_points_[i];
    data_points_[i] = temp;
  }
}

#endif  // DATA_H_
