#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <bitset>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <fstream>

class hash{
    public:
        // inline std::string const getHash(){return hex;}
        inline void setMessage(std::string mes){message = mes;}
        inline std::string const getMessage(){return message;}

        void setFileMessage(std::string);
        std::string bigEndianLength(int);
        std::bitset<8> padBits(int, int, std::string);
        void shuffle();
        void mesToBits();
        void bitDigest();
        void encode (int);
        void splitToWords();

    private:
        std::vector<std::bitset<64>> hex;
        std::vector<std::bitset<64>> bitHex;
        std::string message;
        std::vector<std::bitset<8>> bitCount;
        std::vector<std::bitset<64>> bitKeys;
        std::vector<std::bitset<32>> bitHeys;
        int n; // = message.size();
        int bitN;
        int bitsToAdd;
        int totBitCount;
        div_t res;
        div_t symbToAdd;
        
//         std::string keys [64] = {"8ee90803",
// "4a79ccfb",
// "c0201390",
// "1f028e63",
// "557b7aa5",
// "e7c2ef58",
// "2bfedeea",
// "0a0bb38f",
// "24441e7e",
// "0f5adb92",
// "f883c5c0",
// "e32a6240",
// "e64025f3",
// "39e869df",
// "31e424e1",
// "3ba69d59",
// "e3439625",
// "7fe7ed5d",
// "7d8702e2",
// "9d5e9163",
// "fea9efe4",
// "c90b4317",
// "59f30450",
// "9117b3ba",
// "515ce01f",
// "b87b5066",
// "b025ae4c",
// "a5c082ed",
// "cae76d1b",
// "58315f8a",
// "47d0aa84",
// "2dde953d",
// "9e8ad542",
// "3d4c3770",
// "bf727c60",
// "b183d44f",
// "c7a40ff4",
// "48c0932c",
// "25626e56",
// "268426d3",
// "b66b31a9",
// "572b3e3b",
// "05a879ac",
// "5914589d",
// "8b951548",
// "912b5be5",
// "4c9e6224",
// "3474af21",
// "75689dfd",
// "8e4abc32",
// "ebae65f9",
// "e95da14c",
// "3960a5f0",
// "0b626df9",
// "56c59906",
// "5f1e04dd",
// "89e870f3",
// "a54f01f2",
// "a22df1b5",
// "9f7216b0",
// "21884e97",
// "0531c335",
// "6b72d898",
// "df9c3816"
//  };

        

        std::string heys [5] = { "67DE2A01", "BB03E28C", "011EF1DC", "9293E9E2", "CDEF23A9" };

        
        

};