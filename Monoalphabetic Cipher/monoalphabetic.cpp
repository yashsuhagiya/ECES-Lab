#include<iostream>
#include<string>
using namespace std;

void encrypt(string msg, string key, char p[], char P[])
{
      string enc;
      int i,j;
      for(i=0;i<msg.length();i++)
      {
            for(j=0;j<26;j++)
            {
                  if( msg[i] == p[j] || msg[i] == P[j] )
                  {
                        enc[i] = key[j];
                  }
            }
      }
      cout << "Encrypted text: ";
      for(i=0;i<msg.length();i++)
      {
            cout << enc[i];
      }
      cout << endl;
}

void decrypt(string msg, string key, char p[])
{
      string dec;
      int i,j;
      for(i=0;i<msg.length();i++)
      {
            for(j=0;j<26;j++)
            {
                  if( msg[i] == key[j] )
                  {
                        dec[i] = p[j];
                  }
            }
      }

      cout << "Decrypted text: ";
      for(i=0;i<msg.length();i++)
      {
            cout << dec[i];
      }
      cout << endl;
}

int main()
{
      string msg, key;
      int choice;
      char p[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
      char P[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
      cout << "Enter the message: ";
      cin >> msg;

      cout << "Enter key: ";
      cin >> key;

      cout << "Enter your choice \n1. Encryption \n2. Decryption \n";
      cin >> choice;
      cout << "Your message: " << msg << endl;
      if (choice == 1){
            encrypt(msg,key,p,P);
      }
      else if (choice == 2) {
            decrypt(msg,key,p);
      }
      return 0;
}