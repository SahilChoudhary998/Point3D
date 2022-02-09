// --> YOUR NAME here
// Few comments describing the class Points3D

#ifndef CSCI335_HOMEWORK1_POINTS3D_H_
#define CSCI335_HOMEWORK1_POINTS3D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {

// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Points3D {
  public:
    // Default "big five" -- you have to alter them for your assignment.
    // That means that you will remove the "= default" statement.
    //  and you will provide an implementation.

    // Zero-parameter constructor.
    // Set size to 0.
    Points3D() = default;

    // Copy-constructor.
    Points3D(const Points3D &rhs) = default;

    // Copy-assignment. If you have already written
    // the copy-constructor and the move-constructor
    // you can just use:
    // {
    // Points3D copy = rhs;
    // std::swap(*this, copy);
    // return *this;
    // }
    Points3D& operator=(const Points3D &rhs) = default;

    // Move-constructor.
    Points3D(Points3D &&rhs) = default;

    // Move-assignment.
    // Just use std::swap() for all variables.
    Points3D& operator=(Points3D &&rhs) = default;

    ~Points3D() = default;

    // End of big-five.

    // One parameter constructor.
    Points3D(const std::array<Object, 3>& item) {
        // Provide code.
    }

    size_t size() const {
        // Code missing.
    }

    // @location: an index to a location in the sequence.
    // @returns the point at @location.
    // const version.
    // abort() if out-of-range.
    const std::array<Object, 3>& operator[](size_t location) const {
        // Code missing.
    }

    //  @c1: A sequence.
    //  @c2: A second sequence.
    //  @return their sum. If the sequences are not of the same size, append the
    //    result with the remaining part of the larger sequence.
    friend Points3D operator+(const Points3D &c1, const Points3D &c2) {
        // Code missing.
    }

    // Overloading the << operator.
    friend std::ostream &operator<<(std::ostream &out, const Points3D &some_points) {
        // Code missing.
    }

    // Overloading the >> operator.
    // Read a chain from an input stream (e.g., standard input).
    friend std::istream &operator>>(std::istream &in, Points3D &some_points) {
        // Code missing.
    }

  private:
    // Sequence of points.
    std::array<Object, 3> *sequence_;
    // Size of sequence.
    size_t size_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS3D_H_
