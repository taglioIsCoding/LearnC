#define maxName 1023
#define MAX 10

typedef struct booking
{
    char name[maxName];
    int place;
}Booking;

int read(Booking * dest);

int assegna( Booking list[],int dim, int * lengthList, char * name, int pref);