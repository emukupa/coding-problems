#include <iostream>
#include <list>

using namespace std;

void print(int *array, int length)
{
  cout << "[";
  for (int i = 0; i < length; i++)
  {
    cout << array[i];
    if (i < length - 1)
    {
      cout << ", ";
    }
  }

  cout << "]" << endl;
}

void print(list<int> ll)
{
  list<int>::iterator it;
  cout << "head -> ";
  for (it = ll.begin(); it != ll.end(); ++it)
  {
    cout << *it << " -> ";
  }
  cout << "*null" << endl;
}

// swap array elements
void swap(int *array, int left, int right)
{
  int temp = array[left];
  array[left] = array[right];
  array[right] = temp;
}

void zigZag(int *array, int length)
{
  // start with true flag
  // if flag is true, expect array[i] > array[i -1]
  // else if flag is false, expect array[i] < array[i-1]
  // otherwise swap
  bool flag = true;

  for (int i = 1; i < length; i++)
  {
    if (flag == true && array[i] < array[i - 1])
    {
      swap(array, i - 1, i);
    }
    else if (flag == false && array[i] > array[i - 1])
    {
      swap(array, i - 1, i);
    }

    flag = !flag; // flip the flag
  }
}

void zigZag(list<int> &ll)
{
  // start with true flag
  // if flag is true, expect current > previous
  // else if flag is false, expect current < previous
  // otherwise swap

  bool flag = true;
  list<int> ll2;
  list<int>::iterator it = ll.begin();
  int prev = *it;

  // traverse the list, comparing items and adding them to ll2
  while (it != ll.end())
  {
    int curr = *++it; // move iterator forward and the get the value
    if (flag == true && curr > prev)
    {
      ll2.push_back(prev);
      prev = curr;
    }
    else if (flag == false && curr < prev)
    {
      ll2.push_back(prev);
      prev = curr;
    }
    else
    {
      ll2.push_back(curr);
    }
    flag = !flag;
  }
  ll.assign(ll2.begin(), ll2.end());
}
int main()
{
  // Array
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int length = sizeof(array) / sizeof(array[0]);

  print(array, length); // before zigzag
  zigZag(array, length);
  print(array, length); // after zigzag
  // Lists
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  list<int> ll(begin(arr), end(arr));
  print(ll); // before zigZag
  zigZag(ll);
  print(ll); // after zigZag
  return 0;
}