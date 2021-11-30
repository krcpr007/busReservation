#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
void status();
void busLists();

int busSeat[33][10] = {0};
void redColor()
{
  printf("\033[1;31m");
}
void resetColor()
{
  printf("\033[0m");
}
void DisplaySeat(int bus[33])
{
  for (int i = 1; i <= 32; i++)
  {
    printf("%d .", i);
    {
      if (bus[i] == 0)
        printf("Empty");
      else
        printf("Booked");
    }
    printf("     ");
    if (i % 6 == 0)
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

    printf("\nINVALID DETAILS TRY AGAIN...\n");
    goto login;
  }
}
void ticketBooking(int randomNum)
{
  int choice, seats;
  busLists(randomNum);
}
void status()
{

  printf("Enter your Bus Number ");
}
void busLists(int randomNum)
{
  int cost = 250;
  int choice, seats;
  printf("-----------------------------------------------------------------------------------------");
  printf("\nBus.No\tName\t\t\tDestinations  \t\tCharges  \t\tTime\n");
  printf("-----------------------------------------------------------------------------------------");
  printf("\n1\tGangaTravels         \tDharan to Kavre       \tRs.700   \t\t07:00   AM");
  printf("\n2\tPhaphara Travels     \tKavre To Dharan       \tRs.750    \t\t01:30  PM");
  printf("\n3\tShiv Ganga Travels   \tAllahabad To Gorakhpur\tRs.400    \t\t03:50  PM");
  printf("\n4\tSuper Deluxe         \tPokhara To Benigha    \tRs.350    \t\t01:00  AM");
  printf("\n5\tSai Baba Travels     \tMaitidevi To Janakpur \tRs.400    \t\t12:05  AM");
  printf("\n6\tShine On Travels     \tMadhubani to Patna    \tRs.400    \t\t09:30  AM");
  printf("\n7\tMayur Travels        \tPatna To Gaya         \tRs.350    \t\t11:00  PM");
  printf("\n8\tShree Travels        \tGaya To Chhapra       \tRs.350    \t\t04:00  PM");
  printf("\n9\tShatabdi Travels     \tKathmandu To Pokhara  \tRs.600    \t\t05:35  PM");
  printf("\n10\tRajjo Travels       \tBegusarai To Patna    \tRs.700    \t\t08:15  AM");
  // busLists();
  printf("\nCHOOSE YOUR BUS  : ");
  scanf("%d", &choice);
  printf("\n");
  DisplaySeat(busSeat[choice]);
  printf("\n\nNO. OF SEATS YOU NEED TO BOOK : ");
  scanf("%d", &seats);
  int seatNumber;
  for (int i = 1; i <= seats; i++)
  {
    char passName[20];
    printf("\n\n============================================\n\n");
    printf("   ENTER THE SEAT NUMBER: ");
    scanf("%d", &seatNumber);
    busSeat[choice][seatNumber] = 1;
    printf("\n   ENTER THE PERSON NAME: ");
    scanf("%s", passName);
    printf("\n=============================================\n\n");
  }
  // printf("\nYOUR COST OF BOOKING %d SEAT IS %dRs.\n", seats, cost * seats);
  redColor();
  printf("\nYOUR RESERVATION NUMBER IS  %d\n", randomNum);
  printf("\nPLEASE NOTE DOWN YOUR RESERVATION NUMBER FOR CANCEL BOOKING TICKETS\n");
  resetColor();
  getch();
}
void cancel(int randomNum)
{
  int reservationNo;
  int seatNumber;
  int choice;
  char c;
  int seatCancel;

aa:
{
  printf("\nENTER YOUR RESERVATION NUMBER : ");
  scanf("%d", &reservationNo);
  if (reservationNo == randomNum)
  {
    printf("\nRESERVATION NUMBER IS IT CORRECT ? %d \nENTER (Y/N) : ", reservationNo);
    scanf("%s", &c);
    if (c == 'y' || c == 'Y')
    {
      printf("\n\n============================================\n\n");
      printf("   ENTER THE BUS NUMBER: ");
      scanf("%d", &choice);

      printf("\nHOW MANY SEATS DO WANT TO CANCEL : ");
      scanf("%d", &seatCancel);
      for (int i = 0; i < seatCancel; i++)
      {
        printf("   \nENTER THE SEAT NUMBER: ");
        scanf("%d", &seatNumber);

        busSeat[choice][seatNumber] = 0;
      }
      printf("\n\nYOUR RESERVATION HAS BEEN CANCEL\n");
      getch();
      DisplaySeat(busSeat[choice]); 
    }

    else if (c == 'n' || c == 'N')
    {
      printf("\nYOUR RESERVATION CANCELATION HAS BEEN DENIED\n");
    }
  }
  else
  {
    printf("\nNOT FOUND!! ENTER THE CORRECT RESERVATION NUMBER\n");
    goto aa;
  }
}
}

int main()
{
  srand(time(0));
  int randomNum = rand();
  int num, i;
  login();
main:
{
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
      busLists(randomNum); // for list of bus
      break;
    case 2:
      ticketBooking(randomNum); // for booking the tickets
      break;
    case 3:
      cancel(randomNum);
      break;
    case 4:
      status();
      break;
    }
  } while (num != 5);
  printf("\n\n============================================\n\n");
  printf("THANK YOU FOR USING THIS BUS RESERVATION SYSTEM");
  printf("\n\nPRESS ANY KEY TO EXIT THE END PROGRAM !! \n");
  printf("\n\n");
  getch();
  return 0;
}
}