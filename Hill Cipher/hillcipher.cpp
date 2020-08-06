#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int i,j;
string msg; 
int key[3][3];
float inv[3][3]; //to store inverse of matrix

void inverse(int key[3][3]){
    float det = 0;
    int i,j;
	for(i=0;i<3;i++)
		det += (key[0][i]*(key[1][(i+1)%3]*key[2][(i+2)%3] - key[1][(i+2)%3]*key[2][(i+1)%3]));
	
	cout << "\nDeterminant: " << det;
	
	cout<<"\nInverse of matrix is: \n";
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
            inv[i][j]=((key[(j+1)%3][(i+1)%3]*key[(j+2)%3][(i+2)%3])-(key[(j+1)%3][(i+2)%3]*key[(j+2)%3][(i+1)%3]))/ det;
			cout << inv[i][j] <<" ";
        }
		cout << endl;
	}
    cout<<endl;
}

void encrypt(){
    cout << "Enter message to encrypt: ";
    cin >> msg;     //take message 
    while(msg.length()%3 != 0)
        msg += "x";     //add extra x
    cout << "Enter integer key matrix(3x3): " << endl;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin >> key[i][j];   //take key matrix

    int l=msg.length(),r=3,c=0;
    (l%3 == 0) ? c=l/3 : c=(l/3)+1; //calculate column for the message
    
    int vector[r][c],a[l],enc[30][30],b[30][30];
    char s[l];

    for(i=0;i<l;i++){
        if(msg[i]>='A' && msg[i]<='Z')
            a[i] = int(msg[i]-65);  //convert char message to int
        else if(msg[i]>='a' && msg[i]<='z')
            a[i] = int(msg[i])-97;  //convert char message to int
    }

    int index=0;
    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            vector[j][i] = a[index];    //store message into 2D array
            index++;
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<c;j++){   
            enc[i][j] = 0;
            for(int k=0;k<3;k++)
                enc[i][j] += key[i][k]*vector[k][j];    //matrix multiplication
        }
    }
    /*
    for(i=0;i<3;i++){
        for(j=0;j<c;j++){
            if(msg[i]>='A' && msg[i]<='Z')
                enc[i][j]=(int(enc[i][j])%26)+65;   //convert encrypted message to char
            else if(msg[i]>='a' && msg[i]<='z')
                enc[i][j]=(int(enc[i][j])%26)+97;   //convert encrypted message to char
        }
    }
    int in=0;
    for(i=0;i<c;i++){
        for(j=0;j<3;j++){
            s[in] = enc[j][i];
            in++;
        }
    }*/
    
    for(j=0;j<c;j++){
        for(i=0;i<3;i++){
            b[i][j]=(int(enc[i][j])%26);
            if(b[i][j] < 0)
	    		b[i][j]+=26;    //If multiplication is negative 
    	}
    }

    int in=0;
    for(i=0;i<c;i++){
        for(j=0;j<3;j++){
          	if(msg[i]>='A' && msg[i]<='Z'){
                s[in] = b[j][i]+65;     //convert encrypted message to char
            	in++;
            }
            else if(msg[i]>='a' && msg[i]<='z'){
            	s[in] = b[j][i]+97;     //convert encrypted message to char
            	in++;
            }   
        }
    }
    cout << "Message: " << msg << endl; 
    cout << "Encrypted Text: ";
    for(i=0;i<in;i++)
        cout << s[i] ;
    cout << endl;
}

void decrypt(){
    cout << "Enter message to decrypt: ";
    cin >> msg;     //take message 
    while(msg.length()%3 != 0)
        msg += "x";     //add extra x
    cout << "Enter integer key matrix(3x3): " << endl;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin >> key[i][j];   //take key matrix
    
    inverse(key);
    int l= msg.length(),r=3,c=0;
    (l%3 == 0) ? c=l/3 : c=(l/3)+1; //calculate column for the message
    
    float vector[r][c],dec[30][30];
    int a[l],b[30][30];
    char s[l];

    for(i=0;i<l;i++){
        if(msg[i]>='A' && msg[i]<='Z')
            a[i] = int(msg[i]-65);  //convert char message to int
        else if(msg[i]>='a' && msg[i]<='z')
            a[i] = int(msg[i])-97;  //convert char message to int
    }
    int index=0;
    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            vector[j][i] = a[index];    //store message into 2D array
            index++;
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<c;j++){   
            dec[i][j] = 0;
            for(int k=0;k<3;k++)
                dec[i][j] += inv[i][k]*vector[k][j];    //matrix multiplication
        }
    }

    for(j=0;j<c;j++){
        for(i=0;i<3;i++){
            b[i][j]=(int(dec[i][j])%26);
            if(b[i][j] < 0)
	    		b[i][j]+=26;    //If multiplication is negative 
    	}
    }

    int in=0;
    for(i=0;i<c;i++){
        for(j=0;j<3;j++){
          	if(msg[i]>='A' && msg[i]<='Z'){
                s[in] = b[j][i]+65;     //convert encrypted message to char
            	in++;
            }
            else if(msg[i]>='a' && msg[i]<='z'){
            	s[in] = b[j][i]+97;     //convert encrypted message to char
            	in++;
            }   
        }
    }

    cout << "Encrypted Message: " << msg << endl;
    cout << "Decrypted Text: ";
    for(i=0;i<in;i++)
        cout << s[i] ;
    cout << endl;
}

int main(){
    int n;
    cout << "Enter your choice \n1. Encryption \n2. Decryption \n3. Exit \n";
    cin >> n;
    if(n == 1)
    	encrypt();
   	else if(n == 2)
    	decrypt();
    else if(n == 3){
        cout << "Exited from program.." << endl;
    	exit(1);
    }
    return 0;
}