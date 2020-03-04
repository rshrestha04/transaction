/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   transaction.h
 * Author: Ronish Shrestha
 *
 * Created on February 16, 2018, 5:13 PM
 */

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

namespace csis3700{
    class transaction{
        public:
           // transaction();
            transaction(int,std::string);
            int get_amount() const;
            std::string get_type() const;
  
        
        
        private:
            int amount;
            std::string type;
        
    
    
    };

}


#endif /* TRANSACTION_H */

