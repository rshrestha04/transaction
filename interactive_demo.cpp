/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   interactive_demo.cpp
 * Author: Ronish Shrestha
 *
 * Created on February 19, 2018, 1:11 AM
 */

#include <cstdlib>
#include <iostream>
#include "account.h"
#include <string>

using namespace std;
using namespace csis3700;

account demo;

void operation_function(std::string operation){
    
    if (operation == "d"){
       cout << "Enter amount to deposit:";
       int dep_amount;
       cin >> dep_amount;
       demo.deposit(dep_amount);
    }
    if (operation == "w"){
       cout << "Enter amount to withdraw:";
       int with_amount;
       cin >> with_amount ;
       demo.withdraw(with_amount);
    }
     
    if (operation == "v"){
       cout << "There are "<<demo.get_transactions_size()<<" transaction. Give transaction you want to view.";
       int trans;
       cin >> trans;
       while(trans> demo.get_transactions_size() or 0 >trans ){
        cout << "Invalid Transaction. Give number between 0 and "<< demo.get_transactions_size();
        cin >> trans;   
       }
       cout << "Transaction: " << trans-1<<" amount: "<< demo.get_transaction(trans-1)->get_amount() <<" type: " << demo.get_transaction(trans-1)->get_type()<< endl;
       
    }
    
    
}

int main() {
    
    
    cout <<"Current balance:"<< demo.get_balance()<<endl ;
    
    cout <<"Enter operation: (d)eposit, (w)ithdraw, (v)iew transaction or (e)xit: " ;
    std::string operation;
    cin >>  operation;
    operation_function(operation);
    while (operation!="e"){
     cout <<"Current balance:"<< demo.get_balance()<<endl ;
        cout <<"Enter operation:(d)eposit, (w)ithdraw, (v)iew transaction or (e)xit: " ;
        cin >>  operation;
        operation_function(operation);
    }
    
        cout << "bye";
     
    

 return 0;
}

