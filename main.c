#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sever(char **pole, char **novepole, char *slovo, unsigned int x, unsigned int  y, unsigned int pocetRadku)
{
  unsigned int nalezeno=0, pod2 = strlen(slovo);
  unsigned int i=0,j=0, a=x, b=y;
  i=x;
  if((pod2 <= pocetRadku) && (x+1>=strlen(slovo)))
  { 
     for(i=0;i<strlen(slovo);i++)
      {                 
         if(slovo[j]==pole[x][y])
         {
             nalezeno=1;
         }
         else
         { 
            nalezeno=0; 
            break;
         }
         if(x==0)
          {
                 break;
          }
         x--;
         j++; 
      }
      
  }
  
  if(nalezeno==1)
  {
     for(i=0;i<strlen(slovo);i++)
     {
          novepole[a-i][b]='9';
     }   
     return 1;
  }
  return 0;
}

int jih(char **pole, char **novepole, char *slovo, unsigned int x, unsigned int y, unsigned int pocetRadku)
{
  unsigned int i=0,j=0,nalezeno=0;
  if(pocetRadku-x >= strlen(slovo))
  {
      for(i=x;i<x+strlen(slovo);i++)
      {
         if(slovo[j]==pole[i][y])
         {
             nalezeno=1;
             j++; 
         }
         else
         {
            nalezeno=0;
            break;  
         }
      }
  } 
  if(nalezeno==1)
  {
     for(i=0;i<strlen(slovo);i++)
     {
          novepole[x+i][y]='9';
     }   
     return 1;
  }
  return 0;
}
int vychod(char **pole, char **novepole, char *slovo, unsigned int x, unsigned int y, unsigned int pocetRadku)
{
  unsigned int i=0,j=0,nalezeno=0;
  
  if(strlen(slovo) <= strlen(pole[0])-y)
  {  
      for(i=y;i<(strlen(slovo)+y);i++)
      {
         if(slovo[j]==pole[x][i])
         {
             nalezeno=1;
             j++; 
         }
         else
         {  
            nalezeno=0;
            break;
         }
      }
  }
  if(nalezeno==1)
  {
     for(i=0;i<strlen(slovo);i++)
     {
          novepole[x][y+i]='9';
     }  
     return 1; 
  }
  return 0;
}
int zapad(char **pole, char **novepole, char *slovo, unsigned int x, unsigned int y, unsigned int pocetRadku)
{
  unsigned int i=0,j=0,nalezeno=0;
  int w=(y+1)-strlen(slovo);
  int a=0;
  if(w >= 0)
  {
      for(a=y;a>=w;a--)
      {
         if(slovo[j]==pole[x][a])
         {
             nalezeno=1;
             j++; 
         }
         else
         {   
            nalezeno=0;
            break;
         }  
      }
  }

  if(nalezeno==1)
  {
     for(i=0;i<strlen(slovo);i++)
     {
          novepole[x][y-i]='9';
     }
     return 1;   
  }
  return 0;
}
int severoVychod(char **pole, char **novepole, char *slovo, unsigned int x, unsigned int y, unsigned int pocetRadku)
{
  unsigned int i=0, h=0, a=x, b=y, nalezeno=0;
  
  if((x+1>=strlen(slovo)) && strlen(slovo) <= strlen(pole[0])-y)       
  { 
          for(i=0;i<strlen(slovo);i++)
          {
            if(slovo[h]==pole[a][b])
             {
                nalezeno=1;
                h++; 
             }
             else
             {
                nalezeno=0;
                break;
             }
            if (a==0 || b == strlen(slovo)+y)
            {
               break;
            } 
            b++;
            a--;
              
          }
  }
  if(nalezeno==1)
  {
     for(i=0;i<strlen(slovo);i++)
     {
          novepole[x-i][y+i]='9';
     }  
      return 1;
  } 
  return 0; 
}
int severoZapad(char **pole, char **novepole, char *slovo, unsigned int x, unsigned int y, unsigned int pocetRadku)
{
  unsigned int i=0,h=0,a=x,b=y,nalezeno=0;
  int w=(y+1)-strlen(slovo);
  if((x+1>=strlen(slovo)) && w >= 0)
  {
      for(i=0;i<strlen(slovo);i++)
      {
            if(slovo[h]==pole[a][b])
             {
                nalezeno=1;
                h++; 
             }
             else
             {
                 nalezeno = 0;
                 break;
             }
           if (a==0 || b==0)
           {
              break;
           }
           b--;
           a--;
            
      }
  }  
  
  if(nalezeno==1)
  {
     for(i=0;i<strlen(slovo);i++)
     {
          novepole[x-i][y-i]='9';
     }   
     return 1;
  }
  return 0;
}
int jihoVychod(char **pole, char **novepole, char *slovo, unsigned int x, unsigned int y, unsigned int pocetRadku)
{
  unsigned int i=0,h=0,a=x,b=y,nalezeno=0;
 
  if((pocetRadku-x >= strlen(slovo)) && (strlen(slovo) <= strlen(pole[0])-y))
  {
       for(i=0; i<strlen(slovo);i++)
       {
             if(slovo[h]==pole[a][b])
             {
                nalezeno=1;
                h++; 
             }
             else
             {
                nalezeno = 0;
                break;
             }
           
           b++;
           a++;
           if (a==strlen(pole[0]) || b==strlen(slovo)+y)
           {
              break;
           }   
       }
         
  }
  if(nalezeno==1)
  {
     for(i=0;i<strlen(slovo);i++)
     {
          novepole[x+i][y+i]='9';
     }   
     return 1;
  }
  return 0;
}
int jihoZapad(char **pole, char **novepole, char *slovo, unsigned int x, unsigned int y, unsigned int pocetRadku)
{
  unsigned int i=0,h=0,a=x,b=y,nalezeno=0;
  int w =(y+1)-strlen(slovo);
  if((pocetRadku-x >= strlen(slovo)) && w >= 0)
  {
      for(i=0;i<strlen(slovo);i++)
      {             
             if(slovo[h]==pole[a][b])
             {
                nalezeno=1;
                h++; 
             }
             else
             {
                 nalezeno=0;
                 break;
             }
           if (a==strlen(pole[0]) || b==0)
           {
              break;
           }   
           b--;
           a++;
           
      }
  }
   if(nalezeno==1)
  {
     for(i=0;i<strlen(slovo);i++)
     {
          novepole[x+i][y-i]='9';
     }
     return 1;   
  } 
  return 0;
}

int najdiSmer(char *slovo, char **pole, char **novepole, unsigned int pocetRadku)
{ 
   int nalezeno=0;
   unsigned int x=0, y=0;
   for(x=0;x<pocetRadku;x++)
      {
          for(y=0;y<strlen(pole[0]);y++)
          {
             
              if(slovo[0]==pole[x][y])
              {/* hledam podle prvniho pismenka */
                  nalezeno += sever(pole, novepole, slovo, x, y, pocetRadku);
                  nalezeno += jih(pole, novepole, slovo, x, y, pocetRadku);
                  nalezeno += vychod(pole, novepole, slovo, x, y, pocetRadku);
                  nalezeno += zapad(pole, novepole, slovo, x, y, pocetRadku);
                  nalezeno += severoVychod(pole, novepole, slovo, x, y, pocetRadku);
                  nalezeno += severoZapad(pole, novepole, slovo, x, y, pocetRadku);
                  nalezeno += jihoVychod(pole, novepole, slovo, x, y, pocetRadku);
                  nalezeno += jihoZapad(pole, novepole, slovo, x, y, pocetRadku);
                  
              }
          }
        }
   
         /*for(x=0;x<pocetRadku;x++)
         {
             for(y=0;y<help;y++)
             {
                if(novepole[x][y] == '9')
                {
                   nalezeno=1;
                }  
             }
         }*/
         /*printf("nalezeno: %d\n", nalezeno);*/
         return nalezeno;
}

int main(int argc, char *argv[])
{
    unsigned int mem=64,mem2=10000,i=0,j,b=0, poprve=1,pomocna=0,radek=0,odradkovani=1,pocetslov=0, nalezeno=0;
	char **slova=(char**)malloc((mem2)*(sizeof(char)));
	char **pole = (char**)malloc((mem2)*(sizeof(char)));
	char **novepole = (char**)malloc((mem2)*(sizeof(char)));
    char a, c; 
    pole[0] = (char*)malloc((mem)*(sizeof(char)));
    novepole[0] = (char*)malloc((mem)*(sizeof(char)));
    slova[0] = (char*)malloc((mem)*(sizeof(char)));
	
	printf("Zadejte osmismerku:\n");
	while ((a = getchar()))
	{ 
       if(a != EOF)
       {   
	    if (a != '\n')
        {
           if(a < 'a' || a > 'z')
           {   
               if(a != '.')
               {
                   for(i=0;i<radek;i++)
                        free(pole[i]);
	               free(pole);
	               
	               for(i=0;i<radek;i++)
                       free(novepole[i]);
                   free(novepole);
                   
                   free(slova[0]); 
                   free(slova);
                   printf("Nespravny vstup.\n");
                   return 0;
               }
           }  
           poprve=0;
	       pole[i][b] = a;
	       novepole[i][b] = a;
	       b++;
	       odradkovani = 0;
           
           if(strlen(pole[i]) >= (mem-2))
           {
                  mem *= 4;
                  pole[i] = (char*) realloc (pole[i], mem * sizeof(char));
                  novepole[i] = (char*)realloc(novepole[i], mem * sizeof(char));
           }
        }
	    else
	    {
          if(poprve==1)
          {
              printf("Nespravny vstup.\n"); 
              
              for(i=0;i<radek;i++)
                    free(pole[i]);
              free(pole);
              
              for(i=0;i<radek;i++)
                    free(novepole[i]);
              free(novepole);
          
              free(slova[0]); 
              free(slova); 
              
              return 0;       
          }
          
          pole[i][b]='\0';
          novepole[i][b]='\0';
          
          if(odradkovani == 1)
	                break;
          
          /*if(radek+1 >= mem2-2)
          {printf("sem tu\n");
                mem2*=2;
                pole=(char**) realloc (pole , (mem2) * sizeof(char*));
	            novepole=(char**) realloc (novepole, (mem2) * sizeof(char*));           
            printf("po zmene: %d\n", mem2);
          }*/
     
          radek++;
          pomocna++;
          /*printf("pole[i][b] = %c\n", pole[i][b]);*/
          
          
          
          if(i > 0)
          {
             if(strlen(pole[i-1]) != strlen(pole[i]))
             {
                for(i=0;i<radek;i++)
                    free(pole[i]);
                free(pole);
                
                for(i=0;i<radek;i++)
                    free(novepole[i]);
                free(novepole);
          
                free(slova[0]); 
                free(slova);         
                printf("Nespravny vstup.\n");
                return 0;
             }
          } 
          
          i++;
          b=0;
          pole[i] = (char*)malloc((mem)*(sizeof(char)));
          novepole[i] = (char*)malloc((mem)*(sizeof(char)));
         
          odradkovani = 1;
	      
        }
      }
      else
      {
          printf("Nespravny vstup.\n");      
          
          for(i=0;i<radek;i++)
              free(pole[i]);
          free(pole);
          for(i=0;i<radek;i++)
                    free(novepole[i]);
                free(novepole);
          
          free(slova[0]); 
          free(slova);   
          
          return 0;
      }
   }
   
    b=0,i=0,mem=64, mem2=128, odradkovani=1;
    
    
    /*printf("pred nacitanim slov 0 %d\n", strlen(pole[0]));
    printf("pred nacitanim slov 1 %d\n", strlen(pole[1]));
    printf("pred nacitanim slov nove %d\n", strlen(novepole[0]));*/
    while ((c = getchar()))
	{ 
      if(c != EOF)
      {  
        if(c != '\n')   
        {
           slova[i][b] = c;
	       b++;
	       odradkovani = 0;
           
           if(strlen(slova[i]) >= (mem-2))
	       {
	           mem *= 4;
               slova[i] = (char*)realloc(slova[i],mem * sizeof(char));
	       }
        }
	    else
	    {
          pocetslov++;
          
          /*if(pocetslov >= (mem2-2))
          {
                mem2*=2;
                slova=(char**)realloc(slova,mem2*sizeof(char));
          }  */
          
            
          if(odradkovani==1)
          {
               printf("Nespravny vstup.\n");   
               
               for(i=0;i<radek;i++)
                    free(pole[i]);
                free(pole);
               for(i=0;i<radek;i++)
                    free(novepole[i]);
                free(novepole); 
                
          
               for(i=0;i<pocetslov;i++)
                      free(slova[i]); 
               free(slova); 
               
               return 0;               
          }
          odradkovani=1;  
          slova[i][b]='\0';
          /*printf("strlen slova : %d\n", strlen(slova[i]));*/  
          i++;
          b=0;
          
          slova[i] = (char*)malloc(mem * sizeof(char));
	    }
     }
     else
     {
        break;
     }     
  
  }

nalezeno=0;
/*printf("po funkci 0 %d\n", strlen(pole[0]));
printf("po funkci 1 %d\n", strlen(pole[1]));*/
for(j=0;j<pocetslov;j++)
{     
      nalezeno=najdiSmer(slova[j], pole, novepole, radek); 
      if(nalezeno==0)
      {
          printf("Slovo '%s' nenalezeno.\n", slova[j]);      
          for(i=0;i<radek;i++)
              free(pole[i]);
          free(pole);

          for(i=0;i<radek;i++)
              free(novepole[i]);
          free(novepole);
          
          for(i=0;i<pocetslov;i++)
               free(slova[i]); 
          free(slova);
         
          return 0;
      }
      
}



/*printf("sloupcu v mainu 2 pole0 = %d\n", strlen(pole[0]));
printf("sloupcu v mainu 2 pole1 = %d\n", strlen(pole[1]));
printf("sloupcu v mainu 2 novehopole0 = %d\n", strlen(novepole[0]));*/

/*for(i=0;i<radek;i++)
{
    for(j=0;j<help;j++)
    {    
         printf("%c",novepole[i][j]);
    }
    printf("\n");
}
printf("\n\n\n");*/
printf("Vysledek:\n");

pomocna=0;
poprve=0;

/*for(i=0;i<radek;i++)
{
    for(j=0;j<strlen(pole[0]);j++)
    {    
         printf("%c", novepole[i][j]);
    }
    printf("\n");
}

*/

for(i=0;i<radek;i++)
{
    for(j=0;j<strlen(pole[0]);j++)
    {    
         if(novepole[i][j] != '9' && novepole[i][j] != '.')                       
         {
          poprve++;                 
          if(pomocna==60)
          {
             printf("\n"); 
             pomocna=0;              
          }
          pomocna++;
          printf("%c",novepole[i][j]);
         }
    }
}
if(poprve > 0)
{
printf("\n");   
}

for(i=0;i<radek;i++)
   free(pole[i]);
free(pole);

for(i=0;i<radek;i++)
   free(novepole[i]);
free(novepole);
          
for(i=0;i<pocetslov;i++)
   free(slova[i]); 
free(slova); 
return 0;
}
