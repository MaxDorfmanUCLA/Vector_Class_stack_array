//
//  main.cpp
//  HW310B
//  Created by Max Dorfman on 1/31/17.
//  Copyright © 2017 Max Dorfman. All rights reserved.
//I, Max Dorfman, declare that this work is my own. I did this work honestly and can fully stand behind everything that I have written.
//I did not copy code from anyone, student or otherwise.
//I collaborated with Malaya Du and Monrelle I affirm that we all contributed equally in the code. But I assisted them in writing their code

#include "VectorString.h"
#include <iostream>
#include <string>
#include <memory>


VectorString::VectorString(): sz(0), cap(1), sptr(new std::string[cap]){} // default constructor

VectorString::VectorString(std::size_t size): sz(size), cap(2*size), sptr(new std::string[cap]){} /*constructor with size_t argument*/

VectorString::VectorString(std::size_t size, const std::string& str):  sz(size), cap(2*size), sptr(new std::string[cap]) // constructor with size_t argument and const string refernence
{
    for (std::size_t i=0;i<sz;i++) // loop runs while
        sptr[i]=str; // set index of string array to input string
}

void VectorString::alloc_new() // function that allocates space for new array 2*capacity
{
    std::unique_ptr<std::string[]> temp(new std::string[cap*2]{}); //make a new pointer to a new array twice as long
    for (std::size_t i=0;i<sz;i++) // loops runs through size of origional string array
        temp[i]= sptr[i]; // copies indeces from origional to temp array
    swap (temp,sptr); // swap arrays so origional still has unique pointer and temp goes out of scope and is freed
    cap*=2; // update capacity to 2*
}

VectorString::VectorString(const VectorString& Vec): sz(Vec.sz), cap(Vec.cap), sptr(new std::string[Vec.sz])
//copy constructor
{
    if (sz==cap) // if size goes over capacity run alloc_new
        alloc_new(); // transfers data to array on heap twice as long
    for (std::size_t i=0; i <Vec.sz; ++i) // loops runs through origional array
        sptr[i] = Vec.sptr[i]; // copies origional array to knew array that has twice the capacity
}

VectorString::VectorString(VectorString&& Vec): sz(Vec.sz), cap(Vec.cap), sptr(new std::string[Vec.sz])
// move constructor
{
    if (sz==cap) // if size goes over capacity run alloc_new
        alloc_new(); // transfers data to array on heap twice as long
    sptr.reset(Vec.sptr.release()); // reset new pointer to location of old pointer and old pointer is freed up
}

std::size_t VectorString::size() const // returns sz variable private to class
{
    return sz;
}

std::size_t VectorString::capacity() const // returns cap variable private to class
{
    return cap;
}

void VectorString::push_back(const std::string& str)// function adds to vector
{
    if (sz==cap) // if size goes over capacity run alloc_new
        alloc_new();  // transfers data to array on heap twice as long
    std::unique_ptr<std::string[]> temp(new std::string[sz+1]{}); //make a new pointer to a new array twice as long
    ++sz; // update size by 1
    for (std::size_t i=0;i<sz-1;i++) // loop runs through whole of first array
        temp[i]= sptr[i]; // copy each index of array
    temp[sz-1]= str; // make last element of new array equal to string that is given
    swap (temp,sptr); // swap arrays so origional still has unique pointer and temp goes out of scope and is freed
}

void VectorString::pop_back() // function removes last element of vector
{
    
    std::unique_ptr<std::string[]> temp(new std::string[sz-1]{}); //make a new pointer to a new array that is size-1
    --sz; // update size by subtracting 1
    for (std::size_t i=0;i<sz-1;i++) // loop runs through origional array until one before the end to delete last
        temp[i]= sptr[i]; // copy each index of array
    swap (temp,sptr); // swap arrays so origional still has unique pointer and temp goes out of scope and is freed
}

void VectorString::removeAt(std::size_t index) // function removes string at index input
{
    std::unique_ptr<std::string[]> temp(new std::string[sz-1]{}); //make a new pointer to a new array that is size-1
    --sz; // update vector size
    for (std::size_t i=0;i<index;i++) // loop runs through original vector until removed index
        temp[i]= sptr[i]; // copy first part of vector
    for (std::size_t i=index+1;i<sz-1;i++) // loop runs through original vector after removed index
        temp[i]= sptr[i]; // copy second part of vector
    swap (temp,sptr); // swap arrays so origional still has unique pointer and temp goes out of scope and is freed
}

void VectorString::insertAt(std::size_t index, const std::string& str)//function inserts string inpu tat index input
{
    std::unique_ptr<std::string[]> temp(new std::string[sz+1]{}); //make a new pointer to a new array that is size+1
    ++sz;// update size of vector
    for (std::size_t i=0;i<index;i++) /* loops runs through the first part part of the vector until the inserted index*/
        temp[i]= sptr[i]; // copy first part of the vector
    temp[index]=str; // make the index of vector that was input equal to the input string variable
    for (std::size_t i=index;i<sz-1;i++) // loop runs through the last part of the vector
        temp[i+1]= sptr[i]; // copies vector from after insert index to last elementr of vector
    swap (temp,sptr); // swap arrays so origional still has unique pointer and temp goes out of scope and is freed
}

std::string& VectorString::at(std::size_t index) // function that returns string at vector index
{
    return sptr[index]; // return the index input
}

// didn't know if we needed to write the following clause for any main routine to work so i included it

VectorString foo()
{
    return VectorString(2);
}

