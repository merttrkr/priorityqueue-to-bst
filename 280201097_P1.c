# include <stdio.h>
# include <string.h>
#include <stdlib.h>
#include<math.h>
#include <time.h>
#define MAX 24
 int size = -1;
struct node{
  int data;
  struct node *left,*right;
};

void convert(struct node **, int , int,int* );//convert heap representation array to structer with pointers

void printCurrentLevel(struct node* , int );
int height(struct node* );
void printLevelOrder(struct node* );
void save_file(int num);

 void swap(int i, int j,int *H)
{
  int temp= H[i];
  H[i] = H[j];
  H[j] = temp;
}
 int parent(int i)
{
  return (i - 1) / 2;
}
 
// Function to return the index of the
// left child of the given node
 int leftChild(int i)
{
  return ((2 * i) + 1);
}
 
// Function to return the index of the
// right child of the given node
 int rightChild(int i)
{
  return ((2 * i) + 2);
}
 
// Function to shift up the
// node in order to maintain
// the heap property
 void shiftUp(int i,int *H)
{
  while (i > 0 &&
         H[parent(i)] < H[i])
  {
    // Swap parent and current node
    swap(parent(i), i,H);
 
    // Update i to parent of i
    i = parent(i);
  }
}
 

// Function to insert a
// new element in
// the Binary Heap
 void insert(int p,int *H)
{
  size = size + 1;
  H[size] = p;
 
  // Shift Up to maintain
  // heap property
  shiftUp(size,H);
}
 

int main( )
{
 	
 	struct  node *rootNode;
    FILE *myFile;//file pointer
    myFile = fopen("test_data.txt", "r");
	int* txtToArr = malloc(MAX * sizeof(int));
	int* heapArr = malloc(MAX * sizeof(int));
	int i, arrLen = 0,j;
	
	while(i < MAX ){//fill the array with numbers
		
		fscanf(myFile, "%d", &txtToArr[i]);
		
		arrLen ++;
		i++;
	}
        fclose(myFile);
    
    //traverse the input array 
    printf("text input to array:");
    for (i = 0; i < arrLen; i++)
    {
        printf(" %d", txtToArr[i]); 
    }
    

  
     clock_t t; 
    	t = clock();
    	 
		
	//this loop takes every element of the array and create the heap version of it
    for (j = 0; j < arrLen; j++)
    {
    	insert(txtToArr[j],heapArr);// one by one creating array representation	
    	
		/*printf("\n B%d :",j);
	    for (i = 0; i < j+1; i++)//uncomment this loop to display the process.  
	    {
	        printf(" %d", heapArr[i]); 
	    } */ 	
		}		
		t = clock() - t;
		double time_taken = ((double)t)/CLOCKS_PER_SEC; 
		printf("\nTime elapsed for %d numbers is %f seconds\n", arrLen, time_taken);
		printf("\nheap representation :");
		
		for (i = 0; i < arrLen; i++)//display heap representation 
		    {
		        printf(" %d", heapArr[i]); 
		    }
		convert(&rootNode, 0, arrLen,heapArr);//heap array to data structer
    	
    	//example output
    	printf("\nroot:%d",rootNode->data);
		printf("\nroot->left:%d",rootNode->left->data);
		printf("\nroot->right:%d",rootNode->right->data);
		printf("\nlevel order traversal: ",rootNode->right->data);
		printLevelOrder(rootNode);
		fclose(myFile);*/
	return 0;
}


//receives the address of the root node than converts the heap array into data structer with pointers.
void convert(struct node **rootNode, int index, int n,int *heapArr)
{
    if (index < n) {
    	
    	
        *rootNode = malloc(sizeof(**rootNode));
        
        (*rootNode)->data = heapArr[index];
        (*rootNode)->left = NULL;
        (*rootNode)->right = NULL;
        
        convert(&(*rootNode)->left, leftChild(index), n,heapArr);
        convert(&(*rootNode)->right, rightChild(index), n,heapArr);
    }
}

void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
// Print nodes at a current level 
void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1){
    	printf("%d ", root->data);
        save_file(root->data);
	}
        
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
 
// Calculates the farthest distance between root and the bottom element
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        // calculates both distance 
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        // selects the furthest 
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
void save_file(int num){
	FILE *myFile;
	myFile= fopen("output_file.txt", "a");
	if(myFile == NULL){
	      printf("Error, there is no File!");   
	      exit(1);             
	   }
	fprintf(myFile, "%d", num);
	fprintf(myFile, "%s", " ");
		 
	}

