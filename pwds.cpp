//This code generates random strong password
#include<iostream>
#include<fstream>
#include<cstring>
#include<time.h>
#include<stdlib.h>
using namespace std;
void savefile(string need,char password[64],int a)
{
   ofstream enterneed(".password_list.txt",ios::app);
   enterneed<<need<<"-------";
   for(int i=0;i<a;i++ )
   {
      enterneed<<password[i];
   }
   enterneed<<"\n";
   enterneed.close();
}
int main()
{
   string need;
   int a;
   char q;
   char password[64];
   const char capital[]="QWERTYUIOPLKJHGFDSAZXCVBNM";
   const char small[]="qwertyuioplkjhgfdsazxcvbnm";
   const char number[]="0123456789";
   const char spchar[]="!@#$%&";
   const char allmix[]="QWERTYUIOPLKJHGFDSAZXCVBNMqwertyuioplkjhgfdsazxcvbnm1234567890!@#$%&";
   cout<<"Enter the need :";
   getline(cin,need);
   cout<<need<<"\n";
   cout<<"Enter the number of characters in password(min 8 and max 64) : ";
   cin>>a;
   cout<<"The password is ";
   srand(time(0));
   for (int i=0;i<a;i++)
   {
   if(i==1 || i==6)
   {
      password[i]=capital[rand()%(sizeof(capital)-1)];
   }
   else if(i==2 || i==7)
   {
      password[i]=small[rand()%(sizeof(small)-1)];
   }
   else if(i==3)
   {
      password[i]=number[rand()%(sizeof(number)-1)];
   }
   else if(i==5)
   {
      password[i]=spchar[rand()%(sizeof(spchar)-1)];
   }
   else
   {
      password[i]=allmix[rand()%(sizeof(allmix)-1)];
   }
   }
   for(int i=0;i<a;i++)
   {
      cout<<password[i];
   }
   savefile(need,password,a);
   cout<<"\nPress any key to quit";
   cin>>q;
   return 0;
}
