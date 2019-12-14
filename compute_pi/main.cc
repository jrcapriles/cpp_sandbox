#include <math.h>
#include <stdio.h>
#include <iostream>
#include <limits>

template <typename T>
T ComputePi() {
  T curr_pi = 1;
  T prev_pi = 1;
  T num = 1;
  T prev_num = 0;

  while (true) {
    num = sqrt(2 + prev_num);
    curr_pi = prev_pi * num / 2;

    if (std::fabs(curr_pi - prev_pi) <= std::numeric_limits<T>::epsilon()) {
      break;
    }
    printf("%.100g\n", 2 / curr_pi);
    prev_pi = curr_pi;
    prev_num = num;
  }
  return 2.0 / (curr_pi);
}

// Compute PI with all its decimals based on the data type used
int main() {
  double pi_d = ComputePi<double>();
  printf("=====================================================\n");
  printf("Double: %.100g\n", pi_d);
  printf("=====================================================\n");

  float pi_f = ComputePi<float>();
  printf("=====================================================\n");
  printf("Float: %.100g\n", pi_f);
  printf("=====================================================\n");
}
