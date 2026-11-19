
#include <stdio.h>

int main()
{
    int state=1600,rate=1024;
    int capacity,lanes,i,blocks;

    capacity=state-rate;
    lanes=capacity/64;

    printf("State size: %d bits\n",state);
    printf("Rate: %d bits\n",rate);
    printf("Capacity: %d bits\n",capacity);
    printf("Zero capacity lanes: %d\n",lanes);

    printf("Enter number of message blocks: ");
    scanf("%d",&blocks);

    for(i=1;i<=blocks;i++)
        printf("After block %d: %d capacity lanes remain zero\n",
               i,lanes);

    printf("Without permutation, capacity lanes never become nonzero.\n");

    return 0;
}

