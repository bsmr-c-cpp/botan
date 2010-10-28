/*
* HMAC
* (C) 1999-2007 Jack Lloyd
*
* Distributed under the terms of the Botan license
*/

#ifndef BOTAN_HMAC_H__
#define BOTAN_HMAC_H__

#include <botan/mac.h>
#include <botan/hash.h>

namespace Botan {

/**
* HMAC
*/
class BOTAN_DLL HMAC : public MessageAuthenticationCode
   {
   public:
      void clear();
      std::string name() const;
      MessageAuthenticationCode* clone() const;

      Key_Length_Specification key_spec() const
         {
         return Key_Length_Specification(0, 2*hash->hash_block_size());
         }

      /**
      * @param hash the hash to use for HMACing
      */
      HMAC(HashFunction* hash);
      ~HMAC() { delete hash; }
   private:
      void add_data(const byte[], size_t);
      void final_result(byte[]);
      void key_schedule(const byte[], size_t);

      HashFunction* hash;
      SecureVector<byte> i_key, o_key;
   };

}

#endif
