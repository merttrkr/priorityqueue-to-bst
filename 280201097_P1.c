# include <stdio.h>
# include <string.h>
#include <stdlib.h>
#include<math.h>

#define MAX 6487548

int Queue[MAX],Priority[MAX];
int r = -1,f = -1;
struct node
{
 	int data;
 	struct node* left;
 	struct node* right;
};
struct node *root; 

void createQueue(int data){

	int i;
	if((f==0)&&(r==MAX-1)) //Check if Queue is full
		printf("Queue is full");
	else
	{
		if(f==-1)//if Queue is empty
		{
			f = r = 0;
			Queue[r] = data;
			Priority[r] = data;

		}
		else if(r == MAX-1)//if there there is some elemets in Queue
		{
			for(i=f;i<=r;i++) { 
			Queue[i-f] = Queue[i]; 
			Priority[i-f] = Priority[i]; 
			r = r-f; f = 0; 
			for(i = r;i>f;i--)
				{
					if(data>Priority[i])
					{
						Queue[i+1] = Queue[i];
						Priority[i+1] = Priority[i];
					}
					else
						break;
					Queue[i+1] = data;
					Priority[i+1] = data;
					r++;
				}
			}
		}
		else
		{
			for(i = r;i>=f;i--)
			{
				if( data >Priority[i])
				{
					Queue[i+1] = Queue[i];
					Priority[i+1] = Priority[i];	
				}
				else
					break;
			}
			Queue[i+1] = data;
			Priority[i+1] = data;
			r++;
		}	
	}
};

void convert(){
	
	int i = 0
   struct node *ptr;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));
   int largest = root; // Initialize largest as root
        int l = 2 * root + 1; // left = 2*i + 1
        int r = 2 * root + 2; // right = 2*i + 2
  
        // If left child is larger than root
        if (l < n && arr[l] > Queue[largest])
            largest = l;
  
        // If right child is larger than largest so far
        if (r < n && arr[r] > Queue[largest])
            largest = r;
  
        // If largest is not root
        if (largest != root) {
            int swap = Queue[root];
            arr[i] = arr[largest];
            arr[largest] = swap;
  
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter Item value");  
    scanf("%d",&item);  
      
   if(root==NULL)  
   {  
       ptr->right = NULL;  
       ptr->left=NULL;  
       ptr->data=Queue[i];  
       root=ptr;
	   i++;
   }  
   else   
   {  
       ptr->data=Queue[i];  
       ptr->prev=NULL;  
       ptr->right = root;  
       root->prev=ptr;  
       root=ptr;
	   i++;  
   }  
   printf("\nNode inserted\n");  
	}  
}

int main( )
{
 	
 	
    FILE *myFile;
    myFile = fopen("data.txt", "r");
    int* numberArray = malloc(MAX * sizeof(int));//create an array to hold the numbers which comes from the text file
   
	int i, arrLen = 0;
	
	while(i < 13 ){//fill the array with numbers
		
		fscanf(myFile, "%d", &numberArray[i]);
		
		arrLen ++;
		i++;
	}
        fclose(myFile);
    for (i = 0; i < arrLen; i++)
    {
        printf(" %d", numberArray[i]);//check array
        createQueue(numberArray[i]);//create a priority queue 
    }
    /*for(i=f;i<=r;i++)//print queue
	{
		printf("\nElement = %d\tPriority = %d",Queue[i],Priority[i]);
	}*/
	int x= 2;
	int y = 28;
	int z = pow(x,y);
	
    
    return 0;       
}
