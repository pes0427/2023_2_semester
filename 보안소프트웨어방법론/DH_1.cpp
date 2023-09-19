#include <iostream>
#include <string>

using namespace std;

/*
    base = g
    exp = x
    mod = p
*/

//g의 x 제곱의 mod p 연산한 값을 return하는 함수
int powm(int base, int exp, int mod){
    int r = 1;
    for (int i =0; i < exp; i++){
        r *= base; // g의 x제곱
        r %= mod;  // 중간중간 mod 연산을 해줘도 ok
    }
    return r;
}

int main(){
    int base,exp,mod,result;
    
    std::cout<<"base : ";
    std::cin>>base;

    std::cout<<"exp : ";
    std::cin>>exp;

    std::cout<<"mod : ";
    std::cin>>mod;

    result = powm(base,exp,mod);
    printf("result : %d\n",result);

    return 0;
}