class MyCircularDeque {
public:
    vector<int> deque;
    int front = -1;
    int rear = -1;
    
    MyCircularDeque(int k) {
        deque.resize(k);
    }
    
    bool insertFront(int x) {
        if (!isFull()) {
            if (front == -1) {
                front = rear = 0;
                deque[front] = x;
            } 
            else {
                if (front == 0) {
                    front = deque.size() - 1;
                } else {
                    front--;
                }  
                deque[front] = x;
            }
            return true;
        }
        return false;
    }
    
    bool insertLast(int x) {
        if (!isFull()) {
            if (rear == -1) {
                front = rear = 0;
                deque[rear] = x;
            } 
            else {
                if (rear == deque.size() - 1) {
                    rear = 0;
                } else {
                    rear++;
                }

                deque[rear] = x;
            }
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if (!isEmpty()) {
            if (front == rear) {
                front = rear = -1;
            } 
            else {
                if (front == deque.size() - 1) {
                    front = 0;
                } else {
                    front++;
                }
            }
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if (!isEmpty()) {
            if (front == rear) {
                front = rear = -1;
            } 
            else {
                if (rear == 0) {
                    rear = deque.size() - 1;
                } else {
                    rear--;
                }
            }
            return true;
        }
        return false;
    }
    
    int getFront() {
        if (!isEmpty()) {
            return deque[front];
        }
        return -1;
    }
    
    int getRear() {
        if (!isEmpty()) {
            return deque[rear];
        }
        return -1;
    }
    
    bool isEmpty() {
        if (front == -1) {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if ((rear + 1) % deque.size() == front) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */