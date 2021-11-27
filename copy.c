#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
void cancle(int ReservationNo);
void busLists();
char passName[32][100] = {'\0'};

// char busSeats[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
int busSeat[33] = {0};
char busName[10][130] = {"Delhi to Gurgaun", "Mumbai to Patna", "Surat to Delhi", "Madhubani to Chennai", "Begusarai to Patna"};

void DisplaySeat()
{
  for (int i = 1; i <= 32; i++)
  {
    printf("%d .", i);
    {
      if (busSeat[i] == 0)
        printf("EMPTY");
      else
        printf("BOOKED");
    }
    printf("     ");
    if (i % 4 == 0)
      printf("\n");
  }
}
void login()
{
  char userName[20] = "user";
  char passWord[10] = "team17";
  char matchPass[10];
  char matchUser[10];
  int value;

  printf("=========================================================");
  printf("\n\t\t\tWelcome to Online Bus Reservation");
  printf("\n=======================================================");
login:
{
  printf("\n\nUserName: ");
  gets(matchUser);

  printf("\nPassWord: ");
  gets(matchPass);
}

  value = strcmp(passWord, matchPass); /// string compare is function defined in headerfile i.e string.h
  if (value != 0)
  {

    printf("\nInvalid details try again..");
    goto login;
  }
}
void ticketBooking()
{
  int choice, seats;
  busLists();
  printf("\nCHOOSE YOUR BUS : ");
  scanf("%d", &choice);
  DisplaySeat();
  printf("\n\nNO. OF SEATS YOU NEED TO BOOK : ");
  scanf("%d", &seats);
  int seatNumber;
  for (int i = 1; i <= seats; i++) // for entering the person name and seat number in the file
  {
    printf("\n===================================================================");
    printf("\n  ENTER THE SEAT NUMBER: ");
    scanf("%d", &seatNumber);
    busSeat[seatNumber] = 1;
    printf("\n   ENTER THE PERSON NAME: ");
    scanf("%s", passName);
    printf("\n===================================================================");
    printf("\n");
  }
}
void busLists()
{
  int choice, seats;
  printf("\n======================================\n");
  printf("\n    BUSSES PRESENT RIGHT NOW !!\n\n");
  printf("   [1]  =>  %s\n\n", busName[0]);
  printf("   [2]  =>  %s\n\n", busName[1]);
  printf("   [3]  =>  %s\n\n", busName[2]);
  printf("   [4]  =>  %s\n\n", busName[3]);
  printf("   [5]  =>  %s\n\n", busName[4]);
  printf("\n====================================\n");
  // busLists();
  printf("\nCHOOSE YOUR BUS OR PRESS Q TO MAIN MENU : ");
  scanf("%d", &choice);

  DisplaySeat();
  printf("\n\nNO. OF SEATS YOU NEED TO BOOK : ");
  scanf("%d", &seats);
  int seatNumber;
  for (int i = 1; i <= seats; i++)
  {
    char passName[20];
    printf("\n\n============================================\n\n");
    printf("   ENTER THE SEAT NUMBER: ");
    scanf("%d", &seatNumber);
    busSeat[seatNumber] = 1;
    printf("\n   ENTER THE PERSON NAME: ");
    scanf("%s",passName);
    printf("\n==========================================\n\n"); 
  }
}
void cancle(int ReservationNo)
{

  char c;
aa:
{
  printf("Reservation Number %d is going to be cancelled\nEnter Y for Yes and N for No : ", ReservationNo);
  scanf("%c", &c);
  cancle(12);
  if (c == 'y' || c == 'Y')
  {
    //     //node delete

    printf("\nReseravation has been cancelled successfully.");
  }
  else if (c == 'n' || c == 'N')
  {
    printf("\nReseravation cancellation has denied.");
  }
  else
  {
    printf("Enter valid input");
    goto aa;
  }
}
}

int main()
{
  login();
  int ReservationNo;
  int num, i;
  do
  {
    printf("\n\n========================================\n\n");
    printf("\t\tBUS RESERVATION\t\t");
    printf("\n\n========================================\n");
    printf("\n====================  MAIN MENU  =====================\n\n");
    printf("   [1] View Bus List And Book Tikects\n\n");
    printf("   [2] Book Tickets\n\n");
    printf("   [3] Cancel Booking\n\n");
    printf("   [4] Bus Status Board\n\n");
    printf("   [5] Exit\n");
    printf("\n=====================================================\n");
    printf("   ENTER YOUR CHOICE: ");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
      busLists(); // for list of bus
      break;
    case 2:
      ticketBooking(); // for booking the tickets
      break;
    case 3:
      printf("\nEnter your Reservation NO: ");
      scanf("%d", ReservationNo);
      cancle(ReservationNo);
      break;
    case 4:
      // status();
      break;
    }
  } while (num != 5);
  // system("CLS");
  printf("\n\n============================================\n\n");
  printf("THANK YOU FOR USING THIS BUS RESERVATION SYSTEM");
  printf("\n\nPRESS ANY KEY TO EXIT THE END PROGRAM !! \n");
  printf("\n\n");
  getch();
  return 0;
}