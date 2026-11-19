#include <stdio.h>
#include <string.h>

int P10[10]={3,5,2,7,4,10,1,9,8,6};
int P8[8]={6,3,7,4,8,5,10,9};
int IP[8]={2,6,3,1,4,8,5,7};
int IPI[8]={4,1,3,5,7,2,8,6};
int EP[8]={4,1,2,3,2,3,4,1};
int P4[4]={2,4,3,1};

int S0[4][4]={
{1,0,3,2},{3,2,1,0},
{0,2,1,3},{3,1,3,2}
};

int S1[4][4]={
{0,1,2,3},{2,0,1,3},
{3,0,1,0},{2,1,0,3}
};

void perm(char *in, char *out, int *t, int n)
{
    int i;
    for(i=0;i<n;i++)
        out[i]=in[t[i]-1];
    out[n]='\0';
}

void shift(char *s, int n)
{
    char t[10];
    int i;
    for(i=0;i<n;i++)
        t[i]=s[(i+1)%n];
    for(i=0;i<n;i++)
        s[i]=t[i];
}

void makekeys(char *key, char *k1, char *k2)
{
    char p[11],l[6],r[6],t[11];
    perm(key,p,P10,10);
    strncpy(l,p,5); l[5]='\0';
    strncpy(r,p+5,5); r[5]='\0';

    shift(l,5); shift(r,5);
    strcpy(t,l); strcat(t,r);
    perm(t,k1,P8,8);

    shift(l,5); shift(l,5);
    shift(r,5); shift(r,5);
    strcpy(t,l); strcat(t,r);
    perm(t,k2,P8,8);
}

void xorr(char *a, char *b, char *c, int n)
{
    int i;
    for(i=0;i<n;i++)
        c[i]=(a[i]==b[i])?'0':'1';
    c[n]='\0';
}

void fk(char *b, char *key)
{
    char l[5],r[5],e[9],x[9],s[5],p[5],y[5];
    int row,col,v,i;

    strncpy(l,b,4); l[4]='\0';
    strncpy(r,b+4,4); r[4]='\0';

    perm(r,e,EP,8);
    xorr(e,key,x,8);

    row=(x[0]-'0')*2+(x[3]-'0');
    col=(x[1]-'0')*2+(x[2]-'0');
    v=S0[row][col];
    s[0]=(v/2)+'0'; s[1]=(v%2)+'0';

    row=(x[4]-'0')*2+(x[7]-'0');
    col=(x[5]-'0')*2+(x[6]-'0');
    v=S1[row][col];
    s[2]=(v/2)+'0'; s[3]=(v%2)+'0';
    s[4]='\0';

    perm(s,p,P4,4);
    xorr(l,p,y,4);
    strcpy(b,y);
    strcat(b,r);
}

void encrypt(char *in, char *out, char *k1, char *k2)
{
    char x[9],y[9];
    perm(in,x,IP,8);
    fk(x,k1);
    strncpy(y,x,4); y[4]='\0';
    strncpy(x,x+4,4); x[4]='\0';
    strcat(x,y);
    fk(x,k2);
    perm(x,out,IPI,8);
}

void decrypt(char *in, char *out, char *k1, char *k2)
{
    encrypt(in,out,k2,k1);
}

int main()
{
    char key[11]="0111111101";
    char k1[9],k2[9],iv[9]="10101010";
    char p[2][9]={"00000001","00100011"};
    char c[2][9],d[2][9],x[9];
    int i;

    makekeys(key,k1,k2);

    printf("CBC Encryption:\n");
    for(i=0;i<2;i++)
    {
        xorr(p[i],iv,x,8);
        encrypt(x,c[i],k1,k2);
        strcpy(iv,c[i]);
        printf("Cipher block %d: %s\n",i+1,c[i]);
    }

    strcpy(iv,"10101010");
    printf("\nCBC Decryption:\n");
    for(i=0;i<2;i++)
    {
        decrypt(c[i],x,k1,k2);
        xorr(x,iv,d[i],8);
        strcpy(iv,c[i]);
        printf("Plain block %d: %s\n",i+1,d[i]);
    }

    return 0;
}
