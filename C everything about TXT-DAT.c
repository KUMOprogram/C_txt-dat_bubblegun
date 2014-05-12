#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct lesson{
  int lessonId;    
  char lessonname[40];      
  int weekhours;
  int semester;
  char semestername[10];
};

int main (void)
{
     system("color f1");
     
     int i,j,n,something;
     struct lesson lessons;
     
     FILE *less;                                //create less file
     FILE *counter;                             //create counter file
     
     less=fopen("dats/lesson.dat","r");
     if (less==NULL)
     {
                    system("md dats");                      //md gia fakelo
                    less=fopen("dats/lesson.dat","w");      //lessons se dat
                    counter=fopen("dats/counter.txt","w");  //metrhths se txt
                    fprintf(counter,"%i",0);                //arxikopoihsh
                    fclose(counter);
     }
     fclose(less);

_Bool flag;
while(flag)
{
system("cls");

	 int a;
	 printf("*******************************************************************************\n\n");
     printf("                      reset file ---------------------- 1\n");
     printf("                      add new ------------------------- 2\n");
     printf("                      print in screen ----------------- 3\n");
     printf("                      bubble based on hours per week -- 4\n");
     printf("                      find a lesson by ID ------------- 5\n");
     printf("                      change something ---------------- 6\n");
     printf("                      delete a lesson ----------------- 7\n");
     printf("                      end program --------------------- 8\n\n");
     printf("*******************************************************************************\n");
     printf("                                 Choice: ");
     scanf("%i",&a);
     printf("*******************************************************************************\n");
     
     if (a==1)
     {
          less=fopen("dats/lesson.dat","w");
          counter=fopen("dats/counter.txt","w");
          fprintf(counter,"%i",0);
          fclose(less);
          fclose(counter);

     printf("\n                   EKANE RESET EPITUXIA sto dats/lesson.dat\n");
     printf("                   EKANE RESET EPITUXIA sto dats/counter.txt\n");
     system("pause");
	 }
     
     if (a==2)
     {
     counter=fopen("dats/counter.txt","r");
        fscanf(counter,"%i",&j);      //counter
     fclose(counter);
                 
        printf("                          dwse ID ma8hmatos %i: ", j+1);  //read
        scanf("%i", &lessons.lessonId);
        printf("                          dwse onoma ma8hmatos %i: ", j+1);
        scanf("%s", lessons.lessonname);
        printf("                          dwse wres ma8hmatos %i: ", j+1);
        scanf("%i", &lessons.weekhours);
        printf("                          dwse e3amino ma8hmatos (ari8mhtika) %i: ", j+1);
        scanf("%i", &lessons.semester);
        printf("                          dwse e3amhno ma8hmatos (earino/xeimerino) %i: ", j+1);
        scanf("%s", lessons.semestername);
        
        less=fopen("dats/lesson.dat","a");   //save
            fwrite(&lessons,sizeof(struct lesson),1,less);
        fclose(less);
     
     j++;   
     counter=fopen("dats/counter.txt","w");   //counter+1
        fprintf(counter,"%i",j);
     fclose(counter);
     
     printf("\n                      APO8HKEYTHKE ME EPITUXIA sto dats/lesson.dat\n");
     system("pause");
     }
     
     if (a==3)
     {
     counter=fopen("dats/counter.txt","r");
        fscanf(counter,"%i",&j);      //counter
     fclose(counter);
     
     less=fopen("dats/lesson.dat","r");  //open to less
		 for (i=0; i<j; i++)
         {   
			   something=fread(&lessons,sizeof(struct lesson),1,less);
               printf("                          ID ma8hmatos %i: %i\n", i+1, lessons.lessonId);
               printf("                          onoma ma8hmatos %i: %s\n", i+1, lessons.lessonname);
               printf("                          wres ma8hmatos %i: %i\n", i+1, lessons.weekhours);
               printf("                          e3amhno ma8hmatos %i: %i\n", i+1, lessons.semester);
               printf("                          e3amhno ma8hmatos %i: %s\n", i+1, lessons.semestername);
               printf("                ------------------------------------------------------\n");
               
         }      
	 fclose(less);
	 
     system("pause");
     }
     
     if (a==4)
     {
     counter=fopen("dats/counter.txt","r");
        fscanf(counter,"%i",&j);      //counter
     fclose(counter);
     
     struct lesson les[j];
     
     less=fopen("dats/lesson.dat","r");  //open to less
      if (less!=NULL)
      {
         for (i=0; i<j; i++)
         {   
               something=fread(&lessons,sizeof(struct lesson),1,less);
               les[i]=lessons;
         }      
      }
     fclose(less);
     
        struct lesson bubbla;
        for(i=0; i<j-1; i++)     //squirtle bubble gun
        {
              for (n=j-1; n>i; n--)
              {
                  if (les[n].weekhours<les[n-1].weekhours)
                  {
                     bubbla.lessonId=les[n].lessonId;
                     strcpy(bubbla.lessonname,les[n].lessonname);
                     bubbla.weekhours=les[n].weekhours;
                     bubbla.semester=les[n].semester;
                     strcpy(bubbla.semestername,les[n].semestername);
                     
                     les[n].lessonId=les[n-1].lessonId;
                     strcpy(les[n].lessonname,les[n-1].lessonname);
                     les[n].weekhours=les[n-1].weekhours;
                     les[n].semester=les[n-1].semester;
                     strcpy(les[n].semestername,les[n-1].semestername);
                     
                     les[n-1].lessonId=bubbla.lessonId;
                     strcpy(les[n-1].lessonname,bubbla.lessonname);
                     les[n-1].weekhours=bubbla.weekhours;
                     les[n-1].semester=bubbla.semester;
                     strcpy(les[n-1].semestername,bubbla.semestername);
                  }
              }
        }

        for (i=0; i<j; i++)
	    {
		 	   printf("                       %io\n", i+1);
		 	   printf("                      =====\n");
			   printf("                      ID ma8hmatos: %i\n", les[i].lessonId);
               printf("                      onoma ma8hmatos: %s\n", les[i].lessonname);
               printf("                      wres ma8hmatos: %i\n", les[i].weekhours);
               printf("                      e3amhno ma8hmatos: %i\n", les[i].semester);
               printf("                      e3amhno ma8hmatos: %s\n", les[i].semestername);
               printf("                ------------------------------------------------------\n");
      	}

	 system("pause");
     }
     
     if (a==5)
     {
     counter=fopen("dats/counter.txt","r");
        fscanf(counter,"%i",&j);      //counter
     fclose(counter);

     struct lesson les[j];

     less=fopen("dats/lesson.dat","r");  //open to less
      if (less!=NULL)
      {
         for (i=0; i<j; i++)
         {
               something=fread(&lessons,sizeof(struct lesson),1,less);
               les[i]=lessons;
         }
      }
     fclose(less);
     
     int find;
     printf("                      poio ID 8es na breis: ");  //&find
	 scanf("%i", &find);
	 _Bool flagerstein=1;
	 
	 for (i=0; i<j; i++)
	 {
			if (find==les[i].lessonId)
			{
               printf("                      ID ma8hmatos %i: %i\n", i+1, les[i].lessonId);
               printf("                      onoma ma8hmatos %i: %s\n", i+1, les[i].lessonname);
               printf("                      wres ma8hmatos %i: %i\n", i+1, les[i].weekhours);
               printf("                      e3amhno ma8hmatoss %i: %i\n", i+1, les[i].semester);
               printf("                      e3amhno ma8hmatos %i: %s\n", i+1, les[i].semestername);
               printf("                ------------------------------------------------------\n");
			   flagerstein=0;
			}
	 }
	 if (flagerstein==1)
	 {
			printf("                                         @@@ LA8OS ID @@@\n");
	 }

     system("pause");
     }
     
     if (a==6)
     {
     counter=fopen("dats/counter.txt","r");
        fscanf(counter,"%i",&j);      //counter
     fclose(counter);

     struct lesson les[j];

     less=fopen("dats/lesson.dat","r");  //open to less
      if (less!=NULL)
      {
         for (i=0; i<j; i++)
         {
               something=fread(&lessons,sizeof(struct lesson),1,less);
               les[i]=lessons;
         }
      }
     fclose(less);
     
	 int change;
	 printf("                      poianou ID 8es na alla3eis ta stoixeia: ");
	 scanf("%i", &change);       //&change;
     _Bool flagerstein=1;

	 int answer;
	 for (i=0; i<j; i++)
	 {
       if (change==les[i].lessonId)
	   {
			printf("                      onoma ma8hmatos %i: %s\n", i+1, les[i].lessonname);
			printf("              If u want to change press '1' else press something else: ");
			scanf("%i", &answer);
			if (answer==1)
			{
				printf("                      dwse onoma ma8hmatos %i: ", i+1);
        		scanf("%s", les[i].lessonname);
			}
			
        	printf("                ------------------------------------------------------\n");

			printf("                      wres ma8hmatos %i: %i\n", i+1, les[i].weekhours);
			printf("              If u want to change press '1' else press something else: ");
			scanf("%i", &answer);
			if (answer==1)
			{
        		printf("                      dwse wres ma8hmatos %i: ", i+1);
        		scanf("%i", &les[i].weekhours);
			}
			
        	printf("                ------------------------------------------------------\n");

			printf("                      e3amhno ma8hmatos %i: %i\n", i+1, les[i].semester);
			printf("              If u want to change press '1' else press something else: ");
			scanf("%i", &answer);
			if (answer==1)
			{
        		printf("                      dwse e3amino ma8hmatos (ari8mhtika) %i: ", i+1);
        		scanf("%i", &les[i].semester);
			}
			
        	printf("                ------------------------------------------------------\n");

			printf("                      e3amhno ma8hmatos %i: %s\n", i+1, les[i].semestername);
			printf("              If u want to change press '1' else press something else: ");
			scanf("%i", &answer);
			if (answer==1)
			{
        		printf("                      dwse e3amhno ma8hmatos (earino/xeimerino) %i: ", i+1);
        		scanf("%s", les[i].semestername);
			}
		flagerstein=0;
		}
	 }
	 if (flagerstein==1)
	 {
			printf("                              @@@ LA8OS ID @@@\n");
	 }

	 less=fopen("dats/lesson.dat","w");
	 for (i=0; i<j; i++)
	 {
	    fwrite(&les[i],sizeof(struct lesson),1,less);
	 }
     fclose(less);

 	 system("pause");
     }

     if (a==7)
     {
     counter=fopen("dats/counter.txt","r");
        fscanf(counter,"%i",&j);      //counter
     fclose(counter);

     struct lesson les[j];
     
     less=fopen("dats/lesson.dat","r");  //open to less
      if (less!=NULL)
      {
         for (i=0; i<j; i++)
         {
               something=fread(&lessons,sizeof(struct lesson),1,less);
               les[i]=lessons;
         }
      }
     fclose(less);

	 int deleta;
     printf("                          poio ID 8es na diagrapseis: ");  //&deleta
	 scanf("%i", &deleta);
	 _Bool flagerstein=1;

	 int k=0;
	 struct lesson selector[j-1];
	 i=0;
	 while (i<j)
	 {
			something=fread(&les[i],sizeof(struct lesson),1,less);
		    if (deleta==les[i].lessonId)   //ama uparxei to deleta apla agnww thn eggrafh k paw -1 wste na thn pathsw
		    {
		        flagerstein=0;
			}else{
				les[k]=les[i];
				k++;
			}
	 i++;
	 }
	 
	 if (flagerstein==1)
	 {
			printf("                              @@@ LA8OS ID @@@\n");
	 }

	 if (flagerstein==0)
	 {
 		j--;
	 	counter=fopen("dats/counter.txt","w");
        	fprintf(counter,"%i",j);              //counter j meiwmeno kata 1 AMA uphrxe to ID
    	fclose(counter);
    	printf("                      DIAGRADHKE ME EPITUXIA apo to dats/lesson.dat\n");

	 	less=fopen("dats/lesson.dat","w");
	 	for (i=0; i<j; i++)                     //anoigw me "w" to .dat kai grafw ta panta PRIN autou pou afairesa
	 	{
	    	fwrite(&les[i],sizeof(struct lesson),1,less);
	 	}
     	fclose(less);
	 }
	
	 system("pause");
     }
     
     if (a==8)   //termatismos programmatos me flag
     {
			flag=0;
     }
     
     if (a!=1 && a!=2 && a!=3 && a!=4 && a!=5 && a!=6 && a!=7 && a!=8)  //ama balleis malakia...
     {
			printf("                                         @@@ WRONG CHOICE @@@\n");
			printf("                                          put 1 2 3 4 5 6 7 8\n");
			system("pause");
     }
}

return 0;
}
