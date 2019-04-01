#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
  int data;
  struct node *next;
  int index;
} Node;

// print array utility
void print_array(int array[], int length)
{
  printf("[");
  for (int i = 0; i < length; i++)
  {
    printf("%d", array[i]);
    if (i < length - 1)
    {
      printf(", ");
    }
  }
  printf("]\n");
}

// print list utility
void print_list(Node *node)
{
  printf("head -> ");
  while (node != NULL && node->index >= 0)
  {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf(" * null\n");
}

int main(void)
{
  printf("Enter a list of numbers. Press q to finish!\n");

  char input[256];    // used to store inputs, max input is 256 bits
  int count = 0;      // keep track of the numbers entered
  int nums_array[64]; // will store the list of numbers enterd, max - 64 numbers

  // Get user input until the user quits
  while (1)
  {
    // prompt the user to enter a number
    printf("Number %d: ", count + 1);
    fgets(input, 256, stdin);

    // quits the prompt
    if (strncmp("q", input, 1) == 0 || strncmp("Q", input, 1) == 0)
    {
      break;
    }

    // instantiates a nums array, to store the one values.
    // A simple variables works but
    // TODO extend it to a list of nums sepearated by space or commas
    int nums[1];
    int ints_assigned = sscanf(input, "%d", &nums[0]);

    // sscanf returns the number of assignments,
    // if its int it is assigned otherwise, not
    if (ints_assigned == 1)
    {
      nums_array[count] = nums[0];
      count++;
    }
  }

  Node *root = (Node *)malloc(sizeof(Node));
  root->index = -1;
  Node *pointer = root; // create a point and point it to the root

  for (int i = 0; i < count; i++)
  {
    if (i == 0)
    {
      // start of the list
      root->data = nums_array[i];
      root->next = NULL;
      root->index = i;
    }
    else
    {
      Node *new_node = (Node *)malloc(sizeof(Node));
      new_node->data = nums_array[i];
      new_node->next = NULL;
      new_node->index = i;
      pointer->next = new_node; // link pointer to next node
      pointer = pointer->next;  // move pointer to the next node
    }
  }

  print_array(nums_array, count);
  print_list(root);

  return 0;
}