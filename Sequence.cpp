//
//  Sequence.cpp
//  cs32project2
//
//  Created by Jacqueline Duong on 4/13/22.
//

#include "Sequence.h"
#include <iostream>

using namespace std;

Sequence::Sequence()
{
    //Declare an empty list
    mHead = nullptr;
    mTail = nullptr;
    mSize = 0;
}
 
//DESTRUCTOR
Sequence::~Sequence(){
    //If it the node is empty, then delete the values the pointers are pointing to?
    //freeing the memory
    if (mSize == 0)
    {
        return;
    }
    if (mSize == 1)
    {
        delete mHead;//deleting the node pointed to by the pointer
    }
    else
    {
        Node* current = mHead;

        while (current->next != nullptr){
            Node* nxt = current->next;
            delete current;
            current = nxt;
        }
        delete current;
    }

}

 
//COPY CONSTRUCTOR
//When a brand new Sequence is created as a copy of an existing Sequence, enough new nodes must be allocated to hold a duplicate of the original list.

Sequence::Sequence(const Sequence& other){
    //empty case
    if (other.mSize == 0)
    {
        mHead = nullptr;
        mTail = nullptr;
    }
    else if (other.mSize == 1)
    {
        mSize = 1;
        Node* current = new Node;
        mHead = current;
        mHead->data = other.mHead->data;
        mTail = current;
        mHead->previous = nullptr;
        mHead->next = nullptr;
    }
    else
    {
        ItemType value;
        mSize = 0;
        for (int j = 0; j < other.mSize; j++){
            other.get(j, value);
            insert(j, value);
        }
        
    }
}


//ASSIGNMENT OPERATOR
//When an existing Sequence (the left-hand side) is assigned the value of another Sequence (the right-hand side), the result must be that the left-hand side object is a duplicate of the right-hand side object, with no memory leak of list nodes (i.e. no list node from the old value of the left-hand side should be still allocated yet inaccessible).

Sequence& Sequence::operator=(const Sequence& other){
    if (this != &other)
    {
        Sequence temp(other);
        swap(temp);
    }
    return *this;
}

//DONE
bool Sequence::empty() const{
    if (mSize == 0)
        return true;
    return false;
}

//DONE
int Sequence::size() const{
    return mSize;
}

//DONE
// Insert value into the sequence so that it becomes the item at
     // position pos.  The original item at position pos and those that
     // follow it end up at positions one greater than they were at before.
     // Return pos if 0 <= pos <= size() and the value could be
     // inserted.  (It might not be, if the sequence has a fixed capacity,
     // e.g., because it's implemented using a fixed-size array.)  Otherwise,
     // leave the sequence unchanged and return -1.  Notice that
     // if pos is equal to size(), the value is inserted at the end.
int Sequence::insert(int pos, const ItemType& value){
    if (pos > size())
        return -1;
    //insert first element in an empty list
    else if (pos == 0 && size() == 0)
    {
        Node* n = new Node;
        n->data = value;
        mHead = n;
        mTail = n;
        mHead->previous = nullptr;
        mTail->next = nullptr;
        mSize++;
        return pos;
    }
    //front case
    else if (pos == 0)
    {
        Node* n = new Node;
        
        Node* temp = mHead;
        
        mHead = n;
        //mTail = n;
        n->data = value;
        mHead->next = temp;
        mHead->previous = nullptr;
        temp->previous = mHead;
        mSize++;
        return pos;
    }
    //back case
    else if (pos == size())
    {
        Node* n = new Node;
        Node* temp = mTail;
        mTail = n;
        mTail->data = value;
        mTail->next = nullptr;
        mTail->previous = temp;
        temp->next = n;
        mSize++;
        return pos;
    }
    else
    {
        Node* n = new Node;
        n->data = value;
        
        Node* seq = mHead;
        //started count at 1 because i want to get to the node right before where i want to insert my new node
        int count = 1;
        while (count != pos){
            seq = seq->next;
            count++;
        }
        //seq the node at the position before i want to insert
        Node* temp = seq->next;
        //insert the new node after this current node, push everything back
        seq->next = n;
        temp->previous = n;
        n->previous = seq;
        n->next = temp;
      
        mSize++;
        return pos;
        
    
    }
}

//CHECK
int Sequence::insert(const ItemType& value){
    //empty case
    if (size() == 0)
    {
        insert(0, value);
        return 0;
    }
    else
    {
        Node* seq = mHead;
        
        int pos_counter = 0;
        
        //LOOK FOR POSITION WHERE TO INSERT AND THEN CALL THE OTHER INSERT FUNCTION
        while (seq->next != nullptr){
            if (value > seq->data)
            {
                seq = seq->next;
                pos_counter++;
            }
            else //if our value is <= the value at this node, we should break and now hold the index where that value is
                break;
        }
        if (pos_counter == size())
        {
            //if value not <= any of the elements, add it to the end
            insert(pos_counter - 1, value);
            return size();
        }
        else if (pos_counter == 0)
        {
            //if we need to insert it at the initial position
            insert(0, value);
            return 0;
        }
        else
        {
            insert(pos_counter - 1, value);
            return pos_counter - 1;
        }
    }
    return -1;
}

// If 0 <= pos < size(), remove the item at position pos from
      // the sequence (so that all items that followed that item end up at
      // positions one lower than they were at before), and return true.
      // Otherwise, leave the sequence unchanged and return false.

bool Sequence::erase(int pos){
    if (pos < 0 || pos >= size())
        return false;
    //delete the first thing
    else if (pos == 0 && size() == 1)
    {
        Node* temp = mHead;
        mHead = mTail = nullptr;
        delete temp;
        mSize--;
        return true;
    }
    else if (pos == 0 && size() > 1)
    {
        Node* temp = mHead;
        mHead = mHead->next;
        temp->next->previous = nullptr;
        delete temp;
        mSize--;
        return true; 
    }
    //delete the last thing
    else if (pos == size()-1)
    {
        Node* temp = mTail->previous;
        delete mTail;
        mTail = temp;
        temp->next = nullptr;
        mSize--;
        return true;
    }
    else if (0 <= pos && pos < size())
    {
        Node* seq = mHead;
        int count = 0;
        while (count != pos){
            seq = seq->next;
            count++;
        }//should break out of the loop when count == pos
            
        seq->previous->next = seq->next;
        seq->next->previous = seq->previous;
        delete seq;
        mSize--;
        return true;
    }
    return false;
}

int Sequence::remove(const ItemType& value){
    // Erase all items from the sequence that == value.  Return the
    // number of items removed (which will be 0 if no item == value).
    //empty case
    if (mSize == 0)
        return 0;
    
    int erase_counter = 0;
    while (find(value) != -1){
        erase(find(value));
        erase_counter++;
    }
    return erase_counter;
}

// If 0 <= pos < size(), copy into value the item at position pos
// of the sequence and return true.  Otherwise, leave value unchanged
// and return false.
bool Sequence::get(int pos, ItemType& value) const{
    if (pos >= size() || pos < 0)
        return false;
    else if (0 <= pos && pos < size())
    {
        Node* n = mHead;
        int pos_counter = 0;
        while (n != nullptr){
            if (pos_counter == pos){
                value = n->data;
                break;
            }
            pos_counter++;
            n = n->next;
        }

        return true;
    }
    return false;
}

// If 0 <= pos < size(), replace the item at position pos in the
      // sequence with value and return true.  Otherwise, leave the sequence
      // unchanged and return false.
bool Sequence::set(int pos, const ItemType& value){
    if (pos >= mSize || pos < 0)
        return false;
    else if (0 <= pos && pos < size())
    {
        Node* n = mHead;
        int pos_counter = 0;
        while (n != nullptr){
            if (pos_counter == pos){
                n->data = value;
                return true;
            }
            n = n->next;
        }
    }
    return false;
}

// Let p be the smallest integer such that value == the item at
// position p in the sequence; if no such item exists, let p be -1.
// Return p.
int Sequence::find(const ItemType& value) const{
    Node* seq = mHead;
    int pos = 0;
    while (seq != nullptr){
        if (value == seq->data)
        {
            return pos;
        }
        seq = seq->next;
        pos++;
    }
    return -1;
}

// Exchange the contents of this sequence with the other one.
void Sequence::swap(Sequence& other){
    //switch the sizes
    int temp = mSize;
    mSize = other.mSize;
    other.mSize = temp;
    
    //switch the heads
    Node* temp2 = mHead;
    mHead = other.mHead;
    other.mHead = temp2;
    
    //switch the tails-
    temp2 = mTail;
    mTail = other.mTail;
    other.mTail = temp2;
}

/*Consider all the items in seq2; let's call them seq20, seq21, ..., seq2n. If there exists at least one k such that seq1k == seq20 and seq1k+1 == seq21 and ... and seq1k+n == seq2n, and k+n < seq1.size(), then this function returns the smallest such k. (In other words, if seq2 is a consecutive subsequence of seq1, the function returns the earliest place in seq1 where that subsequence starts.) If no such k exists or if seq2 is empty, the function returns -1.*/


       

int subsequence(const Sequence& seq1, const Sequence& seq2){
    //if seq2 longer than seq1
    if (seq2.size() > seq1.size())
    {
        return -1;
    }
    //if seq1 or seq2 or empty
    else if (seq1.size() == 0 || seq2.size() == 0)
    {
        return -1;
    }
    else
    {
        ItemType some_value;
        ItemType some_value1;
        for (int j = 0; j < seq1.size(); j++){
            seq2.get(0, some_value);
            if (seq1.find(some_value) < 0 || seq1.find(some_value) > seq1.size())
                return -1;
            else
            {
                seq1.get(j,some_value1);
                if (some_value1 != some_value)
                    ;
                else
                {
                    for (int i = 1; i < seq2.size(); i++){
                        seq2.get(i, some_value);
                        seq1.get(j+i, some_value1);
                        if (some_value1 != some_value)
                            break;
                        if (i + 1 == seq2.size())
                            return j;
                    }
                
                }
                
            }
            
        }
        
    }
    return -1;
}


void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result){
    //initialize result by emptying it
    int i = 0;
    while (!result.empty()){
        result.erase(i);
        i++;
    }
    //empty cases
    //both empty
    if (seq1.size() == 0 && seq2.size() == 0)
        ;
    //one empty
    else if (seq1.size() == 0 && seq2.size() != 0)
    {
        for (int i = 0; i < seq2.size(); i++){
            ItemType some_value;
            seq2.get(i, some_value);
            result.insert(i, some_value);
        }
    }
    else if (seq2.size() == 0 && seq1.size() != 0)
    {
        for (int i = 0; i < seq1.size(); i++){
            ItemType some_value;
            seq1.get(i, some_value);
            result.insert(i, some_value);
        }
    }
    //same size
    else if (seq1.size() == seq2.size())
    {
        int res_pos = 0;

        for (int j = 0; j < seq1.size(); j++){
            ItemType some_value;
            ItemType some_value2;
            seq1.get(j, some_value);
            seq2.get(j, some_value2);
            
            result.insert(res_pos, some_value);
            result.insert(res_pos + 1, some_value2);
            res_pos+=2;

        }
    }
    //any size
    else
    {
        //create a variable to hold the last position of the longer list size
        int temp_pos = 0;
        int res_pos = 0;

        if (seq1.size() > seq2.size())
        {
            for (int j = 0; j < seq2.size(); j++)
            {
                ItemType some_value;
                ItemType some_value2;
                seq1.get(j, some_value);
                seq2.get(j, some_value2);
                
                result.insert(res_pos, some_value);
                result.insert(res_pos+1, some_value2);
                res_pos+=2;
                temp_pos++;
            }
            for (int k = temp_pos; k < seq1.size(); k++){
                ItemType some_value;
                seq1.get(k, some_value);
                result.insert(res_pos, some_value);
                res_pos++;
            }
        }
        else
        {
            
            int temp_pos = 0;
            int res_pos = 0;

            if (seq2.size() > seq1.size())
            {
                for (int j = 0; j < seq1.size(); j++)
                {
                    ItemType some_value;
                    ItemType some_value2;
                    seq1.get(j, some_value);
                    seq2.get(j, some_value2);
                    
                    result.insert(res_pos, some_value);
                    result.insert(res_pos+1, some_value2);
                    res_pos+=2;
                    temp_pos++;
                }
                for (int k = temp_pos; k < seq2.size(); k++){
                    ItemType some_value;
                    seq2.get(k, some_value);
                    result.insert(res_pos, some_value);
                    res_pos++;
                }
            }
           
        }

    }     
    
}


