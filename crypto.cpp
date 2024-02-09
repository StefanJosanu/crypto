#include <iostream>
#include <cstdlib>
#include <cstring>
#include "csr.h"
#include "vars.h"

using namespace std;

int main(int argc , char*argv[]){
 if(argc==1){
  cout << argv[0] << " : No option and message " << endl;
  exit(1);
 }
 
 if(argc==2){
  if(strcmp(argv[1],"-Ecsr")==0){
   cout << argv[0] << " : No message " << endl;
   exit(2);
  } else if(strcmp(argv[1],"-Dcsr")==0){
   cout << argv[0] << " : No message " << endl;
   exit(2);
  } else {
   cout << argv[0] << " : No option " << endl;
   exit(3);
  }
 }
 
 if(argc==3){
  if(strcmp(argv[1],"-Ecsr")==0){
   CSR_encrypt(argv[2]);
   CSR_enc_math(argv[2]);
  } else if (strcmp(argv[1],"-Dcsr")==0){
   CSR_decrypt(argv[2]);
   CSR_dec_math(argv[2]);
  } else {
   cout << argv[0] << " : No such option " << endl;
   exit(4);
  } 
 }
 
 if(argc>3){
  cout << argv[0] << " : Too many strings " << endl;
  exit(4);
 }
 
 exit(0);
}
