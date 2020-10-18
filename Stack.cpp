// StackSlides.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stack>

typedef int StackItemType;

class Stack {
public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();

    bool isEmpty() const;
    bool push(StackItemType newItem);
    bool pop();
    bool pop(StackItemType& stackTop);
    bool getTop(StackItemType& stackTop) const;
    void display();

private:
    struct StackNode {
        StackItemType item;
        StackNode* next;
    };
    StackNode* topPtr;
};

// default constructor
Stack::Stack() : topPtr(NULL) {
};

// copy constructor
Stack::Stack(const Stack& aStack) {
    if (aStack.topPtr == NULL) topPtr = NULL;
    else {
        topPtr = new StackNode;
        topPtr->item = aStack.topPtr->item;

        StackNode* newPtr = topPtr;
        for (StackNode* origPtr = aStack.topPtr->next;
                        origPtr != NULL;
                        origPtr = origPtr->next) {
            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
};

// destructor
Stack::~Stack() {
    while (!isEmpty())
        pop();
};

bool Stack::isEmpty() const {
    return topPtr == NULL;
}

bool Stack::push(StackItemType newItem) {
    
    StackNode* newPtr = new StackNode;
    newPtr->item = newItem;
    newPtr->next = topPtr;
    topPtr = newPtr;

    return true;
}

bool Stack::pop() {

    if (isEmpty()) return false;

    else {
        StackNode* temp = topPtr;
        topPtr = topPtr->next;

        temp->next = NULL;
        delete temp;
        return true;
    }
}

bool Stack::pop(StackItemType& stackTop) {
    if (isEmpty())
        return false;

    else {
        stackTop = topPtr->item;
        StackNode* temp = topPtr;
        topPtr = topPtr->next;

        temp->next = NULL;
        delete temp;
        return true;
    }
}

bool Stack::getTop(StackItemType& stackTop) const {
    if (isEmpty()) return false;

    else {
        stackTop = topPtr->item;
        return true;
    }
}

void Stack::display() {
    StackNode* temp = topPtr;
    while (temp != NULL) {
        printf("%d ", temp->item);
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main()
{
    Stack stk;
    stk.push(10); stk.push(20); stk.push(30); stk.display();

    std::cout << stk.pop() << std::endl; stk.display();
    std::cout << stk.pop() << std::endl; stk.display();
    std::cout << stk.pop() << std::endl; stk.display();
    return 0;
}
