//leetcode : https://leetcode.com/problems/design-circular-deque/?envType=daily-question&envId=2024-09-28

class MyCircularDeque {
public:
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;
    MyCircularDeque(int k) {
        arr = new int[k];
        capacity = k;
        front = 0;
        rear = k - 1;
        count = 0;
    }
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        count++;
        return true;
    }
    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;
        return true;
    }
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        count--;
        return true;
    }
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        count--;
        return true;
    }
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
    bool isEmpty() {
        return count == 0;
    }
    bool isFull() {
        return count == capacity;
    }
};
