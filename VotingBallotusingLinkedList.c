#include <stdio.h>  // library for input/output
#include <conio.h>  // library for console functions
#include <string.h> // library for manipulating strings
#include <stdlib.h>  // library which was thought to used for random function but not used can be deleted i am not deleting because i may use it later for updateding this software
#include <windows.h>  // library used for clearing previous output
#include <direct.h>  // library used for making beep sound

void main_menu();  //  function displaying main menu
void voter_insert(); // function used for inserting voter details
void admin();  // function can only be used by password for admin options
void winner(); // function to display winner
void voting();  // function to give vote to a candidate
void show();  // function to display admin options
void stop();  // function called when voter inserts wrong details more than 3 times
void current_result(); //function to show result



typedef struct voter_information
{
  // data part
  char id[10];
  char name[25];
  char birth_date[15];
  char father_name[20];
  char mother_name[20];

  // address part
  struct voter_information * next;


}node;

void displayList(node *head); // function used to display details of voters passing head as parameter to display details.
void checkagain(node *head, char id [20]);  // function to check if the voter who has voted once is trying to vote again


node *head = NULL;

int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0;  // count of votes of individual candidates
int number_of_votes = 0;  // counting number of votes casted in total;
int count = 0;  //keeping count of voter details

int main()
{


  main_menu();  // calling main_menu

  return 0;
}

void main_menu()
{
  count = 0; // intitializing count to be zero so that entering wrong details 3 times by any one voter does not affect other users chances
  system("cls");  // clearing previous output


  printf("\n\n\n");
  printf("\t    --------------------------Welcome to Voting Ballet------------------------\n");

  printf("\n\n\n");

  printf("\t\t\t\t1. VOTER ENTRY ");

  printf("\n\t\t\t\t2. ADMIN PANEL ");

  printf("\n\t\t\t\t3. EXIT");

  printf("\n\n\t\tPLEASE ENTER YOUR CHOICE : ");

  int res;
  scanf("%d", &res);
  printf("\n");

// switch case to manipulate program according to user choice
  switch (res)
  {
    case 1:
    voter_insert();
    break;

    case 2:
    admin();
    break;

    case 3:
    exit(0);


    default :
    printf("Invalid choice");
    _getch();
    main_menu();
  }

}




void voter_insert()
{


  node *temp;  // pointer to create a temporary not attached node
  node *ptr = NULL;  // intitializing ptr pointer to null


  char  id[20], name[25], birth_date[25], f_name[25], m_name [25];  // declaring variabls of same datatype and size to store voter details temporarily.
  system("cls");

  printf("\n\t\tEnter your details registered into the voter id: ");
  printf("\n\t\tEntering wrong details more than 3 times will terminate your entry !!!");
  printf("\n\n");

  printf("\t\tEnter your voter ID :\t\t\t\t ");
  scanf("%s", &id);
  //printf("%s", id);

  printf("\t\tEnter your first name :\t\t\t\t ");
  scanf("%s", &name);
  //printf("%s", name);


  printf("\t\tEnter your Birth date(IN FORMAT DD/MM/YY):\t ");
  scanf("%s", &birth_date);
  //printf("%s", birth_date);


  printf("\t\tEnter your father name :\t\t\t ");
  scanf("%s", &f_name);
//  printf("%s", f_name);

 printf("\t\tEnter your mother's name :\t\t\t ");
 scanf("%s", &m_name);
 //printf("%s", m_name);


temp = (node * ) malloc (sizeof(node));  // allocating memory space for new node


strcpy(temp -> id, id);
//printf("%s ", temp -> id);

strcpy(temp -> name, name);
//printf("%s ", temp -> name);

strcpy(temp -> birth_date, birth_date);
//printf("%s ", temp -> birth_date);

strcpy(temp -> father_name, f_name);
//printf("%s ", temp -> father_name);

strcpy(temp -> mother_name, m_name);
//printf("%s ", temp -> mother_name);


temp -> next = NULL;  // intitializing next part of the node to be null

// checking if the voter is entering authorized details
while (temp != NULL)
{
  if
(
  (strcmp(temp->id , "100001") == 0 && strcmp(temp -> name, "yash") == 0 && strcmp(temp -> birth_date, "06/05/00") == 0 && strcmp(temp-> father_name, "ramchandra") == 0 && strcmp(temp -> mother_name, "roshana") == 0 ) ||
  ( strcmp(temp->id , "100002") == 0 && strcmp(temp -> name, "ram") == 0 && strcmp(temp -> birth_date, "27/09/99") == 0 && strcmp(temp-> father_name, "prabas") == 0 && strcmp(temp -> mother_name, "gita") == 0 ) ||
  ( strcmp(temp->id , "100003") == 0 && strcmp(temp -> name, "abhishek") == 0 && strcmp(temp -> birth_date, "22/01/98") == 0 && strcmp(temp-> father_name, "ramnarayan") == 0 && strcmp(temp -> mother_name, "sarita") == 0 ) ||
  ( strcmp(temp->id , "100011") == 0 && strcmp(temp -> name, "roshana") == 0 && strcmp(temp -> birth_date, "03/02/75") == 0 && strcmp(temp-> father_name, "vinayakrao") == 0 && strcmp(temp -> mother_name, "vatsala") == 0 ) ||
  ( strcmp(temp->id , "100004") == 0 && strcmp(temp -> name, "nikhil") == 0 && strcmp(temp -> birth_date, "14/12/00") == 0 && strcmp(temp-> father_name, "rajesh") == 0 && strcmp(temp -> mother_name, "priyanka") == 0 ) ||
  ( strcmp(temp->id , "100011") == 0 && strcmp(temp -> name, "shweta") == 0 && strcmp(temp -> birth_date, "30/11/98") == 0 && strcmp(temp-> father_name, "ramchandra") == 0 && strcmp(temp -> mother_name, "roshana") == 0 ) ||
  ( strcmp(temp->id , "100005") == 0 && strcmp(temp -> name, "rohan") == 0 && strcmp(temp -> birth_date, "29/03/99") == 0 && strcmp(temp-> father_name, "arun") == 0 && strcmp(temp -> mother_name, "chitra") == 0  ) ||
  ( strcmp(temp->id , "100006") == 0 && strcmp(temp -> name, "aditya") == 0 && strcmp(temp -> birth_date, "01/01/91") == 0 && strcmp(temp-> father_name, "arjun") == 0 && strcmp(temp -> mother_name, "sumitra") == 0  ) ||
  ( strcmp(temp->id , "100007") == 0 && strcmp(temp -> name, "shubham") == 0 && strcmp(temp -> birth_date, "10/06/94") == 0 && strcmp(temp-> father_name, "vinayak") == 0 && strcmp(temp -> mother_name, "radha") == 0  ) ||
  ( strcmp(temp->id , "100008") == 0 && strcmp(temp -> name, "vikcy") == 0 && strcmp(temp -> birth_date, "07/07/99") == 0 && strcmp(temp-> father_name, "ajey") == 0 && strcmp(temp -> mother_name, "kalpana") == 0)  ||
  ( strcmp(temp->id , "100009") == 0 && strcmp(temp -> name, "rawnnie") == 0 && strcmp(temp -> birth_date, "05/09/91") == 0 && strcmp(temp-> father_name, "sharman") == 0 && strcmp(temp -> mother_name, "bhagirathi") == 0 ) ||
  ( strcmp(temp->id , "100010") == 0 && strcmp(temp -> name, "omkar") == 0 && strcmp(temp -> birth_date, "31/01/94") == 0 && strcmp(temp-> father_name, "adinath") == 0 && strcmp(temp -> mother_name, "kaveri") == 0 )

)
  {

    checkagain(head, id);   // checking if the same voter is trying to vote again



    if (head == NULL)  // if the list is cuurently empty, then make temp as first node
    {
      head = temp;
    }

    else  // if the list contains previous nodes then add this new node at the end of the list
    {
      ptr = head;
      while (ptr -> next != NULL)  // going toward the end of the list
      {
        ptr = ptr -> next;
      }

      ptr -> next = temp; // adding temp at the end
    }






    voting();  // allowing voting only after user enters authorized detials


  }




  else
  {

    count++;  // incrementing count

    printf("\n\n\n\n");
    printf("\t\tYour details entered are wrong \n\n");
    printf("\t\tPlease enter again");
    if( count == 3)  // checking if count is equal to 3
    {
      for(int i=0 ; i<5; i++)
      {
       Beep(750, 300);
     }

     _getch();
      stop();   // going to admin if user enters incorrect detials thrice
    }

    _getch();

    voter_insert();

  }

//  temp = temp -> next;

}

}

void voting()
{
  count = 0;  // intitializing count to be zero so that after voting the other user gets 3 chanes again.
  system("cls"); // clear previous output

  // displaying candidates

  printf("\n\n\n\n");
  printf("\t\tTHE FOLLOWING ARE THE CANDIDATES YOU COULD VOTE FOR : ");
  printf("\n\n\tSR.NO\tCANDIDATES\t\t\tPARTY\t\t\t\t\tSYMBOL");
  printf("\n\n\n");
  printf("\n\t1.\tRAM KADAM\t\t\tBHARTIYA JANTA PARTY\t\t\tLOTUS");
  printf("\n\t2.\tYOGI KUMAR\t\t\tMAHARASHTRA NAVNIRMAAN SENA\t\tENGINE");
  printf("\n\t3.\tPRATIBHA K\t\t\tINDIAN NATIONAL CONGRESS\t\tPALM");
  printf("\n\t4.\tSURYAKUMAR P\t\t\tNEW CONGRESS\t\t\t\tKITE");
  printf("\n\t5.\tSANJAY K\t\t\tSHIV SENA\t\t\t\tBOW AND ARROW");
  printf("\n\t6.\t NOTA\t\t\t\tNOTA\t\t\t\t\tNOTA");
  printf("\n\n\t\tPLEASE ENTER YOUR VOTE FOR A SUITABLE CANDIDATE : ");
  number_of_votes++;  // keeps count of number of voters performed voting

  int vote, j;

  for(j=1; j<=1; j++)
  {
    scanf("%d",&vote);

    switch(vote)
    {
      case 1: count1++;
      break;

      case 2: count2++;
      break;

      case 3: count3++;
      break;

      case 4: count4++;
      break;

      case 5: count5++;
      break;

      default : printf("\n\n\t\tYOU HAVE VOTED FOR NONE OF THE ABOVE");
                count6++;

    }

    Beep(750, 300);  // making beep
    printf("\n\n\t\tYOUR VOTE IS SUCCESSFULLY CASTED");
    _getch();


  }



  main_menu();

}

void admin()
{
  int password;
  printf("\n\n\t\tENTER PASSWORD OF ADMIN PANEL: ");
  scanf("%d",&password);
  if(password == 22317)
  {
    show();
  }

  else{
    printf("\t\t\tWRONG PASSWORD !!!!");
    for(int i=0 ; i<5; i++)
    {
     Beep(750, 300);
   }

    _getch();
    main_menu();
  }
}

void show()
{
  int choice;
  system("cls");
  // displaying admin choices
  printf("\n\n\t\tWhat do you wish to do : ");
  printf("\n\n\t\t1. CURRENT WINNER");
  printf("\n\n\t\t2. CURRENT RESULT");
  printf("\n\n\t\t3. TOTAL NUMBER OF VOTES CASTED  ");
  printf("\n\n\t\t4. LIST OF THE VOTERS THAT PERFORMED VOTING");
  printf("\n\n\t\t5. BACK TO MAIN MENU");
  printf("\n\n\t\t6. EXIT");
  printf("\n\n\t\tPLEASE ENTER YOUR CHOICE : ");

  scanf("%d",&choice);


  switch(choice)
  {
    case 1 :
    winner();
    break;

    case 2 :
    system("cls");
    current_result();
    break;

    case 3 : system("cls");
            if(head == NULL)
            {
              printf("\n\n\n\t\t\tNO VOTER HAS VOTED YET !!!");
              _getch();
              main_menu();
            }

            else{

             printf("\n\n\t\t\tTHE TOTAL NUMBER OF VOTES CASETED ARE : %d",number_of_votes);


            _getch();
            main_menu();
          }
    break;

    case 4 :system("cls");
    if(head == NULL)  // if head is equal to NULL that means no node has been inserted which means no voter has voted yet
    {
      printf("\n\n\n\t\t\tNONE OF THE VOTERS HAS V0TED YET.");
      _getch();
      main_menu();
    }
    else{
     displayList(head);
    _getch();
    main_menu();
  }
    break;

    case 5 : main_menu();
    break;

    case 6:
    exit(0);

    default :
    printf("Invalid choice");
    _getch();
    main_menu();

  }




}

void winner()
{
  char res[5];
  system("cls");
// displaying current winner using if condition

  if(head == NULL)
  {
    printf("\n\n\n\t\t\tTHERE IS NO WINNER YET AS NO VOTER HAS VOTED YET.");
    _getch();
    main_menu();
  }

  if(count2<count1 && count3<count1 && count4<count1 && count5<count1)
    printf("\n\n\t\t\tTHE CURRENT WINNER IS RAM KADAM WHO GOT %d votes", count1);

  if(count1<count2 && count3<count2 && count4<count2 && count5<count2)
      printf("\n\n\t\t\tTHE CURRENT WINNER IS YOGI KUMAR WHO GOT %d votes", count2);

  if(count1<count3 && count2<count3 && count4<count3 && count5<count3)
      printf("\n\n\t\t\tTHE CURRENT WINNER IS PRATIBHA K WHO GOT %d votes", count3);

  if(count1<count4 && count2<count4 && count3<count4 && count5<count4)
      printf("\n\n\t\t\tTHE CURRENT WINNER IS SURYAKUMAR P WHO GOT %d votes", count4);

  if(count1<count5 && count2<count5 && count3<count5 && count4<count5)
      printf("\n\n\t\t\tTHE CURRENT WINNER IS SANJAY K WHO GOT %d votes", count5);

  if(count1<count6 && count2<count6 && count3<count6 && count4<count6)
  {
      printf("\n\n\t\t\tNONE OF THE ABOVE CANDIDATES ARE WINNING ");
      printf("\n\n\t\t\tTHE NUMBER OF CANDIDATES VOTED FOR NONE OF THE ABOVE IS %d ", count6);
  }



_getch();

main_menu();

}

static int count_of_admin = 0;  // keeping count of admin entries
void stop()
{
  int pass;

  system("cls");
  printf("\n\n\t\t\tYOU HAVE ENTERED YOUR DETAILS WRONG FOR 3 TIMES YOUR VOTING HAS BEEN TERMINATED.");
  printf("\n\n\t\t\tCONTACT LOCAL ADMINISTRATOR ");
  printf("\n\n\n\t\tENTER ADMIN PASSWORD: ");
  scanf("%d", &pass);

  if(pass == 22317)
  {

    system("cls");
    main_menu();
  }

  else
  {
     for(int i=0 ; i<5; i++)
    {
     Beep(750, 300);
   }


   printf("\n\n\t\tENTERED PASSWORD IS WRONG !!!");
   printf("\n\n\t\tTRY AGAIN");
   printf("\n\n\t\tYOU HAVE 2 MORE CHANCES OR THE SYSTEM TERMINATES !!!!!" );
   _getch();

   printf("\n\n\n\t\tENTER ADMIN PASSWORD: ");
   scanf("%d", &pass);

   if(pass == 22317)
   {

     system("cls");
     main_menu();
   }

   else
   {
     for(int i=0 ; i<5; i++)
     {
      Beep(750, 300);
    }

    printf("\n\n\t\tENTERED PASSWORD IS WRONG !!!");
    printf("\n\n\t\tTRY AGAIN");
    printf("\n\n\t\tYOU HAVE 1 MORE CHANCE OR THE SYSTEM TERMINATES !!!!!" );
    _getch();

    printf("\n\n\n\t\tENTER ADMIN PASSWORD: ");
    scanf("%d", &pass);

    if(pass == 22317)
    {

      system("cls");
      main_menu();
    }

    else
    {
      printf("\n\n\t\tSYSTEM TERMINATED !!!!" );
      _getch();
      exit(0);
    }
   }

  }


}

void current_result()
{
  printf("\n\n\t\t\tTHE CURRENT RESULT IS AS FOLLOWS: ");
  printf("\n\n\t\tCANDIDATE\t\t\tVOTES");
  printf("\n\n\n\t\tRAM KADAM \t\t\t%d",count1);
  printf("\n\t\tYOGI KUMAR \t\t\t%d",count2);
  printf("\n\t\tPRATIBHA K \t\t\t%d",count3);
  printf("\n\t\tSURYAKUMAR P \t\t\t%d",count4);
  printf("\n\t\tSANJAY K \t\t\t%d",count5);
  printf("\n\t\tNOTA \t\t\t\t%d",count6);

  _getch();

  main_menu();


}

void displayList(node *head)
{
  node *ptr = head;
  printf("\n\n\n\t\t\tThe following are the details of the voters that has performed voting : ");
  while(ptr != NULL)  // traversing the linked list
  {

    printf("\n\n\n\t\t\tVOTER ID : %s", ptr -> id);
    printf("\n\t\t\tNAME : %s", ptr -> name);
    printf("\n\t\t\tBIRTH DATE : %s", ptr -> birth_date);
    printf("\n\t\t\tMOTHER NAME : %s", ptr -> mother_name);
    printf("\n\t\t\tFATHER NAME : %s", ptr -> father_name);

    ptr = ptr -> next;  // moving towards next node
    printf("\n\n");
  }
}

void checkagain(node *head, char id [20])
{
  node *ptr = head;
  while(ptr != NULL)
  {

    if(strcmp(ptr -> id, id) == 0)
    {
      system("cls");
      for(int i=0; i< 10; i++)
      {
       Beep(750, 300);
      }
      printf("\n\n\t\tYOU HAVE VOTED ONCE YOU CANNOT VOTE AGAIN !!!");
      printf("\n\n\t\tVOTING MORE THAN ONCE IS A legal CRIME WHICH CAN CAUSE UPTO 10000 RUPEES FINE OF 6 MONTHS JAIL  !!!!");
      _getch();
      main_menu();
    }
    else
    {
      ptr = ptr -> next;
    }
  }
}
