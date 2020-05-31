/*LIBRARY INFORMATION SYSTEM*/


                      /*the password to delete a record is "12345abc"*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct record            /*structure for record of books*/
{
	int num;                        //book number
	char title [30];                   //book title
	int isbn;                       //isbn number
	char date [10];                 //date of publication
	char name [30];                  //name of publisher
	char author [30];     
	char key[30];                         //key words           
	
	
};


struct issued                    /*structure for record of issued books*/
{
    char person[30];                 //name of person
	int b_num;                       //book number
	char b_title[30] ;                   //book title
	char dep[30];                     //department of person
	char d_issue[10];                //date of issue
	char d_return[10];              //date of return 
};




/*List of prototypes*/


void add(struct record*);
void display(struct record*);
void edit(struct record*);
void del(struct record*);                  //to delete a record
void i_add(struct issued*);                   //to add record of issued books
void i_display(struct issued*);             //to display all records of issued books
void i_edit(struct issued*);                    //to edit record of issued books
void i_del(struct issued*);                  //to delete a record of issued book
void search();
void q_title(struct record*);                //to query any book by title 
void q_key(struct record*);                  //to query any book by its key words
void q_author(struct record*);              //to query any book by author
void q_isbn(struct record*);                  //to query any book by ISBN number
void i_search();                             //to search issued books
void q_iperson(struct issued*);               //to query issued books by person name
void q_ititle(struct issued*);                 //to query issued books by book title            
void password();






int main()
{
	system("cls");
	struct record book ;
	struct issued s1;
	printf("\t\t\t\t\t--------------------------\n");
	printf("\t\t\t\t\tLIBRARY INFORMATION SYSTEM\n");
	printf("\t\t\t\t\t--------------------------\n");
	int a, x;
	FILE *fptr;
do
{
	printf("\n\nPress 1 to enter Books Record Menu\npress 2 enter to Issued Books Record Menu\n");
	scanf("%d",&a);
	system("cls");
	if(a==1)
	{  
	    
		printf("\t\t\t\t\t*****BOOKS INFORMATION MENU*****\n\n\n");
	    printf("press 1 to add a record\npress 2 to display all records\npress 3 to edit any record\n");
	    printf("Press 4 to delete any record\nPress 5 to search a record\nPress 6 to go Back\n");
	    scanf("%d",&x);
	    system("cls");

        switch(x)                                     
	    {
		    case 1: add(&book); break;                        /*books information menu*/
	    
	        case 2: display(&book); break;
		     
		    case 3: edit(&book); break;
			
			case 4: del(&book); break;
			 
			case 5: search(); break;
			
			case 6: main(); break;
			
			default: printf("\nYou entered wrong number\n\nPress ANY Key to Continue"); 
			         getch();
			         main();
		
	    }
    }
    else if(a==2)
    {
    	printf("\t\t\t\t\t*****ISSUED BOOKS MENU*****\n\n\n");
    	printf("press 1 to add a record\npress 2 to display all records\npress 3 to edit any record\n");
	    printf("Press 4 to delete any record\nPress 5 to search a record\nPress 6 to go Back\n");
        scanf("%d",&x);
        system("cls");
        
        switch(x)                                               /*issued books menu*/
        {
        	case 1: i_add(&s1); break;
        	
        	case 2: i_display(&s1); break;
        	
        	case 3: i_edit(&s1); break;
        
        	case 4: i_del(&s1); break;
        	
        	case 5: i_search(); break;
        	
        	case 6: main(); break;
        	
        	default: printf("\n\nYou Entered Wrong Number\n\nPress ANY Key to Continue");
        	         getch();
        	         main();
        	
        }
    }
    else
    {
    	printf("\n\nYou entered wrong number\n\n");
    	
    }
    
}while(a!=1 && a!=2);


	getch();
	return 0;
}



                                       
						
void add(struct record *bptr)                    /*function add is used to add 
                                                    data of books from the user*/
{
	int x;
	system("cls");
	printf("\t\t\t\t***tEnter Book Record*** \n\n\n");
	FILE *fptr;
	fptr=fopen("books.txt","a+");
	if(fptr==NULL)
	{
		printf("File Not Opened\n\nPress any key to Continue");
 		getch();
 		main();
	}
	rewind(fptr);
do 
{

	printf("Enter Book number :");
	scanf("%d",&bptr->num);
	printf("Enter book title :");
	scanf("%s",bptr->title);
	printf("Enter ISBN number:");
	scanf("%d",&bptr->isbn);
	printf("Date of publication (dd/mm/yy) :");
	scanf("%s",bptr->date);
	printf("Enter name of publisher :");
	scanf("%s",bptr->name);
	printf("Enter name of Author :");
	scanf("%s",bptr->author);
	printf("Enter key words :");
	scanf("%s",bptr->key);
	printf("\n\n\nDo you want to enter data again(press 1 for yes and 2 for no)");
	scanf("%d",&x);
	fprintf(fptr,"%d\t%s\t%d\t%s\t",bptr->num,bptr->title,bptr->isbn,bptr->date);
	fprintf(fptr,"%s\t%s\t%s\n",bptr->name,bptr->author,bptr->key);
	
}while(x==1);
    
    fclose(fptr);
    main();				
}



void display(struct record *bptr)                           /*function display is used to display 
                                                               all record of books*/
{
	FILE *fptr;
	fptr=fopen("books.txt","a+");
	if(fptr==NULL)
	{
		printf("File Not Opened\n\nPress any key to Continue");
 		getch();
 		main();
	}
	rewind(fptr);
	printf("%9s%16s%16s%22s","Book No.","Book Title","ISBN No.","Publication Date");
	printf("%17s%16s%19s","Publisher","Author","Key Words");
	printf("\n");
	while(!feof(fptr))
	{
		
	    fscanf(fptr,"%d\t%s\t%d\t%s",&bptr->num,bptr->title,&bptr->isbn,bptr->date);
	    printf("%7d%17s%15d%21s",bptr->num,bptr->title,bptr->isbn,bptr->date);
        fscanf(fptr,"%s\t%s\t%s\n",bptr->name,bptr->author,bptr->key);
	    printf("%19s%16s%17s\n",bptr->name,bptr->author,bptr->key);   
	        
	 
    }
    fclose(fptr);
    printf("\n\n\nPress any key to Continue...");
	getch();
	main();
    
}



void edit(struct record *bptr)                          /*function edit is used to edit a record*/
{
	FILE *fptr;
	FILE *fp;
	
	int x,y=0;
	fptr=fopen("books.txt","a+");
	
	if(fptr==NULL)
	{
		printf("File Not Opened\n\nPress ANY Key to Continue");
		getch();
		main();
		
	}
	
	printf("Enter ISBN Number to edit that record :");
	scanf("%d",&x);
	rewind(fptr);

	while(!feof(fptr))
	{
	    fscanf(fptr,"%d\t%s\t%d\t%s",&bptr->num,bptr->title,&bptr->isbn,bptr->date);
		fscanf(fptr,"%s\t%s\t%s\n",bptr->name,bptr->author,bptr->key);
		
		if(bptr->isbn==x)
		{
			printf("\n\n%9s%16s%16s%22s","Book No.","Book Title","ISBN No.","Publication Date");
           	printf("%17s%16s%19s\n","Publisher","Author","Key Words");
            printf("%7d%17s%15d%21s",bptr->num,bptr->title,bptr->isbn,bptr->date);
            printf("%19s%16s%17s\n\n",bptr->name,bptr->author,bptr->key);
            
            printf("\n\n\nPress 1 to edit this record\nPress 2 to return to Main Menu");
            scanf("%d",&y);
                
            if(y!=1)
            {
                main();
            }
		}
		
		
		if(y==1)
		{
			fp=fopen("tempo.txt","a+");                     //temporary file to copy all data 
			
			if(fp==NULL)
			{
				printf("File Not Opened\n\nPress ANY Key to Continue");
		        getch();
		        main();
		      
			}
			rewind(fp);
			rewind(fptr);
			
			
		
		
		    while(!feof(fptr) && y==1)
 		    {
 		            
 		        fscanf(fptr,"%d\t%s\t%d\t%s",&bptr->num,bptr->title,&bptr->isbn,bptr->date);
		        fscanf(fptr,"%s\t%s\t%s\n",bptr->name,bptr->author,bptr->key);
 	           	    
						
			    if(bptr->isbn!=x)
 		        {
 		            fprintf(fp,"%d\t%s\t%d\t%s\t",bptr->num,bptr->title,bptr->isbn,bptr->date);
                  	fprintf(fp,"%s\t%s\t%s\n",bptr->name,bptr->author,bptr->key);
					
			     }
			     
			     if(bptr->isbn==x)
			     {
			     	printf("Enter Book number :");
                	scanf("%d",&bptr->num); 
                	printf("Enter book title :"); 
                  	scanf("%s",bptr->title);
                   	printf("Enter ISBN number:");
	                scanf("%d",&bptr->isbn);
                 	printf("Date of publication (dd/mm/yy) :"); 
                  	scanf("%s",bptr->date);
                   	printf("Enter name of publisher :");
	                scanf("%s",bptr->name); 
                	printf("Enter name of Author :");
	                scanf("%s",bptr->author);
                   	printf("Enter key words :");
	                scanf("%s",bptr->key);
	                
					fprintf(fp,"%d\t%s\t%d\t%s\t",bptr->num,bptr->title,bptr->isbn,bptr->date);
                  	fprintf(fp,"%s\t%s\t%s\n",bptr->name,bptr->author,bptr->key);
	                
	            
	                
			     }
					 
					 
	         }
	    
		
		}
	             
	 }
	             
	    if(y==1)
		{
		         
	        fclose(fptr);
	        fclose(fp);
	
	        remove("books.txt");
	        rename("tempo.txt","books.txt");
	
	       
            
	        printf("\n\n\nThe record was successfully editted\n\nPress any key to Continue\n");
		    getch();
			   
	        main();
            
    
        }
    
    
    printf("\n\nYou Entered Wrong ISBN Number");
    getch();
    main();
    
}







void del(struct record *bptr)                           /*function del is used to delete a record*/
{
	FILE *fptr;
	FILE *fp;
 
 	
 	
		fptr=fopen("books.txt","a+");
	    if(fptr==NULL)
 	    {
 	        printf("File Not Opened\n\nPress any key to Continue");
 	       	getch();
 	        main();
 		
 	    }
 	    
    	    
    system("cls");
	
	int x,y=0,z;
	
	password();                    /*the password to delete a record is "12345abc"*/

	
	printf("\nEnter ISBN number to delete that record :");
    scanf("%d",&x);
    rewind(fptr);
	
	while(!feof(fptr))
	{
 		
 	    
 	    
 	        fscanf(fptr,"%d\t%s\t%d\t%s",&bptr->num,bptr->title,&bptr->isbn,bptr->date);
		    fscanf(fptr,"%s\t%s\t%s\n",bptr->name,bptr->author,bptr->key);
		
		
		
		    if(bptr->isbn==x)
		    {
			    printf("\n\n%9s%16s%16s%22s","Book No.","Book Title","ISBN No.","Publication Date");
           	    printf("%17s%16s%19s\n","Publisher","Author","Key Words");
                printf("%7d%17s%15d%21s",bptr->num,bptr->title,bptr->isbn,bptr->date);
                printf("%19s%16s%17s\n\n",bptr->name,bptr->author,bptr->key);
            
                printf("Press 1 to delete this record");
                scanf("%d",&y);
                
                if(y!=1)
                {
                	main();
                }
            
            
            
		    }
		
 	     
 	
 	        if(y==1)
 	        {
 		       
				fp=fopen("temp.txt","a+");        /*temporary file to copy all data except that
				                                     data which you want to delete*/
				if(fp==NULL)
 	            {
 		            printf("File Not Opened\n\nPress any key to Continue");
 		            getch();
 		            main();
 		
 	            }

 		        rewind(fp);
 		      
 		        
 		    
 		        
 		        	rewind(fptr);
 		        
 		 
 		          
 		        while(!feof(fptr) && y==1)
 		        {
 		            
 		            fscanf(fptr,"%d\t%s\t%d\t%s",&bptr->num,bptr->title,&bptr->isbn,bptr->date);
		            fscanf(fptr,"%s\t%s\t%s\n",bptr->name,bptr->author,bptr->key);
 	           	    
						
				    if(bptr->isbn!=x)
 		            {
 		           	    fprintf(fp,"%d\t%s\t%d\t%s\t",bptr->num,bptr->title,bptr->isbn,bptr->date);
	                    fprintf(fp,"%s\t%s\t%s\n",bptr->name,bptr->author,bptr->key);
 		           
					
					 }
					 
					 
 		       
				
				 }
                
				fclose(fptr);
                fclose(fp);
                remove("books.txt");
                rename("temp.txt","books.txt");
                
                 
               
			    
			    if(y==1)
			    {
			       printf("\nThe file is successfully deleted\n\nPress any key to Continue\n");
			       getch();
				   
				   main();
			    }
			  
			 }
             
             
    }
    printf("\n\nYou entered Wrong ISBN Number");
    getch();
    main();
}



void i_add(struct issued *sptr)                          /*this function is used 
                                                          add record of issued books*/
{	
	FILE *fptr;
	fptr=fopen("issue.txt","a+");
	if(fptr==NULL)
	{
	printf("File Not Opened\n\nPress any key to Continue");
 		getch();
 		main();
	}
	
	int x;
do
{
	printf("Enter Name of Person :");
	scanf("%s",sptr->person);
    printf("Enter Book Number :");
    scanf("%d",&sptr->b_num);
    printf("Enter Book Title :");
    scanf("%s",sptr->b_title);
    printf("Enter department of person :");
    scanf("%s",sptr->dep);
    printf("Issue Date (mm/dd/yy):");
    char date[10];
    printf("%s\n",_strdate(date));
    printf("Enter date of Return (mm/dd/yy) :");
    scanf("%s",sptr->d_return);
	fprintf(fptr,"%s\t%d\t%s\t",sptr->person,sptr->b_num,sptr->b_title);
	fprintf(fptr,"%s\t%s\t%s\n",sptr->dep,_strdate(date),sptr->d_return);
	printf("\n\n\nDo you want to enter data again(press 1 for yes and 2 for no)");
	scanf("%d",&x);
}while(x==1);
	
	fclose(fptr);
    main();

}


void i_display(struct issued *sptr)               /*to display all records of issued books*/
{
	FILE *fptr;
	fptr=fopen("issue.txt","a+");
	if(fptr==NULL)
	{
		printf("File Not Opened\n\nPress any key to Continue");
 		getch();
 		main();
	}
	
	printf("%s%18s%17s","Name of Person","Book Number","Book Title");
	printf("%28s%20s%21s\n","Department of Person","Issue Date","Return Date");
	
	while(!feof(fptr))
	{
	    fscanf(fptr,"%s\t%d\t%s\t",sptr->person,&sptr->b_num,sptr->b_title);
	    printf("%11s%18d%19s",sptr->person,sptr->b_num,sptr->b_title);	
	    fscanf(fptr,"%s\t%s\t%s\t",sptr->dep,sptr->d_issue,sptr->d_return);
	    printf("%24s%24s%21s\n",sptr->dep,sptr->d_issue,sptr->d_return);
	}
	
	fclose(fptr);
	printf("\n\n\nPress ANY Key to Continue");
	getch();
	
	main();

}






void i_edit(struct issued *sptr)                 /*to edit issued books record*/
{
	FILE *fptr;
	FILE *fp;
	
	int x,y=0;
	fptr=fopen("issue.txt","a+");
	
	if(fptr==NULL)
	{
		printf("File Not Opened\n\nPress ANY Key to Continue");
		getch();
		main();
		
	}
	
	printf("Enter Book Number to edit that record :");
	scanf("%d",&x);
	rewind(fptr);

	while(!feof(fptr))
	{
	    fscanf(fptr,"%s\t%d\t%s\t",sptr->person,&sptr->b_num,sptr->b_title);
		fscanf(fptr,"%s\t%s\t%s\t",sptr->dep,sptr->d_issue,sptr->d_return);
		
		if(sptr->b_num==x)
		{
			printf("\n\n%s%18s%17s","Name of Person","Book Number","Book Title");
	        printf("%28s%20s%21s\n","Department of Person","Issue Date","Return Date");
            printf("%11s%18d%19s",sptr->person,sptr->b_num,sptr->b_title);	
            printf("%24s%24s%21s\n",sptr->dep,sptr->d_issue,sptr->d_return);
            
            printf("\n\n\nPress 1 to edit this record\nPress 2 to return to Main Menu");
            scanf("%d",&y);
                
            if(y!=1)
            {
                main();
            }
		}
		
		
		if(y==1)
		{
			fp=fopen("edit.txt","a+");          //temporary file to copy all data 
			
			if(fp==NULL)
			{
				printf("File Not Opened\n\nPress ANY Key to Continue");
		        getch();
		        main();
		      
			}
			rewind(fp);
			rewind(fptr);
			
			
		
		
		    while(!feof(fptr) && y==1)
 		    {
 		            
 		        fscanf(fptr,"%s\t%d\t%s\t",sptr->person,&sptr->b_num,sptr->b_title);
	       	    fscanf(fptr,"%s\t%s\t%s\t",sptr->dep,sptr->d_issue,sptr->d_return);
 	           	    
						
			    if(sptr->b_num!=x)
 		        {
 		            fprintf(fp,"%s\t%d\t%s\t",sptr->person,sptr->b_num,sptr->b_title);
	                fprintf(fp,"%s\t%s\t%s\n",sptr->dep,sptr->d_issue,sptr->d_return);
					
			     }
			     
			     if(sptr->b_num==x)
			     {
			     	printf("Enter Name of Person :");
	                scanf("%s",sptr->person);
                    printf("Enter Book Number :");
                    scanf("%d",&sptr->b_num);
                    printf("Enter Book Title :");
                    scanf("%s",sptr->b_title);
                    printf("Enter department of person :");
                    scanf("%s",sptr->dep);
                    printf("Issue Date (mm/dd/yy):");
                    char date[10];
                    printf("%s\n",_strdate(date));
                    printf("Enter date of Return (mm/dd/yy) :");
                    scanf("%s",sptr->d_return);
	                fprintf(fp,"%s\t%d\t%s\t",sptr->person,sptr->b_num,sptr->b_title);
	                fprintf(fp,"%s\t%s\t%s\n",sptr->dep,_strdate(date),sptr->d_return);
	                
	            
	                
			     }
					 
					 
	         }
	   
	   
	   
	   
	   
	   
	   }
	             
   
   }
   
   
        if(y==1)
		{
			
	        fclose(fptr);
	        fclose(fp);
	
	        remove("issue.txt");
	        rename("edit.txt","issue.txt");
	
	       
            
	        printf("\n\n\nThe file was successfully editted\n\nPress any key to Continue\n");
		    getch();
			
			   
	        main();
            
    
        }
    
    
    printf("\n\nYou Entered Wrong Book Number");
    getch();
    main();
    
}









void i_del(struct issued *sptr)                     /*to delete issued books record*/
{
	FILE *fptr;
	FILE *fp;
	
	password();                       /*the password to delete a record is "12345abc"*/
	system("cls");
	int x,y=0;
	fptr=fopen("issue.txt","a+");
	
	if(fptr==NULL)
	{
		printf("File Not Opened\n\nPress ANY Key to Continue");
		getch();
		main();
		
	}
	
	printf("Enter Book Number to delete that record :");
	scanf("%d",&x);
	rewind(fptr);

	while(!feof(fptr))
	{
	    fscanf(fptr,"%s\t%d\t%s\t",sptr->person,&sptr->b_num,sptr->b_title);
		fscanf(fptr,"%s\t%s\t%s\t",sptr->dep,sptr->d_issue,sptr->d_return);
		
		if(sptr->b_num==x)
		{
			printf("\n\n%s%18s%17s","Name of Person","Book Number","Book Title");
	        printf("%28s%20s%21s\n","Department of Person","Issue Date","Return Date");
            printf("%11s%18d%19s",sptr->person,sptr->b_num,sptr->b_title);	
            printf("%24s%24s%21s\n",sptr->dep,sptr->d_issue,sptr->d_return);
            
            printf("\n\n\nPress 1 to delete this record\nPress 2 to reurn to Main Menu");
            scanf("%d",&y);
                
            if(y!=1)
            {
                main();
            }
		}
		
		
		if(y==1)
		{
			fp=fopen("temporary.txt","w");            /*temporary file to copy all data except that
			                                            data you want to delete*/
			
			if(fp==NULL)
			{
				printf("File Not Opened\n\nPress ANY Key to Continue");
		        getch();
		        main();
		      
			}
			rewind(fp);
			rewind(fptr);
			
			
		
		
		    while(!feof(fptr) && y==1)
 		    {
 		            
 		        fscanf(fptr,"%s\t%d\t%s\t",sptr->person,&sptr->b_num,sptr->b_title);
	       	    fscanf(fptr,"%s\t%s\t%s\t",sptr->dep,sptr->d_issue,sptr->d_return);
 	           	    
						
			    if(sptr->b_num!=x)
 		        {
 		            fprintf(fp,"%s\t%d\t%s\t",sptr->person,sptr->b_num,sptr->b_title);
	                fprintf(fp,"%s\t%s\t%s\n",sptr->dep,sptr->d_issue,sptr->d_return);
					
			     }
					 
					 
	         }
	             
	             
	             
	             
	    }
	
	
    }
	    
		if(y==1)
		{
		
		    fclose(fptr);
	        fclose(fp);
	
	        remove("issue.txt");
	        rename("temporary.txt","issue.txt");
	
	       
            
	        printf("\n\n\nThe file was successfully deleted\n\nPress any key to Continue\n");
		    getch();
			
					
				   
	            main();
            
    
        }
    
    
    printf("\n\nYou Entered Wrong Book Number");
    getch();
    main();
    
}



void search()                                                  /*search menu*/
{
	struct record book;
	int x;
	system("cls");
	printf("\t\t\t\t\t*****SEARCH MENU*****\n");
	printf("\n\n\nPress 1 to search by title\nPress 2 to search by key words\n");
	printf("Press 3 to search by author\nPress 4 to search by ISBN Number\nPress 5 to go back\n");
	scanf("%d",&x);
	
	switch(x)
	{
		case 1: q_title(&book); break;
		
		case 2: q_key(&book); break;
		
		case 3: q_author(&book); break;
		
		case 4: q_isbn(&book); break;
		
		case 5: main(); break;
		
		default: printf("You entered wrong number\n\nPress ANY Key to Continue"); 
			     getch();
			     main();
	}
}




void q_title(struct record *bptr)                          /*this function is used to search 
                                                            a record by its title name*/
{
	FILE *fptr;
	fptr=fopen("books.txt","a+");
	if(fptr==NULL)
	{
		printf("File Not Opened\n\nPress any key to Continue");
 		getch();
 		main();
	}
	
	char x[40];
	
	printf("Enter book title to search :");
	scanf("%s",x);
	
	while(!feof(fptr))
	{
     		
		fscanf(fptr,"%d\t%s\t%d\t%s",&bptr->num,bptr->title,&bptr->isbn,bptr->date);
		fscanf(fptr,"%s\t%s\t%s\n",bptr->name,bptr->author,bptr->key);
        if((strcmpi(bptr->title,x))==0)
        {
            printf("\n\n%9s%16s%16s%22s","Book No.","Book Title","ISBN No.","Publication Date");
           	printf("%17s%16s%19s\n","Publisher","Author","Key Words");
            printf("%7d%17s%15d%21s",bptr->num,bptr->title,bptr->isbn,bptr->date);
            printf("%19s%16s%17s\n\n",bptr->name,bptr->author,bptr->key);
            printf("\nPress any key to continue");
            getch();
		    main();
		}
        
 
    }
    if((strcmpi(bptr->title,x))!=0)
        {
        	printf("\n\nNo data Found\n\nPress any key to Continue");
        	
        	getch();
        	main();
        	
        }
 
    fclose(fptr);
 
 }
 
 
 
 void q_key(struct record *bptr)                      /*to query a record by its key words*/
 {
 	FILE *fptr;
 	fptr=fopen("books.txt","a+");
    
	if(fptr==NULL)
	{
		printf("File Not Opened\n\nPress any key to Continue");
 		getch();
 		main();
	}
	
	char x[40];
	printf("Enter key words to search :");
	scanf("%s",x);
	
 	while(!feof(fptr))
 	{
 		fscanf(fptr,"%d\t%s\t%d\t%s",&bptr->num,bptr->title,&bptr->isbn,bptr->date);
		fscanf(fptr,"%s\t%s\t%s\n",bptr->name,bptr->author,bptr->key);
		
		 if((strcmpi(bptr->key,x))==0)
        {
            printf("\n\n%9s%16s%16s%22s","Book No.","Book Title","ISBN No.","Publication Date");
           	printf("%17s%16s%19s\n","Publisher","Author","Key Words");
            printf("%7d%17s%15d%21s",bptr->num,bptr->title,bptr->isbn,bptr->date);
            printf("%19s%16s%17s\n\n",bptr->name,bptr->author,bptr->key);
            printf("\nPress any key to continue");
            getch();
		    main();
		}
	}
       
	    if((strcmpi(bptr->key,x))!=0)
        {
        	printf("\n\nNo data Found\n\nPress any key to Continue");
        	
        	getch();
        	main();
        	
        }
 
        fclose(fptr);
 
 
		
		
 	
 }
 
 
 void q_author(struct record *bptr)                 /*to query a record by its author name*/
 {
 	FILE *fptr;
 	fptr=fopen("books.txt","a+");
    
	if(fptr==NULL)
	{
		printf("File Not Opened\n\nPress any key to Continue");
 		getch();
 		main();
	}
	
	char x[40];
	printf("Enter Author Name to search :");
	scanf("%s",x);
	
 	while(!feof(fptr))
 	{
 		fscanf(fptr,"%d\t%s\t%d\t%s",&bptr->num,bptr->title,&bptr->isbn,bptr->date);
		fscanf(fptr,"%s\t%s\t%s\n",bptr->name,bptr->author,bptr->key);
		
		 if((strcmpi(bptr->author,x))==0)
        {
            printf("\n\n%9s%16s%16s%22s","Book No.","Book Title","ISBN No.","Publication Date");
           	printf("%17s%16s%19s\n","Publisher","Author","Key Words");
            printf("%7d%17s%15d%21s",bptr->num,bptr->title,bptr->isbn,bptr->date);
            printf("%19s%16s%17s\n\n",bptr->name,bptr->author,bptr->key);
            printf("\nPress any key to continue");
            getch();
		    main();
		}
	}
       
	    if((strcmpi(bptr->author,x))!=0)
        {
        	printf("\n\nNo data Found\n\nPress any key to Continue");
        	
        	getch();
        	main();
        	
        }
 
        fclose(fptr);
 
 
	 	
 }
 
 void q_isbn(struct record *bptr)               /*to query a record by its ISBN number*/
 {
 	FILE *fptr;
 	fptr=fopen("books.txt","a+");
 	
 	if(fptr==NULL)
 	{
 		printf("File Not Opened\n\nPress any key to Continue");
 		getch();
 		main();
 		
 	}
 	int x;
 	printf("\nEnter ISBN number to search :");
 	scanf("%d",&x);
 	
 	
 	while(!feof(fptr))
 	{
 	    fscanf(fptr,"%d\t%s\t%d\t%s",&bptr->num,bptr->title,&bptr->isbn,bptr->date);
		fscanf(fptr,"%s\t%s\t%s\n",bptr->name,bptr->author,bptr->key);
		
		if(bptr->isbn==x)
		{
			printf("\n\n%9s%16s%16s%22s","Book No.","Book Title","ISBN No.","Publication Date");
           	printf("%17s%16s%19s\n","Publisher","Author","Key Words");
            printf("%7d%17s%15d%21s",bptr->num,bptr->title,bptr->isbn,bptr->date);
            printf("%19s%16s%17s\n\n",bptr->name,bptr->author,bptr->key);
            printf("\nPress any key to continue");
            getch();
		    main();
		}
		
 	}
 	fclose(fptr);
 	printf("\n\nNo Data Found\n\nPress Any Key To Continue...");
 	getch();
 	main();
 }
 
 
 
 
 void i_search()                             /*search menu for issued books*/
 {
 	struct issued s1;
 	int x;
 	printf("\t\t\t\t\t*****SEARCH MENU*****\n");
 	printf("\n\nPress 1 to Search by person Name\nPress 2 to Search by Book Title\nPress 3 to go Back\n");
 	scanf("%d",&x);
 	
 	switch(x)
 	{
 		case 1: q_iperson(&s1); break;
 		
 		case 2: q_ititle(&s1); break;
 		
 		case 3: main(); break;
 		
 		
 		
 		default: printf("you entered wrong Number\n\nPress ANY Key to Continue");
 		         getch();
 		         main();
 	}
 }

 
 
 
 
 
 void q_iperson(struct issued *sptr)
 {
 	FILE *fptr;
 	fptr=fopen("issue.txt","a+");
 	
 	if(fptr==NULL)
 	{
 		printf("File Not Opened\n\nPress any key to Continue");
 		getch();
 		main();
 		
 	}
 	
 	char x[30];
 	printf("Enter Person Name to Search :");
 	scanf("%s",x);
 	
 	rewind(fptr);
 	while(!feof(fptr))
 	{
 		fscanf(fptr,"%s\t%d\t%s\t",sptr->person,&sptr->b_num,sptr->b_title);
 		fscanf(fptr,"%s\t%s\t%s\n",sptr->dep,sptr->d_issue,sptr->d_return);
 		
 		if((strcmpi(sptr->person,x))==0)
 		{
 			printf("\n\n%s%18s%17s","Name of Person","Book Number","Book Title");
	        printf("%28s%20s%21s\n","Department of Person","Issue Date","Return Date");
	        printf("%11s%18d%19s",sptr->person,sptr->b_num,sptr->b_title);
	        printf("%24s%24s%21s\n",sptr->dep,sptr->d_issue,sptr->d_return);
	        printf("\n\nPress ANY Key to Continue...");
	        getch();
	        main();
 		}
 		
 		
 	}
 		fclose(fptr);
 	    printf("\n\nNo Data Found\n\nPress Any Key To Continue...");
     	getch();
 	    main();
 	
 	
 }
 
 
 
 void q_ititle(struct issued *sptr)
 {
 	FILE *fptr;
 	fptr=fopen("issue.txt","a+");
 	
 	if(fptr==NULL)
 	{
 		printf("File Not Opened\n\nPress any key to Continue");
 		getch();
 		main();
 		
 	}
 	
 	char x[40];
 	printf("Enter Book Title to Search :");
 	scanf("%s",x);
 	
 	while(!feof(fptr))
 	{
 		fscanf(fptr,"%s\t%d\t%s\t",sptr->person,&sptr->b_num,sptr->b_title);
 		fscanf(fptr,"%s\t%s\t%s\n",sptr->dep,sptr->d_issue,sptr->d_return);
 		
 		if((strcmpi(sptr->b_title,x))==0)
 		{
 			printf("\n\n%s%18s%17s","Name of Person","Book Number","Book Title");
	        printf("%28s%20s%21s\n","Department of Person","Issue Date","Return Date");
	        printf("%11s%18d%19s",sptr->person,sptr->b_num,sptr->b_title);
	        printf("%24s%24s%21s\n",sptr->dep,sptr->d_issue,sptr->d_return);
	        printf("\n\nPress ANY Key to Continue...");
	        getch();
	        main();
 		}
 		
 		
 	}
 		fclose(fptr);
 	    printf("\n\nNo Data Found\n\nPress Any Key To Continue...");
     	getch();
 	    main();
 	
 	
 	
 }
 
 
 
 void password()                       /*function to ask password before deleting a record*/
 {                 
 	
 	int x;
 	char z[30]={"12345abc"};            /*the password to delete a record is "12345abc"*/
 	system("cls");
 	printf("Enter Password to Delete a Record :");
 	scanf("%s",z);
 	if((strcmp(z,"12345abc"))==0)
 	{
 		printf("\n\nPASSWORD ACCEPTED");
 		getch();
 		return;
 	}
 	else
 	{
 		printf("\n\nWrong Password\n\nPress 1 to re-enter the password\nPress 2 to go to Main Menu");
 		scanf("%d",&x);
 		
		if(x==1)
		{
	
 		   password();
 		   
 		   
 	    }
 	    else
 	    {
 	    
 	    	main();
 	    }
 	}
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 


