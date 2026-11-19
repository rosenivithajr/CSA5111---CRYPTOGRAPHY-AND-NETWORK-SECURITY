
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

void perm(char *in,char *out,int *t,int n)
{
    int i;
    for(i=0;i<n;i++) out[i]=in[t[i]-1];
    out[n]='\0';
}

void shift(char *s,int n)
{
    char c;
    int i;
    c=s[0];
    for(i=0;i<n-1;i++) s[i]=s[i+1];
    s[n-1]=c;
}

void makekeys(char *key,char *k1,char *k2)
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

void xorbits(char *a,char *b,char *c,int n)
{
    int i;
    for(i=0;i<n;i++) c[i]=(a[i]==b[i])?'0':'1';
    c[n]='\0';
}

void fk(char *b,char *key)
{
    char l[5],r[5],e[9],x[9],s[5],p[5],y[5];
    int row,col,v;
    strncpy(l,b,4); l[4]='\0';
    strncpy(r,b+4,4); r[4]='\0';
    perm(r,e,EP,8);
    xorbits(e,key,x,8);

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
    xorbits(l,p,y,4);
    strcpy(b,y); strcat(b,r);
}

void swapbits(char *s)
{
    char t[5];
    strncpy(t,s,4); t[4]='\0';
    memmove(s,s+4,4);
    memcpy(s+4,t,4);
    s[8]='\0';
}

void encrypt(char *in,char *out,char *k1,char *k2)
{
    char x[9];
    perm(in,x,IP,8);
    fk(x,k1);
    swapbits(x);
    fk(x,k2);
    perm(x,out,IPI,8);
}

void counterbits(int n,char *s)
{
    int i;
    for(i=7;i>=0;i--)
    {
        s[i]=(n%2)+'0';
        n=n/2;
    }
    s[8]='\0';
}

int main()
{
    char key[11]="0111111101",k1[9],k2[9];
    char p[3][9]={"00000001","00000010","00000100"};
    char c[3][9],d[3][9],ctr[9],stream[9];
    int i;

    makekeys(key,k1,k2);

    printf("CTR Encryption:\n");
    for(i=0;i<3;i++)
    {
        counterbits(i,ctr);
        encrypt(ctr,stream,k1,k2);
        xorbits(p[i],stream,c[i],8);
        printf("Cipher block %d: %s\n",i+1,c[i]);
    }

    printf("\nCTR Decryption:\n");
    for(i=0;i<3;i++)
    {
        counterbits(i,ctr);
        encrypt(ctr,stream,k1,k2);
        xorbits(c[i],stream,d[i],8);
        printf("Plain block %d: %s\n",i+1,d[i]);
    }

    return 0;
}

