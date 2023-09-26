#include <gmpxx.h>
#include <iostream>

using namespace std;

/* wrapper 함수 정의 */
mpz_class powm(mpz_class base, mpz_class exp, mpz_class mod);
mpz_class urandomm(gmp_randstate_t state, const mpz_class n);
int cmp(mpz_class A, mpz_class B);

mpz_class powm(mpz_class base, mpz_class exp, mpz_class mod){
    mpz_class r;
    mpz_powm(r.get_mpz_t(),base.get_mpz_t(),exp.get_mpz_t(),mod.get_mpz_t());
    return r;
}

mpz_class urandomm(gmp_randstate_t state, const mpz_class n){
    mpz_class r;
    mpz_urandomm(r.get_mpz_t(),state,n.get_mpz_t());
    return r;
}

int cmp(mpz_class A, mpz_class B){
    int r = mpz_cmp(A.get_mpz_t(),B.get_mpz_t());
    return r;
}

int main(){
    mpz_class p{"0xFFFFFFFFFFFFFFFFADF85458A2BB4A9AAFDC5620273D3CF1D8B9C583CE2D3695A9E13641146433FBCC939DCE249B3EF97D2FE363630C75D8F681B202AEC4617AD3DF1ED5D5FD65612433F51F5F066ED0856365553DED1AF3B557135E7F57C935984F0C70E0E68B77E2A689DAF3EFE8721DF158A136ADE73530ACCA4F483A797ABC0AB182B324FB61D108A94BB2C8E3FBB96ADAB760D7F4681D4F42A3DE394DF4AE56EDE76372BB190B07A7C8EE0A6D709E02FCE1CDF7E2ECC03404CD28342F619172FE9CE98583FF8E4F1232EEF28183C3FE3B1B4C6FAD733BB5FCBC2EC22005C58EF1837D1683B2C6F34A26C1B2EFFA886B423861285C97FFFFFFFFFFFFFFF"};
    mpz_class g = 2;
    gmp_randstate_t state;
    gmp_randinit_mt(state);

    mpz_class a_private = urandomm(state,p);
    mpz_class b_private = urandomm(state,p);

    mpz_class a_public = powm(g,a_private,p);
    mpz_class b_public = powm(g,b_private,p);

    mpz_class A = powm(b_public,a_private,p);
    mpz_class B = powm(a_public,b_private,p);

    cmp(A,B) == 0 ? cout << "Success!" << endl :  cout << "Fail\n" << endl;
    
    return 0;
}