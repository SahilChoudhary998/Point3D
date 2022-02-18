// Sahil Choudhary
// We're making a sequence in the heap that holds (points) which is a std::array that has 3 elements
// in reality we make a sequence container that holds a containers of 3 elements called (points)
// we implement the big 5 constructors and get familiar with move constructor and move assignment
// we also overload some operator for our objects.

#ifndef CSCI335_HOMEWORK1_POINTS3D_H_
#define CSCI335_HOMEWORK1_POINTS3D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {
//class makes points3d object that holds array of points that are std::array of 3 elements of "object"

template<typename Object>
class Points3D {
  public:
    // Default "big five" -- you have to alter them for your assignment.
    // That means that you will remove the "= default" statement.
    //  and you will provide an implementation.

    // Zero-parameter constructor.
    // Set size to 0.
    Points3D() {
        size_=0;
        sequence_= new std::array<Object, 3>[size_];
    }

    // Copy-constructor.
    Points3D(const Points3D &rhs) {
        size_=rhs.size_;
        sequence_= new std::array<Object, 3>[rhs.size_];
        //std::array<Object, 3> point;
        int k=0;
        while (k < rhs.size()){   //k is a variable for first [] index for bigger sequence to access the arrays inside
            sequence_[k][0] = rhs[k][0];  //copy rhs to contents to sequence
            sequence_[k][1] = rhs[k][1];
            sequence_[k][2] = rhs[k][2];
            k++;    //increment to go to next index for sequence

            }
        }
   // }

    // Copy-assignment. If you have already written
    // the copy-constructor and the move-constructor
    // you can just use:
    // {
    // Points3D copy = rhs;
    // std::swap(*this, copy);
    // return *this;
    // }
    Points3D& operator=(const Points3D &rhs) {
         if (this!=&rhs) {
             Points3D copy = rhs;
             std::swap(*this, copy);
             return *this;
         }
    }

    // Move-constructor.
    Points3D(Points3D &&rhs){
        size_=rhs.size_; //move rhs size to this
        rhs.size_=0; // empty out rhs.size like moving out
        sequence_=rhs.sequence_; //move
        rhs.sequence_= nullptr; // make rhs sequence pointer to null


    }

    // Move-assignment.
    // Just use std::swap() for all variables.
    Points3D& operator=(Points3D &&rhs) {
        if (this!=&rhs) {
            std::swap(size_, rhs.size_);
            std::swap(sequence_, rhs.sequence_);
            rhs.size_=0;
            rhs.sequence_= nullptr;
        }
    }



    ~Points3D() {
        delete [] sequence_;
    }

    // End of big-five.

    // One parameter constructor.
    Points3D(const std::array<Object,3>& item) {

        sequence_= new std::array<Object, 3>[1];
            std::array<Object, 3> &point=sequence_[0];
            for (int j=0;j<3;j++){
                point[j]=item[j];
                //you can also do it with just sequence and not make it = to point
                //sequence[0][j]=item[j];
        }
            size_=1;

    }

    size_t size() const {
        return size_;
    }

    // @location: an index to a location in the sequence.
    // @returns the point at @location.
    // const version.
    // abort() if out-of-range.
    const std::array<Object, 3>& operator[](size_t location) const {
        if (location>size()){
           abort();
       }
        return sequence_[location];
    }

    //  @c1: A sequence.
    //  @c2: A second sequence.
    //  @return their sum. If the sequences are not of the same size, append the
    //    result with the remaining part of the larger sequence.
    friend Points3D operator+(const Points3D &c1, const Points3D &c2) {
        int maxSize ,minSize;
        maxSize=std::max(c1.size(),c2.size()); //finds max size if one is bigger
        minSize=std::min(c1.size(),c2.size()); //finds min size if one is smaller

        Points3D<Object> temp;
        temp.sequence_=new std::array<Object,3>[maxSize]; //temp has size of which one is bigger or if theyre the same its that size
        temp.size_=maxSize;
        int i;                    //if they were same size it runs and does the addition and updates temp.
        for (i=0;i<minSize;i++){   //if one is greater it does until minsize and does the loop below
           temp.sequence_[i][0] = c1[i][0]+c2[i][0];
            temp.sequence_[i][1] = c1[i][1]+c2[i][1];
            temp.sequence_[i][2] = c1[i][2]+c2[i][2];
        }
        for (;i<maxSize;i++){      //i is minsize now(loop) this runs assuming there was a maxsize
            if(maxSize==c1.size()){   // if c1 was maxsize then you copy all of c1 to temp
                temp.sequence_[i][0] = c1[i][0];
                temp.sequence_[i][1] = c1[i][1];
                temp.sequence_[i][2] = c1[i][2];
            }
            else{                                 //if c2 was maxsize then you copy c2 to temp
                temp.sequence_[i][0] = c2[i][0];
                temp.sequence_[i][1] = c2[i][1];
                temp.sequence_[i][2] = c2[i][2];
            }

        }
        return temp;


    }

    // Overloading the << operator.
    friend std::ostream &operator<<(std::ostream &out, const Points3D &some_points) {
        for (int i=0;i<some_points.size();i++){ //loops through size
            out<<"(";   //shows parenthesis
            out<<some_points[i][0];// prints the index of our sequence and  index of the std::array,// loops through size of sequence and prints all [0][1][3] of that sequence
            out<<", ";
            out<<some_points[i][1];
            out<<", ";
            out<<some_points[i][2];
            out<<")";
            out<<" ";
        }
        return out;
    }

    // Overloading the >> operator.
    // Read a chain from an input stream (e.g., standard input).
    friend std::istream &operator>>(std::istream &in, Points3D &some_points) {
        int count=0;
        in>>count;
        some_points.sequence_= new std::array<Object,3>[count];
        some_points.size_=count; //make size to count
        for(int i=0;i<count;i++){ //loop through the count to
            Object a,b,c;// make temp variables for what we extract
            in>>a >>b >>c; //take in
            some_points.sequence_[i][0]=a; //make the sequence to our temp variables
            some_points.sequence_[i][1]=b;
            some_points.sequence_[i][2]=c;

        }

        return in;
    }

  private:
    // Sequence of points.
    std::array<Object, 3> *sequence_;
    // Size of sequence.
    size_t size_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS3D_H_
