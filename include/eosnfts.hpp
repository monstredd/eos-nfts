#include <eosio/eosio.hpp>

using namespace eosio;
using namespace std;

class [[eosio::contract]] eosnfts : public contract {
   public:
      using contract::contract;

      [[eosio::action]] 
      void createnft( name account,string nft);
      [[eosio::action]] 
      void deletenft( name account,uint64_t number);

      using createnft_action = action_wrapper<"createnft"_n, &eosnfts::createnft>;
      using deletenft_action = action_wrapper<"deletenft"_n, &eosnfts::deletenft>;
   
   private:

      struct [[eosio::table]] nft {
            uint64_t number; 
            name owner;  
            string nft;       
            uint64_t primary_key()const { return number;}
         };

        typedef eosio::multi_index< "nfts"_n, nft > nfts;
};