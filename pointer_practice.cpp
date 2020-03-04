/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "counter.h"

using namespace std;
using namespace csis3700;


void replace_with_increment(int *p,std::size_t n){
    for (std::size_t x=0; x<n; x++){
        
       p[x] = p[x]+1; 
      
    }
}
    
void display_increment_array(){
    int a[]={10,20,30};
    replace_with_increment(a,3);
    
    for (int x=0; x<3 ;x++){
        cout << a[x] <<" ";
    }
    
}

int square_1(int *p){
   int a = *p;
   return a*a;
}

int square_2(int *p){
  return *p=(*p)*(*p) ;
}

int square_3(int &a){
    a= a*a;
    return a;
    
}

void display_square(int a){
    int *x=&a; 
    cout << square_1(x)<<endl;
    int c =a;
    int *b =&c;
    cout << square_2(b)<<endl;
    int d= a;
    cout << square_3(d)<<endl;
}

//shows seg-fault
/*
counter* make_broken_counter(){
    counter c ;
    return &c;
}

void display_broken_counter(){
   counter *p= make_broken_counter();
   (*p).increment(1);
    display_square(1);
    p->increment(1);
    cout << p->get_count() ;
}
*/


counter* make_counter(){
    counter *c= new counter;
    return c;
    
}

void display_counter(){

counter *p = make_counter();
p->increment(1);
display_square(1);
p->increment(1);
cout << p->get_count() ;


    
}

counter* make_counter(int start){
    counter *c= new counter(start);
    return c;
}

void display_counter_2(){
    counter *a=make_counter(2);
    cout << a->get_count();
}

counter* bunch_of_counters(size_t number){
    counter *a = nullptr;
    a= new counter[number];
    return a;
    
}

void display_counters(){
    counter *b = bunch_of_counters(25);
    for (int x=0;x<25;x++){
        b->increment(2) ; 
        b++;
    }
    b--;
    
    for(int x=0; x<25;x++){
        cout << b->get_count() <<" ";
        b--;
    }
    
    
}


  


int main(){
    
 display_increment_array(); 
 int b=3;
 int *a=&b;
 cout << square_2(a)<<endl;
 int c=4;
 cout << square_3(c)<<endl;
 cout << c<< endl;
 
 display_square(100);

// display_broken_counter();
    display_counter();
    //display_counters();
    
}  

