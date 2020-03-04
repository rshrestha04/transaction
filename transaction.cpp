/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "transaction.h" 
#include <iostream>
#include <cstring>

namespace csis3700{
    /*
    transaction::transaction(){
        amount= 0;
    }
    */
    transaction::transaction(int a, std::string typ){
        amount =a;
        type=typ;
    }

    
    int transaction::get_amount() const{
      return amount;
    }
    
    std::string transaction::get_type() const{
        return type;
    }
}



