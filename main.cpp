#include "Sequence.h"
#include <iostream>
#include <cassert>


int main()
{
   //Test default constructor
   Sequence a;
   Sequence b;

   //Test empty
   assert(a.empty() == 1);
   assert(b.empty() == 1);


   //Test find, both inserts
   assert(a.find(100) == -1);
   assert(a.insert(100) == 0);
   assert(a.find(100) == 0);
   assert(a.insert(1, 24) == 1);
   assert(a.insert(10, 25) == -1);
   assert(a.find(24) == 1);

   //Test size, erase, and remove
   assert(a.size() == 2);
   a.insert(2,200);
   assert(a.erase(2) == 1);
   assert(a.size() == 2);
   a.insert(2,200);
   assert(a.remove(100) == 1);
   assert(a.size() == 2);
   a.insert(2, 14);
   a.insert(3, 15);
   a.insert(4, 16);
   assert(a.size() == 5);

   //Test subsequence and interleave when one sequence is empty...b is empty
   assert(subsequence(a, b) == -1);
   Sequence c;
   interleave(a, b, c);
   a.swap(b);
   assert(a.size()==0);
   assert(b.size()==5);

   //swap back for future test cases
   a.swap(b);
   assert(a.size()==5);
   assert(b.size()==0);

   unsigned long j;
   assert(!b.get(5, j));

   b.insert(0, 9);
   b.insert(1, 8);
   b.insert(2, 7);
   b.insert(3, 6);
   b.insert(4, 5);
   b.insert(5, 4);
   assert (b.size()==6);

   //test copy constructor
   Sequence d = b; // b = 9 8 7 6 5 4
   assert (d.size()==6);
   // cout << d.size() << endl;
   for (int i = 0; i < d.size(); i++){
       ItemType some_value;
       ItemType some_value1;
       d.get(i, some_value);
       b.get(i, some_value1);
       assert(some_value == some_value1);
   }


   //Test swap
   a.swap(b);
   assert (a.size()==6);
   assert (b.size()==5);

   Sequence jacs;
   jacs.insert(0,1);
   jacs.insert(1,2);
   jacs.insert(2,3);
   jacs.insert(3,2);
   jacs.insert(4,3);
   jacs.insert(5,10);
   jacs.insert(6,100);

   Sequence ncity;
   ncity.insert(0,2);
   ncity.insert(1,3);
   ncity.insert(2,10);

   Sequence ncit;
   ncit.insert(0,2);
   ncit.insert(1,3);

   //Test subsequence where shows 2 twice
   assert(subsequence(jacs, ncity)==3);

   //Test basic subsequence case
   assert(subsequence(jacs, ncit)==1);

   //Test get
   ItemType get_ncit;
   ncit.get(0,get_ncit);
   assert(get_ncit == 2);

   ncity.get(1, get_ncit);
   assert(get_ncit == 3);

   //Test set
   jacs.set(0, 100);
   assert(jacs.find(1)==-1);
   assert(jacs.find(100)==0);

   jacs.set(0,1);

   //Test interleave of two equal sizes
  ncit.insert(4);
    cout << "HERE " << endl;
    cout << ncit.find(2) << endl;
    cout << ncit.find(3) << endl;
    cout << ncit.find(4) << endl;
   // 4 2 3

   Sequence nct;
   interleave(ncity, ncit, nct);

   Sequence jaem;
   jaem.insert(0,4);
   jaem.insert(1,5);
   jaem.insert(2,6);

   //Test interleave
   Sequence end;
   interleave(jacs, jaem, end);

   Sequence yay;
   yay.insert(0, 30);
   yay.insert(1, 21);
   yay.insert(2, 63);
   yay.insert(3, 42);
   yay.insert(4, 17);
   yay.insert(5, 63);
   yay.insert(6, 17);
   yay.insert(7, 29);
   yay.insert(8, 8);
   yay.insert(9, 32);


   Sequence nawr;
   nawr.insert(0, 63);
   nawr.insert(1, 17);
   nawr.insert(2, 29);

   //Test subsequence where 63 shows both times
   assert(subsequence(yay, nawr)==5);

   Sequence bye;
   interleave(nawr, yay, bye);

   //test remove of multiple values
   assert(yay.remove(17) == 2);
   assert(yay.remove(100000) == 0);
   assert(yay.erase(0) == 1);
   assert(yay.size() == 7);

   //Test empty
   assert(yay.empty() == 0);

    Sequence jacqs;
   // Sequence ncity;
    cout << ncity.size() << endl;
    Sequence ncityjacs;
    //empty interleave
    interleave(jacqs, ncity, ncityjacs);
    //assert(ncityjacs.size() == 0);
    cout << "RIGHT HERE " << endl;
    cout << ncityjacs.size() << endl;
    
    jacqs.insert(0,100);
    cout << "my size" << jacqs.size() << endl;

    jacqs.insert(1,2);
    jacqs.insert(2,3);
    jacqs.insert(3,4);
    jacqs.insert(4,5);
    jacqs.insert(5,6);
    jacqs.insert(6,7);
    cout << "my size" << jacqs.size() << endl;

    ItemType some_value;
    for (int i = 0; i < jacqs.size(); i++){
        jacs.get(i, some_value);
        cout << some_value << endl;
    }
    //assert(jacs.size() == 7);
    cout << "my size" << jacqs.size() << endl;

    //one empty
    interleave(jacqs, ncity, ncityjacs);
    ItemType some_value1;
    cout << "ncityjacs" << endl;
    for (int i = 0; i < ncityjacs.size(); i++){
        ncityjacs.get(i, some_value1);
        cout << some_value1 << endl;
    }
    cout << ncityjacs.size() << endl;

    //test cases sequence one is empty
    interleave(ncity, jacqs, ncityjacs);

    cout << jacqs.size() << endl;
    cout << ncity.size() << endl;
    cout << ncityjacs.size() << endl;

//    assert(ncityjacs.size() == 7);



    ncity.insert(0,45);
    ncity.insert(1, 55);
    ncity.insert(100);

    

   cerr << "All test cases passed " << endl;
}


