// Java code to implement
// priority-queue using
// array implementation of
// binary heap
import java.io.File;
import java.util.*;
import java.util.Scanner;

import java.io.FileNotFoundException;
class app{
static int MAX = 24;
static int []H = new int[MAX];
static int size = -1;

// Function to return the index of the
// parent node of a given node
static int parent(int i)
{
  return (i - 1) / 2;
}
 
// Function to return the index of the
// left child of the given node
static int leftChild(int i)
{
  return ((2 * i) + 1);
}
 
// Function to return the index of the
// right child of the given node
static int rightChild(int i)
{
  return ((2 * i) + 2);
}
 
// Function to shift up the
// node in order to maintain
// the heap property
static void shiftUp(int i)
{
  while (i > 0 &&
         H[parent(i)] < H[i])
  {
    // Swap parent and current node
    swap(parent(i), i);
 
    // Update i to parent of i
    i = parent(i);
  }
}
 

// Function to insert a
// new element in
// the Binary Heap
static void insert(int p)
{
  size = size + 1;
  H[size] = p;
 
  // Shift Up to maintain
  // heap property
  shiftUp(size);
}
 



   
static void swap(int i, int j)
{
  int temp= H[i];
  H[i] = H[j];
  H[j] = temp;
}
 
// Driver Code
public static void main(String[] args) throws FileNotFoundException
{
	Scanner scanner = new Scanner(new File("data.txt"));
	int [] arr = new int [MAX];
	int i = 0;
	while(scanner.hasNextInt())
	{
	     arr[i++] = scanner.nextInt();
	}
	//long startTime = System.currentTimeMillis();
	long startTime = System.nanoTime();
	for (int num : arr) {
		insert(num);
	}
	//long stopTime = System.currentTimeMillis();
	long stopTime = System.nanoTime();
	System.out.println("Time elapsed for " +arr.length + " numbers " + (stopTime - startTime) + " nanoseconds");	
 
   i = 0;
   
  // Priority queue before extracting max
  System.out.print("Priority Queue : ");
  while (i <= size)
  {
    System.out.print(H[i] + " ");
    i++;
  }
 
  System.out.print("\n");
 
  // Node with maximum priority
  
}
}