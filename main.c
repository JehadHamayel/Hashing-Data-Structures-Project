//Jehad Hamayel
//1200348
//sec: 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define numChar 40
#define numOfTopics 20
#define numOfCharInLine 200

struct Courses //Define a new type of Courses data
{
    char courseName[numChar];
    char courseCode[numChar];
    char department[numChar];
    char topics [numOfTopics][numChar];
    int creditHours;
    int numOftopics ;
    char state;//E Or NULL=EMPTY, O=OCCUPIED, D=DELETED.

};
typedef struct Courses* hTable;//Define a new variable type name


int isInteger(char []);//Method to Check if the Integer
int smallestPrimeNumber (int );//Method to find the smallest prime number after the entered number. If it is a prime number, return it
int isPrimNumber (int );//Method is checking if it is prime number or not
void readCoursFile ();//Method reads the file and stores the data
int hashCode(char [],unsigned int ) ;//Method to find a unique index of the course in the table
void insertQuTable(hTable);//Method to add the course in the Quadratic table according to its index, and if the load factor is greater than 0.7, it will rehash
void insertDoTable(hTable);//Method to add the course in the Double table according to its index, and if the load factor is greater than 0.7, it will rehash
int hashCodeP(char[],unsigned int ) ;//Method for finding a special number in the double equation
void printQHashedTable();//Method for printing the Quadratic Table
void printDHashedTable();//Method for printing the Double Table
double getLoadFactors(hTable* ,unsigned int );//Method to find the Load Factors
void printLFAndSOT();//Method to Print Load Factors and Size of Tables
int getNumOfElement(hTable* ,unsigned int  );//Method to print Load Factors and Size Of Table
void printUsedHashFunctions();//Method for typing the Functions used in Hashing
void insertNewCourse ();//Method to add a new course from the user
void searchInQ(char []);//Method to search for course in Quadratic Table
void searchInD(char []);//Method to search for course in Double Table
void compareInTermsOfCollisions();//Method for comparing the two special methods in the hashimg
void deleteASpecific(hTable * ,unsigned int ,char []);//Method to delete a course according to its name
void saveAllWords ();//Method to print the data from Double Table in the file
//Auxiliary variable in printing
int print =0;
//Auxiliary variable in compareing
int numOfCollisionsQ=0;
int numOfCollisionsD=0;
//Primitive variables for the size of the tables
unsigned int  sizeOfTableQ =7;
unsigned int  sizeOfTableD =7;
//Pointers on Tables
hTable * pointQTa=NULL;
hTable * pointADTa=NULL;
int main()
{
    printf("-------------------------------------<<<<<<Welcome to my project>>>>>>-------------------------------------\n\n");
    char opch[10];
    int True=1,i;
    hTable quadraticTable [sizeOfTableQ];//Create Array with Size
    pointQTa = quadraticTable;//Pointer points on the Quadratic Array
    for(i=0;i<sizeOfTableQ;i++){
        quadraticTable[i]=NULL;//NULL = EMPTY
    }

    hTable doubleTable [sizeOfTableD];//Create Array with Double Size
    pointADTa = doubleTable;//Pointer points on the Array
    for(i=0;i<sizeOfTableD;i++){
        doubleTable[i]=NULL;//NULL = EMPTY
    }
    readCoursFile ();
    while(True) //Create a loop that displays options for operations and call functions.
    {
        printf("Enter the number of the option that you want:\n\n");
        printf("1. Print hashed tables.\n");
        printf("2. Print out table size and the load factor.\n");
        printf("3. Print out the used hash functions.\n");
        printf("4. Insert a new record to hash table.\n");
        printf("5. Search for a specific word\n");
        printf("6. Delete a specific record.\n");
        printf("7. Compare between the two methods in terms of number of collisions occurred.\n");
        printf("8.Save hash table back to a file named saved_courses.txt\n");
        printf("9. exit.\n\n");
        printf("Choose an option:");

        fflush(stdin);//In order not to take Inter as a character
        gets(opch);
        if(isInteger(opch)) //Check if the entry is a number
        {
            int op=atoi(opch);
            printf("\n-------------------------------------------------------------\n\n");
            switch(op)
            {
            case 1:
                printf("Quadratic Probing Table:\n\n");
                printQHashedTable();//Calling print Quadratic Hashed Table Method
                 printf("-------------------------------------------------------------\n");
                printf("\nDouble Hashing Table:\n\n");
                printDHashedTable();//Calling  print Double Hashed Table Method
                 printf("-------------------------------------------------------------\n\n");
                break;
            case 2:printLFAndSOT();//Calling Print Load Factors and Size of Tables Method
             printf("-------------------------------------------------------------\n\n");
                break;
            case 3:printUsedHashFunctions();//Calling print Used Hash Functions Method
                printf("-------------------------------------------------------------\n\n");
                break;
            case 4:insertNewCourse();//Calling insert New Course Method
                printf("-------------------------------------------------------------\n\n");
                break;
            case 5:
                while(1){
                        printf("\nEnter which Table you want to search in :");
                        printf("\n1-Quadratic Table\n");
                        printf("2-Double Table\n");
                         printf("your choise:");
                    char cho[15];
                    fflush(stdin);//In order not to take Inter as a character
                    gets(cho);
                    if(isInteger(cho)) //Check if the entry is a number
                    { char choi[30];
                        if(atoi(cho)==1){
                                printf("Enter The course name that you want :");
                                fflush(stdin);//In order not to take Inter as a character
                                gets(choi);
                                searchInQ(choi);//Calling search in Quadratic Table Method
                                break;
                            }else if(atoi(cho)==2){
                                printf("Enter The course name that you want :");
                                fflush(stdin);//In order not to take Inter as a character
                                gets(choi);
                                searchInD(choi);//Calling search in Double Table Method
                                break;
                            }
                            else
                                printf("Please choose 1 or 2 :");
                    }
                    else
                        printf("Please Enter Number:");
                }
                 printf("-------------------------------------------------------------\n\n");
                break;
            case 6:
                        printf("Enter The course name that you want to Delete :");
                                char name[30];
                                fflush(stdin);//In order not to take Inter as a character
                                gets(name);
                                printf("\nQuadratic Table:\n");
                                deleteASpecific(pointQTa,sizeOfTableQ,name);//Calling  delete a Specific Course Method
                                printf("-------------------------------------------------------------\n\n");
                                printf("Double Table:\n");
                                deleteASpecific(pointADTa,sizeOfTableD,name);//Calling  delete a Specific Course Method
                                printf("-------------------------------------------------------------\n\n");

                break;
            case 7:
                    compareInTermsOfCollisions();//Calling   compare in Terms Of Collisions Method
                     printf("-------------------------------------------------------------\n\n");
                break;
            case 8:saveAllWords ();//Calling  save all Words Method
                     printf("The data has been printed on the file\n\n");
                    printf("-------------------------------------------------------------\n\n");

                break;
            case 9://exit the Program
                    printf("-------------------------------------<<<<<<Thank You, Goodbey>>>>>>-------------------------------------\n\n");
                    return 0;
                break;
            default :
                printf("Choose a correct number\n\n");
                printf("-------------------------------------------------------------\n\n");
            }
        }
        else
        {
            printf("\nPlease Choose a correct number\n\n");
            printf("-------------------------------------------------------------\n\n");
        }

    }

}
int isInteger(char word[]){ //Method to check if he was trafficked or not
    int index ;
    for(index=0; index<strlen(word); index++)
    {
        if(!isdigit(word[index]))
            return 0;
    }
    return 1;
}
int smallestPrimeNumber (int x){
    while(1){
        if(isPrimNumber(x))
            return x ;
        else
            x++;
    }
}
int isPrimNumber (int x){
    if(x == 1|| x ==0)
        return 0;
    int i;
    for(i=2;i<=x/2;i++){
        if(x%i==0)
            return 0;
    }
    return 1;
}
void readCoursFile (){
     FILE *in;//Define file
    char inf[numOfCharInLine],*token;
    int isEmpty=1,index2,index;
    in = fopen("offered_courses.txt","r");//Make the file in read
    if(in!=NULL) //Check if the file exists
    {

       while(fgets(inf,numOfCharInLine,in)!=NULL) //while loop for reading from file
        {
            if(!print){
                printf("The data that was in the file:\n\n");
                printf("Course Name                    Credit Hours   Course Code          Department           Topics\n\n");
                print=1;
            }
            hTable htemp = (hTable)malloc(sizeof(struct Courses));
            token = strtok(inf,":");//String up to :
            strcpy(htemp->courseName,token);//Copy the string and place it in the required variable
            token = strtok(NULL,"#");//String up to #
            htemp->creditHours=atoi(token);////Converting a String to an Intger
            token = strtok(NULL,"#");//String up to #
            strcpy(htemp->courseCode,token);//Copy the string and place it in the required variable
            token = strtok(NULL,"/");//String up to /
            strcpy(htemp->department,token);//Copy the string and place it in the required variable
            token = strtok(NULL,",\n");//String up to /and \n
            index = 0;
            while(token != NULL) //Loop for storing topics
            {
                strcpy(htemp->topics[index],token);//Copy the string and place it in the required variable
                index++;
                token = strtok(NULL,",\n");//String up to /and \n
            }
            htemp->numOftopics = index;

            //print what has been read
            printf("%-30s %-12d   %-20s %-20s/",htemp->courseName,htemp->creditHours,htemp->courseCode,htemp->department);
            //Print what has been read from the topics
            for(index2=0; index2<(htemp->numOftopics-1); index2++)
            {

                printf("%s,",htemp->topics[index2]);
            }
            printf("%s\n",htemp->topics[index2]);
            insertQuTable(htemp);
            insertDoTable(htemp);
            isEmpty=0;

        }
        if(isEmpty) //Check if the file is empty or not
        {
            printf("\n-------------------------------------------------------------\n\n");
            printf("The File is empty\n\n");

        }
       else{
        printf("\n-------------------------------------------------------------\n\n");
        printf("The file has been read successfully\n\n");}
        fclose(in);//close file
    }
    else
        printf("File not found\n\n");
    fclose(in); //close file

}
int hashCode(char key[],unsigned int sizeOfTable) {
//Finding a special index
  unsigned int hash_val = 0;
    while ( *key != '\0')
        hash_val = (hash_val << 5 ) + *key++;
    if( hash_val < 0 )
        hash_val += sizeOfTable;
    return ( hash_val % sizeOfTable);
}
void insertQuTable(hTable temp){

    int i,index=0;
    for(i=0;i<sizeOfTableQ;i++){//loop Finding Unique Index
            index=(hashCode(temp->courseName,sizeOfTableQ)+(i*i))%sizeOfTableQ;//Unique index finding equation

            if(pointQTa[index]==NULL || pointQTa[index]->state=='D'){//Check if there is a possibility to add a course
                if(pointQTa[index]==NULL)
                    pointQTa[index]=(hTable)malloc(sizeof(struct Courses));//Reserve in memory
                //Copy the added data
                strcpy(pointQTa[index]->courseName,temp->courseName);

                strcpy(pointQTa[index]->courseCode,temp->courseCode);

                strcpy(pointQTa[index]->department,temp->department);

                pointQTa[index]->creditHours=temp->creditHours;
                int index3 ,index2;
                    for(index2=0; index2<numOfTopics; index2++)
                    {
                    strcpy(pointQTa[index]->topics[index2],"");
                    }

                for(index3 =0; index3<temp->numOftopics; index3++)
                {
                strcpy( pointQTa[index]->topics[index3],temp->topics[index3]);
                }

                pointQTa[index]->numOftopics=temp->numOftopics;
                //State change
                pointQTa[index]->state = 'O';
                //Check the Load Factor For Rehashing
                if(getLoadFactors(pointQTa,sizeOfTableQ)>0.7){
                    //Rehashing Operation
                    unsigned int previseSize = sizeOfTableQ;
                    hTable* previseQTable=pointQTa;
                    sizeOfTableQ = smallestPrimeNumber(2*sizeOfTableQ);//new Size
                    hTable* newQuadraticTable=(hTable*)malloc(sizeOfTableQ*sizeof(struct Courses)) ;
                    int i;
                    for(i=0;i<sizeOfTableQ;i++){
                        newQuadraticTable[i]=NULL;//NULL = EMPTY
                    }
                    pointQTa = newQuadraticTable;
                    for(i=0;i<previseSize;i++){
                        if(previseQTable[i]!=NULL){
                            insertQuTable(previseQTable[i]);
                        }
                    free(previseQTable[i]);

    }


                    }

        break;
        }
        else
            numOfCollisionsQ++;
    }
}
void insertDoTable(hTable temp){
int i,index;
    for(i=0;i<sizeOfTableD;i++){
        index=(hashCode(temp->courseName,sizeOfTableD)+(i*hashCodeP(temp->courseName,sizeOfTableD)))%sizeOfTableD;

            if(pointADTa[index]==NULL || pointADTa[index]->state=='D'){//Check if there is a possibility to add a course
                if(pointADTa[index]==NULL)
                    pointADTa[index]=(hTable)malloc(sizeof(struct Courses));//Reserve in memory
                        //Copy the added data
                strcpy(pointADTa[index]->courseName,temp->courseName);
                strcpy(pointADTa[index]->courseCode,temp->courseCode);
                strcpy(pointADTa[index]->department,temp->department);
                pointADTa[index]->creditHours=temp->creditHours;
                int index3 ,index2;
                    for(index2=0; index2<numOfTopics; index2++)
                    {
                    strcpy(pointADTa[index]->topics[index2],"");
                    }
                for(index3 =0; index3<temp->numOftopics; index3++)
                {
                strcpy( pointADTa[index]->topics[index3],temp->topics[index3]);
                }
        pointADTa[index]->numOftopics=temp->numOftopics;
        pointADTa[index]->state='O';//State change
        //Rehashing Operation
        if(getLoadFactors(pointADTa,sizeOfTableD)>0.7){

                    unsigned int previseSize = sizeOfTableD;
                    hTable* previseDTable=pointADTa;
                    sizeOfTableD = smallestPrimeNumber(2*sizeOfTableD);//new Size
                    hTable* newDoubleTable=(hTable*)malloc(sizeOfTableD*sizeof(struct Courses)) ;
                    int i;
                    for(i=0;i<sizeOfTableD;i++){
                        newDoubleTable[i]=NULL;//NULL = EMPTY
                    }
                    pointADTa = newDoubleTable;
                    for(i=0;i<previseSize;i++){
                        if(previseDTable[i]!=NULL){
                            insertDoTable(previseDTable[i]);
                        }
                    free(previseDTable[i]);

    }
                    }
        break;
        }else
            numOfCollisionsD++;
    }

}
int hashCodeP(char key[],unsigned int sizeOfTable) {
    //Find a unique number to add
  unsigned int hash_val = 0;
    while ( *key != '\0')
        hash_val = (hash_val << 5 ) + *key++;
    if( hash_val < 0 )
        hash_val += sizeOfTable;
    return ( 7 - hash_val % 7);
}
void printQHashedTable(){
    //print Quadratic Hashed Table
    int i;
    int c = 1;
    for(i=0;i<sizeOfTableQ;i++){
            if(pointQTa[i]!=NULL && pointQTa[i]->state=='O'){
                printf("Index %-3d %-30s",i,pointQTa[i]->courseName);}
            else
                printf("Index %-3d Empty                         ",i);
            if(c%5==0)
                printf("\n");
            c++;
    }
    printf("\n\n");

}
void printDHashedTable(){
    //print Double Hashed Table
    int i;
    int c = 1;
    for(i=0;i<sizeOfTableD;i++){
            if(pointADTa[i]!=NULL&&pointADTa[i]->state=='O' )
                printf("Index %-3d %-30s",i,pointADTa[i]->courseName);
            else
                printf("Index %-3d Empty                         ",i);
            if(c%5==0)
                printf("\n");
            c++;
    }
    printf("\n\n");

}
double getLoadFactors(hTable* table,unsigned int sizeOfTable){
    //get the Load Factor
    return ((double)getNumOfElement(table,sizeOfTable))/sizeOfTable;
}
void printLFAndSOT(){
    printf("Table Size Of Quadratic Probing Table = %d \nLoadFactors = %lf\n\n",sizeOfTableQ,getLoadFactors(pointQTa,sizeOfTableQ));
    printf("Table Size Of Double Hashing Table = %d \nLoadFactors = %lf\n\n",sizeOfTableD,getLoadFactors(pointADTa,sizeOfTableD));
}
int getNumOfElement(hTable* table,unsigned int sizeOfTable ){
    //Get Number Of Elements
    int i ,counter =0;
    for(i=0;i<sizeOfTable;i++){
        if(table[i]!=NULL)
            counter++;
    }

    return counter;
}
void printUsedHashFunctions(){
    printf("Quadratic Probing Functions: \n\n-------->  hi(key) = [h(key) + i^2] %% tableSize , for i = 0, 1, . . . , tableSize - 1\n");
    printf("which -> h(key) =hash_value %% size Of Table \n");
   printf("____________________________________________________\n\n");
    printf("Double Hashing Functions: \n\n-------->  hi(key) = [h(key) + i*hp(key)]%% tableSize for i = 0, 1, . . . , tableSize - 1\n");
    printf("which -> hp(key) = 7 - key %% 7\n\n");
}
void insertNewCourse (){
    hTable htemp = (hTable)malloc(sizeof(struct Courses));
    //Ask the user to enter the course information
    printf("Enter Course Name:");
    fflush(stdin);
    gets(htemp->courseName);
    printf("Enter CreditHours:");
    char word[15];
    fflush(stdin);
    gets(word);
    while(!isInteger(word))
    {
        printf("Please Enter valid number:");
        fflush(stdin);
        gets(word);
    }
    htemp->creditHours= atoi(word);
    printf("Enter CourseCode:");
    char code[15];
    fflush(stdin);
    gets(code);
    strcpy(htemp->courseCode,code);
    printf("Enter Department Name:");
    fflush(stdin);
    gets(htemp->department);
    char d[15] ;
    printf("Enter topic if you want to stop enter -1:");
    fflush(stdin);
    gets(d);
    int index =0;
    while(strcmp(d,"-1")==0){
            printf("Enter topic if you want to stop enter -1 you have to Enter at least one topic:");
            fflush(stdin);
            gets(d);
    }
    while(strcmp(d,"-1")!=0)
    {

        strcpy(htemp->topics[index],d);
        index ++;
        printf("Enter topic if you want to stop enter -1:");
        fflush(stdin);
        gets(d);
    }
    htemp->numOftopics=index;
    printf("\nThe Course has added successfully \n\n");
    insertQuTable(htemp);
    insertDoTable(htemp);

}
void searchInQ(char key[]){
    //search in Quadratic Table
    int i,found =0;
    for(i=0;i<sizeOfTableQ;i++){
     int index=(hashCode(key,sizeOfTableQ)+(i*i))%sizeOfTableQ;
     if(pointQTa[index]!=NULL)
      if(pointQTa[index]->state=='O'&&strcmp(key,pointQTa[index]->courseName)==0){
        printf("\nCourse Found --> %s  in Index -->%d\n\n",key,index);
        found=1;
        break;
     }
}
if(found==0)
     printf("Course Not Found --> %s\n\n",key);
}
void searchInD(char key[]){
  //  search in Double Table
    int i,found =0;
    for(i=0;i<sizeOfTableD;i++){
     int index=(hashCode(key,sizeOfTableD)+(i*hashCodeP(key,sizeOfTableD)))%sizeOfTableD;

     if(pointADTa[index]!=NULL)
      if(pointADTa[index]->state=='O'&&strcmp(key,pointADTa[index]->courseName)==0){
        printf("\nCourse Found --> %s  in Index -->%d\n\n",key,index);
        found=1;
        break;
     }
}
if(found==0)
     printf("Course Not Found --> %s\n\n",key);
}
void compareInTermsOfCollisions(){
    //compare in Terms Of Collisions
    printf("%d --> number Of Collisions Quadratic Probing,  %d --> number Of Collisions in Double Hashing\n\n",numOfCollisionsQ,numOfCollisionsD);
    if(numOfCollisionsQ>numOfCollisionsD)
        printf("Double Hashing better than Quadratic Probing\n\n");
    else if (numOfCollisionsQ<numOfCollisionsD)
        printf("Quadratic Probing better than Double Hashing \n\n");
    else
        printf("Quadratic Probing same as Double Hashing \n\n");

}
void deleteASpecific(hTable * table,unsigned int sizeOfTable,char key[]){
    //delete a course according to its name
    int i,found =0,index;
    for(i=0;i<sizeOfTable;i++){
    if(table == pointQTa)
      index=(hashCode(key,sizeOfTable)+(i*i))%sizeOfTable;
    else
        index=(hashCode(key,sizeOfTable)+(i*hashCodeP(key,sizeOfTable)))%sizeOfTable;
    if(table[index]!=NULL)
      if((table[index]->state=='O'&&strcmp(key,table[index]->courseName)==0)){
        printf("\nCourse Found and Deleted--> %s  in Index -->%d\n\n",key,index);
        table[index]->state='D';
        found=1;
        break;
     }
}
if(found==0)
     printf("Course Not Found --> %s\n\n",key);
}
void saveAllWords (){ //function definition.
    //Method for writing to a file for the data
    FILE * out;
    out = fopen("saved_courses.txt","w");
    int i;
    for(i=0;i<sizeOfTableD;i++){
    if(pointADTa[i]!=NULL){
     fprintf(out,"%s:%d#%s#%s/",pointADTa[i]->courseName,pointADTa[i]->creditHours,pointADTa[i]->courseCode,pointADTa[i]->department);
        int index;
    for(index =0; index<(pointADTa[i]->numOftopics-1); index++)
    {
        fprintf(out,"%s,",pointADTa[i]->topics[index]);
    }
    fprintf(out,"%s\n",pointADTa[i]->topics[index]);
    }
    }
    fclose(out);
}
