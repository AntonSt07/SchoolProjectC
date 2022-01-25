#include <stdio.h>
#include <string.h>

#define maxbrp 20
typedef struct{
    char name[30];
    int num;
    int marks[maxbrp];
    float avr;
} Tstudent;

void mywrite(char *filename);
void myread(char *filename);
void myadd(char *filename);
void schoolership(char *filename);
void myexam(char *filename);

int main(void)
{
    int op;
    char filename[80];
    printf("\nFile name:");
    scanf("%s",filename);
    do{
    printf("\n1. Zapis");
    printf("\n2. Read");
    printf("\n3. Add");
    printf("\n4. Change file");
    printf("\n5. See who will get scholarship");
    //printf("\n6. See who will have corrective exam");
    printf("\n6. Exit\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1: mywrite(filename);break;
        case 2: myread(filename); break;
        case 3: myadd(filename); break;
        case 4: printf("Filename:"); scanf("%s",filename);break;
        case 5: schoolership(filename); break;
        //case 6: myexam(filename); break;
        case 7: printf("\n5.");break;
        default: printf("\nIncorrect choice!");break;
    }


    }while(op!=6);
}


void mywrite(char *filename)
{
    FILE *f;
    Tstudent s;
    int i;
    char *p;
    int n = 0;
    char yes='y';
    if(f=fopen(filename,"r"))
    {
        fclose(f);
        printf("File exists! Overwrite? y/n:");
        getchar();
        scanf("%c",&yes);
    }
    if(yes!='y')return;

    if(f=fopen(filename,"w"))
    {
        do
        {
            printf("Num (0-end):");scanf("%d",&s.num);
            if(s.num==0)break;
            getchar();
            printf("Name: ");
            fgets(s.name,29,stdin);
            if(p=strchr(s.name,'\n'))*p='\0';
            s.avr=0;
            for(i=0;i<maxbrp;i++)
            {
                printf("Mark (0-end):");scanf("%d",&s.marks[i]);
                if(s.marks[i]==0)break;
                s.avr+=s.marks[i];
            }
            if(i)s.avr=s.avr/i;
            fwrite(&s,sizeof(s),1,f);
        }while(1);

        fclose(f);
    }
    else printf("Error opening file for writing!");

}

void myread(char *filename)
{
    FILE *f;
    Tstudent s;
    int i;
    if(f=fopen(filename,"r"))
    {
        while(!feof(f))
        {
            if(fread(&s,sizeof(s),1,f))
            {
                printf("\n%2d %-30s",s.num,s.name);
                for(i=0;i<maxbrp;i++)
                {
                    if(s.marks[i]==0)break;
                    printf("%2d",s.marks[i]);
                }
                printf("%6.2f",s.avr);
            }
        }
        fclose(f);
    }
    else printf("Error opening file for reading!");

}



void myadd(char *filename)
{
    FILE *f;
    Tstudent s;
    int i;
    char *p;

    if(f=fopen(filename,"r+"))
    {
    while(!feof(f))
    {
        fread(&s,sizeof(s),1,f);
    }

    do
    {
        printf("Num (0-end):");scanf("%d",&s.num);
        if(s.num==0)break;
        getchar();
        printf("Name: ");
        fgets(s.name,29,stdin);
        if(p=strchr(s.name,'\n'))*p='\0';
        s.avr=0;
        for(i=0;i<maxbrp;i++)
        {
        printf("Mark (0-end):");scanf("%d",&s.marks[i]);
        if(s.marks[i]==0)break;
        s.avr+=s.marks[i];
        }
        if(i)s.avr=s.avr/i;
        fwrite(&s,sizeof(s),1,f);
    }while(1);

    fclose(f);
    }
    else printf("Error opening file for reading!");
}


void schoolership(char *filename){
    FILE *f;
    Tstudent s;
    int i;
    if(f=fopen(filename,"r"))
    {
        while(!feof(f))
        {
            if(fread(&s,sizeof(s),1,f))
            {
              if(s.avr >= 5.50){
                printf("\n%s", s.name);
              } 
            }
        }
        fclose(f);
    }
    else printf("Error opening file for reading!");
}


/*void myexam(char *filename){
    FILE *f;
    Tstudent s;
    int i, ok;
    if(f=fopen(filename,"r"))
    {
        while(!feof(f))
        {
            if(fread(&s,sizeof(s),1,f))
            {
              for(i = 0; ????; i++){
                if(s.marks[i] < 3){
                  printf("%d", s.marks[i]);
                  ok = 1;
                }
                else {
                  ok = 0;
                  printf("%d", s.marks[i]);
                }
              }
              if(ok) printf("%s", s.name); 
            }
        }
        fclose(f);
    }
    else printf("Error opening file for reading!");
}
*/