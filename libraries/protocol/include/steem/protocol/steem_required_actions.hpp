#pragma once
#include <steem/protocol/base.hpp>
#include <steem/protocol/block_header.hpp>
#include <steem/protocol/asset.hpp>
#include <steem/protocol/validation.hpp>
#include <steem/protocol/legacy_asset.hpp>

#include <fc/crypto/equihash.hpp>

namespace steem { namespace protocol {

   struct example_required_action : public base_operation
   {
      account_name_type account;

      void validate()const;
      void get_required_active_authorities( flat_set<account_name_type>& a )const{ a.insert(account); }

      friend bool operator==( const example_required_action& lhs, const example_required_action& rhs );
   };

} } // steem::protocol

FC_REFLECT( steem::protocol::example_required_action, (account) )
