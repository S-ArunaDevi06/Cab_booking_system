
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include <stdlib.h>
#include <time.h>
#define ENTER 13
#define BKSP 8
void emergency();

//converting each password characters to *

void pwd(char password[20])
{
int i = 0;
char ch;
while (1)
{
ch = getch();
if (ch == ENTER)
{
password[i] = '\0';
break;
}
else if (ch == BKSP)
{
if (i > 0)
{
i--;
printf("\b \b");
}
}
else
{
password[i++] = ch;
printf("*");
}
}

}
struct dri
{
int passe;
int amount;
};

struct DriverFeedback {
    float rating;
    char comments[100];
   
};
//generating promo code
int promo_code()
{
int x1,x2,x3;
srand(time(NULL));
x1=(rand()%99)+1;
x2=(rand()%99)+1;
x3=x1*100+x2;
return x3;
}


 //alloting the driver for customer
void driallot(char location[20],char destination[20])
{
    int counter=0;
    char choice[2];
    FILE* fp;
    char name[20],mail[30],date[20],carno[20];
    int id,pref1,pref2,pref3,pref4,number;
    system("cls");
    fp = fopen("driver.txt", "r");
    while (!feof(fp))
    {
        
        
        printf("driver:-");
        fscanf(fp,"%s %d %s %d %d %d %d %s %d %s",name,&id,mail,&pref1,&pref2,&pref3,&pref4,date,&number,carno);
        printf("Enter whether the driver wants to take the offer from %s to %s (y/n): ", location, destination);
        scanf("%s",choice);
        choice[strcspn(choice,"\n")]='\0';
        printf("%d",strcmp("y",choice));
        if(strcmp("y",choice)==0)
        {
        	system("cls");
        	printf("CUSTOMER\n");
            counter=1;
            printf("%s driver is taking the offer\n", name);
            printf("%d is the number of the driver\n",number);
            printf("%s is the number of the vehicle\n",carno);
            break;
        }
    }
    if(counter==1)
    {
        fclose(fp);
    }
    else
    {
        driallot(location,destination);
    }
}

//bill estimation for customer
int bill (int vehicle[], int index, int people, float rating, int distance,
   int t1, int advance_book, int cancel, int promocode)
{
   int i;
					
	   float vehicles[4] = { 12.5, 15, 10, 9.25 };
    float base_fare = 0, increments = 0, special = 0;
    for (i = 0; i < index + 1; i++)
      {
	base_fare += vehicles[vehicle[i]-1] *6 ;
      }
    increments +=(people * (0.2) * base_fare) + ((distance - 1) * 15) +(base_fare * 0.1 * rating);
    if (advance_book == 1)
      {
	special += 30;
      }
    if (cancel == 1)
      {
	special += 30;
	return special;
      }
    if (promocode == 1)
      {
	base_fare -= 0.2 * base_fare;
      }
    return (base_fare + increments + special);
  }

//payment
int pay()
{
int pay_mode,online_pay_app,bank_name,dri_pay,amount;
char app[5][20]={"Google Pay","Paytm","Phone Pay"};
char bank[10][50]={"STATE BANK OF TAMIL NADU","INDIAN BANK","AXIS BANK","HDFC","ICICI"};
                                                        char password[6];
printf("\nEnter your mode of payment: \nCash(1) or Online payment(2):");
    scanf("%d",&pay_mode);
if (pay_mode==1)
{
        printf("You can complete the payment once you have reached your destination. ");
        return 1;
}
else if (pay_mode==2)
{
        system("cls");
        printf("Enter your payment app:\n1.Google pay(1)\n2.Paytm(2)\n3.PhonePay(3)\nEnter the number for the option provided: ");
        scanf("%d",&online_pay_app);
        system("cls");
        printf("\t\t*******************%s**********************************",app[online_pay_app-1]);
        printf("\nEnter your password: ");
    pwd(password);
        system("cls");
        printf("YOUR ACCOUNTS:\n1.STATE BANK OF TAMIL NADU (1)\n2.INDIAN BANK(3)\n3.AXIS BANK (3)\n4.HDFC (4)\n5.ICICI (5): ");
        printf("\nEnter your choice: ");
        scanf("%d",&bank_name);
        system("cls");
        printf("\nEnter the amount in rupees: ");
        scanf("%d",&amount);
        printf("\nEnter your pin: ");
    pwd(password);
        printf("\n\nYour payment of rupees %d is successfully made from your account in %s",amount,bank[bank_name-1]);    
        return 0;
}
}

// ticket cancellation
void tktcancel()
{
    FILE *f, *temp;
    int check_id;
    char line[50];
    
    printf("Enter check_id: ");
    scanf("%d", &check_id);
    f = fopen("ticket.txt", "r");
    temp = fopen("temp.txt", "w");
    int line_num = 0;
    while (fgets(line, sizeof(line), f) != NULL) {
        line_num=line[0];
        if ((line_num-48) != check_id) {
            fprintf(temp, "%s", line);
        }
    }
    fclose(f);
    fclose(temp);
    remove("ticket.txt");
    rename("temp.txt", "ticket.txt");
    printf("Line deleted.\n");
    printf("\n\nTICKET CANCELATION SUCCESSFULL");
    exit(0);
}

//implementing google maps

void google_map(char location[],char destination[])
{
 int count=0;
 char command[100];
 char *loc=location,*des=destination;
 char link[100]="https://www.google.com/maps/dir/";
  char *url=link;
 printf("\nFORMAT IS: Address,District,State");
 printf("\nIF THERE ARE ANY SPACES PLEACE ADD '+'");
 while (*url!='\0')
 {
  url++;
  count++;
 }
 while (*loc!='\0')
 {
  *url=*loc;
  
  url++;
  loc++;
  count++;
 }
 *url='/';
 url++;
 while (*des!='\0')
 {
  *url=*des;
  url++;
  des++;
  count++;
 }
 url=url-count-1;

 printf("\nurl is %s",link);
 snprintf(command,sizeof(command),"start %s",link);
 system(command);
 }
 //Otp confirmation
 void otp_confirm(int otp)
 {
        int otp_1;
 		printf("\n\nEnter the otp:");
 		scanf("%d",&otp_1);
 		if(otp_1==otp)
 		{
 			printf("\n\n\t\tWELCOME TO TRAWELL");
 		
		}
		else
		{
			system("cls");
			printf("\nOTP is not correct,please enter your otp again");
		    otp_confirm(otp);
	    }
 }


//emergency services
void emergency()
{
int x;
system("cls");
printf("\n\n\t\t*******WELCOME************");
printf("\n This tab will be open till you reach your destination.\n If you need any of the below mentioned services please enter the number specified.\n Once you reach your destination,enter exit");
printf("\n\nMENU \n1) CHANGE DRIVER\n2) EXIT\n:");
scanf("%d",&x);
if(x==1)
{
    char name[50];
    char loc[20];
    char dest[50];
    char cust[6][6];
    int m1,m2,m3,m4;
        char driver[6][6];
        int distance;
            printf("Enter name of alloted driver:- ");
            scanf("%s",name);
            printf("Enter your current location :- ");
            scanf("%s",loc);
            printf("Enter your destination :- ");
            scanf("%s",dest);
            driallot(loc,dest);
           
        
    }
    else if(x==2)
    {
            printf("\nExiting.....");
           
    }
    else
    {
    	printf("Invalid");
    	exit(0);
	}
}
//feedback from the customer

void getDriverFeedback(struct DriverFeedback *feedback) 
{
    printf("Please provide your rating for the driver (1-5): ");
    scanf("%f", &(feedback->rating));
    printf("Please provide any additional comments (up to 100 characters):\n");
    scanf("%s",&(feedback->comments));
   
}

void clearScreen()
{
   system("cls");
}
int main (void)
{
system("color 0");
int cho3;
int cho4;
printf("\n\nAre you an User[1] or driver[2]:");
scanf("%d",&cho3);
printf("\n\nDo you want to LOGIN[3] or REGISTER[4]:");
scanf("%d",&cho4);
if(cho3==1)
{
  if (cho4==3)
  {
  	system("cls");
  
  //User login
   printf("\t\t\t*********** LOGIN PAGE FOR USER ************\n");
	char username[50];
	char password[20];
	char password2[20];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter the password: ");
    pwd(password);
    system("cls");
    printf("\n*USER LOGIN SUCCESSFULL");
}
    if (cho4==4){
	system("cls");
	//User registration

	char usr_name[20];
	int age;
	char email[50];
	long int ph;
	char gen[2];
	int promo_code1;
	char password_usr[20];
	char password_usr1[20];

	printf("\t\t\t*********** REGISTRATION PAGE FOR USER ************\n");
	printf("\n\n\nEnter your name: ");
	scanf("%s",usr_name);
	printf("Enter your age: ");
	scanf("%d", &age);
	printf("Enter your email ID: ");
	scanf("%s", email);
	printf("Enter your phone number: ");
	scanf("%ld", &ph);
	printf("Enter the gender(f/m):");
	scanf("%s", gen);
	printf("\nEnter the password:");
	pwd(password_usr);
	pass:
  	    printf("\nConfirm password:");
  	    pwd(password_usr1);
	if(strcmp(password_usr,password_usr1)==0)
	{
	FILE *fp;
	fp=fopen("User data.txt","a+");
    if(fwrite!=0)
    {     printf("\n\n*****USER REGISTRATION IS SUCCESFULL***");
          promo_code1=promo_code();
	      printf("\n\nYour promocode is %d",promo_code1);
          fprintf(fp ,"%s %d %s\n",usr_name,age,email);
          printf("\n\n\t\t\tWELCOME TO TRAWELL");
	}
    }
	else
	{
		Beep(800,800);
		goto pass;
	}
	
	

}

}
if(cho3==2) 
 {
//Driver login
    if(cho4==3){
    system("cls");
	
    char username1[50];
	char password1[20];
	char password3[20];
    printf("Enter your username: ");
    scanf("%s", username1);
    printf("Enter the password: ");
    pwd(password1);
    printf("\n*******Driver login successfull*********");
    exit(0);
   }
   
   if(cho4==4){
   	//driver registration
   	
   system("cls");
   
   printf("\t\t\t*********** REGISTRATION PAGE FOR DRIVER ************\n");
   FILE *fp1;
    char dri_name[10];
    char id[20];
    int age_dri;
    char pref1[20];
    char pref2[20];
    char pref3[20];
    int experience;
    char gen_dri[1];
    char email_dri[50];
    char date[20];
    char password_dri[20];
    char password_dri1[20];
    printf("Enter your name: ");
    scanf("%s", dri_name);
    printf("Enter your ID: ");
    scanf("%s", id);
    printf("\nPlease enter your choice in number \n1.sedan\n2.suv\n3.mini sedan \n4.innova");
    printf("\nEnter your preference 1: ");
    scanf("%s", pref1);
    printf("Enter your preference 2: ");
    scanf("%s", pref2);
    printf("Enter your preference 3: ");
    scanf("%s", pref3);
    printf("Enter expiry date of driver license: ");
    scanf("%s", date);
    printf("Enter your experience (years): ");
    scanf("%d", &experience);
  
    printf("\nEnter your password:");
    pwd(password_dri);
    pass1:
      printf("\nConfirm password:");
      pwd(password_dri1);
    if(strcmp(password_dri,password_dri1)==0)
    {
    system("cls");
    printf("\n\n\t\t*DRIVER REGESTRATION SUCCESSFUL*****");
    fp1 = fopen("Drivers Data.txt", "a+");
    fprintf(fp1, "%s %s %s  %d %s\n", dri_name, id, email_dri,experience, date);
    }else
    {
    	Beep(800,800); 
    	goto pass1;
	}
    fclose(fp1);
	exit(0); 
   }
}

FILE *tc= fopen ("ticket.txt", "r+");
int  tot_people, people, map, advance_book, promocode, meridiam,estimation, distance,vehicle[10], index =0,rows=0, cancel = 0;
char *row,l[50];
    
float rating=1, t1;
int i, dri_id, dri_age, p1, p2, p3, yes;
char location[100],destination[100],*loca=location,*des=destination;
char link[100]="https://www.google.com/maps/dir/";
char *url=link;

printf ("\t\t\t\t\n**TICKET BOOKING**");
printf("\n\nSOME INSTRUCTIONS:\n1.Please enter your location and destination.\n2.The map showing the route will be displayed\n3.Choose your desirable path and enter the distance\n4.Minimize the map for further usage");
printf ("\nENTER 1 TO CONTINUE: ");
scanf ("%d", &map);
system("cls");
if(map==1)
{
	int count=0;
 char command[100];
 char location[100],destination[100];
 printf("\nFORMAT IS: Address,District,State");
 printf("\nIF THERE ARE ANY SPACES PLEACE ADD '+'");
 printf("\nEnter location: ");
 scanf("%s",location);
 printf("\nEnter destination:");
 scanf("%s",destination);
 google_map(location,destination);
 printf ("\nENTER THE DISTANCE(in Km): ");
scanf ("%d", &distance);
printf ("ENTER THE VEHICLE(innova=1,SUV=2,sedan=3,mini_sedan=4): ");
scanf ("%d", &vehicle[index]);
printf ("ENTER THE NUMBER OF PEOPLE:");
scanf ("%d", &people);
tot_people = people;
while (people > 4)
{
printf ("\nOnly a maximum of 4 people is allowed!");
printf ("\nYou can book more vehicles instead!");
printf ("\nDO YOU WANT TO BOOK ANOTHER VEHICLE?(YES(1) or NO(0)):");
scanf ("%d", &yes);
if (yes == 1)
 {
   index += 1;
   printf("ENTER THE VEHICLE(innova=1,SUV=2,sedan=3,mini_sedan=4): ");
   scanf ("%d", &vehicle[index]);
   people -= 4;
 }
}
printf ("\nENTER MERIDIAM(am=1,pm=2): ");
scanf ("%d", &meridiam);
printf ("\nENTER TIME(HOUR.MIN  (IN 12-HOURS FORMAT) ): ");
scanf ("%f", &t1);
printf ("\nIS THIS AN ADVANCED BOOKING?(YES(1) OR NO(0)): ");
scanf ("%d", &advance_book);
printf ("\nDO YOU HAVE A PROMOCODE?(YES(ENTER YOUR CODE) OR NO(0)): ");
scanf ("%d", &promocode);
driallot(location,destination);
int x1,x2,x3;
srand(time(NULL));
x1=(rand()%99)+1;
x2=(rand()%99)+1;
x3=x1*100+x2;
printf("Your otp is:-%d",x3);
	
if (((t1 > 4 && t1 < 6) && (meridiam == 2)) || (t1 > 7.30 && t1 < 9))
      {
estimation = bill (vehicle, index, people, rating, distance, t1, advance_book,
cancel, promocode);
      }
else
      {
estimation =bill (vehicle, index, people, rating, distance, 0, advance_book,
cancel, promocode);
      }

    
printf("\n\n\n\t*BILL RECEIPT*");
time_t currentTime = time(NULL);
char* timeString = ctime(&currentTime);
printf("\n\n\n%s", timeString);
printf("\n\nDEAR CUSTOMER,");

printf("\nDISTANCE -%d",distance);

printf("\nNO OF PEOPLES:%d",people);
printf("\nTIME -%.2f",t1);
printf("\nYOUR ESTIMATED BILL IS %d",estimation);
char tct[2];
printf("\n\nDo you want to cancel your ticket[y/n]:");
scanf("%s",tct);
if(strcmp("y",tct)==0)
{
	tktcancel();
	
}
int a=pay();
if(a==0||a==1)
{
	otp_confirm(x3);
	
}

emergency();
system("cls");

while (!feof(tc))
    {
    fgets(l,sizeof(l),tc);
    printf("%s",l);
    rows+=1;
    }
    fprintf (tc, "\n%d %s %s %d ", rows-4, location, destination,distance);
    for ( i = 0; i < index + 1; i++)
      {
fprintf (tc, "%d ", vehicle[i]);
      }
    fprintf (tc, "%d %d %f %d %d %d", tot_people, meridiam, t1,advance_book, promocode,estimation);
    

	struct DriverFeedback feedback;
	clearScreen();
	printf("\n\n\t\t****THANK YOU FOR CHOOSING TRAWELL,HOPE YOU HADE A GREAT TIME WITH US!!!");
	printf("\n\nCustomer Feedback\n");
	printf("=================\n");
	getDriverFeedback(&feedback);
	printf("\nThank you for your feedback!\n");
	printf("Rating: %f\n", feedback.rating);
	printf("Comment: %s\n", feedback.comments);
system("cls");
printf("\n \tFOR DRIVER\n\n");
struct dri u;
u.amount=15000;
printf("\n\nEnter the no of passengers you took in a month:");
scanf("%d",&u.passe);
if(u.passe<15)
{
u.amount=u.amount+u.amount*0.05*u.passe; 
printf("Your salary is %d",u.amount); 
}
else if(15<=u.passe<20)
{
u.amount=u.amount+u.amount*0.07*u.passe;
printf("Your salary is %d",u.amount); 
}
else if(u.passe>=25)
{
u.amount=u.amount+u.amount*0.10*u.passe;
printf("Your salary is %d",u.amount); 
}
else
{
printf("Invalid");
}

return 0;

}}
