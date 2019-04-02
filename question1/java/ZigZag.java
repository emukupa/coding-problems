import java.util.LinkedList;
import java.util.ListIterator;

public class ZigZag {
  // prints an array
  public static void print(int[] array) {
    System.out.print("[");
    for (int i = 0; i < array.length; i++) {
      System.out.print(array[i]);
      if (i < array.length - 1) {
        System.out.print(", ");
      }
    }
    System.out.println("]");
  }

  // prints linked list elements
  public static void print(LinkedList<Integer> list) {
    System.out.print("head -> ");
    ListIterator it = list.listIterator(0);

    // traverse through the list
    while (it.hasNext()) {
      System.out.print(it.next() + " -> ");
    }
    System.out.println("*null");
  }

  // swaps array elements
  private static void swap(int[] array, int left, int right) {
    int temp = array[left];
    array[left] = array[right];
    array[right] = temp;
  }

  // swaps list item
  private static void swap(LinkedList<Integer> list, int left, int right) {
    int temp = list.get(left);
    list.set(left, list.get(right));
    list.set(right, temp);
  }

  public static void zigZag(int[] array) {
    // startwith a true flag
    // if flag is true expect arra[i] > array[i -1]
    // els if flag is false, expect array[i] < array[i -1]
    // otherwise sway elements

    boolean flag = true;
    for (int i = 1; i < array.length; i++) {
      if (flag == true && array[i] < array[i - 1]) {
        swap(array, i - 1, i);
      } else if (flag == false && array[i] > array[i - 1]) {
        swap(array, i - 1, i);
      }
      flag = !flag; // flip the flag
    }
  }

  public static void zigZag(LinkedList<Integer> list) {
    if (list.peekFirst() != null) {
      // start with a true flag
      // if flag is true expect list.get(i) > list.get(i-1) | current > previous
      // else if flag is false expect list.get(i) < list.get(i-1) | current < previous
      // otherwise swap
      boolean flag = true;
      int i = 1;
      while (i < list.size()) {
        int current = list.get(i);
        int previous = list.get(i - 1);
        if (flag == true && current < previous) {
          swap(list, i - 1, i);
        } else if (flag == false && current > previous) {
          swap(list, i - 1, i);
        }
        i++;
        flag = !flag;
      }
    }
  }

  public static void main(String args[]) {

    // Arrays
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    print(array); // before zigzag
    zigZag(array);
    print(array); // after zigzag

    // LinkedList
    LinkedList<Integer> list = new LinkedList<>();
    for (int i = 1; i <= 9; i++) {
      list.add(i);
    }

    print(list); // before zigzag
    zigZag(list);
    print(list); // after zigzag

  }
}