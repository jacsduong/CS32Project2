//
//  Sequence.hpp
//  cs32project2
//
//  Created by Jacqueline Duong on 4/13/22.
//

#ifndef Sequence_hpp
#define Sequence_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

using ItemType = std::string;

class Sequence
{
public:
    Sequence();
    //COPY CONSTRUCTOR
    Sequence(const Sequence& other);
    
    //ASSIGNMENT OP
    Sequence& operator=(const Sequence& other);
    
    //DESTRUCTOR
    ~Sequence();
    
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    
    
private:
    int mSize;

    struct Node
    {
    public:
        ItemType data;
        Node* previous;
        Node* next;
    };
    
    Node* mHead;
    Node* mTail;
};

int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);


#endif /* Sequence_hpp */
