# CS32Project2

**This project was run and tested on a linux server to ensure no memory leaks**

For our UCLA CS 32 Spring 2022 Project 2, we were required to implement a doubly linked list class and its various functionalities: 

class Sequence
{
  public:
    Sequence();
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value); //inserts an item at a specific position 
    int insert(const ItemType& value); //inserts an item directly before the first item that it is less than or equal to, else add to the end 
    bool erase(int pos); //erase an item at a given position 
    int remove(const ItemType& value); //remove the first item in the linked list of given value 
    bool get(int pos, ItemType& value) const; //copy the item at given position into "value"
    bool set(int pos, const ItemType& value); //set the item at given position to the given "value" 
    int find(const ItemType& value) const; //return the first position of a given "value" if it exists 
    void swap(Sequence& other); //exchange the contents of this sequence with the other one
};

We were also required to add to non-member functions, as described below: 

int subsequence(const Sequence& seq1, const Sequence& seq2);

Consider all the items in seq2; let's call them seq20, seq21, ..., seq2n. If there exists at least one k such that seq1k == seq20 and seq1k+1 == seq21 and ... and seq1k+n == seq2n, and k+n < seq1.size(), then this function returns the smallest such k. (In other words, if seq2 is a consecutive subsequence of seq1, the function returns the earliest place in seq1 where that subsequence starts.) If no such k exists or if seq2 is empty, the function returns -1. For example, if seq1 were a sequence of ints consisting of
     30 21 63 42 17 63 17 29 8 32
and seq2 consists of
     63 17 29
then the function returns 5, since the consecutive items 63 17 29 appear in seq1 starting with the 63 at position 5. (The result is not 2, because while there's a 63 at position 2, followed eventually by a 17 and a 29, those items are not consecutive in seq1.) With the same seq1, if seq2 consists of
     17 63 29
then the function returns -1.



void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);

This function produces as a result a sequence that consists of the first item in seq1, then the first in seq2, then the second in seq1, then the second in seq2, etc.
More formally: Consider the items in seq1; let's call them seq10, seq11, …, seq1m, and let's call the items seq2 contains seq20, seq21, …, seq2n. If m equals n, then when this function returns, result must consist of the sequence seq10, seq20, seq11, seq21, …, seq1m, seq2n, and no other items.
If m is less than n, then when this function returns, result must consist of the sequence seq10, seq20, seq11, seq21, …, seq1m, seq2m, seq2m+1, seq2m+2, …, seq2n, and no other items.
If n is less than m, then when this function returns, result must consist of the sequence seq10, seq20, seq11, seq21, …, seq1n, seq2n, seq1n+1, seq1n+2, …, seq1m, and no other items.
If seq1 is empty, then when this function returns, result must consist of the sequence seq20, …, seq2n, and no other items. If seq2 is empty, then when this function returns, result must consist of the sequence seq10, …, seq1m, and no other items. If seq1 and seq2 are empty, then when this function returns, result must be empty.
When this function returns, result must not contain any items that this spec does not require it to contain. (You must not assume result is empty when it is passed in to this function; it might not be.)

