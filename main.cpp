#include "head.h"





std::string hash :: bigEndianLength(int c){

    std::vector<int> a;
    int n = c*8;
    int k;

    char i;
    for(k = 0; n > 0; k++){
        i = n%2;
        a.push_back(i);
        n = n/2;
    }

    std::stringstream ss;
    copy(a.begin(), a.end(), std::ostream_iterator<int>(ss));

    std::string s = ss.str();

    reverse(s.begin(), s.end());

    return s;
}



std::bitset<8> hash :: padBits(int n, int i, std::string message){

    std::bitset<8> first (std::string("10000000"));

    std::bitset<8> sec (std::string("00000000"));

    if(i < n ){
        return std::bitset<8>(message.c_str()[i]);
    }
    else if(i == n){
        return first;
    }
    else{
        return sec;
    }

}











void hash :: mesToBits(){
    n = message.size();
    bitN = n*8;

    // calculating how many bits will need to be padded

    if(bitN + 66 <= 512){
        bitsToAdd = 512 - (64 + bitN);
        totBitCount = 512;
    }
    else{
        res = div(bitN + 66, 512);
        if(res.rem > 0){
            totBitCount = 512 * (res.quot + 1);
        }
        else{
            totBitCount = 512 * (res.quot);
        }
        if(totBitCount - (64 + n*8) > 0){
            bitsToAdd = totBitCount - (64 + n*8);
        }
        else{
            totBitCount += 512;
            bitsToAdd = totBitCount - (64 + n*8);
        }
    }

    symbToAdd = div(bitsToAdd, 8);

    // padding the message with bits

    std::size_t i;

    for(i = 0; i < n + symbToAdd.quot; i++){
        bitCount.push_back(padBits(n, i, message));
    }

    // converting the message length (big-endian integer) into binary format

    std::string output = bigEndianLength(n);
    
    int necNumBits = ( totBitCount - output.size() ) / 8;

    while(i < necNumBits){
        bitCount.push_back(padBits(n, i, message));
        i++;
    }
    std::bitset<8> pad (output);

    // adding the message length at the end of the vector

    bitCount.push_back(pad);

}





// void hash :: shuffle(){
//     std::vector<std::bitset<64>> res;
//     int g = bitHex.size()-1;
//     while(g < bitHex.size()){
//         if(g == bitHex.size()/4){
//             g = bitHex.size()/2;
//         }
//         else if(g == bitHex.size()/3){
//             g = bitHex.size()/5;
//         }
//         res.push_back(bitHex[g]);
//         if(res.size() == bitHex.size()) {break;}
//         g--;
//     }
//     bitHex = res;
// }





std::vector<std::bitset<32>> byteToEight (std::string* bits) {

    std::vector<std::bitset<32>> ret;

    for(int i=0; i<bits->size(); i++) {
        std::string sup = bits[i];

        std::string wat;
        for(int l = 0; l < sup.size(); l++){
            std::bitset<8> w (std::string(sup).c_str()[l]);
            wat += w.to_string();
        }
        std::bitset<32> wut ((std::string (wat)));
        ret.push_back(wut);
    }
        return ret;

}






// void hash :: encode (int i){

//     int l = 0;
//     for(int k = 0; k < bitKeys.size(); k++){
//         if(k < 20){
//             bitHex[i] = (bitHex[i] ^ bitKeys[k]) | ((bitHeys[l]) ^ bitKeys[l+l*i]);
//             bitHex[i] = bitHex[i] | bitHex[l];
//             l++;
//             if(l >= bitHeys.size()){
//                 l = 0;
//             }
//         }
//         else if(k < 40){
//             bitHex[i] = (bitHex[i] ^ bitKeys[k]) | ((bitHeys[l/i]) ^ bitKeys[k-i+l]);
//             bitHex[i] = bitHex[i/l] | bitHex[l] << i;
//             l+=2;
//             if(l >= bitHeys.size()){
//                 l = 6;
//             }
//         }
//         else{
//             bitHex[i] = (bitHex[i/l] ^ bitKeys[k]) | ((bitHeys[l]) ^ bitKeys[k-l]);
//             l++;
//             if(l >= bitHeys.size()){
//                 l = 3;
//             }
//         }
//     }

// }


void hash :: splitToWords(){
    
}



void hash :: bitDigest(){

    // arrays of keys and heys (type = string) are being converted to std::bitset<64>

    // bitKeys = byteToEight(keys);

    bitHeys = byteToEight(heys);

    std::cout << "Cia yra bitHeys pradzia" << std::endl;
    for(int i =0; i < bitHeys.size(); i++){
        std::cout << "wut " << bitHeys[i] << std::endl;
    }
    std::cout << "Cia yra bitHeys pabaiga" << std::endl;

    // initial vector (type = std::bitset<8>) is being converted to std::bitset<64>

    int c = 0;

    std::cout<< "bitcount size yra " << bitCount.size() << std::endl;

    if(bitCount.size()*8 > 512){

    }
    else{

    }

    // while(c<bitCount.size()){
    //     std::cout << c << " yra lygus " << bitCount[c].to_string() << std::endl;
    //     std::string temp = bitCount[c].to_string();
    //     temp += bitCount[c+1].to_string();
    //     temp += bitCount[c+2].to_string();
    //     temp += bitCount[c+3].to_string();
    //     temp += bitCount[c+4].to_string();
    //     temp += bitCount[c+5].to_string();
    //     temp += bitCount[c+6].to_string();
    //     temp += bitCount[c+7].to_string();
    //     std::bitset<32> tBit ((std::string(temp)));
    //     bitHex.push_back(tBit);
    //     c+=8;
    //     if(c >= bitCount.size()){
    //         break;
    //     }
    // }


    // std::cout << "Generated string is: " << str << std::endl;

}


void hash :: setFileMessage(std::string fName){
    
    std::ifstream file(fName);
    std::string tempMes;

    while(!file.eof()){
        file >> tempMes;
        message += tempMes;
    }

    file.close();
}


int main(int argc, char** argv){

    hash test;
    std::string fileName = "";
    int pref;
    std::string input = "";

    if(argc > 1){
        std::cout << "first " << std::endl;
    }

    std::cout << "What's your preference for input ?" << std::endl;
    std::cout << "1 - console input" << std::endl;
    std::cout << "2 - file input" << std::endl;
    std::cin >> pref;

    if(pref == 2){
        std::cout << "Enter the name of the input file" << std::endl;
        std::cin >> fileName;
        test.setFileMessage(fileName);
        std::cout << "The message is - " << test.getMessage() << std::endl;
        std::cout << std::endl;
    }
    else{
        std::cout << "Enter your message: ";
        std::cin >> input;
        test.setMessage(input);
    }

    

    test.mesToBits();

    test.bitDigest();
}