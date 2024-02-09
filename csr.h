#ifndef CSR_H
#define CSR_H

#include <iostream>
#include <cstring>
#include "vars.h"

using namespace std;

void CSR_encrypt(char*message){
 int key;
 cout << "Encrypt function " << endl;
 cout << "Enter key = ";
 cin >> key;
 
 int i,j;
 char encryption[25];
 char letterUppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 char letterLowercase[] = "abcdefghijklmnopqrstuvwxyz";
  
 for (i = 0; i < strlen(message); ++i) {
        char msg = message[i];

        if (isalpha(msg) && isupper(msg)) {
            for (j = 0; j < strlen(letterUppercase); ++j) {
                if (letterUppercase[j] == msg) {
                    int cry = (j + key) % strlen(letterUppercase);
                    encryption[i] = letterUppercase[cry];
                    cout << encryption[i];
                    break;
                }
            }
        } else if (isalpha(msg) && !isupper(msg)) {
            for (j = 0; j < strlen(letterLowercase); ++j) {
                if (letterLowercase[j] == msg) {
                    int cry = (j + key) % strlen(letterLowercase);
                    encryption[i] = letterLowercase[cry];
                    cout << encryption[i];
                    break;
                }
            }
        }
    }   
}

void CSR_decrypt(char*message){
 int key;
 cout << "Decrypt function " << endl;
 cout << "Enter key = ";
 cin >> key;
 
 int i,j;
 char encryption[25];
 char letterUppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 char letterLowercase[] = "abcdefghijklmnopqrstuvwxyz";
 
  
 for (i = 0; i < strlen(message); ++i) {
        char msg = message[i];

        if (isalpha(msg) && isupper(msg)) {
            for (j = 0; j < strlen(letterUppercase); ++j) {
                if (letterUppercase[j] == msg) {
                    int cry = (j - key + strlen(letterUppercase)) % strlen(letterUppercase);
                    encryption[i] = letterUppercase[cry];
                    cout << encryption[i];
                    break;
                }
            }
        } else if (isalpha(msg) && !isupper(msg)) {
            for (j = 0; j < strlen(letterLowercase); ++j) {
                if (letterLowercase[j] == msg) {
                    int cry = (j - key + strlen(letterLowercase)) % strlen(letterLowercase);
                    encryption[i] = letterLowercase[cry];
                    cout << encryption[i];
                    break;
                }
            }
        }  
    }
}

void CSR_enc_math(char* message) {
    int k;
    cout << "\n";
    cout << "\n";
    cout << "Encrypt function using math :)" << endl;
    cout << "Enter key = ";
    cin >> k;

    char* cry = message;

    while (*message) {
        if (*message >= 'A' && *message <= 'Z') {
            *message = ((*message - 'A' + k) % 26) + 'A';
        } else if (*message >= 'a' && *message <= 'z') {
            *message = ((*message - 'a' + k) % 26) + 'a';
        }
        message++;
    }

    cout << cry << endl;
}

void CSR_dec_math(char* message) {
    int k;
    cout << "\n";
    cout << "\n";
    cout << "Decrypt function using math :)" << endl;
    cout << "Enter key = ";
    cin >> k;

    char* cry = message;

    while (*message) {
        if (*message >= 'A' && *message <= 'Z') {
            *message = ((*message - 'A' - k + 26) % 26) + 'A';
        } else if (*message >= 'a' && *message <= 'z') {
            *message = ((*message - 'a' - k + 26) % 26) + 'a';
        }
        message++;
    }

    cout << cry << endl;
}

#endif
