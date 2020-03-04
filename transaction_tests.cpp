/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "transaction.h"
#include "account.h"

using namespace csis3700;
/*
TEST_CASE("testing null constrictor","[transaction]"){
    transaction a;
    REQUIRE( a.get_amount()==0);
    
}
*/
TEST_CASE ("Testing constructor","[transaction]"){
    transaction a(100,"withdrawal");
    REQUIRE (a.get_amount()==100);
    REQUIRE (a.get_type()=="withdrawal");
}
/*----------------------------------------------------------------------------*/
TEST_CASE("checking constructors","[account]"){
    account a;
    REQUIRE (a.get_balance()==0);
    REQUIRE(a.get_transactions_size()==0);
}

TEST_CASE("checking deposit","[account]"){
    account a;
    a.deposit(100);
    REQUIRE(a.get_balance()==100);
}

TEST_CASE("checking withdrawal","[account]"){
    account a;
    a.deposit(1000);
    a.withdraw(100);
    REQUIRE(a.get_balance()==900);
}

TEST_CASE("checking transactions","[account"){
    account a; 
    a.deposit(100);
    a.withdraw(20);
    a.deposit(120);
    REQUIRE(a.get_balance()==200);
    REQUIRE(a.get_transactions_size()==3);
    REQUIRE((a.get_transaction(2))->get_amount()==120);
    REQUIRE((a.get_transaction(0))->get_type()=="deposit");
}

TEST_CASE("checking transaction exceeding 30","[account]"){
    account b;
    for (int x=0; x <32; x++){
        b.deposit(10);
    }
    for(int x=0;x<40;x++){
        b.withdraw(1);
    }
    REQUIRE(b.get_transactions_size()==72);
    REQUIRE((b.get_transaction(31))->get_amount()==10);
    REQUIRE((b.get_transaction(31))->get_type()=="deposit");
    REQUIRE((b.get_transaction(45))->get_amount()==1);
    REQUIRE((b.get_transaction(45))->get_type()=="withdraw");
}



