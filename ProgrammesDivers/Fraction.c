#include <stdio.h>

#define N 22000


int quotient(int a,int b)
        {
            int q=a/b;
            return(q);
        }

int reste(int a,int b)
       {
           int r=a-b*quotient(a,b);
           return (r);
       }


void initialisation_tableau(int T[N])
           {

               int i=0;
               while(i<N)
               {
                   T[i]=0;
                   i++;
               };
           }


int kieme_decimale(int a,int b,int k)
       {
         int i=0;
         int q=0;

         while(i<k+1)
           {
             q=quotient(a,b);
             a=10*reste(a,b);
             i++;

           }
         return(q);

      }




void n_decimales(int a, int b,int T[N])
       {

           int k=0;
           int q=quotient(a,b);

           printf(" %d.",q);


           while(k<N)
           {
               a=10*reste(a,b);
               q=quotient(a,b);
               T[k]=q;
               printf(" %d",q);
               k++;
           }



           printf("\n");
       }

void Analyse_Decimales(int T[N])
         {
             int i=0;
             int j=0;
             int k=0;
             int n=0;
             int l=0;
             int m=0;
             int p=0;
             int q=0;
             int longueur_periode=0;
             int longueur_periode2=0;
             int somme=0;
             int produit=0;
             int compteur=0;
             int compteur2=0;
             int N_i[10];
             int L_i[10];
             int S[10][N];
             int D[10][N];

             while(i<10)
             {
                 initialisation_tableau(S[i]);
                 initialisation_tableau(D[i]);

                 for(j=1;j<N+1;j++)
                 {
                   if(T[j-1]==i)
                   {
                       S[i][k]=j;

                       if(k==0)
                       {
                        /*printf("La suite de decimales contient le chiffre %d\n",i);*/
                       }
                      /* printf("S[%d][%d] = %d\n",i,k,j);*/
                       k++;
                       if(k>=2)
                       {
                          p=k-1;
                          D[i][p-1]=S[i][p]-S[i][p-1];
                          m=D[i][p-1];
                          /*printf("S[%d][%d]-S[%d][%d] = %d\n",i,p,i,p-1,m);*/
                       }
                    }
                  }


                k=0;
                i++;
             }
                printf("\n*******************************************************************************************\n");

                for(i=0;i<10;i++)
                {
                    N_i[i]=0;
                    L_i[i]=0;
                    j=0;
                    while((S[i][j]!=0)&&(j<N))
                      {
                          j++;
                      }

                    N_i[i] = j;



                    if(j!=0)
                    {
                        printf(" Le chiffre %d est present %5d fois dans le developpement decimal de votre quotient.\n",i,j);

                    }

                    if(N_i[i]==N)
                    {
                        if(i==0)
                        {
                            printf(" Le resultat de votre quotient est un nombre entier.\n");
                            printf(" Votre fraction n'est pas periodique.\n");
                        }
                        else
                        {
                            longueur_periode=1;
                        }
                    }

                   }

                   printf("\n*******************************************************************************************\n");

                   p=N_i[0]-1;
                   j=1;
                   while((D[0][p-j]==1)&&(j<p))
                   {
                     j++;
                   }

                   if(j>=quotient(N,2))
                   {
                     longueur_periode=0;
                     printf(" Le resultat de votre quotient est un nombre entier.\n");
                     printf(" Votre fraction n'est pas periodique.\n");
                   }

                  i=0;
                  while(i<10)
                    {
                      if(N_i[i]>1)
                      {
                          j=0;
                          while((D[i][j]==D[i][j+1])&&(j<N_i[i]-1))
                            {
                                j++;
                                /*printf("Valeurs de N_%d[%d]=%d et j= %d\n",i,i,N_i[i],j);*/
                            }
                          if(j==N_i[i]-2)
                          {
                              L_i[i]=D[i][j];
                              /*printf(" Valeur de longueur periode L_%d[%d] = %d.\n",i,i,L_i[i]);*/
                              longueur_periode=L_i[i];
                          }
                          i++;
                      }

                      else
                      {
                          i++;
                      }
                    }




                 /*  for(i=0;i<10;i++)
                   {
                       for(j=0;j<N_i[i]-1;j++)
                       {
                           p=D[i][j];
                           printf("D[%d][%d] = %d\n",i,j,p);
                       }
                   }*/







                 for(i=0;i<10;i++)
                   {


                       p=N_i[i];


                       for(j=0;j<p-2-k+1;j++)
                       {

                           for(k=1;k<=p-2-j;k++)
                           {
                               if(((D[i][j]==D[i][j+k])&&(D[i][p-3]==D[i][p-3-k]))&&(D[i][j+2]==D[i][j+2+k])&&(D[i][p-4]==D[i][p-4-k]))
                               {
                                   L_i[i]=k;
                                  /*printf(" Valeur de i= %d et nombre de termes à additionner L_%d[%d] = %d. \n",i,i,i,k);*/

                                  j=p-2-k+1;

                               }
                              else
                               {
                                  j++;
                               }
                           }
                       }

                   }







               for(i=0;i<10;i++)
               {
                   l=0;
                   if(L_i[i]!=0)
                   {
                       for(j=0;j<L_i[i];j++)
                       {

                            l=l+D[i][j];

                       }
                       printf(" Avec le chiffre %d, la periode comporte %d chiffre(s).\n",i,l);
                   }


               }




               k=1
               ;
               while((k<10)&&(N_i[k]==0))
               {
                 k++;
               }

               if(((k==0)&&(N_i[k]==0))||(k==10))
               {
                   longueur_periode=0;
               }

               else
               {
                   l=0;
                   for(j=0;j<L_i[k];j++)
                   {


                           l=l+D[k][j];

                   }
                   /*printf(" Avec le chiffre %d, la periode comporte %d chiffres.\n",k,l);*/
               }


               longueur_periode=l;


                printf("\n");
                printf("*********************************************************************************************************************\n");
                printf(" La fraction que vous avez saisie est periodique.\n");
                printf(" Sa periode comporte %d chiffre(s)\n",longueur_periode);
                printf(" Voici sa periode :\n\n");




                k=0;
                while((T[k]==0)&&(k<N))
                {
                    k++;

                }



                if(k==0)
                {

                  printf(" ");
                  for(i=0;i<longueur_periode;i++)
                  {
                    printf(" %d",T[i+k]);
                  }
                   printf("\n");
                   printf("*********************************************************************************************************************\n");
                   printf("\n $$$$$$ Fin du programme $$$$$$\n");
                }

                else
                {
                    printf(" ");
                    for(i=0;i<longueur_periode;i++)
                  {
                    printf(" %d",T[i+k-1]);
                  }
                  printf("\n");
                  printf("*********************************************************************************************************************\n");
                  printf("\n $$$$$$ Fin du programme. $$$$$$\n");
                }



       }


  int main()
        {

         int a=0;
         int b=0;
         int i=0;

         for(i=0;i<1;i++)

         {
          int T[N];
          initialisation_tableau(T);
          printf("Ce programme vous permet de connaître la période d'un nombre rationnel a/b ,avec b#0.\n");
          printf(" Entrez le numerateur a =\n");
          scanf("%d",&a);
          printf(" Entrez le denominateur b =\n");
          scanf("%d",&b);
          printf("************************************************\n");
          printf(" Vous avez saisi la fraction %d/%d\n\n",a,b);
          printf("**************************************************************************************************************************\n");
          printf(" Voici le developpement decimal de votre fraction :\n\n");
          n_decimales(a,b,T);

          Analyse_Decimales(T);
         }
          return(1);
        }
