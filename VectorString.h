//
//  VectorString.h
//  HW310B
//  Created by Max Dorfman on 1/31/17.
//  Copyright © 2017 Max Dorfman. All rights reserved.
//I, Max Dorfman, declare that this work is my own. I did this work honestly and can fully stand behind everything that I have written.
//I did not copy code from anyone, student or otherwise.
//I collaborated with Malaya Du and Monrelle and I affirm that we all contributed equally in the code

#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>
#include <memory>

class VectorString
{
public:
    VectorString(); // default constructor declaration
    VectorString(std::size_t); // constructor declaration with size_t argument
    VectorString(std::size_t, const std::string&); /*constructor declaration with size_t and const string referance argument */
    void alloc_new(); // function declaration for function that allocates space for new array 2*capacity
    VectorString(const VectorString&); // copy constructor
    VectorString(VectorString&&); // move constructor
    std::size_t size() const; // declaration for function that returns size of vector from private variables
    std::size_t capacity() const; // declaration for function that returns capacity of vector from private variables
    void push_back(const std::string&); /* declaration for function that takes a const reference to a string and adds it to vector*/
    void pop_back(); // declaration function that removes last index of vector
    void removeAt(std::size_t); /* declaration for function that takes a size_t argument and removes index at that number*/
    void insertAt(std::size_t, const std::string&); /*declaration for function that takes a size_t argument and a const reference to a string and adds the string at that index*/
    std::string& at(std::size_t); // function that returns a const reference to a string at the index provided
private:
    std::size_t sz; // private variable for size of vector
    std::size_t cap; // private variable for capacity of vector
    std::unique_ptr<std::string[]> sptr; // private variable for  unique pointer to a new array
};



#endif /* Header_h */
