class Node {
  constructor(data = null) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor(data) {
    if (Array.isArray(data)) {
      data.forEach(value => this.add_node(value));
    } else {
      this.add_node(data);
    }
  }

  add_node(data) {
    const node = new Node(data);

    if (!this.head) {
      this.head = node;
    } else {
      let current = this.head;
      while (current.next !== null) {
        current = current.next;
      }
      current.next = node;
    }
  }

  print_list() {
    process.stdout.write('head -> ');
    let current = this.head;
    while (current != null) {
      process.stdout.write(current.data + ' -> ');
      current = current.next;
    }
    console.log('*null');
  }
  // start with a flag of true
  // if flag is true then expected current.next.data > current.data
  // else if flag false, we expect current.next.data < current.data
  // otherwise swap
  zigzag(flag = true) {
    let current = this.head;

    while (current.next !== null) {
      if (flag == true && current.next.data < current.data) {
        [current.next.data, current.data] = [current.data, current.next.data];
      } else if (flag == false && current.next.data > current.data) {
        [current.next.data, current.data] = [current.data, current.next.data];
      }
      flag = !flag;
      current = current.next;
    }
    this.print_list(); // after zig zag
  }
}

const LL = new LinkedList([1, 2, 3, 4, 5, 6, 7, 8, 9]);
LL.print_list();
LL.zigzag(false);
