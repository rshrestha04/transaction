/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "account.h"
#include "transaction.h"
#include <iostream>
#include <assert.h>


namespace csis3700{
    account::account(){
        balance= 0;
        transaction_size=0;
        transaction_cap=30;
        transactions = new transaction*[transaction_cap];
        }
    
    void account::deposit(int a){
        assert(a>0);
        transaction *t =new transaction(a,"deposit");
        add_transactions(t);
        balance +=a;
    }
    
    void account::withdraw(int a){
        assert(a>0&& a<=balance);
        transaction *t= new transaction(a,"withdraw");
        add_transactions(t);        
        balance -=a;
    }
    
    int account::get_balance() const{
        return balance;
    }
    
    void account::add_transactions(transaction *t){
            if(transaction_cap <= transaction_size){
                resize_transaction();
            }
            transactions[transaction_size] = t; //need to check
            transaction_size++;
    }
    
    void account ::resize_transaction(){
        transaction_cap=2*transaction_cap;
        
        transaction** copy;
        copy = new transaction*[transaction_cap];
        for (int x=0; x<transaction_size; x++){
            copy[x]= transactions[x]; //need to check
        }
        delete[] transactions;
        transactions = copy;
        
        
    }
    
    std::size_t account::get_transactions_size() const{
        return transaction_size;
    }
    
    transaction* account::get_transaction(size_t i) const {
        assert(i<transaction_cap);
        return transactions[i];
    }
        
}
