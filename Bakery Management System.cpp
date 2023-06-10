
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#define MAX_STOCK_ITEMS 100


void insertfirst(int data, char foodname[25], int quantity, float price);
void insertmid(int pos, int data, char foodname[25], int quantity, float price);
void insertend(int data, char foodname[25], int quantity, float price);
void updatefood(int udata, int uquantity);
void order_view(int order, int quantity, int or_no);
void foodlist();                                                                                //Displays item menu
void main_menu();                                                                               //Displays main screen
void deletefood(int serial);                                                                    //Displays menu list with deleted items
void cls();                                                                                     //Clears Console Screen
void echo(char print[]);                                                                        //Displays/works like prints statement
void br(int line);                                                                              //Breaks line or jumps to new line
void pre(int tab);                                                                              //This function is used to add tabs before printing some output to the console. 
void span(int space);                                                                           //This function is used to add space on console
void ccolor(int clr);                                                                           //This function changes color of text on console according to the number provided
void pwellcome();                                                                               //This function displays the title of project
void middle1(void);                                                                             //This and below function are used for centering text on console screen
void middtab1(void);                                                                            //centering        
void backuploader(void);                                                                        //This function displays some animation while backing up the data
int countitem();                                                                                //This function is used to count iteams in the list/menu


char* current_time() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char* time_str = (char*) malloc(sizeof(char) * 20);
    sprintf(time_str, "%04d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    return time_str;
}

struct StockItem {
    int itemId;
    char itemName[50];
    int quantity;
    float price;
};

struct StockItem stockItems[MAX_STOCK_ITEMS];  // Using an array

struct Node{

	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Node *next;

};


typedef struct Node node ;

node *head, *list;


int main(){

	system("title Bakery Management System");
	system("mode con: cols=88 lines=30"); //set the size of console

	pwellcome();
	Sleep(300);
	cls();

	int c=0; int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;
	int citem;
	int rating;
    char feedback[100];
    int numStockItems = 0;

	head = NULL;
    insertend(1,"Cookies",18,20);
	insertend(2,"Coffee  ",50,79);
	insertend(3,"Brownies   ",40,59);
	insertend(4,"Hot Pudding  ",34,149);
    insertend(5,"Strawberry pie  ",30,125);
    insertend(6,"Muffins",50,29);
    insertend(7,"Donuts",18,59);
    insertend(8,"Rolls",70,79);
    insertend(9,"Waffles",40,110);
    insertend(10,"Pastries",50,99); 



	mainmenu:
	br(1);

	main_menu();

	int main_menu_choice;

	br(1); pre(4); fflush(stdin);
	printf(" Please enter your choise: \n");
	 scanf("%d",&main_menu_choice);

	if((main_menu_choice >=1 && main_menu_choice <=4)){

		if(main_menu_choice == 1){

			foodlist:

			cls();
			printf("=> 0. Main Menu ");
			foodlist();


		}

		else if( main_menu_choice == 2){

			adminpanelchoice:

			int admin_panel_choice;

			cls(); middle1() ;   pre(4); 
			printf("1. Main Menu\n\n\t"); Sleep(300);
			printf("Please Enter Password or (Press 1 to Back in Main Menu ) : ");

			fflush(stdin);  
			scanf("%d",&admin_panel_choice);

			if(admin_panel_choice==12345){



				node *temp;

				temp = list;

				adminchoise:

				cls();  br(3); pre(4); 
				echo(">>>> Admin Panel <<<<   \n\n");
				pre(4);
				printf(" 1. Total Payment Today \n\n");Sleep(250);pre(4);
				printf(" 2. View Card Payment \n\n");Sleep(250);pre(4);
				printf(" 3. Add Bakery Item \n\n");Sleep(250);pre(4);
				printf(" 4. Delete Item \n\n");Sleep(250);pre(4);
				printf(" 5. Instant Item List \n\n");Sleep(250);pre(4);
				printf(" 6. Backup System\n\n");Sleep(250);pre(4);
				printf(" 7. Customers Feedback\n\n");Sleep(250);pre(4);
				printf(" 0. Main Menu \n\n");
				printf("Enter Your From 1-0: ");
				Sleep(250);

				int adminchoise;



				fflush(stdin);  
				 scanf("%d",&adminchoise);

				if(adminchoise==1){

					cls();  middle1(); pre(4);   printf("Todays Total Cash : %0.2f  \n",totalmoney);

					Sleep(2000);

					goto adminchoise;
				}
			else if (adminchoise == 2) {
    if (c != 0) {
        cls();
        br(3);
        pre(4);
        printf(" ____________________________\n");
        pre(4);
        printf("|   Card NO.   |   Money $   |\n");
        pre(4);
        printf("------------------------------\n");
        pre(4);

        // Open a file to save the card details
        FILE *file = fopen("card_details.txt", "w");
        if (file == NULL) {
            printf("Failed to open the file for writing.\n");
            return 1;
        }

        for (int z = 1; z <= c; z++) {
            printf("|  %d  | %0.2f |\n", cardno[z], cardmoney[z]);
            pre(4);
            printf("------------------------------\n");
            pre(4);
            Sleep(150);

            // Write the card details to the file
            fprintf(file, "%d %0.2f\n", cardno[z], cardmoney[z]);
        }

        // Close the file
        fclose(file);

        Sleep(1500);
    }

    if (c == 0) {
        cls();
        middle1();
        pre(4);
        printf("No Card History\n");
    }
    Sleep(1500);
    goto adminchoise;
}


				else if(adminchoise==3){

					foodadd:
					cls();

					char ffoodname[25];
					int fquantity;
					int fdata;
					float fprice;
					int fposi;


					br(3);pre(4);      printf(" Enter Bakery Item Name :  ");

					fflush(stdin);     scanf("%[^\n]s",ffoodname);
					fquantity:
					fflush(stdin);

					br(2);pre(4);
					printf(" Enter Item Quantity :  ");

					scanf("%d",&fquantity); fflush(stdin);

                        foodserial:
					br(2);pre(4);  printf(" Enter Item Serial :  ");
                      scanf("%d",&fdata);
                            node *exist;
                            exist = list;
                      while(exist->data!=fdata){
                            if(exist->next==NULL){
                                break;
                            }
                        exist=exist->next;
                      }
                      if(exist->data==fdata){
                       cls(); br(5);pre(3);  printf(" Bakery Item Serial Already Exist, Please Re-Enter  "); Sleep(2000);
                       goto foodserial;
                      }

                    fprice:
                      fflush(stdin);

					br(2);pre(4);
					  printf(" Enter Item Price :  ");fflush(stdin);

					scanf("%f",&fprice);



					br(2);pre(4);  printf("Submitting your data");for(int cs=0;cs<4;cs++){printf(" .");Sleep(500);}


					insertend(fdata,ffoodname,fquantity,fprice);

					br(2);pre(4);      printf("Adding Item  Successfull.......\n");

					Sleep(2000);

					goto adminchoise;

				}
				else if(adminchoise==4){

					cls();
					middle1();pre(2);
					printf("Enter Serial No of the Item To Delete : ");
					fdelete:
					int fdelete;
					fflush(stdin); scanf("%d",&fdelete);
					node *temp;
					temp=list;
					while(temp->data != fdelete){
						temp = temp->next;
					}
					if(temp->data==fdelete){
						deletefood(fdelete);
					}
					else{
						br(2); pre(2); printf("Please Enter Correct Number :  "); Sleep(500);
						goto fdelete;
					}


					goto adminchoise;
				}

				else if(adminchoise==5){

					cls();    foodlist(); Sleep(1000);

					br(2);pre(4);  printf("1. <-- back  \n\n");pre(5);



					fflush(stdin);   scanf("%d",&any);

					goto adminchoise;

				}
				

                        ///Backup System
				else if(adminchoise==6){
					
                   char ffoodname[50];
                    int fdata;
                    int fquantity;

                    char date[35] = __DATE__;
                    strcat(date, ".txt");

                    FILE *fptr;
                    fptr = fopen(date, "w");


                   if (fptr == NULL) {
                    br(3); pre(3); printf("Error!"); Sleep(500);
                     goto adminchoise;
}

               fprintf(fptr, "Total Cash Today : %0.2f\n\n\n", totalmoney);


                 fprintf(fptr, "Card No ------- Money \n\n");
                 for (int l = 1; l <= c; l++) {
               fprintf(fptr, "%d ------- %0.2f \n", cardno[l], cardmoney[l]);
             }

                   br(2); pre(4); printf("Backup Successful..."); Sleep(1500);

                     fclose(fptr);
                    goto adminchoise;

				}
				
			else if (adminchoise == 7) {
            FILE *file;
    char filename[] = "feedback.txt";
    char line[100];

    // Open the file for reading
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    printf(" \n Valuable Contents :\n");
    
    br(2);
    pre(4);

    // Read and print each line until the end of the file
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        Sleep(100);
        pre(4);
        getch();
        
    }

    // Close the file
    fclose(file);
  goto adminchoise;

}


				
				else if(adminchoise==0){

					goto mainmenu;
				}

				else{
					br(2); pre(4); printf("Please Select From List :  "); Sleep(500);
					goto adminchoise;
				}



			}

			else if(admin_panel_choice==1){
				goto mainmenu;
			}
			else{
				br(2); pre(4);  printf("Please Enter Correct Choice");
				goto adminpanelchoice;
			}

		}
		
		else if(main_menu_choice==3){
			cls();
			middle1(); pre(1);
			 printf("Thank you for visiting our bakery! Please provide your feedback:\n");
              printf("Rate our service (1-5): ");
              scanf("%d", &rating);

                printf("Enter your comments: ");
                getchar(); // Clear the newline character from the previous input
                     fgets(feedback, sizeof(feedback), stdin);

     
                      printf("Thank you for your feedback. We appreciate your input!\n");
                      Sleep(2000);
                       FILE *file = fopen("C:\\Users\\soham\\OneDrive\\Desktop\\mini ppro\\meoww\\feedback.txt", "a");

                        if (file != NULL) {
                         fprintf(file, "Rating: %d\n", rating);
                         fprintf(file, "Comments: %s", feedback);
                         fprintf(file, "---------------------------\n");
                         fclose(file);
                         printf("Your feedback has been saved. Thank you!\n");
                        }
						 else {
                         printf("Error: Unable to save the feedback.\n");
                          }
    	               goto mainmenu;
                

		}

		else if(main_menu_choice==4){
			cls();
			middle1(); pre(3); printf("Thank You For Using Our System.\n\n\n\n\n\n\n");
			Sleep(1000);

			exit(0);

		}

	}
	else{
		br(2); pre(4); printf("Please Enter Correct Choice"); Sleep(300);
		goto mainmenu;
	}


	int get_food_choice;


	br(2); pre(3);fflush(stdin);
	printf("Place Your Order: ") ;
	scanf("%d",&get_food_choice);

	if(get_food_choice==0){
		goto mainmenu;
	}

	node *temp;

	temp = list ;

	while(temp->data != get_food_choice){

		temp = temp->next;
		if(temp==NULL){
			br(2); pre(4);  echo("Please Choice From List: "); br(2); Sleep(1000);
			goto foodlist;
		}

	}
	if(get_food_choice == temp->data){

		fcquantity:
		br(2); pre(4);
		printf("Enter Item Quantity : ");

		int fcquantity;

		fflush(stdin); scanf("%d",&fcquantity); cls();



		if(fcquantity==0){
			cls(); middle1();pre(3); printf("Quantity Can not be Zero "); Sleep(2000);
			cls();
			goto foodlist;
		}
		else if(fcquantity>temp->quantity){
			cls(); middle1();pre(3); printf("Out of Stock ! "); Sleep(2000);

			goto foodlist;
		}

		middle1();pre(4); 
		 printf("Choice item %s  its price is %0.2f \n\n",temp->foodname,temp->price*fcquantity);pre(4);
		printf("1. Confirm to buy this \n\n");pre(4);
		printf("2. Item List \n\n");
		printf("Press 1 to confirm and 2 to back to list :");

		confirm:
		int confirm;

		fflush(stdin); scanf("%d",&confirm);

		if(confirm == 1 ){

			br(2);pre(4);
			 printf("Select Method Of payment 1-2: \n");
			 br(2);pre(4);
			printf(" 1. Cash ");
			br(2);pre(4);
            printf(" 2. Credit\n");
           
			payment:
			int payment;

			fflush(stdin);  scanf("%d",&payment);

			if(payment==1){


				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice,uquantity);


				cls();middle1();pre(4);  printf("===>THANK YOU<===");
				br(2);pre(4);  printf("Item Ordered Successfully ...");
				br(2);pre(4);  printf("1. Wanna Buy Another Delicious ? ");
				br(2);pre(4);  printf("2. Main Menu \n");
				br(2);pre(4);   printf("Select: ");
				psmenu:
				int ps_menu;

				fflush(stdin);  scanf("%d",&ps_menu);

				if(ps_menu==1){goto foodlist;}
				else if(ps_menu==2){goto mainmenu;}
				else{br(2);pre(4);printf("Please Choice from list : "); goto psmenu;}

			}

			///Credit Card Option

			else if (payment == 2) {
    int card_number[8];
    c++;
    cls();
    middle1();
    pre(4);
    printf("Enter Your Card No: ");
    fflush(stdin);
    scanf("%d", &card_number[c]);

    cardno[c] = card_number[c];

    int pin;
    br(2);
    pre(2);
    printf("Enter Your Card Pin [we never save your pin]: ");

    char ch;
    int i = 0;
    char pin_input[50]; // Store the pin as a character array
    while (1) {
        ch = getch();
        if (ch == '\r') { // Stop reading input on Enter key
            pin_input[i] = '\0'; // Add null terminator at the end of the pin_input
            break;
        } else if (ch == '\b') { // Handle backspace
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            pin_input[i++] = ch;
            printf("*");
        }
    }
    fflush(stdin);
    sscanf(pin_input, "%d", &pin); // Convert the pin_input to an integer

    cardmoney[c] = temp->price * fcquantity;
    totalmoney += temp->price * fcquantity;
    order++;
    total_order[order] = get_food_choice;
    order_quantity[order] = fcquantity;

    uquantity = temp->quantity - fcquantity;

    updatefood(get_food_choice, uquantity);

    br(2);
    pre(4);
    printf("Payment Success...");
    br(2);
    pre(4);
    printf("1. Wanna Buy Another Delicious? ");
    br(2);
    pre(4);
    printf("2. Main Menu \n");
    br(2);
    pre(4);
    printf("select: ");
psmenu2:
    int ps_menu2;
    scanf("%d", &ps_menu2);

    if (ps_menu2 == 1) {
        goto foodlist;
    } else if (ps_menu2 == 2) {
        goto mainmenu;
    } else {
        br(2);
        pre(4);
        printf("Please Choose from the list: ");
        goto psmenu2;
    }
} else {
    br(2);
    pre(4);
    printf("Enter Choice from List: ");
    goto payment;
}

} ///END Confirm Y/y

else if (confirm == 2) {
    goto foodlist;
} else {
    br(2);
    pre(4);
    printf("Enter Choice from List: ");
    goto confirm;
}
} ///end get food choice if line
else {
    br(2);
    pre(4);
    printf("Please Choose From List ");
    br(2);
    Sleep(300);
    goto foodlist;
} ///end get food choice
}

void cls(){

	system("cls");

}

void echo(char print[]){

	printf("%s",print);
}

void br(int line){
	for(int i=0; i<line;i++){
		printf("\n");
	}
}

void pre(int tab){

	for(int i=0; i<tab;i++){
		printf("\t");
	}

}
void span(int space){

	for(int i=0; i<space;i++){
		printf(" ");
	}

}

void main_menu(){

	cls();
	br(5); pre(3); echo(">> 1. Bakery Item List"); Sleep(400);
	br(2); pre(3); echo(">> 2. Admin Panel"); Sleep(400);
	br(2); pre(3); echo(">> 3. FeedBack");  Sleep(400);
	br(2); pre(3); echo(">> 4. Exit");  Sleep(400);

	br(1);

}

void insertend(int data, char foodname[25], int quantity, float price) {
    node *temp;
    temp = (node *)malloc(sizeof(node));

    temp->data = data;
    temp->price = price;
    temp->quantity = quantity;
    strcpy(temp->foodname, foodname);
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        list = head;
    } else {
        node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

void insertfirst(int data, char foodname[25], int quantity, float price) {
    node *temp;
    temp = (node *)malloc(sizeof(node));

    temp->data = data;
    temp->price = price;
    temp->quantity = quantity;
    strcpy(temp->foodname, foodname);

    temp->next = head;
    head = temp;
    list = head;
}

void insertmid(int pos, int data, char foodname[25], int quantity, float price) {
    node *temp;
    temp = (node *)malloc(sizeof(node));

    temp->data = data;
    temp->price = price;
    temp->quantity = quantity;
    strcpy(temp->foodname, foodname);

    if (head == NULL) {
        head = temp;
        list = head;
    } else {
        node *current = head;
        while (current->next != NULL && current->data != pos) {
            current = current->next;
        }
        if (current->data == pos) {
            temp->next = current->next;
            current->next = temp;
        } else {
            free(temp);
            printf("Position not found.\n");
        }
    }
}

void deletefood(int serial) {
    node *temp = head;
    node *prev = NULL;

    if (temp != NULL && temp->data == serial) {
        head = temp->next;
        free(temp);
        printf("Item %d deleted successfully.\n", serial);
        return;
    }

    while (temp != NULL && temp->data != serial) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Item not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Item %d deleted successfully.\n", serial);
}

void updatefood(int udata, int uquantity) {
    node *temp = head;

    while (temp != NULL) {
        if (temp->data == udata) {
            temp->quantity = uquantity;
            printf("Item %d updated successfully.\n", udata);
            return;
        }
        temp = temp->next;
    }

    printf("Item not found.\n");
}

void foodlist() {
    node *temp = list;

    printf("\n\t\t_____________________________________________________________\n");
    printf("\t\t| %-8s | %-20s | %-6s    | %-10s  |\n", "Item No.", "Item Name", "Price", "In Stock");
    printf("\t\t--------------------------------------------------------------");

    while (temp != NULL) {
        printf("\n\t\t| %-8d | %-20s | RS.%-6.2f | %-10d  |", temp->data, temp->foodname, temp->price, temp->quantity);
        printf("\n\t\t------------------------------------------------------------");
        temp = temp->next;
    }
}


void order_view(int order, int quantity, int or_no) {
    ccolor(26);

    node *temp = head;

    while (temp != NULL) {
        if (temp->data == order) {
            ccolor(26);
            printf("\n\t\t"); 
            ccolor(62);
            printf("|%d|%s|%d|%d|", or_no, temp->foodname, quantity, temp->quantity);
            ccolor(26);
            printf("\n\t\t"); 
            ccolor(62);
            printf("-------------------------------------------------------");

            Sleep(100);
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Item not found.\n");
    }

    ccolor(26);
}


void ccolor(int clr){

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

}




void pwellcome(){
	ccolor(26);

	char welcome[100]="WELCOME TO BAKERY";
	printf("\n\n\n\n\n\t\t\t");
	for(int wlc=0; wlc<strlen(welcome);wlc++){

		printf(" %c",welcome[wlc]);
	Sleep(50);
	}
	ccolor(26);

}

void backuploader(void){

	for (int i=15;i<=100;i+=5){

		cls();
		ccolor(26);

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Backing UP DATA...\n\n\t\t",i);

		printf("");

		for (int j=0; j<i;j+=2){

			ccolor(120+j);
			printf(" ");
			ccolor(26);

		}
		Sleep(50);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(50);
		}
	}

}


void middle1(void){

	printf("\n\n\n\n\n\n\n");
}

void middtab1(void){
	printf("\t\t\t\t\t");
}


int numStockItems = 0;
void processOrder(int itemId, int quantity) {
    // Iterate through the stock items
    for (int i = 0; i < numStockItems; i++) {
        if (stockItems[i].itemId == itemId) {
            // Check if there is sufficient quantity in stock
            if (stockItems[i].quantity >= quantity) {
                // Deduct the ordered quantity from the stock
                stockItems[i].quantity -= quantity;
                printf("Order processed successfully.\n");
            } else {
                printf("Insufficient quantity in stock.\n");
            }
            return;  // Exit the function after processing the order
        }
    }
    // If the item ID is not found
    printf("Item not found in stock.\n");
}

