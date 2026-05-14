#include <iostream>
using namespace std;

#define SIZE 100

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        arr[rear] = val;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        int val = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        return val;
    }
};

void task1() {
    CircularQueue q;
    int n, val, sum = 0;
    cout << "\n--- Task 1: Sum of Elements ---\n";
    cout << "Kitne elements dalne hain? ";
    cin >> n;
    cout << "Elements enter karo: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.enqueue(val);
    }
    
    while (!q.isEmpty()) {
        sum += q.dequeue();
    }
    cout << "Sum = " << sum << endl;
}

void task2() {
    CircularQueue q;
    int val, max;
    cout << "\n--- Task 2: Largest Number ---\n";
    cout << "5 integers enter karo: ";
    for (int i = 0; i < 5; i++) {
        cin >> val;
        q.enqueue(val);
    }
    
    max = q.dequeue();
    while (!q.isEmpty()) {
        val = q.dequeue();
        if (val > max) max = val;
    }
    cout << "Largest number = " << max << endl;
}

void task3() {
    CircularQueue q;
    int n, val, tempArr[SIZE], count = 0;
    cout << "\n--- Task 3: Reverse Order ---\n";
    cout << "Kitne elements hain? ";
    cin >> n;
    cout << "Elements enter karo: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.enqueue(val);
    }
    
    while (!q.isEmpty()) {
        tempArr[count++] = q.dequeue();
    }
    
    cout << "Reverse order: ";
    for (int i = count - 1; i >= 0; i--) {
        cout << tempArr[i] << " ";
    }
    cout << endl;
}

void task4() {
    CircularQueue q;
    int n, val, count = 0;
    cout << "\n--- Task 4: Count Even Numbers ---\n";
    cout << "Kitne elements hain? ";
    cin >> n;
    cout << "Elements enter karo: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.enqueue(val);
    }
    
    while (!q.isEmpty()) {
        if (q.dequeue() % 2 == 0) count++;
    }
    cout << "Total even numbers = " << count << endl;
}

int main() {
    int choice;
    do {
        cout << "\n====== MENU ======";
        cout << "\n1. Task 1 - Sum of Elements";
        cout << "\n2. Task 2 - Largest Number";
        cout << "\n3. Task 3 - Reverse Order";
        cout << "\n4. Task 4 - Count Even Numbers";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 0: cout << "Program khatam." << endl; break;
            default: cout << "Invalid choice!";
        }
    } while (choice!= 0);

    return 0;
}