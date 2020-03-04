/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   account.h
 * Author: Ronish Shrestha
 *
 * Created on February 16, 2018, 6:32 PM
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "transaction.h"


namespace csis3700{
class account {
    public :
        account();
        void deposit(int);
        void withdraw(int);
        int get_balance() const ;
        std::size_t get_transactions_size() const;
        transaction *get_transaction(std::size_t i)  const;
        
        
        
    private :
        int balance ;
        std::size_t transaction_cap;
        std:: size_t transaction_size;
        transaction **transactions;
        
        void add_transactions(transaction *t);
        void resize_transaction();
    
    
};

}



#endif /* ACCOUNT_H */

