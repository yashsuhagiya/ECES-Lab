#include <iostream>
using namespace std;

string encrypt(string text, int s)
{
	  string res = "";

	  for (int i=0;i<text.length();i++)
	  {
	     	res += char(int(text[i]+s-65)%26 +65);
	  }
	  return res;													
}

string decrypt(string text, int s)
{
	  string res = "";

	  for (int i=0;i<text.length();i++)
	  {
	    	res += char(int(text[i]-s-65)%26 +65);
	  }
	  return res;
}

int main()
{
	  string text;
	  cout<<"Enter the message: ";
	  cin>>text;
	  cout << "Enter key: ";
	  int key, choice;
	  cin>>key;
	  cout<<"Enter your choice \n1. Encryption \n2. Decryption \n";
	  cin>>choice;
	  cout << "Your message : " << text;
	  if (choice == 1)
	  {
		    string cipher = encrypt(text, key);
		    cout << "\nEncrypted Text: " << cipher << endl;
	  }
	  else if (choice == 2)
	  {
	    	cout << "\nDecrypted Text: " << decrypt(text, key) << endl;
	  }
	  return 0;
}
