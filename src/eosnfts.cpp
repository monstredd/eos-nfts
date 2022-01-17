#include <eosnfts.hpp>

[[eosio::action]]
void eosnfts::createnft( name account ,string nft) {
require_auth (account);
nfts _nfts_table (get_self(),account.value);
_nfts_table.emplace(account,[&](auto& new_nft){
new_nft.number = _nfts_table.available_primary_key();
new_nft.owner = account;
new_nft.nft = nft;
});
}

[[eosio::action]]
void eosnfts::deletenft( name account,uint64_t number) {
require_auth (get_self());
nfts _nfts_table (get_self(),account.value);
auto itr = _nfts_table.find(number);
check (itr != _nfts_table.end(),"id number not found");
_nfts_table.erase(itr);
}
