#include<bits/stdc++.h>
using namespace std;

char matrix[5][5];
char key[26];
char msg[100];
int mark[130],len,r,c;

void createMatrix()
{
    cout<<"Enter Key: ";
    cin>>key;
    getchar();
    len=strlen(key);
    mark['J']=1;
    r=0,c=0;

    for(int i=0;i<len;i++)
    {
        if(!mark[toupper(key[i])])
        {
            mark[toupper(key[i])]=1;
            matrix[r][c++]=toupper(key[i]);
            if(c%5==0)
            {
                c=0;
                r++;
            }
        }
    }

    for(int i='A';i<='Z';i++)
    {
        if(mark[i]==0)
        {
            matrix[r][c++]=i;
            mark[i]=1;
            if(c%5==0)
            {
                if(r==4 && c==5) break;

                r++;
                c=0;
            }
        }
    }
}

void showMatrix()
{
    cout<<"Key Matrix"<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void decrypt()
{
    createMatrix();
    cout<<"Ciphered text: ";
    char cipText[150];
    cin>>cipText;
	cout<<endl;
    getchar();
    int l=strlen(cipText);

   	showMatrix();
    cout<<"Decrypted text: ";
    int P,Q,R,S,f1,f2;
    char x,y;
    for(int i=0;i<l;i+=2)
    {
        x=cipText[i];
        y=cipText[i+1];
        f1=f2=0;
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(x==matrix[j][k])
                {
                    P=j;
                    Q=k;
                    f1=1;
                }
                if(y==matrix[j][k])
                {
                    R=j;
                    S=k;
                    f2=1;
                }
                if(f1 && f2) break;
            }
            if(f1 && f2) break;
        }
        if(P==R)
        {
            if(Q==0) cout<<matrix[P][4];
            else cout<<matrix[P][Q-1];
            if(S==0) cout<<matrix[R][4];
            else cout<<matrix[R][S-1];
        }
        else if(Q==S)
        {
            if(P==0) cout<<matrix[4][Q];
            else cout<<matrix[P-1][Q];
            if(R==0) cout<<matrix[4][S];
            else cout<<matrix[R-1][S];
        }
        else
        {
            cout<<matrix[P][S]<<matrix[R][Q];
        }
    }
    cout<<endl;
}

void encrypt()
{
    createMatrix();
    cout<<"Message to cipher: ";
    gets(msg);
	cout<<endl;
    int l=strlen(msg);
    char reqText[150],a[150];
    int in=0,j=0;
   
    for(int i=0;i<l;i++)
    {
        if(msg[i]==' ') continue;
        else if(msg[i]=='j')
        {
            a[in]='i';
            in++;
        }
        else
        {
            a[in]=toupper(msg[i]);
            in++;
        }
    }

    int k=0;
    char filler='X';
    bool filled=false;
    for(int i=0;i<in;i+=2)
    {
        reqText[k]=a[i];
        k++;
        if(i+1!=in)
        {
            if(a[i]==a[i+1] && filled==false)
            {
                reqText[k]=filler;
                k++;
                reqText[k]=a[i+1];
                k++;
                filled=true;
                continue;
            }
            else
            {
                reqText[k]=a[i+1];
                k++;
            }
        }
    }
    if(k%2!=0)  reqText[k]=filler;

    showMatrix();
    cout<<"Encrypted text: ";
    int P,Q,R,S,f1,f2;
    char x,y;
    for(int i=0;i<in;i+=2)
    {
        x=reqText[i];
        y=reqText[i+1];
        f1=f2=0;
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(x==matrix[j][k])
                {
                    P=j;
                    Q=k;
                    f1=1;
                }
                if(y==matrix[j][k])
                {
                    R=j;
                    S=k;
                    f2=1;
                }
                if(f1 && f2) break;
            }
            if(f1 && f2) break;
        }
        if(P==R)
        {
            if(Q==4) cout<<matrix[P][0];
            else cout<<matrix[P][Q+1];
            if(S==4) cout<<matrix[R][0]<<" ";
            else cout<<matrix[R][S+1]<<" ";
        }
        else if(Q==S)
        {
            if(P==4) cout<<matrix[0][Q];
            else cout<<matrix[P+1][Q];
            if(R==4) cout<<matrix[0][S]<<" ";
            else cout<<matrix[R+1][S]<<" ";
        }
        else
        {
            cout<<matrix[P][S]<<matrix[R][Q]<<" ";
        }
    }
    cout<<endl;
}

void menu()
{
    int n;
    cout<<"Enter your choice \n1. Encryption \n2. Decryption \n";
    cin>>n;
    if(n==1) encrypt();
    else if(n==2) decrypt();
    else exit(1);
}

int main()
{
    menu();
    return 0;
}