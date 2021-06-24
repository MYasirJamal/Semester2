#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct patient_info
{
    char name[50];
    char disease[50];
    int room,phone,age;
} x[100];
struct staff_info
{
   char name[50] ;
   char post[50];
   int house_no,street;
   int age;
   float salary;
   int phone_no;
} y[150];
int n,i,sum=0,g,count; //global declaraction of variables 
 
                      //we have used fflush(stdin) on multiple ocassions in this project as during the testing stage we encountered an error which was not letting us enter anything after using integers because it was considering enter as a character  
                      //note for creating file you would have to use write option in the programs
void home_screen(); //this function is used to display home screen in which there are three options patient staff and exit for example if we are using pateine and want to add staff information then we can go to homescreen option 

void addinfo_staff();//this function is used to add information of staff for example name age salary post etc

void edit_staff();//this function can edit the records just by asking serial number and serial number can be found by search function incase you forget

void search_staff();//this function was our main focus it can search the record of any staff by just providng any one information.

void delete_info_staff();//this function can delete any record 

void view_staff();//this functon will display the whole records in the database

int write_staff();//if you want to create file than you would have to use this function

void addinfo_patient();//this function is used to add information of patients for example name age disease etc

void search(); //this function was our main focus it can search the record of any patient by just providng any one information.

void edit_patient(); //this function can edit the records just by asking serial number and serial number can be found by search function incase you forget

void view_patient();//this functon will display the whole records in the database

void delete_info_patient(); //this function can delete any record 

int write_patient();//if you want to create file than you would have to use this function

int main()
{
	home_screen();  
}

void home_screen()
{
 
    
    int c,choice,i;
    
     printf("\n\n\n\n\n\t\t\t\t********************************************************\n");
      printf("\t\t\t\t********************************************************\n");
     printf("\t\t\t\t\t********Fast University Hospital********");
    printf("\n\t\t\t\t********************************************************");
      printf("\n\t\t\t\t********************************************************");
    printf("\n\n\n\n\n\n\n");
    printf("\t\t1.PATIENT");
    printf("\n\t\t2.STAFF"); 
    printf("\n\t\t3.EXIT");
    printf("\n\n\tEnter your choice: "); //c is for chosing between pateint and staff
    scanf("%d",&c);
    fflush(stdin);
   
    
 
	if(c==1){
    while(choice!=9) //choice is for option what we want to do add edit seearch delete etc
    {

        printf("**Enter your choice**\n\n1. Add Information\n2. Edit Information \n3. Search \n4. Delete information \n5. view_pateints information  \n6. write file \n7. Home Screen \n8. Exit \nOption=");
        scanf("%d",&choice);
        fflush(stdin);
        if(choice==1)
        {
            
            addinfo_patient();
        }
        
        else if(choice==2)
        {
            
            edit_patient();
        }
        else if(choice==3)
        {
        
            search();
        }
         else if(choice==4)
        {
        
           delete_info_patient();
           
        }
        
		 else if(choice==5)
        {
        
            view_patient();
        } 
		
		else if(choice==6)
        {
        
            write_patient();
            
        }
        else if(choice==7)
        {
        
            home_screen();
            
        }
        else if(choice==8)
        {
        
           exit(1);
            
        }
        else
        {
           
            printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }}
	
	else if (c==2)
	{ while(choice!=9)
    {

        printf("**Enter your choice**\n\n1. Add staff Information\n2. Edit staff Information \n3. Search staff information \n4. Delete staff information \n5. View staff iformation \n6. write staff  file \n7. Home Screen \n8. Exit \nOption=");
        scanf("%d",&choice);
        fflush(stdin);
        if(choice==1)
        {
            
            addinfo_staff();
        }
        
        else if(choice==2)
        {
            
            edit_staff();
        }
        else if(choice==3)
        {
        
            search_staff();
        }
        else if(choice==4)
        {
            delete_info_staff();
          
        }
         else if(choice==5)
        {
        
            view_staff();
        } 
		
		else if(choice==6)
        {
        
            write_staff();
            
        }
        else if(choice==7)
        {
        
            home_screen();
            
        }
        else if(choice==8)
        {
        
           exit(1);
            
        }
        
        
        else
        {
           
            printf("\n\nInvalid input , try again by using valid inputs"); // this will run if choice exceeds the condition for example if you type 10 
        }
        printf("\n\n");
    }
	}
	else if(c==3){
	
	exit(0);
}
	else 
	printf("\n\n wrong input , please try again wth a valid input !!!"); //this will run if you write something other than 1,2,3 
}

void addinfo_staff()
{
    struct staff_info *p;
    p=y;
    printf("\n\n");
    printf("Already data inputed on the program =%d \n",count);//count is globally deccalred it is used here to count total number of enteries in system
    
    printf("How many entry do you want to add=\n");//how many patients record we want to add

    scanf("%d",&n);	// n = number of enteries
    sum=n+count;

    for(i=count; i<sum; i++) //sum is also globaly declared its used here to run the loop until sum of n+count condition is reached
    {
        printf("\n\n");
        fflush(stdin);
        
        printf("Enter Employee Name = ");
        gets((p+i)->name);
        fflush(stdin);
        printf("Enter Employee post   = ");
        gets((p+i)->post);
        fflush(stdin);
        printf("Enter Employ address   ");
        printf("Enter house No");
        scanf("%d",&(p+i)->house_no);
        fflush(stdin);
        printf("Enter street No ");
        scanf("%d",&(p+i)->street);
        fflush(stdin);
        printf("Enter the age = ");
        scanf("%d",&(p+i)->age);
        fflush(stdin);
        printf("Enter salary  = ");
        scanf("%f",&(p+i)->salary);
        fflush(stdin);
        printf("Enter phone number = ");
        scanf("%d",&(p+i)->phone_no);
        fflush(stdin);
        printf("\n");
        
        
        count++;
    }
}
void edit_staff()
{
	struct staff_info *ptr;
    ptr=y;
    int q,p;
    fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Employee Name\n2.Employee post \n3.house No\n4.street No\n5.Age \n6.salary \n7.Phone no.\n");
    printf("Option=");
    scanf("%d",&q);  //q is for option 
    if(q<=7)
    {
        printf("Enter the serial no of that staff = ");
        scanf("%d",&p);  // p is for serial number
        if(p<count)
        {
            if(q==1)
            {
                fflush(stdin);
                printf("Enter the new Eployee Name=");
                gets((ptr+p)->name);

            }
            else if(q==2)
            {
                fflush(stdin);
                printf("Enter the new Employee post");
                gets((ptr+p)->post);
            }
            else if(q==3)
            {
                fflush(stdin);
                printf("Enter the new House no =");
                scanf("%d",&(ptr+p)->house_no);
            }

            else if(q==4)
            {
                fflush(stdin);
                printf("Enter the new street no=");
                scanf("%d",&(ptr+p)->street);
            }

             else if(q==5)
            {
                fflush(stdin);
                printf("Enter the new Age=");
                scanf("%d",&(ptr+p)->age);
            } 
			else if(q==6)
            {
                fflush(stdin);
                printf("Enter the new salary=");
                scanf("%f",&(ptr+p)->salary);
            }


            else if(q==7)
            {
                fflush(stdin);
                printf("Enter the new Phone no =");
                scanf("%d",&(ptr+p)->phone_no);
            }
        }
        else
        {
            printf("\n\n the entered Serial no is invalid \nplease Try Again with a valid serial no!!\n\n");
        }
    }
    else
    {
        printf("\n\nInvalid option\nplease Try Again!!\n\n");
    }
}
void search_staff()
{
	struct staff_info *ptr;
    ptr=y;
    int s,h,f;
    char u[100];
        printf("select the option by what do you want to search ?\n");
    printf("1.Serial no. \n2.Employee Name\n3.Employee post \n4.house No\n5.street No\n6.Age \n7.salary \n8.Phone no.\n");
    printf("\n option =");
    scanf("%d",&h);
    
    if(h==1)
    {
        printf("Enter the Serial number of the emplyee=");//s=serial number
        scanf("%d",&s);
        if(s<count)
        {
            printf("\n\n\n");
            printf("\t\t\tSerial Number = %d\n",s);
            printf("\t\t\t Employee Name = ");
            puts((ptr+s)->name);
            printf("\t\t\tEmployee post = ");
            puts((ptr+s)->post);
            printf("\t\t\tAddress \n\t\t\tHouse No = %d\n\t\t\tStreet No = %d\n\t\t\tAge = %d\n ",(ptr+s)->house_no,(ptr+s)->street,(ptr+s)->age);
            printf("\t\t\tSalary = %.2f\n\t\t\tPhone No = %d",(ptr+s)->salary,(ptr+s)->phone_no);
            printf("\n\n\n");
        }
        else
            printf("\n\nRecord Not Found\n\n");
    }
    else if(h==2)//h=options
    {
        int f=1;
        fflush(stdin);
        printf("Enter Employee name=");
        gets(u);
        fflush(stdin);
        for(g=0; g<count; g++)//g is globally decleared and is used here for loop 
        {
            if(strcmp(u,(ptr+g)->name)==0)
            {
            	 printf("\n\n\n");
            printf("\t\t\tSerial Number = %d\n",g);
            printf("\t\t\t Employee Name = ");
            puts((ptr+g)->name);
            printf("\t\t\tEmployee post = ");
            puts((ptr+g)->post);
              printf("\t\t\tAddress \n\t\t\tHouse No = %d\n\t\t\tStreet No = %d\n\t\t\tAge = %d\n ",(ptr+g)->house_no,(ptr+g)->street,(ptr+g)->age);
            printf("\t\t\tSalary = %.2f\n\t\t\tPhone No =",(ptr+g)->salary,(ptr+g)->phone_no);
            printf("\n\n\n");
               
                f=0;

            }
        }
        if(f==1)   // if for loop didnot not run than f would be equal to 1 and this condition would be implemented
            printf("\nRecord Not Found\n"); 
    }
else if(h==3)//h=options
    {
        int f=1;
        fflush(stdin);
        printf("Enter Employee post=");
        gets(u);
        fflush(stdin);
        for(g=0; g<count; g++)
        {
            if(strcmp(u,(ptr+g)->post)==0)
            {
            	 printf("\n\n\n");
            printf("\t\t\tSerial Number = %d\n",g);
            printf("\t\t\t Employee Name = ");
            puts((ptr+g)->name);
            printf("\t\t\tEmployee post = ");
            puts((ptr+g)->post);
            printf("\t\t\tAddress \n\t\t\tHouse No = %d\n\t\t\tStreet No = %d\n\t\t\tAge = %d\n ",(ptr+g)->house_no,(ptr+g)->street,(ptr+g)->age);
            printf("\t\t\tSalary = %.2f\n\t\t\tPhone No =",(ptr+g)->salary,(ptr+g)->phone_no);
            printf("\n\n\n");
               
                f=0;

            }
        }
        if(f==1)
            printf("\nRecord Not Found\n");
        }
else if(h==4)//h=options
    {
        int f=1;
        fflush(stdin);
        printf("Enter Employee House No=");
        scanf("%d",&f);
        fflush(stdin);
        for(g=0; g<count; g++)
        {
        	if(f==(ptr+g)->house_no)
            
            {
            	 printf("\n\n\n");
            printf("\t\t\tSerial Number = %d\n",g);
            printf("\t\t\t Employee Name = ");
            puts((ptr+g)->name);
            printf("\t\t\tEmployee post = ");
            puts((ptr+g)->post);
            printf("\t\t\tAddress \n\t\t\tHouse No = %d\n\t\t\tStreet No = %d\n\t\t\tAge = %d\n ",(ptr+g)->house_no,(ptr+g)->street,(ptr+g)->age);
            printf("\t\t\tSalary = %.2f\n\t\t\tPhone No =",(ptr+g)->salary,(ptr+g)->phone_no);
            printf("\n\n\n");
               
                f=0;

            }
        }
        if(f==1)
            printf("\nRecord Not Found\n");
        }
else if(h==5)//h=options
    {
        int f=1;
        fflush(stdin);
        printf("Enter Employee Street No=");
        scanf("%d",&f);
        fflush(stdin);
        for(g=0; g<count; g++)
        {
            if(f==(ptr+g)->street)
            {
            	 printf("\n\n\n");
            printf("\t\t\tSerial Number = %d\n",g);
            printf("\t\t\t Employee Name = ");
            puts((ptr+g)->name);
            printf("\t\t\tEmployee post = ");
            puts((ptr+g)->post);
            printf("\t\t\tAddress \n\t\t\tHouse No = %d\n\t\t\tStreet No = %d\n\t\t\tAge = %d\n ",(ptr+g)->house_no,(ptr+g)->street,(ptr+g)->age);
            printf("\t\t\tSalary = %.2f\n\t\t\tPhone No =",(ptr+g)->salary,(ptr+g)->phone_no);
            printf("\n\n\n");
               
                f=0;

            }
        }
        if(f==1)
            printf("\nRecord Not Found\n");
        }
        else if(h==6)//h=options
    {
        int f=1;
        fflush(stdin);
        printf("Enter Employee Age=");
        scanf("%d",&f);
        fflush(stdin);
        for(g=0; g<count; g++)
        {
            if(f==(ptr+g)->age)
            {
            	 printf("\n\n\n");
                 printf("\t\t\tSerial Number = %d\n",g);
                 printf("\t\t\t Employee Name = ");
                 puts((ptr+g)->name);
                 printf("\t\t\tEmployee post = ");
                 puts((ptr+g)->post);
                 printf("\t\t\tHouse No = %d\n\t\t\tStreet No = %d\n\t\t\tAge = %d\n ",(ptr+g)->house_no,(ptr+g)->street,(ptr+g)->age);
                 printf("\t\t\tSalary = %.2f\n\t\t\tPhone No =",(ptr+g)->salary,(ptr+g)->phone_no);
                 printf("\n\n\n");
               
                f=0;

            }
        }
        if(f==1)
            printf("\nRecord Not Found\n");
   }
else if(h==7)//h=options
    {
        int f=1;
        fflush(stdin);
        printf("Enter Employee Salary=");
        scanf("%.2f",&f);
        fflush(stdin);
        for(g=0; g<count; g++)
        {
            if(f==(ptr+g)->salary)
            {
            	 printf("\n\n\n");
            printf("\t\t\tSerial Number = %d\n",g);
            printf("\t\t\t Employee Name = ");
            puts((ptr+g)->name);
            printf("\t\t\tEmployee post = ");
            puts((ptr+g)->post);
            printf("\t\t\tHouse No = %d\n\t\t\tStreet No = %d\n\t\t\tAge = %d\n ",(ptr+g)->house_no,(ptr+g)->street,(ptr+g)->age);
            printf("\t\t\tSalary = %.2f\n\t\t\tPhone No =",(ptr+g)->salary,(ptr+g)->phone_no);
            printf("\n\n\n");
               
                f=0;

            }
        }
        if(f==1)
            printf("\nRecord Not Found\n");
        }
else if(h==8)//h=options
    {
        int f=1;
        fflush(stdin);
        printf("Enter Employee Phone Number=");
        scanf("%d",&f);
        fflush(stdin);
        for(g=0; g<count; g++)
        {
            if(f==(ptr+g)->phone_no)
            {
            	 printf("\n\n\n");
            printf("\t\t\tSerial Number = %d\n",g);
            printf("\t\t\t Employee Name = ");
            puts((ptr+g)->name);
            printf("\t\t\tEmployee post = ");
            puts((ptr+g)->post);
            printf("\t\t\tHouse No = %d\n\t\t\tStreet No = %d\n\t\t\tAge = %d\n ",(ptr+g)->house_no,(ptr+g)->street,(ptr+g)->age);
            printf("\t\t\tSalary = %.2f\n\t\t\tPhone No =",(ptr+g)->salary,(ptr+g)->phone_no);
            printf("\n\n\n");
               
                f=0;

            }
        }
        if(f==1)
            printf("\nRecord Not Found\n");


    }
	
    else
    {
	
        printf("\n\nInvalid input\n\n");}

}
void delete_info_staff()
{
		struct staff_info *ptr;
       ptr=y;
     int sno,opt;
    printf("Enter the serial number of the staff  that you want to delete=");
    scanf("%d",&sno); //sno is used for serial number
    if(sno<count)
    {
        printf("What do you want ?\n");
        printf("1.Remove Name\n2.Remove Post\n3.Remove House no\n4.Remove Street No \n5.Remove Age \n6.Remove salary \n7.Remove phone number\nOption = ");
        scanf("%d",&opt); //opt is used for option
        
         if(opt==1)
        {
            strcpy((ptr+sno)->name,"Cleared");

        }
        else if(opt==2)
        {
            strcpy((ptr+sno)->post,"Cleared");
        }
		 
         else if(opt==3)
        {
           (ptr+sno)->house_no=0;
			}
            else if(opt==4)
        {
            (ptr+sno)->street=0;
	    }
        else if(opt==5)
        {
            (ptr+sno)->age=0;
        }
         else if(opt==6)
        {
            (ptr+sno)->salary=0;
        }
        
        else if(opt==7)
        {
            (ptr+sno)->phone_no=0;
        }

    }
    else
        printf("\n\nInvalid Serial number\n");

}
void view_staff()
{
    for(i=0; i<count; i++)
    {
        printf("\n");
        printf("\t\tSerial Number=%d\n",i);
        printf("\t\tName = ");
        puts(y[i].name);
        printf("\t\tPost = ");
        puts(y[i].post);
        printf("\t\tHouse Number = %d\n\t\tStreet Number = %d\n\t\tAge = %d\n\t\tSalary = %.2f\n\t\tphone number=%d",y[i].house_no,y[i].street,y[i].age,y[i].salary,y[i].phone_no);
        printf("\n\n");
    }
}

int write_staff()
{
    FILE *fp = fopen("staff.txt","w");
    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(y, sizeof(struct staff_info),count, fp);

    fclose(fp);
}
   
void addinfo_patient()
{

    printf("\n\n");
    printf("Already data inputed on the database =%d \n",count);
    printf("How many entry do you want to add=\n");
    scanf("%d",&n);
    sum=n+count;

    for(i=count; i<sum; i++)//sum is also globaly declared its used here to run the loop until sum of n+count condition is reached
    {
        printf("\n");
        fflush(stdin);
        
        printf("Enter patient's Name = ");
        gets(x[i].name);
        fflush(stdin);
        printf("Enter disease = ");
        gets(x[i].disease);
        fflush(stdin);
        printf("Enter the age = ");
        scanf("%d",&x[i].age);
        fflush(stdin);
        printf("Enter Room no = ");
        scanf("%d",&x[i].room);
        fflush(stdin);
        printf("Enter phone number = ");
        scanf("%d",&x[i].phone);
        fflush(stdin);
        printf("\n");
        
        
        count++;
    }
}


void edit_patient()
{
    int q,p;
    fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Name\n2.Disease\n3.Age\n4.Room No\n5.Phone no.\n");
    printf("Option=");
    scanf("%d",&q);
    if(q<=5)
    {
        printf("Enter the serial no of that patient = ");
        scanf("%d",&p);
        if(p<count)
        {
            if(q==1)
            {
                fflush(stdin);
                printf("Enter the new name=");
                gets(x[p].name);

            }
            else if(q==2)
            {
                fflush(stdin);
                printf("Enter the new Disease=");
                gets(x[p].disease);
            }
            else if(q==3)
            {
                fflush(stdin);
                printf("Enter the new Age=");
                scanf("%d",&x[p].age);
            }

            else if(q==4)
            {
                fflush(stdin);
                printf("Enter the new Room no=");
                scanf("%d",&x[p].room);
            }

            else if(q==5)
            {
                fflush(stdin);
                printf("Enter the new Phone no =");
                scanf("%d",&x[p].phone);
            }
        }
        else
        {
            printf("\n\nInvalid Serial \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
}
void search()
{
    int s,h,f;
    char u[100];
        printf("select the option by what do you want to search ?\n");
    printf("1.Serial no.\n2.Name\n3.Disease\n4.Room no.\n5.Phone no.\n6.Age\n\nOption = ");

    scanf("%d",&h);
    
    if(h==1)
    {
        printf("Enter the Serial number of the patient=");//s=serial number
        scanf("%d",&s);
        if(s<count)
        {
            printf("\n\n\n");
            printf("\t\t\tSerial Number = %d\n",s);
            printf("\t\t\tName = ");
            puts(x[s].name);
            printf("\t\t\tDisease = ");
            puts(x[s].disease);
            printf("\t\t\tAge = %d\n\t\t\tRoom no = %d\n\t\t\tPhone number = 0%d\n ",x[s].age,x[s].room,x[s].phone);
            printf("\n\n");
        }
        else
            printf("\n\nRecord Not Found\n\n");
    }
    else if(h==2)//h=options
    {
        int f=1;  // if for loop didnot not run than f would be equal to 1 and this condition would be implemented
        fflush(stdin);
        printf("Enter your name=");
        gets(u);
        fflush(stdin);
        for(g=0; g<count; g++)
        {
            if(strcmp(u,x[g].name)==0)
            {
                printf("\n\n\n");
                printf("\t\t\tSerial Number=%d\n",g);
               printf("\t\t\tName = ");
            puts(x[g].name);
            printf("\t\t\tDisease = ");
            puts(x[g].disease);
            printf("\t\t\tAge = %d\n\t\t\tRoom no = %d\n\t\t\tPhone number = 0%d\n ",x[g].age,x[g].room,x[g].phone);
            printf("\n\n\n");
                f=0;

            }
        }
        if(f==1)
            printf("\nRecord Not Found\n");



    }
    else if(h==3)
    {
        int f=1;
        fflush(stdin);
        printf("Enter Disease = ");
        gets(u);
        fflush(stdin);
        for(g=0; g<count; g++)
        {
            if(strcmp(u,x[g].disease)==0)
            {
                 printf("\n\n\n");
                printf("\t\t\tSerial Number=%d\n",g);
               printf("\t\t\tName = ");
            puts(x[g].name);
            printf("\t\t\tDisease = ");
            puts(x[g].disease);
            printf("\t\t\tAge = %d\n\t\t\tRoom no = %d\n\t\t\tPhone number = 0%d\n ",x[g].age,x[g].room,x[g].phone);
            printf("\n\n\n");
                f=0;
            }


        }
        if(f==1)
            printf("\n Record Not Found\n");


    }
    else if(h==4)
    {
        int f=1;
        printf("Enter Room number = ");
        scanf("%d",&f);
        for(g=0; g<count; g++)
        {
            if(f==x[g].room)
            {
                printf("\n\n\n");
                printf("\t\t\tSerial Number=%d\n",g);
               printf("\t\t\tName = ");
            puts(x[g].name);
            printf("\t\t\tDisease = ");
            puts(x[g].disease);
            printf("\t\t\tAge = %d\n\t\t\tRoom no = %d\n\t\t\tPhone number = 0%d\n ",x[g].age,x[g].room,x[g].phone);
            printf("\n\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Record Not Found\n\n");

    }
    else if(h==5)
    {
        int f=1;
        printf("Enter Phone number = ");
        scanf("%d",&f);
        for(g=0; g<count; g++)
        {
            if(f==x[g].phone)
            {
                printf("\n\n\n");
                printf("\t\t\tSerial Number=%d\n",g);
               printf("\t\t\tName = ");
            puts(x[g].name);
            printf("\t\t\tDisease = ");
            puts(x[g].disease);
            printf("\t\t\tAge = %d\n\t\t\tRoom no = %d\n\t\t\tPhone number = 0%d\n ",x[g].age,x[g].room,x[g].phone);
            printf("\n\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Record Not Found");
    }
    else if(h==6)
    {
        int f=1;
        printf("Enter Age = ");
        scanf("%d",&f);
        for(g=0; g<count; g++)
        {
            if(f==x[g].age)
            {
                 printf("\n\n\n");
                printf("\t\t\tSerial Number=%d\n",g);
               printf("\t\t\tName = ");
            puts(x[g].name);
            printf("\t\t\tDisease = ");
            puts(x[g].disease);
            printf("\t\t\tAge = %d\n\t\t\tRoom no = %d\n\t\t\tPhone number = 0%d\n ",x[g].age,x[g].room,x[g].phone);
            printf("\n\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Record Not Found\n\n");

    }
    else
    {
	
        printf("\n\nInvalid input\n\n");}
}
void delete_info_patient()
{
    int f,h;
    printf("Enter the serial number of the patient that you want to delete=");
    scanf("%d",&f);
    if(f<count)
    {
        printf("What do you want ?\n");
        printf("1.Remove Name\n2.Remove Disease\n3.Remove age\n4.Remove Cabin\n5.Remove phone number\nOption = ");
        scanf("%d",&h);
        
        
        if(h==1)
        {
            strcpy(x[f].name,"Cleared");

        }
        else if(h==2)
        {
            strcpy(x[f].disease,"Cleared");
        }
        else if(h==3)
        {
            x[f].age=0;
        }
        else if(h==4)
        {
            x[f].room=0;
        }
        else if(h==5)
        {
            x[f].phone=0;
        }

    }
    else
        printf("\n\nInvalid Serial number\n");

}
void view_patient()
{
    for(i=0; i<count; i++)
    {
        printf("\n");
        printf("\t\tSerial Number=%d\n",i);
        printf("\t\tName = ");
        puts(x[i].name);
        printf("\t\tDisease = ");
        puts(x[i].disease);
        printf("\t\tAge = %d\n\t\tRoom number = 0%d\n\t\tphone number=%d",x[i].age,x[i].room,x[i].phone);
        printf("\n\n");
    }
}

int write_patient()
{
    FILE *fp = fopen("patient.txt","w");
    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(x, sizeof(struct patient_info),count, fp);

    fclose(fp);
}
