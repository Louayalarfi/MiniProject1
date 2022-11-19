#include <stdio.h>
#include <string.h>



int main()
{
    FILE *p, *pd;

   int i,y,o,u[255], x;
   char m[127], fname[100], basename[100];

   printf("\nPlease enter a file name:\t");
   scanf("%s", fname);

   printf("\nPlease choose following options:\n");
   printf("1 to Encrypt the string or 2 to Decrypt the string: ");
   scanf("%d", &x);
    p =fopen(fname, "r");
    for(int w=0;w<strlen(fname) && fname[w]!= '.'; w++)
    {
        basename[w]=fname[w];
    }
    if(x==1)
    {
    strcat(basename, ".crp");
 pd =fopen(basename,"w");
 printf("%s",basename);
    }
    else
    {strcat(basename, ".txt");
 pd =fopen(basename,"w");
 

    }
   
    
    if (p == NULL){
        printf("cannot open file");
    }

   //using switch case statements\
   
   while(fgets(m,sizeof(m),p) !=NULL){
      fprintf(pd,"\n");
    switch(x)
    {
    case 1:
        
        for(i = 0; i < strlen(m); i++)
          {
            if(m[i]==32)
              fprintf(pd,"80");
              else if(m[i]==9)
                fprintf(pd,"TT");
              else if(m[i]==3)
                fprintf(pd,"<CR>");  
            else if (m[i]>32)
          {
            u[i] = m[i] -16;
            
              fprintf(pd,"%X",u[i]);
            }
      else if(m[i]<32 && m[i]!=9 && m[i]!=3)
      {
          u[i]=m[i]-32+144;
            fprintf(pd,"%X",u[i]);
            }
    
          }
          

        
  break;
    case 2:
    for(i = 0; i < strlen(m); i++)
    {
    if((m[i]==56)&& (m[i+1]==48))
    {
    fprintf(pd," ");
    
    i=i+1;
    }
    else if ((m[i]==56)&& (m[i+1]==55))
    {
      fprintf(pd,"'");
    }
    else if((m[i]==50)&&(m[i+1]==70))
    {
      fprintf(pd,"?");
    }
    else if((m[i]==56)&&(m[i+1]==49))
    {
      fprintf(pd,"!");
    }
    else{
    if((i%2==0 || i==0))
    {u[i]=m[i]-48;
  u[i]=u[i]*16;

    }
    else
    {
  if (m[i]=='A')
  u[i]=u[i-1]+10;
  else if (m[i]=='B')
  u[i]=u[i-1]+11;
  else if (m[i]=='C')
  u[i]=u[i-1]+12;
  else if (m[i]=='D')
  u[i]=u[i-1]+13;
  else if (m[i]=='E')
  u[i]=u[i-1]+14;
  else if (m[i]=='F')
  u[i]=u[i-1]+15;

  else
  {
  u[i]=m[i]-48;
  u[i]=u[i-1]+u[i];
  }
  m[i]=u[i]+16;


  if(m[i]>127)
  {
      m[i]=(m[i]-144)+32;
      fprintf(pd,"%c",m[i]);
  }
  else
  fprintf(pd,"%c",m[i]);
    }
    
                   
    }
    }
  break;

    }
   }
    

   return 0;
}