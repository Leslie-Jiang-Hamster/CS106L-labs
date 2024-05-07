#include <string>
#include <iostream>

/*
 * Assigment 3: Make a class!
 * Requirements:
 * Must have a custom constructor ❌
 * Must have a default constructor ❌
    - i.e. constructor overloading
 * Must have private members (functions and/or variables) ❌
 * Must have public members (functions) ❌
 * Must have at least one getter function ❌
 * Must have at least one setter function ❌
 */

class Complex {
  int real, imaginary;

public:
  Complex(const int real_, const int imaginary_) : real{real_}, imaginary{imaginary_} {}
  Complex() = default;
  Complex(const Complex&) = default;
  auto get_real() const {
    return real;
  }
  auto get_imaginary() const {
    return imaginary;
  }
  auto set_real(const int real_) {
    real = real_;
  }
  auto set_imaginary(const int imaginary_) {
    imaginary = imaginary_;
  }
  auto to_string() const {
    return std::to_string(real) + "+" + std::to_string(imaginary) + "i";
  }
  Complex& operator=(const Complex &other) = default;
  auto operator+=(const Complex &other) {
    real += other.real;
    imaginary += other.imaginary;
    return *this;
  }
  auto operator-() const {
    return Complex{-real, -imaginary};
  }
  ~Complex() = default;
};

auto operator +(const Complex &a, const Complex &b) {
  Complex c{};
  c += a;
  c += b;
  return c;
}

int main() {
  Complex c1{1, 2};
  std::cout << c1.to_string() << std::endl; // 1+2i
  Complex c2{};
  std::cout << c2.to_string() << std::endl; // 0+0i
  std::cout << c1.get_real() << std::endl;  // 1
  c2 = Complex{c1};
  std::cout << c2.get_imaginary() << std::endl; // 2
  c2 = -c2;
  std::cout << c2.to_string() << std::endl; // -1-2i
  c2 = c1 + (-c2);
  std::cout << c2.to_string() << std::endl; // 2+4i
  c2.set_imaginary(3);
  std::cout << c2.to_string() << std::endl; // 2+3i
  return 0;
}